package model

type WithdrawIndex struct {
	Base
	B2IndexBlock uint64 `json:"b2_index_block" gorm:"comment:b2 index block"`
	B2IndexTx    uint   `json:"b2_index_tx" gorm:"comment:b2 tx index"`
	B2LogIndex   uint   `json:"b2_log_tx" gorm:"comment:b2 log index"`
}

func (WithdrawIndex) TableName() string {
	return "withdraw_index"
}
