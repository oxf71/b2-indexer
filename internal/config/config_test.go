package config_test

import (
	"os"
	"testing"

	"github.com/b2network/b2-indexer/internal/config"
	"github.com/btcsuite/btcd/chaincfg"
	"github.com/stretchr/testify/require"
)

func TestBitcoinConfig(t *testing.T) {
	// clean BITCOIN env set
	// This is because the value set by the environment variable affects viper reading file
	os.Unsetenv("BITCOIN_NETWORK_NAME")
	os.Unsetenv("BITCOIN_RPC_HOST")
	os.Unsetenv("BITCOIN_RPC_PORT")
	os.Unsetenv("BITCOIN_RPC_USER")
	os.Unsetenv("BITCOIN_RPC_PASS")
	os.Unsetenv("BITCOIN_DISABLE_TLS")
	os.Unsetenv("BITCOIN_WALLET_NAME")
	os.Unsetenv("BITCOIN_ENABLE_INDEXER")
	os.Unsetenv("BITCOIN_INDEXER_LISTEN_ADDRESS")
	os.Unsetenv("BITCOIN_INDEXER_INIT_BLOCK")
	config, err := config.LoadBitcoinConfig("./testdata")
	require.NoError(t, err)
	require.Equal(t, "signet", config.NetworkName)
	require.Equal(t, "localhost", config.RPCHost)
	require.Equal(t, "8332", config.RPCPort)
	require.Equal(t, "b2node", config.RPCUser)
	require.Equal(t, "b2node", config.RPCPass)
	require.Equal(t, true, config.DisableTLS)
	require.Equal(t, true, config.EnableIndexer)
	require.Equal(t, "tb1qfhhxljfajcppfhwa09uxwty5dz4xwfptnqmvtv", config.IndexerListenAddress)
	require.Equal(t, uint64(1), config.IndexerInitBlock)
}

func TestBitcoinConfigEnv(t *testing.T) {
	os.Setenv("BITCOIN_NETWORK_NAME", "testnet")
	os.Setenv("BITCOIN_RPC_HOST", "127.0.0.1")
	os.Setenv("BITCOIN_RPC_PORT", "8888")
	os.Setenv("BITCOIN_RPC_USER", "abc")
	os.Setenv("BITCOIN_RPC_PASS", "abcd")
	os.Setenv("BITCOIN_DISABLE_TLS", "false")
	os.Setenv("BITCOIN_WALLET_NAME", "b2node")
	os.Setenv("BITCOIN_ENABLE_INDEXER", "false")
	os.Setenv("BITCOIN_INDEXER_LISTEN_ADDRESS", "tb1qgm39cu009lyvq93afx47pp4h9wxq5x92lxxgnz")
	os.Setenv("BITCOIN_INDEXER_INIT_BLOCK", "2")

	config, err := config.LoadBitcoinConfig("./")
	require.NoError(t, err)
	require.Equal(t, "testnet", config.NetworkName)
	require.Equal(t, "127.0.0.1", config.RPCHost)
	require.Equal(t, "8888", config.RPCPort)
	require.Equal(t, "abc", config.RPCUser)
	require.Equal(t, "abcd", config.RPCPass)
	require.Equal(t, false, config.DisableTLS)
	require.Equal(t, false, config.EnableIndexer)
	require.Equal(t, "tb1qgm39cu009lyvq93afx47pp4h9wxq5x92lxxgnz", config.IndexerListenAddress)
	require.Equal(t, uint64(2), config.IndexerInitBlock)
}

func TestChainParams(t *testing.T) {
	testCases := []struct {
		network string
		params  *chaincfg.Params
	}{
		{
			network: "mainnet",
			params:  &chaincfg.MainNetParams,
		},
		{
			network: "testnet",
			params:  &chaincfg.TestNet3Params,
		},
		{
			network: "signet",
			params:  &chaincfg.SigNetParams,
		},
		{
			network: "simnet",
			params:  &chaincfg.SimNetParams,
		},
		{
			network: "regtest",
			params:  &chaincfg.RegressionNetParams,
		},
		{
			network: "invalid",
			params:  &chaincfg.TestNet3Params,
		},
	}

	for _, tc := range testCases {
		t.Run(tc.network, func(t *testing.T) {
			result := config.ChainParams(tc.network)
			if result == nil || result != tc.params {
				t.Errorf("ChainParams(%s) = %v, expected %v", tc.network, result, tc.params)
			}
		})
	}
}

func TestConfig(t *testing.T) {
	os.Unsetenv("INDEXER_ROOT_DIR")
	os.Unsetenv("INDEXER_LOG_LEVEL")
	os.Unsetenv("INDEXER_LOG_FORMAT")
	os.Unsetenv("INDEXER_DATABASE_SOURCE")
	os.Unsetenv("INDEXER_DATABASE_MAX_IDLE_CONNS")
	os.Unsetenv("INDEXER_DATABASE_MAX_OPEN_CONNS")
	os.Unsetenv("INDEXER_DATABASE_CONN_MAX_LIFETIME")

	config, err := config.LoadConfig("./testdata")
	require.NoError(t, err)
	require.Equal(t, "/data/b2-indexer", config.RootDir)
	require.Equal(t, "info", config.LogLevel)
	require.Equal(t, "json", config.LogFormat)
	require.Equal(t, "postgres://postgres:postgres@127.0.0.2:5432/b2-indexer", config.DatabaseSource)
	require.Equal(t, 1, config.DatabaseMaxIdleConns)
	require.Equal(t, 2, config.DatabaseMaxOpenConns)
	require.Equal(t, 3600, config.DatabaseConnMaxLifetime)
}

func TestConfigEnv(t *testing.T) {
	os.Setenv("INDEXER_ROOT_DIR", "/data/test")
	os.Setenv("INDEXER_LOG_LEVEL", "debug")
	os.Setenv("INDEXER_LOG_FORMAT", "json")
	os.Setenv("INDEXER_DATABASE_SOURCE", "testtest")
	os.Setenv("INDEXER_DATABASE_MAX_IDLE_CONNS", "12")
	os.Setenv("INDEXER_DATABASE_MAX_OPEN_CONNS", "22")
	os.Setenv("INDEXER_DATABASE_CONN_MAX_LIFETIME", "2100")
	config, err := config.LoadConfig("./")
	require.NoError(t, err)
	require.Equal(t, "/data/test", config.RootDir)
	require.Equal(t, "debug", config.LogLevel)
	require.Equal(t, "json", config.LogFormat)
	require.Equal(t, "testtest", config.DatabaseSource)
	require.Equal(t, 12, config.DatabaseMaxIdleConns)
	require.Equal(t, 22, config.DatabaseMaxOpenConns)
	require.Equal(t, 2100, config.DatabaseConnMaxLifetime)
}
