package server

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/b2network/b2-indexer/internal/types"

	"github.com/b2network/b2-indexer/internal/config"
	"github.com/b2network/b2-indexer/internal/logic/bitcoin"
	logger "github.com/b2network/b2-indexer/pkg/log"
	"github.com/btcsuite/btcd/rpcclient"
	"github.com/spf13/cobra"
	"gorm.io/gorm"
)

func Start(ctx *Context, cmd *cobra.Command) (err error) {
	bitcoinCfg := ctx.BitcoinConfig
	if bitcoinCfg.EnableIndexer {
		logger.Infow("bitcoin index service starting!!!")
		bclient, err := rpcclient.New(&rpcclient.ConnConfig{
			Host:         bitcoinCfg.RPCHost + ":" + bitcoinCfg.RPCPort,
			User:         bitcoinCfg.RPCUser,
			Pass:         bitcoinCfg.RPCPass,
			HTTPPostMode: true,                  // Bitcoin core only supports HTTP POST mode
			DisableTLS:   bitcoinCfg.DisableTLS, // Bitcoin core does not provide TLS by default
		}, nil)
		if err != nil {
			logger.Errorw("failed to create bitcoin client", "error", err.Error())
			return err
		}
		defer func() {
			bclient.Shutdown()
		}()
		bitcoinParam := config.ChainParams(bitcoinCfg.NetworkName)

		bidxLogger := newLogger(ctx, "[bitcoin-indexer]")
		bidxer, err := bitcoin.NewBitcoinIndexer(bidxLogger, bclient, bitcoinParam, bitcoinCfg.IndexerListenAddress, bitcoinCfg.IndexerListenTargetConfirmations)
		if err != nil {
			logger.Errorw("failed to new bitcoin indexer indexer", "error", err.Error())
			return err
		}
		// check bitcoin core status, whether the request succeed
		_, err = bidxer.BlockChainInfo()
		if err != nil {
			logger.Errorw("failed to get bitcoin core status", "error", err.Error())
			return err
		}

		db, err := GetDBContextFromCmd(cmd)
		if err != nil {
			logger.Errorw("failed to get db context", "error", err.Error())
			return err
		}

		bindexerService := bitcoin.NewIndexerService(bidxer, db, bidxLogger)

		errCh := make(chan error)
		go func() {
			if err := bindexerService.Start(); err != nil {
				errCh <- err
			}
		}()

		select {
		case err := <-errCh:
			return err
		case <-time.After(5 * time.Second): // assume server started successfully
		}

	}

	// wait quit
	code := WaitForQuitSignals()
	logger.Infow("server stop!!!", "quit code", code)
	return nil
}

func GetDBContextFromCmd(cmd *cobra.Command) (*gorm.DB, error) {
	if v := cmd.Context().Value(types.DBContextKey); v != nil {
		db := v.(*gorm.DB)
		return db, nil
	}
	return nil, fmt.Errorf("db context not set")
}

func GetAuditDBContextFromCmd(cmd *cobra.Command) (*gorm.DB, error) {
	if v := cmd.Context().Value(types.AuditDBContextKey); v != nil {
		db := v.(*gorm.DB)
		return db, nil
	}
	return nil, fmt.Errorf("audit db context not set")
}

func WaitForQuitSignals() int {
	sigs := make(chan os.Signal, 1)
	signal.Notify(sigs, syscall.SIGTERM, syscall.SIGQUIT, syscall.SIGINT, syscall.SIGHUP)
	sig := <-sigs
	return int(sig.(syscall.Signal)) + 128
}

func newLogger(ctx *Context, name string) logger.Logger {
	bridgeB2NodeLoggerOpt := logger.NewOptions()
	bridgeB2NodeLoggerOpt.Format = ctx.Config.LogFormat
	bridgeB2NodeLoggerOpt.Level = ctx.Config.LogLevel
	bridgeB2NodeLoggerOpt.EnableColor = true
	bridgeB2NodeLoggerOpt.Name = name
	bridgeB2NodeLogger := logger.New(bridgeB2NodeLoggerOpt)
	return bridgeB2NodeLogger
}
