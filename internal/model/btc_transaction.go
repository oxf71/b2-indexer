package model

const (
	DirectionIn  = 0
	DirectionOut = 1
)

type BtcTransaction struct {
	Base
	BtcBlockNumber    int64  `json:"btc_block_number" gorm:"index;comment:bitcoin block number"`
	BtcTxIndex        int64  `json:"btc_tx_index" gorm:"comment:bitcoin tx index"`
	BtcTxHash         string `json:"btc_tx_hash" gorm:"type:varchar(64);not null;default:'';uniqueIndex;comment:bitcoin tx hash"`
	BtcTxType         int    `json:"btc_tx_type" gorm:"type:SMALLINT;default:0;comment:btc tx type"`
	BtcFroms          string `json:"btc_froms" gorm:"type:jsonb;comment:bitcoin transfer, from may be multiple"`
	BtcFrom           string `json:"btc_from" gorm:"type:varchar(64);not null;default:'';index"`
	BtcTos            string `json:"btc_tos" gorm:"type:jsonb;comment:bitcoin transfer, to may be multiple"`
	BtcTo             string `json:"btc_to" gorm:"type:varchar(64);not null;default:'';index"`
	BtcFromAAAddress  string `json:"btc_from_aa_address" gorm:"type:varchar(42);default:'';comment:from aa address"`
	BtcFromEvmAddress string `json:"btc_from_evm_address" gorm:"type:varchar(42);default:'';comment:from evm address"`
	BtcValue          int64  `json:"btc_value" gorm:"default:0;comment:bitcoin transfer value"`
	Direction         int    `json:"direction" gorm:"type:SMALLINT;default:0;comment:direction"`
}

type BtcTransactionColumns struct {
	BtcBlockNumber    string
	BtcTxIndex        string
	BtcTxHash         string
	BtcTxType         string
	BtcFroms          string
	BtcFrom           string
	BtcTos            string
	BtcTo             string
	BtcFromAAAddress  string
	BtcFromEvmAddress string
	BtcValue          string
	Direction         string
}

func (BtcTransaction) TableName() string {
	return "btc_transaction"
}

func (BtcTransaction) Column() BtcTransactionColumns {
	return BtcTransactionColumns{
		BtcBlockNumber:    "btc_block_number",
		BtcTxIndex:        "btc_tx_index",
		BtcTxHash:         "btc_tx_hash",
		BtcTxType:         "btc_tx_type",
		BtcFroms:          "btc_froms",
		BtcFrom:           "btc_from",
		BtcTos:            "btc_tos",
		BtcTo:             "btc_to",
		BtcFromAAAddress:  "btc_from_aa_address",
		BtcFromEvmAddress: "btc_from_evm_address",
		BtcValue:          "btc_value",
		Direction:         "direction",
	}
}
