﻿/**
* Copyright (C) 2010-2020 TASS
* @file TassAPI4GHVSM.h
* @brief GHSM/GVSM接口
* @detail 用于访问GHSM/GVSM密码机
* @author WenHuan
* @version 1.0.0
* @date 2020/05/13
* Change History :
* <Date>     | <Version>  | <Author>       | <Description>
*---------------------------------------------------------------------------------
* 2020/05/13 | 1.0.0      | WenHuan        | Create file
* 2020/12/15 | 1.0.1      | WenHuan        | Add functions with key cipher by LMK
*---------------------------------------------------------------------------------
*/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif
	typedef enum {
		TA_ENC = 0,
		TA_DEC = 1,
	}TA_SYMM_OP;
	typedef enum {
		TA_CMAC_DES64 = 0,
		TA_CMAC_DES128 = 1,
		TA_CMAC_DES192 = 2,
		TA_CMAC_AES128 = 3,
		TA_CMAC_AES192 = 4,
		TA_CMAC_AES256 = 5,
		TA_CMAC_SM4 = 7,
	}TA_CMAC_ALG;

	typedef enum {
		TA_DES64 = 0,
		TA_DES128 = 1,
		TA_DES192 = 2,
		TA_AES128 = 3,
		TA_AES192 = 4,
		TA_AES256 = 5,
		TA_SM1 = 6,
		TA_SM4 = 7,
		TA_SSF33 = 8,
		TA_RC4 = 9,
		TA_ZUC = 10,
		TA_SM7 = 11,
		TA_XOR_MK_EK_01 = 97,
		TA_XOR_MK_EK_02 = 98,
		TA_XOR_EK_MK = 99,
		TA_XOR = 99,
	}TA_SYMM_ALG;

	typedef enum {
		TA_ASYM_USAGE_SIGN = 1,
		TA_ASYM_USAGE_ENC = 2,
		TA_ASYM_USAGE_BOTH = 3,
	}TA_ASYM_USAGE;

	typedef enum {
		TA_SM9_STREAM = 1,
		TA_SM9_ECB = 2,
		TA_SM9_CBC = 3,
		TA_SM9_CFB = 4,
		TA_SM9_OFB = 5,
	}TA_SM9_ENC_MODE;


	typedef enum {
		TA_REQ = 0,
		TA_RSP = 1,
	}TA_EXKEY_MODE;
	typedef enum {
		TA_SESS_KEY_GEN_NO = 0x00,
		TA_SESS_KEY_GEN_00 = 0x00,
		TA_SESS_KEY_GEN_01 = 0x01,
		TA_SESS_KEY_GEN_02 = 0x02,
		TA_SESS_KEY_GEN_03 = 0x03,
		TA_SESS_KEY_GEN_04 = 0x04,
		TA_SESS_KEY_GEN_05 = 0x05,
	}TA_SESS_KEY_GEN_MODE;

	typedef enum {
		TA_ECB = 0,
		TA_CBC = 1,
		TA_CFB = 2,
		TA_OFB = 3,
		TA_STREAM = 4,//仅适用于RC4算法
		TA_EEA3 = 5,//仅适用于ZUC算法
		TA_GCM = 6,
		TA_CTR = 8,
		TA_XTS = 9,
	}TA_SYMM_MODE;

	typedef enum {
		TA_ISO9797_1_CBC = 1,
		TA_ISO9797_3_LRL = 2,//仅适用于DES128或DES192
		TA_EIA3 = 2,//仅适用于ZUC算法
	}TA_SYMM_MAC_MODE;

	typedef enum {
		TA_SIGN = 0,
		TA_CIPHER = 1,
		TA_EXKEY = 1,
	}TA_ASYMM_USAGE;

	typedef enum {
		TA_SYMM = 0,
		TA_RSA = 1,
		TA_ECC = 2,
	}TA_KEY_TYPE;


	typedef enum {
		TA_SM2 = 0X0007,
		TA_NID_BRAINPOOLP192R1 = 0x039B,
		TA_NID_BRAINPOOLP192T1 = 0x039C,
		TA_NID_BRAINPOOLP224R1 = 0x039D,
		TA_NID_BRAINPOOLP224T1 = 0x039E,
		TA_NID_BRAINPOOLP256R1 = 0x03A0,
		TA_NID_BRAINPOOLP256T1 = 0x039F,
		TA_NID_BRAINPOOLP320R1 = 0x03A1,
		TA_NID_BRAINPOOLP320T1 = 0x03A2,
		TA_NID_BRAINPOOLP384R1 = 0x03A3,
		TA_NID_BRAINPOOLP384T1 = 0x03A4,
		TA_NID_BRAINPOOLP512R1 = 0x03A5,
		TA_NID_BRAINPOOLP512T1 = 0x03A6,
		TA_NID_X9_62_PRIME192V1 = 0x0199,
		TA_NID_X9_62_PRIME192V2 = 0x019A,
		TA_NID_X9_62_PRIME192V3 = 0x019B,
		TA_NID_X9_62_PRIME256V1 = 0x019F,
		TA_NID_SECP192K1 = 0x02C7,
		TA_NID_SECP256K1 = 0x02CA,
		TA_NID_SECP224R1 = 0x02C9,
		TA_NID_SECP384R1 = 0x02CB,
		TA_NID_SECP521R1 = 0x02CC,
		TA_NID_SECT233K1 = 0x02D6,
		TA_NID_SECT283K1 = 0x02D9,
		TA_NID_SECT409K1 = 0x02DB,
		TA_NID_SECT571K1 = 0x02DD,
		TA_NID_SECT233R1 = 0x02D7,
		TA_NID_SECT283R1 = 0x02DA,
		TA_NID_SECT409R1 = 0x02DC,
		TA_NID_SECT571R1 = 0x02DE,
		TA_NID_X25519 = 0x040A,
		TA_NID_X448 = 0x040B,
		TA_NID_ED25519 = 0x043F,
		TA_NID_ED448 = 0x0440,

		TA_NID_FRP256V1 = 0X03A8,

		TA_NID_SECP256R1 = TA_NID_X9_62_PRIME256V1,

		TA_NID_NISTP224 = TA_NID_SECP224R1,
		TA_NID_NISTP256 = TA_NID_X9_62_PRIME256V1,
		TA_NID_NISTP384 = TA_NID_SECP384R1,
		TA_NID_NISTP521 = TA_NID_SECP521R1,
		TA_NID_NISTK233 = TA_NID_SECT233K1,
		TA_NID_NISTK283 = TA_NID_SECT283K1,
		TA_NID_NISTK409 = TA_NID_SECT409K1,
		TA_NID_NISTK571 = TA_NID_SECT571K1,
		TA_NID_NISTB233 = TA_NID_SECT233R1,
		TA_NID_NISTB283 = TA_NID_SECT283R1,
		TA_NID_NISTB409 = TA_NID_SECT409R1,
		TA_NID_NISTB571 = TA_NID_SECT571R1,

		TA_NID_NISTP192V1 = TA_NID_X9_62_PRIME192V1,
		TA_NID_NISTP192V2 = TA_NID_X9_62_PRIME192V2,
		TA_NID_NISTP192V3 = TA_NID_X9_62_PRIME192V3,
	}TA_ECC_CURVE;  //是否支持需根据密码机服务版本而定

	typedef enum {
		TA_3 = 3,
		TA_65537 = 65537,
	}TA_RSA_E;

	typedef enum {
		TA_DER = 0,
		TA_PEM = 1
	}
	TA_CERT_TYPE;
	typedef enum {
		TA_NOPAD = 0,
		TA_PKCS1_5 = 1,
		TA_OAEP = 2,
		TA_PSS = 4,
	}TA_RSA_PAD;

	typedef enum {
		TA_SHA1 = 1,
		TA_NOHASH = 4,
		TA_SHA224 = 5,
		TA_SHA256 = 6,
		TA_SHA384 = 7,
		TA_SHA512 = 8,
		TA_SM3 = 20,
		TA_SHA3_224 = 35,
		TA_SHA3_256 = 36,
		TA_SHA3_384 = 37,
		TA_SHA3_512 = 38,
	}TA_HASH_ALG;

	typedef enum {
		TA_NOFORCE_PAD_80 = 0,	//非强制补 80
		TA_FORCE_PAD_80 = 1,	//强制补 80
		TA_NOFORCE_PAD_00 = 2,	//非强制补 00
		TA_PAD_PKCS1_5 = 3,		//PKCS 1.5,仅 RSA 可用
		TA_PAD_PKCS_7 = 4,		//PKCS#7
		TA_NO_PAD = 5,			//不填充(外部填充)
		TA_PAD_OAEP = 6,		//OAEP,仅 RSA 可用
	}TA_PAD;

	typedef enum {	//0、1、2、12、20、21、22 || 0、2、12 || 0、1、2、12
		TA_SYMM_KEY = 0,
		TA_RSA_KEY_P8 = 1,
		TA_ECC_KEY_P8 = 2,
		TA_ECC_SPECIAL_KEY = 12,//32B*0x00||NB私钥
		TA_SYMM_GET_MAC_KEY = 20,
		TA_RSA_GET_MAC_KEY = 21,
		TA_ECC_GET_MAC_KEY = 22,
		TA_RSA_KEY_P1 = 31,
	}TA_COVERT_KEY_TYPE, TA_EXPORTED_KEY_FMT, TA_IMPORTED_KEY_FMT;

	typedef enum {
		TA_ISO_18033_2_KDF1 = 0,
		TA_ISO_18033_2_KDF2 = 1,
		TA_X9_63KDF = 2,
	}TA_KDF;

	typedef enum {
		TA_HMAC_SHA224 = 5,
		TA_HMAC_SHA256 = 6,
		TA_HMAC_SHA384 = 7,
		TA_HMAC_SHA512 = 8,
		TA_HMAC_SM3 = 20,
		TA_HMAC_SHA3_224 = 35,
		TA_HMAC_SHA3_256 = 36,
		TA_HMAC_SHA3_384 = 37,
		TA_HMAC_SHA3_512 = 38,
	}TA_HMAC_ALG;

	typedef enum {
		TA_FALSE = 0,
		TA_TRUE = !TA_FALSE,
	}TA_BOOL;

	typedef enum {
		TA_NO_AGREE = 0,
		TA_AGREE_SHA1 = 1,
		TA_AGREE_SHA224 = 2,
		TA_AGREE_SHA256 = 3,
		TA_AGREE_SHA384 = 4,
		TA_AGREE_SHA512 = 5,
		TA_AGREE_SM3 = 20,
		TA_AGREE_SHA3_224 = 35,
		TA_AGREE_SHA3_256 = 36,
		TA_AGREE_SHA3_384 = 37,
		TA_AGREE_SHA3_512 = 38,

		TA_ECDH_NO_HASH = TA_NO_AGREE,
		TA_ECDH_SHA1 = TA_AGREE_SHA1,
		TA_ECDH_SHA224 = TA_AGREE_SHA224,
		TA_ECDH_SHA256 = TA_AGREE_SHA256,
		TA_ECDH_SHA384 = TA_AGREE_SHA384,
		TA_ECDH_SHA512 = TA_AGREE_SHA512,
		TA_ECDH_SHA3_224 = TA_AGREE_SHA3_224,
		TA_ECDH_SHA3_256 = TA_AGREE_SHA3_256,
		TA_ECDH_SHA3_384 = TA_AGREE_SHA3_384,
		TA_ECDH_SHA3_512 = TA_AGREE_SHA3_512,
		TA_HMAC_HASH_SHA1 = TA_AGREE_SHA1,
		TA_HMAC_HASH_SHA224 = TA_AGREE_SHA224,
		TA_HMAC_HASH_SHA256 = TA_AGREE_SHA256,
		TA_HMAC_HASH_SHA384 = TA_AGREE_SHA384,
		TA_HMAC_HASH_SHA512 = TA_AGREE_SHA512,
		TA_HMAC_HASH_SHA3_224 = TA_AGREE_SHA3_224,
		TA_HMAC_HASH_SHA3_256 = TA_AGREE_SHA3_256,
		TA_HMAC_HASH_SHA3_384 = TA_AGREE_SHA3_384,
		TA_HMAC_HASH_SHA3_512 = TA_AGREE_SHA3_512,
	}TA_AGREE_ALG, TA_ECDH_ALG, TA_HMAC_HASH_ALG;

	typedef enum {
		PBKDF_HMAC_SHA1 = 1,
		PBKDF_HMAC_SHA224 = 2,
		PBKDF_HMAC_SHA256 = 3,
		PBKDF_HMAC_SHA384 = 4,
		PBKDF_HMAC_SHA512 = 5,
	}TA_PBKDF_HMAC_TYPE;

	typedef enum {
		TA_DB_FIRST = 1,
		TA_DB_MID = 2,
		TA_DB_LAST = 3,
	}TA_DATA_BLOCK_TYPE;


	typedef enum {
		TA_SM9_DES128 = 'X',
		TA_SM9_DES128_VAR = 'U',
		TA_SM9_DES192 = 'Y',
		TA_SM9_DES192_VAR = 'T',
		TA_SM9_SM1 = 'P',
		TA_SM9_SM4 = 'R',
		TA_SM9_AES128 = 'L',
		TA_SM9_AES192 = 'M',
		TA_SM9_AES256 = 'N',
		TA_SM9_DES64 = 'Z',
	}TA_SM9_SYMM_ALG;
	typedef struct {
		unsigned char* name;//in: 要加密的name/要解密的密文
							//out: 输出的密文缓冲区/输出的明文name缓冲区
		unsigned int nameLen;//in: name长度/name缓冲区大小
							//out: name长度
		unsigned char* phone;
		unsigned int phoneLen;
		unsigned char* id;
		unsigned int idLen;
	}UserInfo;

	typedef struct {
		unsigned char* data;
		unsigned int dataLen;
	}TassData;

	typedef struct {
		char* ip;
		unsigned short port;
		TA_BOOL alive;
	}TassHostInfos;


	typedef struct {
		unsigned int hostCnt;
		struct HostMessage {
			int code;
			char* ip;
		}*hostMessage;
	}TassCommAllMessage;
	/*
	* 接口通用规则
	* 1、当接口同时输出数据（记为buf）和数据长度（记为pBufLen）时
	*    a) 若buf和pBufLen均为NULL，则该数据不输出
	*    b) 若buf为NULL但pBufLen不为NULL，则为*pBufLen赋值，表明实际所需空间，接口返回成功
	*    c) 若buf和pBufLen均不为NULL，则*pBufLen的表示buf的实际大小，若*pBufLen不足则赋值为实际需要的大小，接口返回空间不足（TASSR_BUFFTOOSMALL）
	*/

	typedef struct {
		struct {
			unsigned int index;
			const char* ip;
			unsigned short port;
			unsigned int protocol;
			const char* pfxPath;
		}host;
		unsigned char pwdSm2Pk[64];
	}TassTLSHostInfo;


	/**
	* @brief	证书密码回调
	* @param	hostInfo			[IN]	待返回的主机信息 包含随机生成的sm2公钥
	* @param	pwd					[IN]	证书密码明文（与密文选其一）
	* @param	pwdSm2Cipher		[IN]	证书密码经返回的sm2公钥加密后的密文
	* @param	pwdSm2CipherLen		[IN]	证书密码经返回的sm2公钥加密后的密文长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note		
	*/
	typedef int (*Tass_CbTlsPassword)(
		TassTLSHostInfo* hostInfo,
		char pwd[128 + 1],
		unsigned char pwdSm2Cipher[32 + 32 + 32 + 128],
		unsigned int* pwdSm2CipherLen);


	/**
	* @brief	启用证书密码回调函数
	* @param	cbTlsPwd		[IN]	证书密码回调
	*
	* @note		需在初始化前调用
	*		
	*/
	void Tass_SetCbTlsPassword(Tass_CbTlsPassword cbTlsPwd);

	/**
	* @brief 打开密码设备，可通过不同的配置文件打开多个设备
	* @param	pcCfg			[IN]	配置文件路径或地址
	* @param	phDeviceHandle	[OUT]	返回设备句柄
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note	phDeviceHandle由函数初始化并填写内容
	*		返回句柄须调用SDF_CloseDevice关闭
	*/
	int Tass_GHVSM_Initialize(const char* pcCfg, void** phDeviceHandle);

	int Tass_GHVSM_Finalize(void* hDeviceHandle);

	/**
	* @brief	获取主机数量
	*
	* @param	hDeviceHandle		[in]	已打开的设备句柄
	* @param	cnt					[out]	主机数量
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_GetHostCnt(void* hDeviceHandle, unsigned int* cnt);

	/**
	* @brief	获取主机信息
	*
	* @param	hDeviceHandle		[in]	设备句柄
	* @param	hostNum				[in]	主机序号
	*										1~n: n为Tass_GetHostCnt返回的cnt值
	* @param	pHostInfo			[out]	主机信息
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_GetHostInfo(void* hDeviceHandle, unsigned int hostNum, TassHostInfos* pHostInfo);

	/**
	* @brief	打开会话
	*			可选接口，用于与指定设备通讯或提高性能
	*
	* @param	hDeviceHandle		[in]	设备句柄
	* @param	hostNum				[in]	主机序号
	*										0: 默认，不指定序号，接口内部自动分配
	*										1~n: n为Tass_GetHostCnt返回的cnt值
	* @param	phSessionHandle		[out]	打开的会话句柄
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_OpenSession(void* hDeviceHandle, unsigned int hostNum, void** phSessionHandle);

	int Tass_CloseSession(void* hSessionHandle);

	/**
	* @brief	设置配置文件路径，用于设置SDF_OpenDevice时的配置文件路径
	* @param	cfgPath			[IN]		配置文件路径，不包含配置文件名字
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note cfgPath只传路径，不用传配置文件的名字
	*/
	int Tass_SetCfgPath(const char* cfgPath);

	/***************************************************************************
	* 设备管理
	* 	Tass_GetDeviceInfo
	*	Tass_GetDevVersionInfo
	****************************************************************************/

	/**
	* @brief	获取加密机设备信息
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	issuerName				[OUT]		设备生产厂商名称
	* @param	issuerNameLen			[IN|OUT]	输入时：issuerName大小；输出时：issuerName长度
	* @param	deviceName				[OUT]		设备型号
	* @param	deviceNameLen			[IN|OUT]	输入时：deviceName大小；输出时：deviceName长度
	* @param	deviceSerial			[OUT]		设备编号，包含日期（8字符）、批次号（3字符）、流水号（5字符）
	* @param	deviceSerialLen			[IN|OUT]	输入时：deviceSerial大小；输出时：deviceSerial长度
	* @param	deviceVersion			[OUT]		密码设备内部软件版本号
	* @param	standardVersion			[OUT]		密码设备支持的接口规范版本号
	* @param	asymAlgAbility			[OUT]		非对称算法能力，前4字节表示支持的算法，非对称算法标识按位异或，后4字节表示算法的最大模长，表示方法为支持模长按位异或的结果
	* @param	symAlgAbility			[OUT]		对称算法能力，对称算法标识按位异或
	* @param	bufferSize				[OUT]		支持的最大文件存储空间（单位字节）
	* @param	dmkcv					[OUT]		DMK校验值
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetDeviceInfo(void* hSessionHandle,
		unsigned char* issuerName, unsigned int* issuerNameLen,
		unsigned char* deviceName, unsigned int* deviceNameLen,
		unsigned char* deviceSerial, unsigned int* deviceSerialLen,
		unsigned char deviceVersion[4],
		unsigned char standardVersion[4],
		unsigned char asymAlgAbility[8],
		unsigned char symAlgAbility[4],
		unsigned char fileStoreSize[4],
		unsigned char dmkcv[8]);

	/**
	* @brief	获取设备版本信息
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	dmkcv				[OUT]		DMK的校验值,当为兼容模式时长度为16，当为FIPS/国密模式时长度为32
	* @param	hostVersion			[OUT]		主机服务版本号
	* @param	manageVersion		[OUT]		管理服务版本信息
	* @param	cryptoModuleVersion	[OUT]		应用密码模块版本
	* @param	devSn				[OUT]		设备序列号
	* @param	devSnLen			[OUT]		设备序列号长度
	* @param	runMode				[OUT]		运行模式, 1-FIPS模式，2-国密模式，0/3-兼容模式
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetDevVersionInfo(void* hSessionHandle,
		unsigned char* dmkcv,
		unsigned char* hostVersion,
		unsigned char* manageVersion,
		unsigned char* cryptoModuleVersion,
		unsigned char* devSn,
		unsigned int* devSnLen,
		unsigned int* runMode);

	/**
	* @brief	获取密码机运行状态
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	devSelfCheckStatus		[OUT]		设备自检状态
	* @param	maxConn					[OUT]		支持的最大连接数
	* @param	useConn					[OUT]		当前已被占用的连接数
	* @param	cpuUtility				[OUT]		CPU 利用率
	* @param	memoryUsage				[OUT]		内存使用率
	* @param	amount					[OUT]		开机后总笔数
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetDevOperationStatus(void* hSessionHandle,
		unsigned char* devSelfCheckStatus,
		unsigned char* maxConn,
		unsigned char* useConn,
		unsigned char* cpuUtility,
		unsigned char* memoryUsage,
		unsigned char* amount);

	/**
* @brief	获取密码机状态
* @param	hSessionHandle			[IN]		与设备建立的会话句柄
* @param	cpuUtility				[OUT]		CPU 利用率
* @param	memoryUsage				[OUT]		内存使用率
* @param	hsmVersion				[OUT]		hsm 版本号
* @param	devConn					[OUT]		密码机服务当前连接数
* @param	hsmSeries				[OUT]		hsm 序列号
* @param	hsmSeriesLen			[OUT]		序列号长度
* @param	dmkcv					[OUT]		dmk校验值
* 
* @return
*   @retval	0		成功
*   @retval	非0		失败，返回错误代码
*/
	int Tass_GetDevStatus(void* hSessionHandle,
		unsigned char* cpuUtility,
		unsigned char* memoryUsage,
		unsigned char* hsmVersion,
		unsigned int* devConn,
		unsigned char* hsmSeries,
		unsigned int* hsmSeriesLen,
		unsigned char* dmkcv);



	/***************************************************************************
	* 随机数
	* 	Tass_GenerateRandom
	****************************************************************************/

	/**
	* @brief	产生随机数
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	randomLen		[IN]		随机数长度
	* @param	random			[OUT]		随机数
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateRandom(void* hSessionHandle,
		unsigned int randomLen,
		unsigned char* random);

	/***************************************************************************
	* 密钥管理
	* 	生成
	*	导入&导出
	*	索引&标签管理
	*	派生
	****************************************************************************/

	/***************************************************************************
	* 密钥管理-生成
	* 	Tass_GeneratePlainRSAKeyPair
	*	Tass_GeneratePlainECCKeyPair
	*	Tass_GenerateAsymmKeyWithLMK
	*	Tass_GenerateSymmKeyWithLMK
	*	Tass_GenerateSymmKeyWithRSA
	*	Tass_GenerateSymmKeyWithECC
	*	Tass_GenerateSymmKeyWithInternalKEK
	****************************************************************************/
	/**
	* @brief	生成明文RSA密钥对
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	bits			[IN]		密钥位长度1024-4096
	* @param	e				[IN]		密钥指数
	* @param	pubKeyN			[OUT]		公钥N
	* @param	pubKeyNLen		[IN|OUT]	输入时：pubKeyN大小；输出时：pubKeyN长度
	* @param	pubKeyE			[OUT]		公钥E
	* @param	pubKeyELen		[IN|OUT]	输入时：pubKeyE大小；输出时：pubKeyE长度
	* @param	priKeyD			[OUT]		私钥D
	* @param	priKeyDLen		[IN|OUT]	输入时：priKeyD大小；输出时：priKeyD长度
	* @param	priKeyP			[OUT]		私钥P
	* @param	priKeyPLen		[IN|OUT]	输入时：priKeyP大小；输出时：priKeyP长度
	* @param	priKeyQ			[OUT]		私钥Q
	* @param	priKeyQLen		[IN|OUT]	输入时：priKeyQ大小；输出时：priKeyQ长度
	* @param	priKeyDp		[OUT]		私钥DP
	* @param	priKeyDpLen		[IN|OUT]	输入时：priKeyDp大小；输出时：priKeyDp长度
	* @param	priKeyDq		[OUT]		私钥DQ
	* @param	priKeyDqLen		[IN|OUT]	输入时：priKeyDq大小；输出时：priKeyDq长度
	* @param	priKeyQinv		[OUT]		私钥QINV
	* @param	priKeyQinvLen	[IN|OUT]	输入时：priKeyQinv大小；输出时：priKeyQinv长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GeneratePlainRSAKeyPair(void* hSessionHandle,
		unsigned int bits,
		TA_RSA_E e,
		unsigned char* pubKeyN, unsigned int* pubKeyNLen,
		unsigned char* pubKeyE, unsigned int* pubKeyELen,
		unsigned char* priKeyD, unsigned int* priKeyDLen,
		unsigned char* priKeyP, unsigned int* priKeyPLen,
		unsigned char* priKeyQ, unsigned int* priKeyQLen,
		unsigned char* priKeyDp, unsigned int* priKeyDpLen,
		unsigned char* priKeyDq, unsigned int* priKeyDqLen,
		unsigned char* priKeyQinv, unsigned int* priKeyQinvLen);

	/**
	* @brief	生成ECC明文密钥对
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		ECC曲线
	* @param	pubKeyX			[OUT]		公钥X
	* @param	pubKeyXLen		[IN|OUT]	输入时：pubKeyX大小；输出时：pubKeyX长度
	* @param	pubKeyY			[OUT]		公钥E
	* @param	pubKeyYLen		[IN|OUT]	输入时：pubKeyY大小；输出时：pubKeyY长度
	* @param	priKeyD			[OUT]		私钥D
	* @param	priKeyDLen		[IN|OUT]	输入时：priKeyD大小；输出时：priKeyD长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GeneratePlainECCKeyPair(void* hSessionHandle,
		TA_ECC_CURVE curve,
		unsigned char* pubKeyX, unsigned int* pubKeyXLen,
		unsigned char* pubKeyY, unsigned int* pubKeyYLen,
		unsigned char* priKeyD, unsigned int* priKeyDLen);

	/**
	* @brief	产生LMK加密的随机非对称密钥
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	type					[IN]		密钥类型，目前支持TA_RSA/TA_ECC
	* @param	rsaBits					[IN]		RSA密钥模长，仅type=TA_RSA时有效
	* @param	rsaE					[IN]		RSA密钥指数，仅type=TA_RSA时有效
	* @param	eccCurve				[IN]		ECC曲线标识，仅type=TA_ECC时有效
	*												目前支持TA_NID_NISTP256/TA_NID_BRAINPOOLP256R1/TA_NID_FRP256V1/TA_NID_SECP256K1
	* @param	pubKeyN_X				[OUT]		公钥N(type=TA_RSA时)或X(type=TA_ECC时)
	* @param	pubKeyN_XLen			[IN|OUT]	输入时：pubKeyN_X大小，输出时：pubKeyN_X长度
	* @param	pubKeyE_Y				[OUT]		公钥E(type=TA_RSA时)或Y(type=TA_ECC时)
	* @param	pubKeyE_YLen			[IN|OUT]	输入时：pubKeyE_Y大小，输出时：pubKeyE_Y长度
	* @param	priKeyCipherByLmk		[OUT]		LMK加密的私钥密文
	* @param	priKeyCipherByLmkLen	[IN|OUT]	输入时：priKeyCipherByLmk大小，输出时：priKeyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateAsymmKeyWithLMK(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int rsaBits, TA_RSA_E rsaE,
		TA_ECC_CURVE eccCurve,
		unsigned char* pubKeyN_X, unsigned int* pubKeyN_XLen,
		unsigned char* pubKeyE_Y, unsigned int* pubKeyE_YLen,
		unsigned char* priKeyCipherByLmk, unsigned int* priKeyCipherByLmkLen);

	/**
	* @brief	产生LMK加密的随机密钥
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	alg					[IN]		算法标识，目前仅支持TA_DES128/TA_AES128/TA_SM1/TA_SM4/TA_SSF33
	* @param	keyCipherByLmk		[OUT]		LMK加密的密钥密文
	* @param	keyCipherByLmkLen	[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @param	kcv					[OUT]		密钥校验值
	* @param	kcvLen				[IN|OUT]	输入时：kcv大小，输出时：kcv长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateSymmKeyWithLMK(void* hSessionHandle,
		TA_SYMM_ALG alg,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen,
		unsigned char* kcv, unsigned int* kcvLen);

	/**
	* @brief	生成随机对称密钥并使用内/外部RSA公钥加密
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	pubKeyN					[IN]		公钥N，index为0时有效
	* @param	pubKeyNLen				[IN]		pubKeyN长度，index为0时有效
	* @param	pubKeyE					[IN]		公钥E，index为0时有效
	* @param	pubKeyELen				[IN]		pubKeyE长度，index为0时有效
	* @param	symmBytes				[IN]		要生成的随机对称密钥字节长度，目前支持16/24/32
	* @param	keyCipherByPubKey		[OUT]		RSA公钥加密的随机对称密钥密文
	* @param	keyCipherByPubKeyLen	[IN|OUT]	输入时：keyCipherByPubKey大小，输出时：keyCipherByPubKey长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateSymmKeyWithRSA(void* hSessionHandle,
		unsigned int index,
		const unsigned char* pubKeyN, unsigned int pubKeyNLen,
		const unsigned char* pubKeyE, unsigned int pubKeyELen,
		unsigned int symmBytes,
		unsigned char* keyCipherByPubKey, unsigned int* keyCipherByPubKeyLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	生成随机对称密钥并使用内/外部ECC公钥加密
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	curve					[IN]		曲线标识，目前只支持TA_SM2，index为0时有效
	* @param	pubKeyX					[IN]		公钥X，index为0时有效
	* @param	pubKeyXLen				[IN]		pubKeyX长度，index为0时有效
	* @param	pubKeyY					[IN]		公钥Y，index为0时有效
	* @param	pubKeyYLen				[IN]		pubKeyY长度，index为0时有效
	* @param	symmBytes				[IN]		要生成的随机对称密钥字节长度，目前支持16/24/32
	* @param	keyCipherByPubKey		[OUT]		ECC公钥加密的随机对称密钥密文
	* @param	keyCipherByPubKeyLen	[IN|OUT]	输入时：keyCipherByPubKey大小，输出时：keyCipherByPubKey长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateSymmKeyWithECC(void* hSessionHandle,
		unsigned int index,
		TA_ECC_CURVE curve,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		unsigned int symmBytes,
		unsigned char* keyCipherByPubKey, unsigned int* keyCipherByPubKeyLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	生成随机对称密钥并使用内部KEK加密
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	symmBytes				[IN]		要生成的随机对称密钥字节长度，目前支持16/24/32
	* @param	keyCipherByKek			[OUT]		KEK加密的随机对称密钥密文
	* @param	keyCipherByKekLen		[IN|OUT]	输入时：keyCipherByKek大小，输出时：keyCipherByKek长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateSymmKeyWithInternalKEK(void* hSessionHandle,
		unsigned int index,
		unsigned int symmBytes,
		unsigned char* keyCipherByKek, unsigned int* keyCipherByKekLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/***************************************************************************
	* 密钥管理-导入&导出
	*	Tass_ImportSymmKeyCipherByInternalRSA
	*	Tass_ImportSymmKeyCipherByInternalECC
	*	Tass_ImportSymmKeyCipherByInternalKEK
	*	Tass_ConvertSymmKeyCipherByLMKToKEK
	*	Tass_ConvertSymmKeyCipherByKEKToLMK
	*	Tass_GetInternalKeyCipherByLMK
	*	Tass_ImportKeyCipherByLMK
	*	Tass_GetInternalRSAPublicKey
	*	Tass_GetInternalECCPublicKey
	*	Tass_ExportSymmKeyBySymmKey
	*	Tass_ImportSymmKeyBySymmKey
	*	Tass_ExportKey
	*	Tass_ImportKey
	*	Tass_GetPublicKeyByPrivateKey
	*	Tass_ImportSymmConvertKey（建议弃用，不再升级）
	*	Tass_ExportCovertKeyBySymmKey（建议弃用，不再升级）
	*	Tass_ImportCovertKeyBySymmKey（建议弃用，不再升级）
	*	Tass_ExportCovertKeyByAsymmKey（建议弃用，不再升级）
	*	Tass_ImportCovertKeyByAsymmKey（建议弃用，不再升级）
	*	Tass_KeyEncryptByLMKToOhter（建议弃用，不再升级）
	*	Tass_KeyEncryptByOhterToLMK（建议弃用，不再升级）

	****************************************************************************/

	/**
	* @brief	导入内部RSA公钥加密的对称密钥
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		RSA密钥索引
	* @param	keyCipherByPubKey		[IN]		RSA公钥加密的随机对称密钥密文
	* @param	keyCipherByPubKeyLen	[IN]		keyCipherByPubKey长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小；输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_ImportSymmKeyCipherByInternalRSA(void* hSessionHandle,
		unsigned int index,
		const unsigned char* keyCipherByPubKey, unsigned int keyCipherByPubKeyLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);
	/**
	* @brief	导入内部ECC公钥加密的对称密钥
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		ECC密钥索引，目前只支持SM2密钥
	* @param	keyCipherByPubKey		[IN]		ECC公钥加密的随机对称密钥密文
	* @param	keyCipherByPubKeyLen	[IN]		keyCipherByPubKey长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_ImportSymmKeyCipherByInternalECC(void* hSessionHandle,
		unsigned int index,
		const unsigned char* keyCipherByPubKey, unsigned int keyCipherByPubKeyLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	导入内部KEK加密的对称密钥
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		密钥索引
	* @param	keyCipherByKek			[IN]		KEK加密的随机对称密钥密文
	* @param	keyCipherByKekLen		[IN]		keyCipherByKek长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_ImportSymmKeyCipherByInternalKEK(void* hSessionHandle,
		unsigned int index,
		const unsigned char* keyCipherByKek, unsigned int keyCipherByKekLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	LMK加密的对称密钥转KEK加密
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	keyCipherByLmk		[IN]		LMK加密的密钥密文
	* @param	keyCipherByLmkLen	[IN]		keyCipherByLmk大小
	* @param	kekIdx				[IN]		KEK密钥索引
	* @param	kekCipherByLmk		[IN]		LMK加密的密钥KEK密文，kekIdx为0时有效
	* @param	kekCipherByLmkLen	[IN]		kekCipherByLmk大小，kekIdx为0时有效
	* @param	alg					[IN]		KEK算法标识，目前仅支持TA_DES128/TA_AES128/TA_SM1/TA_SM4/TA_SSF33
	* @param	mode				[IN]		KEK加密模式，目前仅支持ECB
	* @param	keyCipherByKek		[OUT]		KEK加密的密钥密文
	* @param	keyCipherByKekLen	[IN|OUT]	输入时：keyCipherByKek大小，输出时：keyCipherByKek长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ConvertSymmKeyCipherByLMKToKEK(void* hSessionHandle,
		const unsigned char* keyCipherByLmk, unsigned int keyCipherByLmkLen,
		unsigned int kekIdx,
		const unsigned char* kekCipherByLmk, unsigned int kekCipherByLmkLen,
		TA_SYMM_ALG alg,
		TA_SYMM_MODE mode,
		unsigned char* keyCipherByKek, unsigned int* keyCipherByKekLen);

	/**
	* @brief	将KEK加密的对称密钥转LMK加密
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	keyCipherByKek		[IN]		KEK加密的密钥密文
	* @param	keyCipherByKekLen	[IN]		keyCipherByKek大小
	* @param	kekIdx				[IN]		KEK密钥索引
	* @param	kekCipherByLmk		[IN]		LMK加密的密钥KEK密文，kekIdx为0时有效
	* @param	kekCipherByLmkLen	[IN]		kekCipherByLmk大小，kekIdx为0时有效
	* @param	alg					[IN]		KEK算法标识，目前仅支持TA_DES128/TA_AES128/TA_SM1/TA_SM4/TA_SSF33
	* @param	mode				[IN]		KEK加密模式，目前仅支持ECB
	* @param	keyCipherByLmk		[OUT]		LMK加密的密钥密文
	* @param	keyCipherByLmkLen	[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ConvertSymmKeyCipherByKEKToLMK(void* hSessionHandle,
		const unsigned char* keyCipherByKek, unsigned int keyCipherByKekLen,
		unsigned int kekIdx,
		const unsigned char* kekCipherByLmk, unsigned int kekCipherByLmkLen,
		TA_SYMM_ALG alg,
		TA_SYMM_MODE mode,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	获取内部密钥LMK加密的密钥密文
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	index						[IN]		密钥索引
	* @param	type						[IN]		密钥类型
	* @param	usage						[IN]		非对称密钥用途，type不是TA_SYMM时有效
	* @param	pubKeyN_X					[OUT]		公钥N（type为TA_RSA）或X（type为TA_ECC），type不是TA_SYMM时有效
	* @param	pubKeyN_XLen				[IN|OUT]	输入时：pubKeyN_X大小，输出时：pubKeyN_X长度
	* @param	pubKeyE_Y					[OUT]		公钥E（type为TA_RSA）或Y（type为TA_ECC），type不是TA_SYMM时有效
	* @param	pubKeyE_YLen				[IN|OUT]	输入时：pubKeyE_Y大小，输出时：pubKeyE_Y长度
	* @param	pri_symmKeyCipherByLmk		[OUT]		私钥（type为TA_RSA/TA_ECC）或对称密钥密文（type为TA_SYMM）
	* @param	pri_symmKeyCipherByLmkLen	[IN|OUT]	输入时：pri_symmKeyCipherByLmk大小，输出时：pri_symmKeyCipherByLmk长度
	* @param	symmKcv						[OUT]		对称密钥校验值，type为TA_SYMM时有效，为NULL时不输出
	* @param	alg							[OUT]		对称密钥算法，type为TA_SYMM时有效，为NULL时不输出
	* @param	curve						[OUT]		ECC曲线标识，type为TA_ECC时有效，为NULL时不输出
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 若获非对称密钥密文，需先获取私钥权限
	*/
	int Tass_GetInternalKeyCipherByLMK(void* hSessionHandle,
		unsigned int index,
		TA_KEY_TYPE type,
		TA_ASYMM_USAGE usage,
		unsigned char* pubKeyN_X, unsigned int* pubKeyN_XLen,
		unsigned char* pubKeyE_Y, unsigned int* pubKeyE_YLen,
		unsigned char* pri_symmKeyCipherByLmk, unsigned int* pri_symmKeyCipherByLmkLen,
		unsigned char symmKcv[8],
		TA_SYMM_ALG* alg,
		TA_ECC_CURVE* curve);

	/**
	* @brief	导入LMK加密的密钥
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	index						[IN]		要导入的索引
	* @param	type						[IN]		密钥类型
	* @param	curve						[IN]		ECC曲线，type为TA_ECC时有效
	* @param	alg							[IN]		对称密钥算法，type为TA_SYMM时有效
	* @param	usage						[IN]		非对称密钥用途，type不为TA_SYMM时有效
	* @param	pubKeyN_X					[IN]		公钥N（RSA)或X（ECC)，type不为TA_SYMM时有效
	* @param	pubKeyN_XLen				[IN]		pubKeyN_XLen长度，type不为TA_SYMM时有效
	* @param	pubKeyE_Y					[IN]		公钥E（RSA)或Y（ECC)，type不为TA_SYMM时有效
	* @param	pubKeyE_YLen				[IN]		pubKeyE_YLen长度，type不为TA_SYMM时有效
	* @param	pri_symmKeyCipherByLmk		[IN]		私钥或对称密钥密文
	* @param	pri_symmKeyCipherByLmkLen	[IN]		pri_symmKeyCipherByLmkLen长度
	* @param	symmKcv						[IN]		对称密钥校验值，type为TA_SYMM时有效
	* @param	coverFlag    				[IN]		密钥存在时是否覆盖密钥，0：不覆盖，非0：覆盖
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ImportKeyCipherByLMK(void* hSessionHandle,
		unsigned int index,
		TA_KEY_TYPE type,
		TA_ECC_CURVE curve,
		TA_SYMM_ALG alg,
		TA_ASYMM_USAGE usage,
		const unsigned char* pubKeyN_X, unsigned int pubKeyN_XLen,
		const unsigned char* pubKeyE_Y, unsigned int pubKeyE_YLen,
		const unsigned char* pri_symmKeyCipherByLmk, unsigned int pri_symmKeyCipherByLmkLen,
		const unsigned char symmKcv[8],
		unsigned int coverFlag);

	/**
	* @brief	获取内部RSA公钥
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		索引
	* @param	usage			[IN]		密钥用途
	* @param	pubKeyN			[OUT]		公钥N
	* @param	pubKeyNLen		[IN|OUT]	输入时：pubKeyN大小；输出时：pubKeyN长度
	* @param	pubKeyE			[OUT]		公钥E
	* @param	pubKeyELen		[IN|OUT]	输入时：pubKeyE大小，输出时：pubKeyE长度
	* @param	label			[OUT]		标签
	* @param	labelLen		[IN|OUT]	输入时：label大小，输出时：label长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetInternalRSAPublicKey(void* hSessionHandle,
		unsigned int index,
		TA_ASYMM_USAGE usage,
		unsigned char* pubKeyN, unsigned int* pubKeyNLen,
		unsigned char* pubKeyE, unsigned int* pubKeyELen,
		unsigned char* label, unsigned int* labelLen);

	/**
	* @brief	获取内部ECC公钥
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		索引
	* @param	usage			[IN]		用途
	* @param	curve			[OUT]		为NULL时不输出
	* @param	pubKeyX			[OUT]		公钥X
	* @param	pubKeyXLen		[IN|OUT]	输入时：pubKeyX大小；输出时：pubKeyX长度
	* @param	pubKeyY			[OUT]		公钥Y
	* @param	pubKeyYLen		[IN|OUT]	输入时：pubKeyY大小，输出时：pubKeyY长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetInternalECCPublicKey(void* hSessionHandle,
		unsigned int index,
		TA_ASYMM_USAGE usage,
		TA_ECC_CURVE* curve,
		unsigned char* pubKeyX, unsigned int* pubKeyXLen,
		unsigned char* pubKeyY, unsigned int* pubKeyYLen);

	/**
	* @brief	传输密钥保护导出一条密钥
	*
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	encMode						[IN]		加密模式，仅支持ECB/CBC
	* @param	macMode						[IN]		MAC模式
	* @param	macValWay					[IN]		MAC取值方式：
	*													0x01-0x08 输出MAC值的左n字节（n取值为第2个数字）;
	*													0x11-0x18 输出MAC值的右n字节;
	*													0x21-0x28 左右异或后取左n字节输出;
	*													0x31-0x38 左右异或后取右n字节输出;
	*													0x44 四字节异或，最后输出4字节;
	*													0x10 密钥标识为P/L/R时输出完整的16字节MAC值;
	* @param	proIndex					[IN]		保护密钥索引
	* @param	proAlg						[IN]		保护密钥算法，proIndex=0时有效
	* @param	proKeyCipherByLmk			[IN]		LMK加密的保护密钥密文，proIndex=0时有效
	* @param	proKeyCipherByLmkLen		[IN]		proKeyCipherByLmk长度，proIndex=0时有效
	* @param	proDeriveFactor				[IN]		保护密钥分散因子，8字节倍数
	* @param	proDeriveFactorLen			[IN]		proDeriveFactor长度
	* @param	expIndex					[IN]		导出密钥索引
	* @param	expAlg						[IN]		导出密钥算法，expIndex=0时有效
	* @param	expKeyCipherByLmk			[IN]		LMK加密的导出密钥密文，expIndex=0时有效
	* @param	expKeyCipherByLmkLen		[IN]		expKeyCipherByLmk长度，expIndex=0时有效
	* @param	expDeriveFactor				[IN]		导出密钥分散因子，8字节倍数
	* @param	expDeriveFactorLen			[IN]		expDeriveFactor长度
	* @param	otherMacKey					[IN]		是否使用其他的密钥计算MAC
	* @param	macIndex					[IN]		MAC密钥索引，otherMacKey为TA_TRUE时有效
	* @param	macAlg						[IN]		MAC密钥算法，otherMacKey为TA_TRUE且macIndex=0时有效
	* @param	macKeyCipherByLmk			[IN]		LMK加密的导出密钥密文，otherMacKey为TA_TRUE且macIndex=0时有效
	* @param	macKeyCipherByLmkLen		[IN]		expKeyCipherByLmk长度，otherMacKey为TA_TRUE且macIndex=0时有效
	* @param	macDeriveFactor				[IN]		MAC密钥分散因子，8字节倍数，otherMacKey为TA_TRUE时有效
	* @param	macDeriveFactorLen			[IN]		macDeriveFactor长度，otherMacKey为TA_TRUE时有效
	* @param	keyHead						[IN]		密钥头
	* @param	keyHeadLen					[IN]		keyHead长度
	* @param	keyTail						[IN]		密钥尾
	* @param	keyTailLen					[IN]		keyTail长度
	* @param	cmdHead						[IN]		命令头
	* @param	cmdHeadLen					[IN]		cmdHead长度
	* @param	rand						[IN]		随机数
	* @param	randLen						[IN]		rand长度
	* @param	encIv						[IN]		加密IV
	* @param	encIvLen					[IN]		encIv长度
	* @param	macIv						[IN]		MAC IV
	* @param	macIvLen					[IN]		macIv长度
	* @param	expKeyCipherByProKey		[OUT]		保护密钥加密的导出密钥密文
	* @param	expKeyCipherByProKeyLen		[IN|OUT]	输入时：expKeyCipherByProKey大小，输出时：expKeyCipherByProKey长度
	* @param	mac							[OUT]		MAC
	* @param	macLen						[IN|OUT]	输入时：mac大小，输出时：mac长度
	* @param	kcv							[OUT]		导出密钥校验值
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ExportSymmKeyBySymmKey(void* hSessionHandle,
		TA_SYMM_MODE encMode,
		TA_SYMM_MAC_MODE macMode,
		unsigned int macValWay,
		unsigned int proIndex,
		TA_SYMM_ALG proAlg,
		unsigned char* proKeyCipherByLmk, unsigned int proKeyCipherByLmkLen,
		unsigned char* proDeriveFactor, unsigned int proDeriveFactorLen,
		unsigned int expIndex,
		TA_SYMM_ALG expAlg,
		const unsigned char* expKeyCipherByLmk, unsigned int expKeyCipherByLmkLen,
		unsigned char* expDeriveFactor, unsigned int expDeriveFactorLen,
		TA_BOOL otherMacKey,
		unsigned int macIndex,
		TA_SYMM_ALG macAlg,
		const unsigned char* macKeyCipherByLmk, unsigned int macKeyCipherByLmkLen,
		const unsigned char* macDeriveFactor, unsigned int macDeriveFactorLen,
		const unsigned char* keyHead, unsigned int keyHeadLen,
		const unsigned char* keyTail, unsigned int keyTailLen,
		const unsigned char* cmdHead, unsigned int cmdHeadLen,
		const unsigned char* rand, unsigned int randLen,
		const unsigned char* encIv, unsigned int encIvLen,
		const unsigned char* macIv, unsigned int macIvLen,
		unsigned char* expKeyCipherByProKey, unsigned int* expKeyCipherByProKeyLen,
		unsigned char* mac, unsigned int* macLen,
		unsigned char kcv[8]);

	/**
	* @brief	传输密钥保护导入一条密钥
	*
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	withMac						[IN]		是否校验MAC
	* @param	encMode						[IN]		加密模式，仅支持ECB/CBC
	* @param	macMode						[IN]		MAC模式，withMac为TA_TRUE时有效
	* @param	macValWay					[IN]		MAC取值方式，withMac为TA_TRUE时有效：
	*													0x01-0x08 输出MAC值的左n字节（n取值为第2个数字）;
	*													0x11-0x18 输出MAC值的右n字节;
	*													0x21-0x28 左右异或后取左n字节输出;
	*													0x31-0x38 左右异或后取右n字节输出;
	*													0x44 四字节异或，最后输出4字节;
	*													0x10 密钥标识为P/L/R时输出完整的16字节MAC值;
	* @param	proIndex					[IN]		保护密钥索引
	* @param	proAlg						[IN]		保护密钥算法，proIndex=0时有效
	* @param	proKeyCipherByLmk			[IN]		LMK加密的保护密钥密文，proIndex=0时有效
	* @param	proKeyCipherByLmkLen		[IN]		proKeyCipherByLmk长度，proIndex=0时有效
	* @param	proDeriveFactor				[IN]		保护密钥分散因子，8字节倍数
	* @param	proDeriveFactorLen			[IN]		proDeriveFactor长度
	* @param	impAlg						[IN]		导入密钥算法
	* @param	impIndex					[IN]		导入密钥索引
	* @param	impLabel					[IN]		导入密钥标签
	* @param	otherMacKey					[IN]		是否使用其他的密钥计算MAC
	* @param	macIndex					[IN]		MAC密钥索引，otherMacKey为TA_TRUE时有效
	* @param	macAlg						[IN]		MAC密钥算法，otherMacKey为TA_TRUE且macIndex=0时有效
	* @param	macKeyCipherByLmk			[IN]		LMK加密的导出密钥密文，otherMacKey为TA_TRUE且macIndex=0时有效
	* @param	macKeyCipherByLmkLen		[IN]		expKeyCipherByLmk长度，otherMacKey为TA_TRUE且macIndex=0时有效
	* @param	macDeriveFactor				[IN]		MAC密钥分散因子，8字节倍数，otherMacKey为TA_TRUE时有效
	* @param	macDeriveFactorLen			[IN]		macDeriveFactor长度，otherMacKey为TA_TRUE时有效
	* @param	keyHead						[IN]		密钥头
	* @param	keyHeadLen					[IN]		keyHead长度
	* @param	keyTail						[IN]		密钥尾
	* @param	keyTailLen					[IN]		keyTail长度
	* @param	cmdHead						[IN]		命令头
	* @param	cmdHeadLen					[IN]		cmdHead长度
	* @param	rand						[IN]		随机数
	* @param	randLen						[IN]		rand长度
	* @param	encIv						[IN]		加密IV
	* @param	encIvLen					[IN]		encIv长度
	* @param	macIv						[IN]		MAC IV
	* @param	macIvLen					[IN]		macIv长度
	* @param	impKeyCipherByProKey		[IN]		保护密钥加密的导入密钥密文
	* @param	impKeyCipherByProKeyLen		[IN]		impKeyCipherByProKey长度
	* @param	mac							[IN]		导入密钥MAC
	* @param	macLen						[IN]		mac长度
	* @param	impKeyCipherByLmk			[OUT]		保护密钥加密的导出密钥密文
	* @param	impKeyCipherByLmkLen		[IN|OUT]	输入时：impKeyCipherByLmk大小，输出时：impKeyCipherByLmk长度
	* @param	kcv							[OUT]		导如密钥校验值
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ImportSymmKeyBySymmKey(void* hSessionHandle,
		TA_BOOL withMac,
		TA_SYMM_MODE encMode,
		TA_SYMM_MAC_MODE macMode,
		unsigned int macValWay,
		unsigned int proIndex,
		TA_SYMM_ALG proAlg,
		unsigned char* proKeyCipherByLmk, unsigned int proKeyCipherByLmkLen,
		unsigned char* proDeriveFactor, unsigned int proDeriveFactorLen,
		TA_SYMM_ALG impAlg,
		unsigned int impIndex,
		const char* impLabel,
		TA_BOOL otherMacKey,
		unsigned int macIndex,
		TA_SYMM_ALG macAlg,
		const unsigned char* macKeyCipherByLmk, unsigned int macKeyCipherByLmkLen,
		const unsigned char* macDeriveFactor, unsigned int macDeriveFactorLen,
		const unsigned char* keyHead, unsigned int keyHeadLen,
		const unsigned char* keyTail, unsigned int keyTailLen,
		const unsigned char* cmdHead, unsigned int cmdHeadLen,
		const unsigned char* rand, unsigned int randLen,
		const unsigned char* encIv, unsigned int encIvLen,
		const unsigned char* macIv, unsigned int macIvLen,
		const unsigned char* impKeyCipherByProKey, unsigned int impKeyCipherByProKeyLen,
		const unsigned char* mac, unsigned int macLen,
		unsigned char* impKeyCipherByLmk, unsigned int* impKeyCipherByLmkLen,
		unsigned char kcv[8]);

	/**
	* @brief	内部密钥或LMK加密的密钥密文转其它密钥加密
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	proKeyType				[IN]		保护密钥类型
	* @param	proAlg					[IN]		保护密钥算法类型，当proKeyType=TA_SYMM或TA_ECC时有效
	*																当proKeyType=TA_ECC时，proAlg为外送曲线标识，目前仅支持TA_SM2
	*																当proKeyType=TA_SYMM时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4
	* @param	mode					[IN]		保护密钥加密模式，当proKeyType=TA_SYMM_KEY时有效，支持TA_ECB/TA_CBC/TA_GCM
	* @param	iv						[IN]		加密IV，当proKeyType=TA_SYMM_KEY且mode=TA_CBC时有效
	* @param	gcmIv					[IN]		mode=TA_GCM时有效
	* @param	gcmIvLen				[IN]		gcmIv长度, 取值 1-8192
	* @param	aad						[IN]		mode=TA_GCM时有效
	* @param	aadLen					[IN]		aad长度, 取值 1-8192
	* @param	proIndex				[IN]		保护密钥索引，0：代表外送保护密钥, 9999: 代表根据 proLabel 或 proId 查找密码机内密钥
	* @param	proUsage				[IN]		非对称保护密钥用途, 当proKeyType=TA_ECC或proKeyType=TA_RSA且proIndex>0时有效
	* @param	proKey					[IN]		外送保护密钥, 当proIndex=0 时有效
	* @param	proKeyLen				[IN]		proKey长度, 当proIndex=0 时有效
	* @param	proLabel				[IN]		保护密钥的标签, 当proIndex=9999 时有效
	* @param	proId					[IN]		保护密钥的ID,  当proIndex=9999 时有效
	* @param	proIdLen				[IN]		proId长度, 当proIndex=9999 时有效（长度范围：1-128）
	* @param	pad						[IN]		加密填充方式,当proKeyType!=TA_ECC时有效
	* @param	mgfHash					[IN]		MGF 杂凑算法, proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效
	*													支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	paramHash				[IN]		Param 哈希算法, proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效
	*													支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	oaepParam				[IN]		OAEP 编码参数， proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效
	* @param	oaepParamLen			[IN]		oaepParam长度, 取值范围：0-2048。proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效,
	* @param	expKeyFmt				[IN]		导出密钥格式，
	*													proKeyType=TA_SYMM时，取值TA_SYMM_KEY/TA_RSA_KEY_P8/TA_ECC_KEY_P8/TA_ECC_SPECIAL_KEY/TA_SYMM_GET_MAC_KEY/TA_RSA_GET_MAC_KEY/TA_ECC_GET_MAC_KEY/TA_RSA_KEY_P1
	*													proKeyType=TA_RSA时，取值TA_SYMM_KEY/TA_ECC_KEY_P8/TA_ECC_SPECIAL_KEY
	*													proKeyType=TA_ECC时，取值TA_SYMM_KEY/TA_RSA_KEY_P8/TA_ECC_KEY_P8/TA_ECC_SPECIAL_KEY
	* @param	expIndex				[IN]		导出密钥索引
	* @param	expUsage				[IN]		导出非对称密钥用途，当导出密钥为ECC 或 RSA时且expIndex>0时有效
	* @param	expAlg					[IN]		导出密钥算法，导出密钥非RSA密钥时有效，
	*																导出密钥为对称密钥时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4，
	*																导出密钥为ECC密钥时，支持TA_SM2/TA_NID_NISTP256/TA_NID_SECP256K1
	* @param	expKeyCipherByLmk		[IN]		导出密钥密文，当expIndex=0时有效
	*													对称密钥:密钥密文值(LMK 加密)
	*													RSA: 密钥值[n||e]（e按3个字节长度处理）
	*													ECC: 密钥值[x||y]
	* @param	expKeyCipherByLmkLen	[IN]		expKeyCipherByLmk长度，当expIndex=0时有效
	* @param	macIv					[IN]		MAC IV，expKeyFmt=/TA_SYMM_GET_MAC_KEY/TA_RSA_GET_MAC_KEY/TA_ECC_GET_MAC_KEY/时有效
	* @param	expKeyCipherByProKey	[OUT]		保护密钥加密的导出密钥密文
	* @param	expKeyCipherByProKeyLen	[IN|OUT]	输入时：expKeyCipherByProKey大小，输出时：expKeyCipherByProKey长度
	* @param	mac						[OUT]		导出密钥MAC, expKeyFmt=/TA_SYMM_GET_MAC_KEY/TA_RSA_GET_MAC_KEY/TA_ECC_GET_MAC_KEY/时有效
	* @param	macLen					[IN|OUT]	输入时：mac大小，输出时：mac长度
	* @param	tags					[OUT]		TAGS, proKeyType=TA_SYMM且pad=TA_GCM时有效
	* @param	tagsLen					[IN|OUT]	输入时：tags大小，输出时：tags长度
	* @param	symmKcv					[OUT]		导出密钥校验值，导出密钥为对称密钥时存在
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ExportKey(void* hSessionHandle,
		TA_KEY_TYPE proKeyType,
		unsigned int proAlg,
		TA_SYMM_MODE mode,
		const unsigned char* iv,
		const unsigned char* gcmIv, unsigned int gcmIvLen,
		const unsigned char* aad, unsigned int aadLen,
		unsigned int proIndex,
		TA_ASYMM_USAGE proUsage,
		const unsigned char* proKey, unsigned int proKeyLen,
		const char* proLabel,
		const unsigned char* proId, unsigned int proIdLen,
		TA_PAD pad,
		TA_HASH_ALG mgfHash,
		TA_HASH_ALG paramHash,
		const unsigned char* oaepParam, unsigned int oaepParamLen,
		TA_EXPORTED_KEY_FMT expKeyFmt,
		unsigned int expIndex,
		TA_ASYMM_USAGE expUsage,
		unsigned int expAlg,
		const unsigned char* expKeyCipherByLmk, unsigned int expKeyCipherByLmkLen,
		const unsigned char* macIv,
		unsigned char* expKeyCipherByProKey, unsigned int* expKeyCipherByProKeyLen,
		unsigned char* mac, unsigned int* macLen,
		unsigned char* tags, unsigned int* tagsLen,
		unsigned char symmKcv[8]);

	/**
	* @brief	其它密钥加密转 LMK 加密的密钥
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	proKeyType				[IN]		保护密钥类型
	* @param	proAlg					[IN]		保护密钥算法类型，当proKeyType=TA_SYMM或TA_ECC时有效
	*																当proKeyType=TA_ECC时，proAlg为外送曲线标识，目前仅支持TA_SM2
	*																当proKeyType=TA_SYMM时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4
	* @param	mode					[IN]		保护密钥加密模式，当proKeyType=TA_SYMM_KEY时有效，支持TA_ECB/TA_CBC/TA_GCM
	* @param	iv						[IN]		加密IV，当proKeyType=TA_SYMM_KEY且mode=TA_CBC时有效
	* @param	gcmIv					[IN]		mode=TA_GCM时有效
	* @param	gcmIvLen				[IN]		gcmIv长度, 取值 1-8192
	* @param	aad						[IN]		mode=TA_GCM时有效
	* @param	aadLen					[IN]		aad长度, 取值 1-8192
	* @param	tags					[IN]		mode=TA_GCM时有效
	* @param	tagsLen					[IN]		tags长度
	* @param	proIndex				[IN]		保护密钥索引，0：代表外送保护密钥, 9999: 代表根据 proLabel 或 proId 查找密码机内密钥
	* @param	proUsage				[IN]		非对称保护密钥用途, 当proKeyType=TA_ECC或proKeyType=TA_RSA且proIndex>0时有效
	* @param	proKeyCipherByLmk		[IN]		外送保护密钥, 当proIndex=0 时有效
	* @param	proKeyCipherByLmkLen	[IN]		proKey长度, 当proIndex=0 时有效
	* @param	proLabel				[IN]		保护密钥的标签, 当proIndex=9999 时有效
	* @param	proId					[IN]		保护密钥的ID,  当proIndex=9999 时有效
	* @param	proIdLen				[IN]		proId长度, 当proIndex=9999 时有效（长度范围：1-128）
	* @param	pad						[IN]		加密填充方式,当proKeyType!=TA_ECC时有效
	* @param	mgfHash					[IN]		MGF 杂凑算法, proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效
	*													支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	paramHash				[IN]		Param 哈希算法, proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效
	*													支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	oaepParam				[IN]		OAEP 编码参数， proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效
	* @param	oaepParamLen			[IN]		oaepParam长度, 取值范围：0-2048。proKeyType=TA_RSA且pad=TA_PAD_OAEP时有效,
	* @param	impKeyFmt				[IN]		导入密钥格式，
	*													proKeyType=TA_SYMM时，取值TA_SYMM_KEY/TA_RSA_KEY_P8/TA_ECC_KEY_P8/TA_ECC_SPECIAL_KEY/TA_SYMM_GET_MAC_KEY/TA_RSA_GET_MAC_KEY/TA_ECC_GET_MAC_KEY/TA_RSA_KEY_P1
	*													proKeyType=TA_RSA时，取值TA_SYMM_KEY/TA_ECC_KEY_P8/TA_ECC_SPECIAL_KEY
	*													proKeyType=TA_ECC时，取值TA_SYMM_KEY/TA_RSA_KEY_P8/TA_ECC_KEY_P8/TA_ECC_SPECIAL_KEY
	*																	 12-ECC 密钥（特殊结构，32 字节 0x0||32 字节私钥）
	* @param	impAlg					[IN]		导入密钥算法，非RSA密钥时有效，
	*													对称密钥时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4，
	*													为ECC密钥时，支持TA_SM2/TA_NID_NISTP256/TA_NID_SECP256K1
	* @param	impKeyCipherByProKey	[IN]		保护密钥加密的导入密钥密文
	* @param	impKeyCipherByProKeyLen	[IN]		impKeyCipherByProKey长度
	* @param	macIv					[IN]		MAC IV，impKeyFmt=/TA_SYMM_GET_MAC_KEY/TA_RSA_GET_MAC_KEY/TA_ECC_GET_MAC_KEY/时有效
	* @param	mac						[IN]		导入密钥MAC，，impKeyFmt=/TA_SYMM_GET_MAC_KEY/TA_RSA_GET_MAC_KEY/TA_ECC_GET_MAC_KEY/时有效
	* @param	macLen					[IN]		MACmac
	* @param	impKeyCipherByLmk		[OUT]		LMK密钥加密的导入密钥密文
	* @param	impKeyCipherByLmkLen	[IN|OUT]	输入时：impKeyCipherByLmk大小，输出时：impKeyCipherByLmk长度
	* @param	symmKcv					[OUT]		导入密钥校验值，导入密钥为对称密钥时存在
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ImportKey(void* hSessionHandle,
		TA_KEY_TYPE proKeyType,
		unsigned int proAlg,
		TA_SYMM_MODE mode,
		const unsigned char* iv,
		const unsigned char* gcmIv, unsigned int gcmIvLen,
		const unsigned char* aad, unsigned int aadLen,
		const unsigned char* tags, unsigned int tagsLen,
		unsigned int proIndex,
		TA_ASYMM_USAGE proUsage,
		const unsigned char* proKeyCipherByLmk, unsigned int proKeyCipherByLmkLen,
		const char* proLable,
		const unsigned char* proId, unsigned int proIdLen,
		TA_PAD pad,
		TA_HASH_ALG mgfHash,
		TA_HASH_ALG paramHash,
		const unsigned char* oaepParam, unsigned int oaepParamLen,
		TA_IMPORTED_KEY_FMT impKeyFmt,
		unsigned int impAlg,
		const unsigned char* impKeyCipherByProKey, unsigned int impKeyCipherByProKeyLen,
		const unsigned char* macIv,
		const unsigned char* mac, unsigned int macLen,
		unsigned char* impKeyCipherByLmk, unsigned int* impKeyCipherByLmkLen,
		unsigned char symmKcv[8]);

	/**
	* @brief	通过 RSA/ECC/SM2 私钥获取对应公钥
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	keyType			[IN]		密钥类型, 1-RSA密钥, 2-ECC/SM2 密钥
	* @param	curve			[IN]		曲线标识, 仅当密钥类型为2-ECC密钥时存在
	* @param	keyStatus		[IN]		密钥状态,取值如下：
	*									    当密钥类型为 1-RSA 密钥时，取值: 2-LMK加密的密钥密文
	*										当密钥类型为 2-ECC/SM2 密钥时，取值：1-密钥明文, 2-LMK加密的密钥密文
	* @param	key				[IN]		明文或密文密钥
	* @param	keyLen			[IN]		明文或密文密钥的长度
	* @param	rsaBits			[OUT]		密钥 bits，仅当密钥类型为 1-RSA 时存在
	* @param	pubKeyN_X		[OUT]		公钥 X/N，当密钥类型为1-RSA时，为公钥 N 长度；
	*												  当密钥类型为2-ECC时，为公钥 X 长度
	* @param	pubKeyN_XLen	[OUT]		公钥 X/N长度
	*
	* @param	pubKeyE_Y		[OUT]		公钥 Y/E，当密钥类型为 1-RSA 时，为公钥 E 长度；
	*												  当密钥类型为 2-ECC 时，为公钥 Y 长度
	* @param	pubKeyE_YLen	[OUT]		公钥 Y/E长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetPublicKeyByPrivateKey(void* hSessionHandle,
		TA_KEY_TYPE type,
		TA_ECC_CURVE curve,
		unsigned int keyStatus,
		unsigned char* key,
		unsigned int keyLen,
		unsigned int* rsaBits,
		unsigned char* pubKeyN_X,
		unsigned int* pubKeyN_XLen,
		unsigned char* pubKeyE_Y,
		unsigned int* pubKeyE_YLen);

	/**
	* @brief	获取SDF密钥句柄中的密钥密文
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	hKeyHandle				[IN]		密钥句柄
	* @param	keyCipherByLmk			[OUT]		LMK加密的对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*
	*/
	int Tass_GetKeyCipherByLMKFromSDFKeyHandle(void* hSessionHandle,
		void* hKeyHandle,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	传输密钥保护导入一条密钥。推荐使用Tass_Import
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	cipherKey				[IN]		保护密钥
	* @param	uiKeyLength				[IN]		保护密钥长度
	* @param	key						[IN]		保护密钥加密下的被导入的密钥数据块密文
	* @param	keyLen					[IN]		被导入的密钥数据密文长度
	* @param	keyCipherByLmk			[OUT]		LMK加密的随机对称密钥密文
	* @param	keyCipherByLmkLen		[IN|OUT]	输入时：keyCipherByLmk大小，输出时：keyCipherByLmk长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*
	*/
	int Tass_ImportSymmConvertKey(void* hSessionHandle,
		const unsigned char* cipherKey, unsigned int uiKeyLength,
		unsigned char* key, unsigned int keyLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);

	/**
	* @brief	导出密钥密文（对称密钥加密被保护密钥）。（建议弃用，不再升级）
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	alg						[IN]		保护密钥算法类型
	* @param	mode					[IN]		保护密钥算法模式（暂时仅支持 ECB/CBC）
	* @param	inIv					[IN]		输入IV，mode不是ecb时有效，des算法时为8字节，其他算法16字节
	* @param	index					[IN]		保护密钥索引
	* @param	keyType					[IN]		被保护密钥类型，0-对称密钥，1-RSA密钥，2-ECC密钥
	* @param	covertIndex				[IN]		被保护密钥索引
	* @param	keyAlg					[OUT]		被保护密钥类型
	* @param	covertKey				[OUT]		被保护密钥密文
	* @param	covertKeyLen			[IN|OUT]	被保护密钥密文长度
	* @param	label					[OUT]		被保护密钥 Label
	* @param	labelLen				[IN|OUT]	被保护密钥 Label长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 导出非对称密钥时，该接口默认导出的是加密密钥，签名密钥暂时不支持
	*/
	int Tass_ExportCovertKeyBySymmKey(void* hSessionHandle,
		TA_SYMM_ALG alg, TA_SYMM_MODE mode,
		const unsigned char* inIv,
		unsigned int index,
		TA_KEY_TYPE keyType,
		unsigned int covertIndex,
		unsigned int* keyAlg,
		unsigned char* covertKey, unsigned int* covertKeyLen,
		unsigned char* label, unsigned int* labelLen);

	/**
	* @brief	导入密钥密文（对称密钥加密被保护密钥）（建议弃用，不再升级）
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	alg						[IN]		保护密钥算法类型
	* @param	mode					[IN]		保护密钥算法模式
	* @param	inIv					[IN]		输入IV，mode不是ecb时有效，des算法时为8字节，其他算法16字节
	* @param	index					[IN]		保护密钥索引
	* @param	keyType					[IN]		被保护密钥类型，0-对称密钥，1-RSA密钥，2-ECC密钥
	* @param	keyAlg					[IN]		被保护密钥算法类型，当keyType=1时，keyAlg为1
	*																	当keyType=2时，keyAlg为外送曲线标识，支持TA_SM2/TA_NID_NISTP256/TA_NID_BRAINPOOLP256R1/TA_NID_BRAINPOOLP192R1/TA_NID_FRP256V1/TA_NID_SECP256K1/TA_NID_FRP256V1
	*																	当keyType=0时，支持TA_DES128/TA_DES192/TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33/TA_RC4/TA_ZUC
	* @param	covertIndex				[IN]		被保护密钥索引，存储到密码机，为0时代表不存储
	* @param	covertKey				[IN]		被保护密钥密文
	* @param	covertKeyLen			[IN]		被保护密钥密文长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ImportCovertKeyBySymmKey(void* hSessionHandle,
		TA_SYMM_ALG alg, TA_SYMM_MODE mode,
		const unsigned char* inIv,
		unsigned int index,
		TA_KEY_TYPE keyType, unsigned int keyAlg,
		unsigned int covertIndex,
		unsigned char* covertKey, unsigned int covertKeyLen);

	/**
	* @brief	导出密钥密文（非对称密钥加密对称密钥）。（建议弃用，不再升级）
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		保护密钥索引
	* @param	keyType					[IN]		保护密钥类型，1-RSA密钥，2-ECC密钥
	* @param	covertIndex				[IN]		被保护密钥索引
	* @param	keyAlg					[OUT]		被保护密钥算法类型
	* @param	covertKey				[OUT]		被保护密钥密文
	* @param	covertKeyLen			[IN|OUT]	被保护密钥密文长度
	* @param	label					[OUT]		被保护密钥 Label
	* @param	labelLen				[IN|OUT]	被保护密钥 Label长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ExportCovertKeyByAsymmKey(void* hSessionHandle,
		unsigned int index,
		TA_KEY_TYPE keyType,
		unsigned int covertIndex,
		unsigned int* keyAlg,
		unsigned char* covertKey, unsigned int* covertKeyLen,
		unsigned char* label, unsigned int* labelLen);

	/**
	* @brief	导入密文（非对称密钥加密对称密钥）。（建议弃用，不再升级）
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		保护密钥索引
	* @param	keyType					[IN]		保护密钥类型，1-RSA密钥，2-ECC密钥
	* @param	keyAlg					[IN]		被保护密钥算法类型, 支持TA_DES128/TA_DES192/TA_AES128/TA_AES192/TA_AES256/TA_SM4/TA_SSF33/TA_RC4/TA_ZUC（暂不支持TA_SM1）
	* @param	covertIndex				[IN]		被保护密钥索引，存储到密码机，为0时代表不存储
	* @param	covertKey				[IN]		被保护密钥密文
	* @param	covertKeyLen			[IN]		被保护密钥密文长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_ImportCovertKeyByAsymmKey(void* hSessionHandle,
		unsigned int index,
		TA_KEY_TYPE keyType,
		unsigned int keyAlg,
		unsigned int covertIndex,
		unsigned char* covertKey, unsigned int covertKeyLen);

	/**
	* @brief	LMK加密的密钥转其它密钥加密。（建议弃用，不再升级）
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	keyType					[IN]		保护密钥类型，0-对称密钥，1-RSA密钥，2-ECC密钥
	* @param	keyAlg					[IN]		保护密钥算法类型，当保护密钥类型keyType=0或2时，keyAlg有效
	*																	当keyType=2时，keyAlg为外送曲线标识，目前仅支持TA_SM2
	*																	当keyType=0时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4
	* @param	mode					[IN]		保护密钥加密模式，当保护密钥类型为对称密钥时有效，支持ECB/CBC/GCM
	* @param	iv						[IN]		保护密钥 IV，仅当保护密钥类型为对称密钥时且保护密钥加密模式为CBC时有效
	* @param	gcmIv					[IN]		仅当保护密钥加密模式为 GCM 时有效
	* @param	gcmIvLen				[IN]		仅当保护密钥加密模式为 GCM 时有效, 取值 1-8192
	* @param	aad						[IN]		加密导出认证数据AAD，仅当保护密钥加密模式为 GCM 时有效
	* @param	aadLen					[IN]		加密导出认证数据AAD长度，仅当保护密钥加密模式为 GCM 时有效, 取值 1-8192
	* @param	index					[IN]		保护密钥索引，0：代表外送保护密钥, 9999: 代表根据 Lable 或 ID 查找密码机内密钥
	* @param	AsymmKeyUsage			[IN]		非对称保护密钥用途, 当保护密钥为ECC 或 RSA时且索引为内部密钥时有效
	* @param	key						[IN]		外送保护密钥, 当保护密钥索引为 0 时有效
	* @param	keyLen					[IN]		外送保护密钥长度, 当保护密钥索引为 0 时有效
	* @param	lable					[IN]		保护密钥的lable, 当保护密钥索引为 9999 时有效
	* @param	lableLen				[IN]		保护密钥标的lable长度, 当保护密钥索引为9999时有效（长度范围：1-128）
	* @param	id						[IN]		保护密钥的id, 当保护密钥索引为 9999 时有效
	* @param	idLen					[IN]		保护密钥的id 长度, 当保护密钥索引为9999时有效（长度范围：1-128）
	* @param	pad						[IN]		保护密钥加密填充方式,当ECC作为保护密钥时无效，0-非强制补80，1-强制补80，2-非强制补00，
	*																		 3-PKCS 1.5(仅当保护密钥为 RSA 时可选该参数)--仅 RSA可用，
	*																		 4-PKCS#7，5:-不填充(外部填充)
	*																		 6-OAEP（EME-OAEP-ENCODE）(仅当保护密钥为 RSA 时 可选该参数)--仅RSA可用
	* @param	mgfHash					[IN]		MGF 杂凑算法, 仅当“保护密钥加密填充方式”取值为06（OAEP）时有效，支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	paramHash				[IN]		Param 哈希算法, 仅当“保护密钥加密填充方式”取值为 06（OAEP）时有效,支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	oaepParam				[IN]		OAEP 编码参数，仅当“保护密钥加密填充方式”取值为 06（OAEP）时有效，如果存在，则应参照 PKCS#1 v2.0 第 11.2.1 节进行编码，HSM不解释和验证该域的内容
	*												如果使用 OAEP 填充模式而不提供编码参数，则 OAEP 编码参数长度为 00，并且该参数为空
	* @param	oaepParamLen			[IN]		OAEP 编码参数长度，仅当“保护密钥加密填充方式”取值为 06（OAEP）时有效, 取值范围：0-2048
	* @param	covertKeyType			[IN]		被保护密钥类型，当保护密钥为对称密钥时: 0-对称密钥,1-RSA密（P8 结构）,2-ECC 密钥（P8 结构）
	*																					  12-ECC密钥（特殊结构，32 字节 0x0||32 字节私 钥）
	*																					  20-对称密钥（仅当保护密钥为对称密钥时，产生MAC）
	*																					  21-RSA密钥（仅当保护密钥为对称密钥时，产生MAC）
	*																					  22-ECC密钥（仅当保护密钥为对称密钥时，产生MAC）
	*												当保护密钥为 RSA 时：0-对称密钥, 2-ECC 密钥（P8 结构）
	*																	 12-ECC 密钥（特殊结构，32 字节 0x0||32 字节私钥）
	*												当保护密钥为 ECC 时：0-对称密钥, 1-RSA密钥（P8 结构）, 2-ECC 密钥（P8 结构）
	*																	 12-ECC 密钥（特殊结构，32 字节 0x0||32 字节私钥）
	* @param	covertKeyFlag			[IN]		被保护密钥获取标识，0-内部密钥, 1-外部密钥
	* @param	covertAsymmKeyUsage		[IN]		被保护非对称密钥用途，当被保护密钥为ECC 或 RSA时且被保护密钥获取标识为0时有效，0-签名密钥，1-加密密钥
	* @param	covertKeyIndex			[IN]		被保护密钥索引，当被保护密钥获取标识为0时有效
	* @param	covertKetyAlg			[IN]		被保护密钥算法，当密钥类型为RSA密钥时无效，
	*																当密钥类型为对称密钥时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4，
	*																当密钥类型为为ECC密钥时，支持TA_SM2/TA_NID_NISTP256/TA_NID_SECP256K1
	* @param	covertKey				[IN]		被保护密钥密文，当被保护密钥获取标识为 1 时有效
	* @param	covertKeyLen			[IN]		被保护密钥密文长度，当被保护密钥获取标识为 1 时有效
	* @param	macIv					[IN]		仅当被保护密钥类型为 20/21/22 时有效， 用于计算 MAC
	* @param	keyByCovertKey			[OUT]		保护密钥加密的密文
	* @param	keyByCovertKeyLen		[IN|OUT]	保护密钥加密的密文长度
	* @param	mac						[OUT]		仅当被保护密钥类型为 20/21/22 时存在
	* @param	macLen					[IN|OUT]	仅当被保护密钥类型为 20/21/22 时存在
	* @param	tags					[OUT]		仅当保护密钥加密模式为 6（GCM）时存在
	* @param	tagsLen					[IN|OUT]	仅当保护密钥加密模式为 6（GCM）时存在
	* @param	keyCV					[OUT]		仅当被保护密钥为对称密钥时存在
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_KeyEncryptByLMKToOhter(void* hSessionHandle,
		TA_KEY_TYPE keyType,
		unsigned int keyAlg,
		TA_SYMM_MODE mode,
		const unsigned char* iv,
		const unsigned char* gcmIv,
		unsigned int gcmIvLen,
		const unsigned char* aad,
		unsigned int aadLen,
		unsigned int index,
		TA_ASYMM_USAGE AsymmKeyUsage,
		const unsigned char* key,
		unsigned int keyLen,
		const unsigned char* lable,
		unsigned int lableLen,
		const unsigned char* id,
		unsigned int idLen,
		TA_PAD pad,
		TA_HASH_ALG mgfHash,
		TA_HASH_ALG paramHash,
		const unsigned char* oaepParam,
		unsigned int oaepParamLen,
		TA_COVERT_KEY_TYPE covertKeyType,
		unsigned int covertKeyFlag,
		TA_ASYMM_USAGE covertAsymmKeyUsage,
		unsigned int covertKeyIndex,
		unsigned int covertKeyAlg,
		const unsigned char* covertKey,
		unsigned int covertKeyLen,
		const unsigned char* macIv,
		unsigned char* keyByCovertKey,
		unsigned int* keyByCovertKeyLen,
		unsigned char* mac,
		unsigned int* macLen,
		unsigned char* tags,
		unsigned int* tagsLen,
		unsigned char* keyCV);

	/**
	* @brief	其它密钥加密转 LMK 加密的密钥。（建议弃用，不再升级）
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	keyType					[IN]		保护密钥类型，0-对称密钥，1-RSA密钥，2-ECC密钥
	* @param	keyAlg					[IN]		保护密钥算法类型，当保护密钥类型keyType=0或2时，keyAlg有效
	*																	当keyType=2时，keyAlg为外送曲线标识，目前仅支持TA_SM2
	*																	当keyType=0时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4
	* @param	mode					[IN]		保护密钥加密模式，当保护密钥类型为对称密钥时有效，支持ECB/CBC/GCM
	* @param	iv						[IN]		保护密钥IV，仅当保护密钥类型为对称密钥时且保护密钥加密模式为CBC时有效
	* @param	gcmIv					[IN]		仅当保护密钥加密模式为 GCM 时有效
	* @param	gcmIvLen				[IN]		仅当保护密钥加密模式为 GCM 时有效, 取值 1-8192
	* @param	aad						[IN]		加密导出认证数据AAD，仅当保护密钥加密模式为 GCM 时有效
	* @param	aadLen					[IN]		加密导出认证数据AAD长度，仅当保护密钥加密模式为 GCM 时有效, 取值 1-8192
	* @param	tags					[IN]		仅当保护密钥加密模式为 6（GCM）时存在
	* @param	tagsLen					[IN]		仅当保护密钥加密模式为 6（GCM）时存在, 取值16
	* @param	index					[IN]		保护密钥索引，0：代表外送保护密钥, 9999: 代表根据 Lable 或 ID 查找密码机内密钥
	* @param	AsymmKeyUsage			[IN]		非对称保护密钥用途, 当保护密钥为ECC 或 RSA时且索引为内部密钥时有效
	* @param	key						[IN]		外送保护密钥, 当保护密钥索引为 0 时有效
	* @param	keyLen					[IN]		外送保护密钥, 当保护密钥索引为 0 时有效
	* @param	lable					[IN]		保护密钥的lable, 当保护密钥索引为 9999 时有效
	* @param	lableLen				[IN]		保护密钥标的lable长度, 当保护密钥索引为9999时有效（长度范围：1-128）
	* @param	id						[IN]		保护密钥的id, 当保护密钥索引为 9999 时有效
	* @param	idLen					[IN]		保护密钥的id 长度, 当保护密钥索引为9999时有效（长度范围：1-128）
	* @param	pad						[IN]		当ECC作为保护密钥时无效，0-非强制补80，1-强制补80，2-非强制补00，
	*																		 3-PKCS 1.5(仅当保护密钥为 RSA 时可选该参数)--仅 RSA可用，
	*																		 4-PKCS#7，5:-不填充(外部填充)
	*																		 6-OAEP（EME-OAEP-ENCODE）(仅当保护密钥为 RSA 时 可选该参数)--仅RSA可用
	* @param	mgfHash					[IN]		MGF杂凑算法, 仅当“保护密钥加密填充方式”取值为06（OAEP）时有效，支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	paramHash				[IN]		Param哈希算法, 仅当“保护密钥加密填充方式”取值为 06（OAEP）时有效,支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	oaepParam				[IN]		OAEP 编码参数，仅当“保护密钥加密填充方式”取值为 06（OAEP）时有效，如果存在，则应参照 PKCS#1 v2.0 第 11.2.1 节进行编码,HSM不解释和验证该域的内容
	*												如果使用 OAEP 填充模式而不提供编码参数，则 OAEP 编码参数长度为 00，并且该参数为空
	* @param	oaepParamLen			[IN]		OAEP 编码参数长度，仅当“保护密钥加密填充方式”取值为 06（OAEP）时有效, 取值范围：0-2048
	* @param	covertKeyType			[IN]		被保护密钥类型，当保护密钥为对称密钥时: 0-对称密钥,1-RSA密（P8 结构）,2-ECC 密钥（P8 结构）
	*																					  12-ECC密钥（特殊结构，32 字节 0x0||32 字节私 钥）
	*																					  20-对称密钥（仅当保护密钥为对称密钥时，产生MAC）
	*																					  21-RSA密钥（仅当保护密钥为对称密钥时，产生MAC）
	*																					  22-ECC密钥（仅当保护密钥为对称密钥时，产生MAC）
	*												当保护密钥为 RSA 时：0-对称密钥, 2-ECC 密钥（P8 结构）
	*																	 12-ECC 密钥（特殊结构，32 字节 0x0||32 字节私钥）,即密钥模长/8 || 32 字节私钥明文，二者拼起来后加密得到最终的密文
	*												当保护密钥为 ECC 时：0-对称密钥, 1-RSA密钥（P8 结构）, 2-ECC 密钥（P8 结构）
	*																	 12-ECC 密钥（特殊结构，32 字节 0x0||32 字节私钥）
	* @param	covertKetyAlg			[IN]		被保护密钥算法，当密钥类型为RSA密钥时无效，
	*																当密钥类型为对称密钥时，支持TA_AES128/TA_AES192/TA_AES256/TA_SM4，
	*																当密钥类型为为ECC密钥时，支持TA_SM2/TA_NID_NISTP256/TA_NID_SECP256K1
	* @param	covertKey				[IN]		被保护密钥密文，保护加密的P8 Der文件Der密文值或密钥密文值，
	*																当被保护密钥类型为 1 或 2 时，其明文为p8格式的密钥明文或被保护密钥加密的对称密钥密文
	* @param	covertKeyLen			[IN]		被保护密钥密文长度，保护密钥加密的密钥P8 Der 文件 Der密文长度或被保护密钥加密的对称密钥密文
	* @param	macIv					[IN]		仅当被保护密钥类型为 20/21/22 时有效，用于计算 MAC
	* @param	mac						[IN]		仅当被保护密钥类型为 20/21/22 时存在，用于校验被保护密钥的MAC
	* @param	macLen					[IN]		仅当被保护密钥类型为 20/21/22 时存在
	* @param	keyCipherByLmk			[OUT]		LMK 密钥加密的密文
	* @param	keyCipherByLmkLen		[IN|OUT]	LMK 加密的密文长度
	* @param	keyCV					[OUT]		当被保护密钥类型为对称密钥时存在
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_KeyEncryptByOhterToLMK(void* hSessionHandle,
		TA_KEY_TYPE keyType,
		unsigned int keyAlg,
		TA_SYMM_MODE mode,
		const unsigned char* iv,
		const unsigned char* gcmIv, unsigned int gcmIvLen,
		const unsigned char* aad, unsigned int aadLen,
		unsigned char* tags, unsigned int tagsLen,
		unsigned int index,
		TA_ASYMM_USAGE AsymmKeyUsage,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* lable, unsigned int lableLen,
		const unsigned char* id, unsigned int idLen,
		TA_PAD pad,
		TA_HASH_ALG mgfHash,
		TA_HASH_ALG paramHash,
		const unsigned char* oaepParam, unsigned int oaepParamLen,
		TA_COVERT_KEY_TYPE covertKeyType,
		unsigned int covertKeyAlg,
		const unsigned char* covertKey, unsigned int covertKeyLen,
		const unsigned char* macIv,
		const unsigned char* mac, unsigned int macLen,
		unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen,
		unsigned char* keyCV);

	/***************************************************************************
	* 密钥管理-索引&标签管理
	* 	Tass_GetIndexInfo
	*	Tass_GetSymmKeyInfo
	*	Tass_GetSymmKCV
	*	Tass_SetKeyLabel
	*	Tass_GetKeyLabel
	*	Tass_GetKeyIndex
	*	Tass_DestroyKey
	*	Tass_GetKeyInfo
	****************************************************************************/

	/**
	* @brief	获取索引信息
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	type			[IN]		密钥类型
	* @param	info			[OUT]		索引信息
	* @param	infoLen			[IN|OUT]	输入时：info大小，输出时：info长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetIndexInfo(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned char* info, unsigned int* infoLen);

	/**
	* @brief	获取对称密钥信息
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	alg				[OUT]		密钥算法，为NULL时不输出
	* @param	label			[OUT]		标签
	* @param	labelLen		[IN|OUT]	输入时：label大小，输出时：label长度
	* @param	kcv				[OUT]		校验值，为NULL时不输出
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetSymmKeyInfo(void* hSessionHandle,
		unsigned int index,
		TA_SYMM_ALG* alg,
		char* label, unsigned int* labelLen,
		unsigned char kcv[8]);

	/**
	* @brief	获取对称密钥校验值
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	index			[IN]	索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]	密钥，index为0时有效
	* @param	keyLen			[IN]	密钥长度，index为0时有效
	* @param	alg				[IN]	外部密钥算法算法，index为0时有效
	* @param	kcv				[OUT]	校验值
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetSymmKCV(void* hSessionHandle,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		unsigned char kcv[8]);

	/**
	* @brief	设置密钥标签
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	type			[IN]	密钥类型
	* @param	index			[IN]	密钥索引
	* @param	label			[IN]	标签
	* @param	labelLen		[IN]	label长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SetKeyLabel(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int index,
		const char* label, unsigned int labelLen);

	/**
	* @brief	获取密钥标签
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	type			[IN]		密钥类型
	* @param	index			[IN]		密钥索引
	* @param	label			[OUT]		标签
	* @param	labelLen		[IN|OUT]	输入时：label大小，输出时：label长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetKeyLabel(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int index,
		char* label, unsigned int* labelLen);

	/**
	* @brief	获取密钥索引
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	type			[IN]		密钥类型
	* @param	label			[IN]		标签
	* @param	labelLen		[IN]		label长度
	* @param	index			[OUT]		密钥索引
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetKeyIndex(void* hSessionHandle,
		TA_KEY_TYPE type,
		const char* label, unsigned int labelLen,
		unsigned int* index);

	/**
	* @brief	销毁密钥
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	type			[IN]	密钥类型
	* @param	index			[IN]	密钥索引
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_DestroyKey(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int index);

	/**
	* @brief	通过密钥类型和索引获取密钥信息
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	keyType			[IN]		密钥类型, 1-RSA密钥, 2-ECC/SM2 密钥
	* @param	index			[IN]		密钥索引
	* @param	signBits_Curve	[OUT]		当密钥类型为对称密钥时，表示密钥算法：
	*										0-DES64，1-DES128, 2-DES192,3-AES128,4-AES192,5-AES256,
	*										6-SM1, 7-SM4, 8-SSF33, 9-RC4, 10-ZUC, 11-SM7
	*										当密钥类型为RSA密钥时,表示签名密钥模长:1024、1152、1408、1984、2048、3072、4096
	*										当密钥类型为ECC密钥时，表示签名密钥曲线标识
	* @param	signE			[OUT]		签名密钥幂指数E，仅当密钥类型为RSA且签名密钥模长不为0时存在
	* @param	encBits_Curve	[OUT]		仅当密钥类型为RSA/ECC时存在,
	*										当密钥类型为RSA密钥时，表示签名密钥模长；
	*										当密钥类型为ECC密钥时，表示签名密钥曲线标识；
	* @param	encE			[OUT]		加密密钥幂指数E，仅当密钥类型为RSA且加密密钥模长不为0时存在
	* @param	priKeyPwdFlag	[OUT]		私钥权限控制码存在标识，仅当密钥类型为RSA/ECC时存在
	*										0-不存在，1-存在
	* @param	label			[OUT]		密钥标签
	* @param	labelLen		[OUT]		密钥标签长度
	* @param	kcv				[OUT]		密钥的校验值，当密钥类型为对称密钥时存在
	* @param	updateTime		[OUT]		最后更新时间
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetKeyInfo(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int index,
		unsigned int* signBits_Curve,
		TA_RSA_E* signE,
		unsigned int* encBits_Curve,
		TA_RSA_E* encE,
		unsigned int* priKeyPwdFlag,
		unsigned char* label,
		unsigned int* labelLen,
		unsigned char* kcv,
		unsigned char* updateTime);

	/***************************************************************************
	* 密钥管理-派生
	*	Tass_PBKDFWithRandom
	*	Tass_PBKDF
	* 	Tass_HKDF
	****************************************************************************/

	/**
	* @brief	密钥派生HKDF
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	index			[IN]	密钥索引
	* @param	plainKey		[IN]	外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key				[IN]	被派生密钥,仅密钥索引为 0 时有效
	* @param	keyLen			[IN]	被派生密钥长度,仅密钥索引为 0 时有效
	* @param	symmAlg			[IN]	被派生密钥算法
	* @param	salt			[IN]	盐值
	* @param	saltLen			[IN]	盐值长度,0-128字节
	* @param	hashAlg			[IN]	HMAC-Hash标识，支持TA_HMAC_HASH_SHA1/TA_HMAC_HASH_SHA224/TA_HMAC_HASH_SHA256/TA_HMAC_HASH_SHA382/TA_HMAC_HASH_SHA512
	* @param	iterCnt			[IN]	迭代次数
	* @param	deriveKeyLen	[IN]	派生密钥长度
	* @param	deriveAlg		[IN]	派生密钥算法
	* @param	deriveKey		[OUT]	派生密钥（明文）
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_PBKDFWithRandom(void* hSessionHandle,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* random, unsigned int randomLen,
		const unsigned char* salt, unsigned int saltLen,
		TA_HMAC_HASH_ALG hashAlg,
		int iterCnt,
		unsigned int deriveKeyLen,
		unsigned char* deriveKey);

	/**
	* @brief	密钥派生HKDF
	* @param	hSessionHandle				[IN]	与设备建立的会话句柄
	* @param	index						[IN]	密钥索引
	* @param	plainKey					[IN]	外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key							[IN]	被派生密钥,仅密钥索引为 0 时有效
	* @param	keyLen						[IN]	被派生密钥长度,仅密钥索引为 0 时有效
	* @param	symmAlg						[IN]	被派生密钥算法
	* @param	salt						[IN]	盐值
	* @param	saltLen						[IN]	盐值长度,0-128字节
	* @param	hashAlg						[IN]	HMAC-Hash标识，支持TA_HMAC_HASH_SHA1/TA_HMAC_HASH_SHA224/TA_HMAC_HASH_SHA256/TA_HMAC_HASH_SHA382/TA_HMAC_HASH_SHA512
	* @param	iterCnt						[IN]	迭代次数
	* @param	deriveKeyLen				[IN]	派生密钥长度
	* @param	deriveAlg					[IN]	派生密钥算法
	* @param	deriveKeyCipherByLmk		[OUT]	LMK加密的派生密钥
	* @param	deriveKeyCipherByLmkLen		[OUT]	deriveKeyCipherByLmk长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_PBKDF(void* hSessionHandle,
		unsigned int index,
		TA_BOOL plainKey,
		unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG symmAlg,
		unsigned char* salt, unsigned int saltLen,
		TA_HMAC_HASH_ALG hashAlg,
		int iterCnt,
		unsigned int deriveKeyLen,
		TA_SYMM_ALG deriveAlg,
		unsigned char* deriveKeyCipherByLmk, unsigned int* deriveKeyCipherByLmkLen);

	/**
	* @brief	密钥派生HKDF
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	alg				[IN]	HMAC-Hash标识，支持TA_HMAC_HASH_SHA224/TA_HMAC_HASH_SHA256/TA_HMAC_HASH_SHA382/TA_HMAC_HASH_SHA512
	* @param	salt			[IN]	盐值
	* @param	saltLen			[IN]	盐值长度,0-128字节
	* @param	index			[IN]	密钥索引
	* @param	plainKey		[IN]	外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key				[IN]	被派生密钥,仅密钥索引为 0 时有效
	* @param	keyLen			[IN]	被派生密钥长度,仅密钥索引为 0 时有效
	* @param	info			[IN]	上下文和应用程序特定信息
	* @param	infoLen			[IN]	上下文和应用程序特定信息长度，0-8192字节
	* @param	offset			[IN]	偏移量，表明从何处开始截取，首次传入0
	* @param	inT				[IN]	T(n)
	* @param	inTLen			[IN]	T(n)长度，当偏移量 为 0 时，长度为0；当偏移量不为0时，长度为 hashlen
	* @param	deriveLen		[IN]	派生密钥输出长度，取值1-8192，输入偏移量+派生密钥输出长度 <= 255*hashlen
	* @param	nextOffset		[OUT]	派生密钥输出偏移量，作为下一次产生密钥的输入 = 输入偏移量+派生密钥输出长度
	* @param	outT			[OUT]	T(n)，作为下一次产生密钥的输入，当输出偏移量 >= hashlen 时存在，n = 偏移量/hashlen
	* @param	outTLen			[OUT]	长度为 hashlen
	* @param	deriveKey		[OUT]	派生密钥
	* @param	deriveKeyLen	[OUT]	派生密钥长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_HKDF(void* hSessionHandle,
		TA_HMAC_HASH_ALG alg,
		const unsigned char* salt, unsigned int saltLen,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* info, unsigned int infoLen,
		unsigned int offset,
		const unsigned char* inT, unsigned int inTLen,
		unsigned int deriveLen,
		unsigned int* nextOffset,
		unsigned char* outT, unsigned int* outTLen,
		unsigned char* deriveKey, unsigned int* deriveKeyLen);

	/***************************************************************************
	* 密钥运算
	* 	非对称密钥运算
	*	对称密钥运算
	****************************************************************************/

	/***************************************************************************
	* 密钥运算--非对称密钥运算
	*	Tass_ExchangeDataEnvelopeRSA
	*	Tass_RSAEncrypt
	*	Tass_RSADecrypt
	*	Tass_RSASign
	*	Tass_RSAVerify
	*	Tass_RSASignPublicKeyOperation
	*	Tass_ExchangeDataEnvelopeECC
	*	Tass_InternalECCSignHash
	*	Tass_ExternalECCSignHash
	*	Tass_ECCVerifyHash
	*	Tass_ECCEncrypt
	*	Tass_ECCDecrypt
	*	Tass_ExternalECCDecrypt
	*	Tass_InternalECCDecrypt
	*	Tass_PrivateKeyCipherByLMKOperation
	*	Tass_EciesEncrypt
	*	Tass_EciesDecrypt
	*	Tass_ECDHKeyAgree
	*	Tass_AgreementDataAndKeyWithECC
	****************************************************************************/
	/**
	* @brief	RSA数字信封转换（用于密钥转加密）
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		RSA密钥索引
	* @param	pubKeyN			[IN]		公钥N，index为0时有效
	* @param	pubKeyNLen		[IN]		pubKeyN长度，index为0时有效
	* @param	pubKeyE			[IN]		公钥E，index为0时有效
	* @param	pubKeyELen		[IN]		pubKeyE长度，index为0时有效
	* @param	srcEnvelope		[IN]		源数字信封
	* @param	srcEnvelopeLen	[IN]		srcEnvelope长度
	* @param	dstEnvelope		[OUT]		目的数字信封
	* @param	dstEnvelopeLen	[IN|OUT]	输入时：dstEnvelope大小，输出时：dstEnvelope长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_ExchangeDataEnvelopeRSA(void* hSessionHandle,
		unsigned int index,
		const unsigned char* pubKeyN, unsigned int pubKeyNLen,
		const unsigned char* pubKeyE, unsigned int pubKeyELen,
		const unsigned char* srcEnvelope, unsigned int srcEnvelopeLen,
		unsigned char* dstEnvelope, unsigned int* dstEnvelopeLen);

	/**
	* @brief	RSA公钥加密，使用加密密钥对
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		RSA密钥索引
	* @param	pubKeyN			[IN]		公钥N，index为0时有效
	* @param	pubKeyNLen		[IN]		pubKeyN长度，index为0时有效
	* @param	pubKeyE			[IN]		公钥E，index为0时有效
	* @param	pubKeyELen		[IN]		pubKeyE长度，index为0时有效
	* @param	pad				[IN]		填充方式，不能使用TA_PSS
	* @param	mgfHash			[IN]		MGF杂凑算法，pad为TA_OAEP时有效，不能使用TA_NOHASH和TA_SM3
	* @param	oaepParam		[IN]		OAEP参数，pad为TA_OAEP时有效
	* @param	oaepParamLen	[IN]		oaepParam长度，0~99，pad为TA_OAEP时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		data长度
	* @param	cipher			[OUT]		密文
	* @param	cipherLen		[IN|OUT]	输入时：cipher大小，输出时：cipher长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_RSAEncrypt(void* hSessionHandle,
		unsigned int index,
		const unsigned char* pubKeyN, unsigned int pubKeyNLen,
		const unsigned char* pubKeyE, unsigned int pubKeyELen,
		TA_RSA_PAD pad,
		TA_HASH_ALG mgfHash,
		const unsigned char* oaepParam, unsigned int oaepParamLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* cipher, unsigned int* cipherLen);

	/**
	* @brief	RSA私钥解密，使用加密密钥对
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		RSA密钥索引
	* @param	priKeyCipherByLmk		[IN]		私钥密文，index为0时有效
	* @param	priKeyCipherByLmkLen	[IN]		priKeyCipherByLmk长度，index为0时有效
	* @param	pad						[IN]		填充方式，不能使用TA_PSS
	* @param	mgfHash					[IN]		MGF杂凑算法，pad为TA_OAEP时有效，不能使用TA_NOHASH和TA_SM3
	* @param	oaepParam				[IN]		OAEP参数，pad为TA_OAEP时有效
	* @param	oaepParamLen			[IN]		oaepParam长度，pad为TA_OAEP时有效
	* @param	data					[IN]		数据
	* @param	dataLen					[IN]		data长度
	* @param	plain					[OUT]		明文
	* @param	plainLen				[IN|OUT]	输入时：plain大小，输出时：plain长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_RSADecrypt(void* hSessionHandle,
		unsigned int index,
		const unsigned char* priKeyCipherByLmk, unsigned int priKeyCipherByLmkLen,
		TA_RSA_PAD pad,
		TA_HASH_ALG mgfHash,
		const unsigned char* oaepParam, unsigned int oaepParamLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* plain, unsigned int* plainLen);

	/**
	* @brief	RSA私钥签名，使用签名密钥对
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	index					[IN]		RSA密钥索引
	* @param	priKeyCipherByLmk		[IN]		私钥密文，index为0时有效
	* @param	priKeyCipherByLmkLen	[IN]		priKeyCipherByLmk长度，index为0时有效
	* @param	pad						[IN]		填充方式，不能使用TA_OAEP
	* @param	hash					[IN]		HASH算法，pad不为TA_NOPAD时有效，不能使用TA_SM3
	* @param	mgfHash					[IN]		MGF杂凑算法，pad为TA_PSS时有效，不能使用TA_NOHASH和TA_SM3
	* @param	saltLen					[IN]		盐长度，范围为: 0 - 最大值，最大值的算法为：模长-hashlen-2，最大值不得大于493
	* @param	data					[IN]		数据，（若为hash值时，可以对hash值进行填充，也可以不填充，目前哈希方式支持SHA-224、SHA-256、SHA-384、SHA-512）
	* @param	dataLen					[IN]		data长度
	* @param	sig						[OUT]		签名值
	* @param	sigLen					[IN|OUT]	输入时：sig大小，输出时：sig长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_RSASign(void* hSessionHandle,
		unsigned int index,
		const unsigned char* priKeyCipherByLmk, unsigned int priKeyCipherByLmkLen,
		TA_RSA_PAD pad,
		TA_HASH_ALG hash,
		TA_HASH_ALG mgfHash,
		unsigned int saltLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* sig, unsigned int* sigLen);

	/**
	* @brief	RSA公钥验签，使用签名密钥对
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	index			[IN]	RSA密钥索引
	* @param	pubKeyN			[IN]	公钥N，index为0时有效
	* @param	pubKeyNLen		[IN]	pubKeyN长度，index为0时有效
	* @param	pubKeyE			[IN]	公钥E，index为0时有效
	* @param	pubKeyELen		[IN]	pubKeyE长度，index为0时有效
	* @param	pad				[IN]	填充方式，不能使用TA_OAEP
	* @param	hash			[IN]	HASH算法，pad不为TA_NOPAD时有效，不能使用TA_SM3
	* @param	mgfHash			[IN]	MGF杂凑算法，pad为TA_PSS时有效，不能使用TA_NOHASH和TA_SM3
	* @param	saltLen			[IN]	盐长度，范围为: 0 - 最大值，最大值的算法为：模长-hashlen-2，最大值不得大于493
	* @param	data			[IN]	数据，（若为hash值时，可以对hash值进行填充，也可以不填充，目前哈希方式支持SHA-224、SHA-256、SHA-384、SHA-512）
	* @param	dataLen			[IN]	data长度
	* @param	sig				[IN]	签名值
	* @param	sigLen			[IN]	签名值长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_RSAVerify(void* hSessionHandle,
		unsigned int index,
		const unsigned char* pubKeyN, unsigned int pubKeyNLen,
		const unsigned char* pubKeyE, unsigned int pubKeyELen,
		TA_RSA_PAD pad,
		TA_HASH_ALG hash,
		TA_HASH_ALG mgfHash,
		unsigned int saltLen,
		const unsigned char* data, unsigned int dataLen,
		const unsigned char* sig, unsigned int sigLen);

	/**
	* @brief	RSA公钥运算，使用签名密钥对或外部公钥
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		RSA密钥索引
	* @param	pubKeyN			[IN]		公钥N，index为0时有效
	* @param	pubKeyNLen		[IN]		pubKeyN长度，index为0时有效
	* @param	pubKeyE			[IN]		公钥E，index为0时有效
	* @param	pubKeyELen		[IN]		pubKeyE长度，index为0时有效
	* @param	inData			[IN]		输入数据
	* @param	inDataLen		[IN]		inData长度
	* @param	outData			[OUT]		输出数据，长度与inData相同
	* @param	outDataLen		[IN|OUT]	输入时：outData大小，输出时：outData长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_RSASignPublicKeyOperation(void* hSessionHandle,
		unsigned int index,
		const unsigned char* pubKeyN, unsigned int pubKeyNLen,
		const unsigned char* pubKeyE, unsigned int pubKeyELen,
		const unsigned char* inData, unsigned int dataLen,
		unsigned char* outData, unsigned int* outDataLen);

	/**
	* @brief	ECC数字信封转换（用于密钥转加密）
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	index			[IN]		ECC密钥索引
	* @param	curve			[IN]		曲线标识，目前只支持TA_SM2，index为0时有效
	* @param	pubKeyX			[IN]		公钥X
	* @param	pubKeyXLen		[IN]		pubKeyX长度
	* @param	pubKeyY			[IN]		公钥Y
	* @param	pubKeyYLen		[IN]		pubKeyY长度
	* @param	srcEnvelope		[IN]		源数字信封
	* @param	srcEnvelopeLen	[IN]		srcEnvelope长度
	* @param	dstEnvelope		[OUT]		目的数字信封
	* @param	dstEnvelopeLen	[IN|OUT]	输入时：dstEnvelope大小，输出时：dstEnvelope长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_ExchangeDataEnvelopeECC(void* hSessionHandle,
		unsigned int index,
		TA_ECC_CURVE curve,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		const unsigned char* srcEnvelope, unsigned int srcEnvelopeLen,
		unsigned char* dstEnvelope, unsigned int* dstEnvelopeLen);

	/**
	* @brief	内部ECC私钥（对摘要）签名
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识
	* @param	index			[IN]		密钥索引
	* @param	hash			[IN]		数据摘要
	* @param	hashLen			[IN]		hash长度
	* @param	sig				[OUT]		摘要签名
	* @param	sigLen			[IN|OUT]	输入时：sig大小，输出时：sig长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_InternalECCSignHash(void* hSessionHandle,
		TA_ECC_CURVE curve,
		unsigned int index,
		const unsigned char* hash, unsigned int hashLen,
		unsigned char* sig, unsigned int* sigLen);

	/**
	* @brief	外部ECC私钥（对摘要）签名
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识
	* @param	priKeyD			[IN]		私钥
	* @param	priKeyDLen		[IN]		priKeyD长度
	* @param	hash			[IN]		数据摘要
	* @param	hashLen			[IN]		hash长度
	* @param	sig				[OUT]		摘要签名
	* @param	sigLen			[IN|OUT]	输入时：sig大小，输出时：sig长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_ExternalECCSignHash(void* hSessionHandle,
		TA_ECC_CURVE curve,
		const unsigned char* priKeyD, unsigned int priKeyDLen,
		const unsigned char* hash, unsigned int hashLen,
		unsigned char* sig, unsigned int* sigLen);

	/**
	* @brief	ECC（对摘要）验签
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识
	* @param	index			[IN]		密钥索引
	* @param	pubKeyX			[IN]		公钥X，index为0时有效
	* @param	pubKeyXLen		[IN]		pubKeyX长度，index为0时有效
	* @param	pubKeyY			[IN]		公钥Y，index为0时有效
	* @param	pubKeyYLen		[IN]		pubKeyY长度，index为0时有效
	* @param	hash			[IN]		数据摘要
	* @param	hashLen			[IN]		hash长度
	* @param	sig				[IN]		摘要签名
	* @param	sigLen			[IN]		sig长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ECCVerifyHash(void* hSessionHandle,
		TA_ECC_CURVE curve,
		unsigned int index,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		const unsigned char* hash, unsigned int hashLen,
		const unsigned char* sig, unsigned int sigLen);

	/**
	* @brief	ECC加密
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识，目前仅支持TA_SM2
	* @param	index			[IN]		密钥索引
	* @param	pubKeyX			[IN]		公钥X，index为0时有效
	* @param	pubKeyXLen		[IN]		pubKeyX长度，index为0时有效
	* @param	pubKeyY			[IN]		公钥Y，index为0时有效
	* @param	pubKeyYLen		[IN]		pubKeyY长度，index为0时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		data长度
	* @param	cipher			[OUT]		密文
	* @param	cipherLen		[IN|OUT]	输入时：cipher大小，输出时：cipher长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ECCEncrypt(void* hSessionHandle,
		TA_ECC_CURVE curve,
		unsigned int index,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* cipher, unsigned int* cipherLen);

	/**
	* @brief	使用内/外部签名密钥/加密密钥ECC解密
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识，目前仅支持TA_SM2
	* @param	keyUsage		[IN]		密钥用途，0-签名密钥，1-加密密钥
	* @param	index			[IN]		密钥索引
	* @param	priKeyD			[IN]		外部私钥（明文），index为0时有效
	* @param	priKeyDLen		[IN]		priKeyD长度，index为0时有效
	* @param	data			[IN]		需要解密的密文数据
	* @param	dataLen			[IN]		data长度
	* @param	plain			[OUT]		解密出来的明文数据
	* @param	plainLen		[IN|OUT]	输入时：plain大小，输出时：plain长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ECCDecrypt(void* hSessionHandle,
		TA_ECC_CURVE curve,
		TA_ASYMM_USAGE keyUsage,
		unsigned int index,
		const unsigned char* priKeyD, unsigned int priKeyDLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* plain, unsigned int* plainLen);

	/**
	* @brief	ECC解密
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识，目前仅支持TA_SM2
	* @param	priKeyD			[IN]		外部私钥
	* @param	priKeyDLen		[IN]		外部私钥长度
	* @param	data			[IN]		需要解密的密文数据
	* @param	dataLen			[IN]		data长度
	* @param	plain			[OUT]		解密出来的明文数据
	* @param	plainLen		[IN|OUT]	输入时：plain大小，输出时：plain长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ExternalECCDecrypt(void* hSessionHandle, TA_ECC_CURVE curve,
		const unsigned char* priKeyD, unsigned int priKeyDLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* plain, unsigned int* plainLen);

	/**
	* @brief	内部ECC密钥解密
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	curve			[IN]		曲线标识，目前仅支持TA_SM2
	* @param	index			[IN]		密钥索引
	* @param	data			[IN]		数据摘要
	* @param	dataLen			[IN]		data长度
	* @param	plain			[OUT]		明文
	* @param	plainLen		[IN|OUT]	输入时：plain大小，输出时：plain长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 需先获取私钥权限
	*/
	int Tass_InternalECCDecrypt(void* hSessionHandle,
		TA_ECC_CURVE curve,
		unsigned int index,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* plain, unsigned int* plainLen);

	/**
	* @brief	私钥密文运算
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	type					[IN]		非对称密钥类型，TA_RSA/TA_ECC
	* @param	curve					[IN]		曲线标识，type=TA_ECC时有效
	*												目前支持TA_SM2/TA_NID_NISTP256/TA_NID_BRAINPOOLP256R1/TA_NID_FRP256V1
	* @param	usage					[IN]		密钥用途，curve=TA_SM2时有效（仅SM2曲线支持加解密）
	*												TA_SIGN：私钥签名
	*												TA_CIPHER：私钥解密
	* @param	priKeyCipherByLmk		[IN]		私钥密文
	* @param	priKeyCipherByLmkLen	[IN]		priKeyCipherByLmk长度
	* @param	inData					[IN]		输入数据
	* @param	inDataLen				[IN]		inData长度
	*												type=TA_RSA时：数据长度需与模长相同
	*												type=TA_ECC时：
	*													1、curve!=TA_SM2时：输入数据为原文的数据摘要
	*													2、curve=TA_SM2，但usage=TA_SIGN：输入数据为原文的数据摘要
	*													3、curve=TA_SM2，但usage=TA_CIPHER：输入数据为公钥加密的密文
	* @param	outData					[OUT]		输出数据
	* @param	outDataLen				[IN|OUT]	输入时：outData大小，输出时：outData长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_PrivateKeyCipherByLMKOperation(void* hSessionHandle,
		TA_KEY_TYPE type,
		TA_ECC_CURVE curve,
		TA_ASYMM_USAGE usage,
		const unsigned char* priKeyCipherByLmk, unsigned int priKeyCipherByLmkLen,
		const unsigned char* inData, unsigned int inDataLen,
		unsigned char* outData, unsigned int* outDataLen);

	/**
	* @brief	ECIES 加密
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	curve					[IN]		曲线标识，支持TA_NID_NISTP256/TA_NID_SECP256K1/TA_NID_SECP384R1/TA_NID_BRAINPOOLP192R1/TA_NID_BRAINPOOLP256R1/TA_NID_FRP256V1
	* @param	kdf						[IN]		KDF
	* @param	hash					[IN]		哈希，支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	alg						[IN]		加密算法标识,支持TA_DES128/TA_DES192/TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33/TA_SM7/TA_XOR_MK_EK_01/TA_XOR_MK_EK_03/TA_XOR_EK_MK/TA_XOR,（其中SM7依赖硬件，具体根据加密机本身是否支持）
	*												其中alg为TA_XOR_MK_EK_01时：（KDF长度为16+xorlen；先取MK，再取EK，即不向后兼容SCE1 v1.0标准，符合v2.0标准-兼容java BC库；
	*												其中alg为TA_XOR_MK_EK_02时：（KDF长度为 hashlen+xorlen；先取MK，再取EK，即不向后兼容SCE1 v1.0标准，符合v2.0标准）；
	*												其中alg为TA_XOR_EK_MK时：（KDF长度为xorlen*2；先取EK，再取MK，即向后兼容SCE1 v1.0标准，符合v2.0标准）；
	*												其中alg为TA_XOR时与TA_XOR_EK_MK一样；
	* @param	mode					[IN]		加密算法模式，仅当加密算法标识非 99 时存在
	*												支持TA_ECB/TA_CBC/TA_CFB/TA_OFB/TA_CTR
	* @param	index					[IN]		Peer ECC公钥索引号，当为 0 时标识外部密钥;
	* @param	publicKeyECC			[IN]		Peer公钥，仅当公钥索引为 0 时存在
	* @param	publicKeyECCLen			[IN]		Peer公钥长度，仅当公钥索引为 0 时存在
	* @param	privateKeyType			[IN]		Ephemeral 私钥使用类型，目前只能使用0-随机密钥
	* @param	iv						[IN]		初始 IV，当加密算法标识不为 99(XOR)并且加密算法模式 不为 0(ECB)时存在
	* @param	ivLen					[IN]		初始 IV长度，当加密算法标识为 TA_DES128/TA_DES192/TA_SM7时为8，其余为16
	* @param	sharedInfoSeque			[IN]		Shared info 顺序，当KDF算法为 TA_ISO_18033_2_KDF1/TA_ISO_18033_2_KDF2时存在
	*												0 - z |sharedinfo | c
	*												1 - sharedinfo |z | c
	*												备注:当 X9.63KDF 时 拼装顺序为 z | c| sharedinfo
	* @param	sharedInfoS1			[IN]		Shared info（共享加 密信息）S1
	* @param	sharedInfoS1Len			[IN]		Shared info（共享加 密信息）S1长度，长度范围0-128，用于KDF分散密钥 k
	* @param	hmacFlag				[IN]		HMAC 标识，0 - 不计算 HMAC，1 - 计算 HMAC
	* @param	hmacAlg					[IN]		HMAC 算法标识，当 HMAC 标识为 1 时有效
	* @param	sharedInfoS2			[IN]		Shared info( 共 享 HMAC 信息)S2，当 HMAC 标识为 1 时有效
	* @param	sharedInfoS2Len			[IN]		Shared info( 共 享 HMAC 信息)S2 长度，当 HMAC 标识为 1 时有效，
	*												取值 0-128，如果长度大于 0，则对所有密文串联后，右边填充此数据，再计算 HMAC
	* @param	pad						[IN]		PAD 标识，取值范围：00–05
	* @param	plain					[IN]		待加密数据
	* @param	plainLenLen				[IN]		待加密数据长度，数据长度1-4096
	* @param	ephemeralPubKeyR		[OUT]		Ephemeral 公钥R，内部随机产生的公钥，用于 KDF 产生密钥
	* @param	ephemeralPubKeyRLen		[IN|OUT]	Ephemeral 公钥R 长度
	* @param	cipher					[OUT]		加密后的密文
	* @param	cipherLen				[IN|OUT]	加密后的密文长度
	* @param	hmac					[OUT]		hmac，当 HMAC 标识为 1 时存在
	* @param	hmacLen					[IN|OUT]	hmac长度，当 HMAC 标识为 1 时存在
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_EciesEncrypt(void* hSessionHandle,
		TA_ECC_CURVE curve, TA_KDF kdf,
		TA_HASH_ALG hash, TA_SYMM_ALG alg,
		TA_SYMM_MODE mode, unsigned int index,
		unsigned char* publicKeyECC, unsigned int publicKeyECCLen,
		unsigned int privateKeyType,
		unsigned char* iv, unsigned int ivLen,
		unsigned int sharedInfoSeque,
		unsigned char* sharedInfoS1, unsigned int sharedInfoS1Len,
		unsigned int hmacFlag, TA_HMAC_ALG hmacAlg,
		unsigned char* sharedInfoS2, unsigned int sharedInfoS2Len,
		TA_PAD pad,
		unsigned char* plain, unsigned int plainLen,
		unsigned char* ephemeralPubKeyR, unsigned int* ephemeralPubKeyRLen,
		unsigned char* cipher, unsigned int* cipherLen,
		unsigned char* hmac, unsigned int* hmacLen);

	/**
	* @brief	ECIES 解密
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	curve					[IN]		曲线标识，支持TA_NID_NISTP256/TA_NID_SECP256K1/TA_NID_SECP384R1/TA_NID_BRAINPOOLP192R1/TA_NID_BRAINPOOLP256R1/TA_NID_FRP256V1
	* @param	kdf						[IN]		KDF
	* @param	hash					[IN]		哈希算法标识，支持TA_SHA224/TA_SHA256/TA_SHA384/TA_SHA512
	* @param	alg						[IN]		加密算法标识，支持TA_DES128/TA_DES192/TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33/TA_SM7/TA_XOR_MK_EK_01/TA_XOR_MK_EK_03/TA_XOR_EK_MK/TA_XOR,（其中SM7依赖硬件，具体根据加密机本身是否支持）
	*												其中alg为TA_XOR_MK_EK_01时：（KDF长度为16+xorlen；先取MK，再取EK，即不向后兼容SCE1 v1.0标准，符合v2.0标准-兼容java BC库；
	*												其中alg为TA_XOR_MK_EK_02时：（KDF长度为 hashlen+xorlen；先取MK，再取EK，即不向后兼容SCE1 v1.0标准，符合v2.0标准）；
	*												其中alg为TA_XOR_EK_MK时：（KDF长度为xorlen*2；先取EK，再取MK，即向后兼容SCE1 v1.0标准，符合v2.0标准）；
	*												其中alg为TA_XOR时与TA_XOR_EK_MK一样；
	* @param	mode					[IN]		加密算法模式，仅当加密算法标识非 99 时存在
	*												支持TA_ECB/TA_CBC/TA_CFB/TA_OFB/TA_CTR
	* @param	index					[IN]		Ephemeral ECC公钥索引号，当为 0 时，使用外部密钥
	* @param	publicKeyECC			[IN]		Ephemeral公钥，仅当公钥索引为 0 时存在
	* @param	publicKeyECCLen			[IN]		Ephemeral公钥长度，仅当公钥索引为 0 时存在
	* @param	privateKeyIndex			[IN]		己方 ECC 私钥索 引号，当为 0 时，使用外部密钥
	* @param	privateKeyFlag			[IN]		己方私钥标识，仅当己方 ECC 私钥索引为 0 时存在，1-明文密钥，2-LMK加密的私钥;
	* @param	privateKeyECC			[IN]		己方私钥，仅当己方 ECC 私钥索引为 0 时存在，当己方私钥标识为 1 时为明文密钥，当己方私钥标识为 2 时为 LMK 加密的己方私钥;
	* @param	privateKeyECCLen		[IN]		己方私钥长度，仅当己方 ECC 私钥索引为 0 时存在，当己方私钥标识为 1 时为明文密钥，当己方私钥标识为 2 时为 LMK 加密的己方私钥;
	* @param	iv						[IN]		初始 IV，当加密算法标识不为 99(XOR)并且加密算法模式 不为 0(ECB)时存在，
	* @param	ivLen					[IN]		初始 IV长度，当加密算法标识为 TA_DES128/TA_DES192/TA_SM7时为8，其余为16
	* @param	sharedInfoSeque			[IN]		Shared info 顺序，当KDF算法为 TA_ISO_18033_2_KDF1/TA_ISO_18033_2_KDF2时存在
	*												0 - z |sharedinfo | c
	*												1 - sharedinfo |z | c
	*												备注:当 X9.63KDF 时 拼装顺序为 z | c| sharedinfo
	* @param	sharedInfoS1			[IN]		Shared info（共享加 密信息）S1
	* @param	sharedInfoS1Len			[IN]		Shared info（共享加 密信息）S1长度，长度范围0-128，用于KDF分散密钥 k
	* @param	hmacFlag				[IN]		HMAC 验证标识，0 - 不验证 HMAC，1 - 验证 HMAC
	* @param	hmacAlg					[IN]		HMAC 算法标识，当 HMAC 标识为 1 时有效
	* @param	sharedInfoS2			[IN]		Shared info( 共 享 HMAC 信息)S2，当 HMAC 标识为 1 时有效
	* @param	sharedInfoS2Len			[IN]		Shared info( 共 享 HMAC 信息)S2 长度，当 HMAC 标识为 1 时有效，
	*												取值 0-128，如果长度大于 0，则对所有密文串联后，右边填充此数据，再计算 HMAC
	* @param	hmac					[IN]		hmac，当 HMAC 验证标识 hmacFlag=1 时存在
	* @param	hmacLen					[IN]		hmac长度，当 HMAC 验证标识 hmacFlag=1 时存在，长度为0时不做验证
	* @param	pad						[IN]		PAD 标识，取值范围：00–05
	* @param	cipher					[IN]		待解密的密文
	* @param	cipherLen				[IN]		待解密的密文长度，字节数1-4096+16
	* @param	plain					[OUT]		明文数据
	* @param	plainLenLen				[IN|OUT]	明文数据长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note
	*/
	int Tass_EciesDecrypt(void* hSessionHandle,
		TA_ECC_CURVE curve, TA_KDF kdf,
		TA_HASH_ALG hash, TA_SYMM_ALG alg,
		TA_SYMM_MODE mode, unsigned int publicKeyIndex,
		unsigned char* publicKeyECC, unsigned int publicKeyECCLen,
		unsigned int privateKeyIndex, unsigned int privateKeyFlag,
		unsigned char* privateKeyECC, unsigned int privateKeyECCLen,
		unsigned char* iv, unsigned int ivLen,
		unsigned int sharedInfoSeque,
		unsigned char* sharedInfoS1, unsigned int sharedInfoS1Len,
		unsigned int hmacFlag, TA_HMAC_ALG hmacAlg,
		unsigned char* sharedInfoS2, unsigned int sharedInfoS2Len,
		unsigned char* hmac, unsigned int hmacLen,
		TA_PAD pad,
		unsigned char* cipher, unsigned int cipherLen,
		unsigned char* plain, unsigned int* plainLen);

	/**
	* @brief	ECC/SM2 密钥协商
	* @param	hSessionHandle		[IN]	与设备建立的会话句柄
	* @param	curve				[IN]	曲线标识
	* @param	ecdhAlg				[IN]	协商算法
	* @param	selfIndex			[IN]	密钥索引,0-代表私钥使用外送的
	* @param	selfPriKeyD			[IN]	私钥,仅当密钥索引为 0 时有效
	* @param	selfPriKeyDLen		[IN]	私钥长度,仅当密钥索引为 0 时有效,
	*										内部按照曲线标识对比私钥 D 长度，当长度相符时默认此域为私钥明文 D 长度;
	*										当长度不符时，默认此域为私钥密文长度（私钥密文会有填充）
	* @param	peerPubKeyX			[IN]	公钥X数据
	* @param	peerPubKeyXLen		[IN]	公钥X长度
	* @param	peerPubKeyY			[IN]	公钥Y数据
	* @param	peerPubKeyYLen		[IN]	公钥Y长度
	* @param	sessionKeyPlain		[OUT]	会话密钥
	* @param	sessionKeyPlainLen	[OUT]	会话密钥长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 使用的公私钥非一对,如果使用对方公钥，需使用己方私钥.
	*/
	int Tass_ECDHKeyAgree(void* hSessionHandle,
		TA_ECC_CURVE curve,
		TA_ECDH_ALG ecdhAlg,
		unsigned int selfIndex,
		unsigned char* selfPriKeyD, unsigned int selfPriKeyDLen,
		unsigned char* peerPubKeyX, unsigned int peerPubKeyXLen,
		unsigned char* peerPubKeyY, unsigned int peerPubKeyYLen,
		unsigned char* sessionKeyPlain, unsigned int* sessionKeyPlainLen);

	/**
	* @brief	ECC/SM2 密钥协商。推荐使用Tass_ECDHKeyAgree
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	curve				[IN]		曲线标识
	* @param	agreeAlg			[IN]		协商算法
	* @param	index				[IN]		密钥索引,0-代表私钥使用外送的
	* @param	priKeyD				[IN]		私钥,仅当密钥索引为 0 时有效
	* @param	priKeyDLen			[IN]		私钥长度,仅当密钥索引为 0 时有效,
	*											内部按照曲线标识对比私钥 D 长度，当长度相符时默认此域为私钥明文 D 长度;
	*											当长度不符时，默认此域为私钥密文长度（私钥密文会有填充）
	* @param	pubKeyX				[IN]		公钥X数据
	* @param	pubKeyXLen			[IN]		公钥X长度
	* @param	pubKeyY				[IN]		公钥Y数据
	* @param	pubKeyYLen			[IN]		公钥Y长度
	* @param	sessionKey			[OUT]		会话密钥
	* @param	sessionKeyYLen		[OUT]		会话密钥长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note 使用的公私钥非一对,如果使用对方公钥，需使用己方私钥.
	*/
	int Tass_AgreementDataAndKeyWithECC(void* hSessionHandle,
		TA_ECC_CURVE curve,
		TA_AGREE_ALG agreeAlg,
		unsigned int index,
		unsigned char* priKeyD, unsigned int priKeyDLen,
		unsigned char* pubKeyX, unsigned int pubKeyXLen,
		unsigned char* pubKeyY, unsigned int pubKeyYLen,
		unsigned char* sessionKey, unsigned int* sessionKeyLen);

	/***************************************************************************
	* 密钥运算--对称密钥运算
	*	Tass_SymmKeyOperation
	*	Tass_CalculateMAC
	*	Tass_SymmKeyGCMOperation
	*	Tass_SymmKeyGCMOperationInit
	*	Tass_SymmKeyGCMOperationUpdate
	*	Tass_SymmKeyGCMOperationFinal
	*	Tass_SymmKeyCCMOperation
	*	Tass_SymmKeyCCMOperationInit
	*	Tass_SymmKeyCCMOperationUpdate
	*	Tass_SymmKeyCCMOperationFinal
	*	Tass_BatchEncrypt
	*	Tass_BatchDecrypt
	*	Tass_MultiDataEncrypt
	*	Tass_MultiDataDecrypt
	****************************************************************************/

	/**
	* @brief	对称密钥运算（加/解密）
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	op				[IN]	加密或解密
	* @param	mode			[IN]	加/解密模式
	*									支持TA_ECB/TA_CBC/TA_CFB/TA_OFB/TA_STREAM/TA_EEA3/TA_CTR
	* @param	inIv			[IN]	输入IV，mode不是TA_ECB时有效，des算法时为8字节，其他算法16字节
	* @param	index			[IN]	索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]	密钥，index为0时有效
	* @param	keyLen			[IN]	密钥长度，index为0时有效
	* @param	alg				[IN]	算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	* @param	inData			[IN]	输入数据
	* @param	dataLen			[IN]	数据长度，必须为分组长度的整数倍，最大8192字节
	* @param	outData			[OUT]	输出数据，长度与dataLen相同
	* @param	outIv			[OUT]	输出IV，mode不是ecb或stream时有效，长度与inIv相同，传入NULL时不输出IV
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyOperation(void* hSessionHandle,
		TA_SYMM_OP op,
		TA_SYMM_MODE mode,
		const unsigned char* inIv,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* inData, unsigned int dataLen,
		unsigned char* outData,
		unsigned char* outIv);

	/**
	* @brief	对称密钥运算（加/解密），带IV长度
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	op				[IN]	加密或解密
	* @param	mode			[IN]	加/解密模式
	*									支持TA_ECB/TA_CBC/TA_CFB/TA_OFB/TA_STREAM/TA_EEA3/TA_CTR/TA_XTS
	* @param	inIv			[IN]	输入IV，mode不是TA_ECB时有效，
	* @param	inIvLen			[IN]	inIv长度，mode=TA_XTS时，取值1~16字节
	* @param	index			[IN]	索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]	密钥，index为0时有效
	* @param	keyLen			[IN]	密钥长度，index为0时有效
	* @param	alg				[IN]	算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	* @param	inData			[IN]	输入数据
	* @param	dataLen			[IN]	数据长度，必须为分组长度的整数倍，最大8192字节
	* @param	outData			[OUT]	输出数据，长度与dataLen相同
	* @param	outIv			[OUT]	输出IV，mode不是ecb或stream时有效，长度与inIv相同，传入NULL时不输出IV
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyOperationWithIVLen(void* hSessionHandle,
		TA_SYMM_OP op,
		TA_SYMM_MODE mode,
		const unsigned char* inIv, unsigned int inIvLen,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* inData, unsigned int dataLen,
		unsigned char* outData,
		unsigned char* outIv);

	/**
	* @brief	对称密钥计算MAC
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	mode			[IN]		计算MAC模式
	* @param	iv				[IN]		IV
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]		密钥，index为0时有效
	* @param	keyLen			[IN]		密钥长度，index为0时有效
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		data长度，必须为分组长度的整数倍，最大8192字节
	* @param	mac				[OUT]		MAC
	* @param	macLen			[IN|OUT]	输入时：mac大小，输出时：mac长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CalculateMAC(void* hSessionHandle,
		TA_SYMM_MAC_MODE mode,
		const unsigned char* iv,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* mac,
		unsigned int* macLen);

	/**
	* @brief	对称密钥GCM模式运算（加/解密）
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]		密钥，index为0时有效
	* @param	keyLen			[IN]		密钥长度，index为0时有效
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	*										目前支持TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33
	* @param	inData			[IN]		输入数据
	* @param	inDataLen		[IN]		inData长度，最大8192
	* @param	iv				[IN]		IV
	* @param	ivLen			[IN]		iv长度
	* @param	authData		[IN]		认证数据
	* @param	authDataLen		[IN]		authData长度
	* @param	tags			[IN|OUT]	tags
	*										op为TA_ENC时为输出
	*										op为TA_DEC时为输入
	* @param	tagsLen			[IN|OUT]	op为TA_ENC时：输入时：tags大小，输出时：tags长度
	*										op为TA_DEC时：输入，tags长度
	* @param	outData			[OUT]		输出数据
	* @param	outDataLen		[IN|OUT]	输入时：outData大小，输出时：outData长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyGCMOperation(void* hSessionHandle,
		TA_SYMM_OP op,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* inData, unsigned int inDataLen,
		const unsigned char* iv, unsigned int ivLen,
		const unsigned char* authData, unsigned int authDataLen,
		unsigned char* tags, unsigned int* tagsLen,
		unsigned char* outData, unsigned int* outDataLen);

	/**
	* @brief	对称密钥GCM模式运算（加/解密）初始化
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		密钥是否为明文，index=0时有效
	* @param	key				[IN]		密钥，，index=0时有效
	* @param	keyLen			[IN]		密钥长度，，index=0时有效
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	*										目前支持TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33
	* @param	iv				[IN]		IV
	* @param	ivLen			[IN]		iv长度
	* @param	authData		[IN]		认证数据
	* @param	authDataLen		[IN]		authData长度
	* @param	ctx				[OUT]		输出数据
	* @param	ctxLen			[IN|OUT]	输入时：ctx大小，输出时：ctx长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyGCMOperationInit(void* hSessionHandle,
		TA_SYMM_OP op,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* iv, unsigned int ivLen,
		const unsigned char* authData, unsigned int authDataLen,
		unsigned char* ctx, unsigned int* ctxLen);

	/**
	* @brief	对称密钥GCM模式运算（加/解密）更新
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	*										目前支持TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33
	* @param	inData			[IN]		输入数据
	* @param	inDataLen		[IN]		inData长度
	* @param	inCtx			[IN]		输入上下文
	* @param	inCtxLen		[IN]		inCtx长度
	* @param	outData			[OUT]		输出数据
	* @param	outDataLen		[IN|OUT]	输入时：outData大小，输出时：outData长度
	* @param	outCtx			[OUT]		输出上下文
	* @param	outCtxLen		[IN|OUT]	输入时：outCtx大小，输出时：outCtx长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyGCMOperationUpdate(void* hSessionHandle,
		TA_SYMM_OP op,
		TA_SYMM_ALG alg,
		const unsigned char* inData, unsigned int inDataLen,
		const unsigned char* inCtx, unsigned int inCtxLen,
		unsigned char* outData, unsigned int* outDataLen,
		unsigned char* outCtx, unsigned int* outCtxLen);
	/**
	* @brief	对称密钥GCM模式运算（加/解密）结束
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	*										目前支持TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33
	* @param	ctx				[IN]		上下文
	* @param	ctxLen			[IN]		ctx长度
	* @param	tags			[IN|OUT]	tags
	*										op为TA_ENC时为输出
	*										op为TA_DEC时为输入
	* @param	tagsLen			[IN|OUT]	op为TA_ENC时：输入时：tags大小，输出时：tags长度
	*										op为TA_DEC时：输如，tags长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyGCMOperationFinal(void* hSessionHandle,
		TA_SYMM_OP op,
		TA_SYMM_ALG alg,
		const unsigned char* ctx, unsigned int ctxLen,
		unsigned char* tags, unsigned int* tagsLen);

	/**
	* @brief	对称密钥CCM模式运算（加/解密）
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		密钥是否为明文，index=0时有效
	* @param	key				[IN]		密钥，index=0时有效
	* @param	keyLen			[IN]		密钥长度，index=0时有效
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	*										目前支持TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33
	* @param	inData			[IN]		输入数据
	* @param	inDataLen		[IN]		inData长度，最大8192
	* @param	nonce			[IN]		nonce
	* @param	nonceLen		[IN]		nonce长度，取值7-13
	* @param	authData		[IN]		认证数据
	* @param	authDataLen		[IN]		authData长度
	* @param	tags			[IN|OUT]	tags
	*										op为TA_ENC时为输出，长度由tagsLen确定
	*										op为TA_DEC时为输入
	* @param	tagsLen			[IN]		tags长度
	* @param	outData			[OUT]		输出数据
	* @param	outDataLen		[IN|OUT]	输入时：outData大小，输出时：outData长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyCCMOperation(void* hSessionHandle,
		TA_SYMM_OP op,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* inData, unsigned int inDataLen,
		const unsigned char* nonce, unsigned int nonceLen,
		const unsigned char* authData, unsigned int authDataLen,
		unsigned char* tags, unsigned int tagsLen,
		unsigned char* outData, unsigned int* outDataLen);

	/**
	* @brief	对称密钥CCM模式运算（加/解密）初始化
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		密钥是否为明文，index=0时有效
	* @param	key				[IN]		密钥，index为0时有效
	* @param	keyLen			[IN]		密钥长度，index为0时有效
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	*										目前支持TA_AES128/TA_AES192/TA_AES256/TA_SM1/TA_SM4/TA_SSF33
	* @param	nonce			[IN]		nonce
	* @param	nonceLen		[IN]		nonce长度，取值7-13
	* @param	authData		[IN]		认证数据
	* @param	authDataLen		[IN]		authData长度
	* @param	tagsLen			[IN]		tags长度
	* @param	dataLen			[IN]		数据总长度
	* @param	ctx				[OUT]		上下文
	* @param	ctxLen			[IN|OUT]	输入时：ctx大小，输出时：ctx长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyCCMOperationInit(void* hSessionHandle,
		TA_SYMM_OP op,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* nonce, unsigned int nonceLen,
		const unsigned char* authData, unsigned int authDataLen,
		unsigned int tagsLen,
		unsigned int dataLen,
		unsigned char* ctx, unsigned int* ctxLen);

	/**
	* @brief	对称密钥CCM模式运算（加/解密）更新
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	inCtx			[IN]		输入上下文
	* @param	inCtxLen		[IN]		inCtx长度
	* @param	inData			[IN]		输入数据
	* @param	inDataLen		[IN]		inData长度,最大4096字节
	* @param	outCtx			[OUT]		输出上下文
	* @param	outCtxLen		[IN|OUT]	输入时：outCtx大小，输出时：outCtx长度
	* @param	outData			[OUT]		输出数据
	* @param	outDataLen		[IN|OUT]	输入时：outData大小，输出时：outData长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyCCMOperationUpdate(void* hSessionHandle,
		TA_SYMM_OP op,
		const unsigned char* inCtx, unsigned int inCtxLen,
		const unsigned char* inData, unsigned int inDataLen,
		unsigned char* outCtx, unsigned int* outCtxLen,
		unsigned char* outData, unsigned int* outDataLen);

	/**
	* @brief	对称密钥CCM模式运算（加/解密）结束
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	op				[IN]		加密或解密
	* @param	ctx				[IN]		上下文
	* @param	ctxLen			[IN]		ctx长度
	* @param	tags			[IN|OUT]	TAG
	*										op为TA_ENC时为输出
	*										op为TA_DEC时为输入
	* @param	tagsLen			[IN|OUT]	op为TA_ENC时：输入时：tags大小，输出时：tag长度
	*										op为TA_DEC时：输入，tags长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_SymmKeyCCMOperationFinal(void* hSessionHandle,
		TA_SYMM_OP op,
		const unsigned char* ctx, unsigned int ctxLen,
		unsigned char* tags, unsigned int* tagsLen);

	/**
	* @brief	使用指定的密钥对数据进行对称加密运算
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	index				[IN]		索引
	* @param	key					[IN]		对称密钥，index = 0时有效
	* @param	keyLen				[IN]		对称密钥长度，index = 0时有效
	* @param	uiAlgID				[IN]		算法标识，指定的对称加密算法
	* @param	pucIV				[IN/OUT]	缓冲区指针，用于存放输入和返回的IV数据
	* @param	infoNum				[IN]		结构体的个数
	* @param	inInfo				[IN]		输入的结构体数组明文
	* @param	outInfo				[OUT]		输出的结构体数组密文
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_BatchEncrypt(
		void* hSessionHandle,
		unsigned int index,
		const unsigned char* key,
		unsigned int keyLen,
		unsigned int uiAlgID,
		unsigned char* pucIV,
		unsigned int infoNum,
		const UserInfo* inInfo,
		UserInfo* outInfo);

	/**
	* @brief	使用指定的密钥对数据进行对称解密运算
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	index				[IN]		索引
	* @param	key					[IN]		对称密钥，index = 0时有效
	* @param	keyLen				[IN]		对称密钥长度，index = 0时有效
	* @param	uiAlgID				[IN]		算法标识，指定的对称加密算法
	* @param	pucIV				[IN]		缓冲区指针，用于存放输入的IV数据
	* @param	infoNum				[IN]		结构体的个数
	* @param	inInfo				[IN]		输入的结构体数组密文
	* @param	outInfo				[OUT]		输出的结构体数组明文
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_BatchDecrypt(
		void* hSessionHandle,
		unsigned int index,
		const unsigned char* key,
		unsigned int keyLen,
		unsigned int uiAlgID,
		unsigned char* pucIV,
		unsigned int infoNum,
		const UserInfo* inInfo,
		UserInfo* outInfo);

	/**
		* @brief	使用指定的密钥加密多包数据
		*
		* @param	hSessionHandle		[IN]		与设备建立的会话句柄
		* @param	index				[IN]		索引
		* @param	key					[IN]		对称密钥，index = 0时有效
		* @param	keyLen				[IN]		对称密钥长度，index = 0时有效
		* @param	uiAlgID				[IN]		算法标识，指定的对称加密算法
		*												仅支持ECB模式
		* @param	dataCnt				[IN]		数据条数
		* @param	plainData			[IN]		输入明文数据数组
		*												plainData.data：单条明文数据
		*												plainData.dataLen：单条明文数据长度
		* @param	cipherData			[OUT]		输出密文数据数组，应用应保证缓冲区不会溢出
		* 												cipherData.data：单条密文数据，HEX字符串编码，最后以'\0'结尾
		*												cipherData.dataLen：单条密文数据长度，不包含最后的'\0'
		* @return
		*   @retval	0		成功
		*   @retval	非0		失败，返回错误代码
		*/
	int Tass_MultiDataEncrypt(void* hSessionHandle,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		unsigned int uiAlgID,
		unsigned int dataCnt,
		const TassData* plainData,
		TassData* cipherData);

	/**
	* @brief	使用指定的密钥解密多包数据
	*
	* @param	hSessionHandle		[IN]		与设备建立的会话句柄
	* @param	index				[IN]		索引
	* @param	key					[IN]		对称密钥，index = 0时有效
	* @param	keyLen				[IN]		对称密钥长度，index = 0时有效
	* @param	uiAlgID				[IN]		算法标识，指定的对称加密算法
	*												仅支持ECB模式
	* @param	dataCnt				[IN]		数据条数
	* @param	cipherData			[IN]		密文数据数组
	*												cipherData.data：单条密文数据
	*												cipherData.dataLen：单条密文数据长度
	* @param	plainData			[OUT]		明文数据数组，应用应保证缓冲区不会溢出
	* 												plainData.data：单条明文数据
	*												plainData.dataLen：单条明文数据长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_MultiDataDecrypt(void* hSessionHandle,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		unsigned int uiAlgID,
		unsigned int dataCnt,
		const TassData* cipherData,
		TassData* plainData);

	/***************************************************************************
	* 摘要运算
	*	Tass_HashInit
	*	Tass_HashUpdate
	*	Tass_HashFinal
	*	Tass_MultiHash
	*	Tass_CMACSingle
	*	Tass_CMAC
	*	Tass_HMAC
	*	Tass_CalculateHmac
	*	Tass_PlainKeyCalculateHmac
	****************************************************************************/

	/**
	* @brief	摘要初始化
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	alg				[IN]		摘要算法，不能使用TA_NOHASH
	* @param	pubKeyX			[IN]		公钥X，alg为TA_SM3时有效
	* @param	pubKeyXLen		[IN]		pubKeyX长度，alg为TA_SM3时有效
	* @param	pubKeyY			[IN]		公钥Y，alg为TA_SM3时有效
	* @param	pubKeyYLen		[IN]		pubKeyY长度，alg为TA_SM3时有效
	* @param	userId			[IN]		用户ID，alg为TA_SM3时有效
	* @param	userIdLen		[IN]		userId长度，alg为TA_SM3时有效
	* @param	ctx				[OUT]		摘要上下文
	* @param	ctxLen			[IN|OUT]	输入时：ctx大小，输出时：ctx长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note pubKeyXLen、pubKeyYLen和userIdLen均为0时，则进行不带ID的SM3运算
	*       当进行带ID的SM3运算时，若userIdLen为0，则使用默认ID即，“1234567812345678”
	*/
	int Tass_HashInit(void* hSessionHandle,
		TA_HASH_ALG alg,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		const unsigned char* userId, unsigned int userIdLen,
		unsigned char* ctx, unsigned int* ctxLen);

	/**
	* @brief	摘要更新
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	inCtx			[IN]		输入摘要上下文
	* @param	inCtxLen		[IN]		inCtx长度
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		data长度，最大8192字节
	* @param	outCtx			[OUT]		输出摘要上下文
	* @param	outCtxLen		[IN|OUT]	输入时：outCtx大小，输出时：outCtx长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_HashUpdate(void* hSessionHandle,
		const unsigned char* inCtx, unsigned int inCtxLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* outCtx, unsigned int* outCtxLen);

	/**
	* @brief	摘要结束
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	ctx				[IN]		摘要上下文
	* @param	ctxLen			[IN]		ctx长度
	* @param	hash			[OUT]		摘要结果
	* @param	hashLen			[IN|OUT]	输入时：hash大小，输出时：hash长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_HashFinal(void* hSessionHandle,
		const unsigned char* ctx, unsigned int ctxLen,
		unsigned char* hash, unsigned int* hashLen);

	/**
	* @brief	多包数据摘要
	*
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	alg				[IN]		摘要算法，不能使用TA_NOHASH
	* @param	pubKeyX			[IN]		公钥X，alg为TA_SM3时有效
	* @param	pubKeyXLen		[IN]		pubKeyX长度，alg为TA_SM3时有效
	* @param	pubKeyY			[IN]		公钥Y，alg为TA_SM3时有效
	* @param	pubKeyYLen		[IN]		pubKeyY长度，alg为TA_SM3时有效
	* @param	userId			[IN]		用户ID，alg为TA_SM3时有效
	* @param	userIdLen		[IN]		userId长度，alg为TA_SM3时有效
	* @param	dataCnt			[IN]		数据条数
	* @param	datas			[IN]		数据
	* @param	dataLens		[IN]		数据长度,1~64字节
	* @param	hashs			[OUT]		摘要结果
	* @param	hashLen			[IN|OUT]	输入时：单个hash大小，输出时：单个hash长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	* @note pubKeyXLen、pubKeyYLen和userIdLen均为0时，则进行不带ID的SM3运算
	*       当进行带ID的SM3运算时，若userIdLen为0，则使用默认ID即，“1234567812345678”
	*/
	int Tass_MultiHash(void* hSessionHandle,
		TA_HASH_ALG alg,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		const unsigned char* userId, unsigned int userIdLen,
		unsigned char dataCnt,
		const unsigned char* datas[], unsigned int dataLens[],
		unsigned char* hashs[], unsigned int* hashLen);

	/**
	* @brief	对称密钥 CMAC 运算，单包模式，最大长度8192
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	symmAlg			[IN]		对称密钥算法
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key				[IN]		密文对称密钥，index为0时有效
	* @param	keyLen			[IN]		密文对称密钥长度，index为0时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		数据长度
	* @param	cmac			[OUT]		CMAC
	* @param	cmacLen			[OUT]		HMAC长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CMACSingle(void* hSessionHandle,
		TA_SYMM_ALG symmAlg,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* cmac, unsigned int* cmacLen);

	/**
	* @brief	对称密钥 CMAC 运算，支持多包，单包最大8192字节
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	blockType		[IN]		数据块类型
	* @param	hmacAlg			[IN]		HMAC算法，目前支持TA_HMAC_SHA224/TA_HMAC_SHA256/TA_HMAC_SHA384/TA_HMAC_SHA512/TA_HMAC_SM3
	*														  TA_HMAC_SHA3_224/TA_HMAC_SHA3_256/TA_HMAC_SHA3_384/TA_HMAC_SHA3_512
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key				[IN]		密文对称密钥，index为0时有效
	* @param	keyLen			[IN]		密文对称密钥长度，index为0时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		数据长度
	* @param	ctx				[IN|OUT]	上下文
	* @param	ctxLen			[IN|OUT]	ctx长度(首包时长度为0)
	* @param	hmac			[OUT]		HMAC，blockType=TA_DB_LAST时有效
	* @param	hmacLen			[OUT]		HMAC长度，blockType=TA_DB_LAST时有效
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CMAC(void* hSessionHandle,
		TA_DATA_BLOCK_TYPE blockType,
		TA_SYMM_ALG symmAlg,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* ctx, unsigned int* ctxLen,
		unsigned char* cmac, unsigned int* cmacLen);

	/**
	* @brief	对称密钥 HMAC 运算，支持多包，单包最大8192字节
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	hmacAlg			[IN]		HMAC算法，目前支持TA_HMAC_SHA224/TA_HMAC_SHA256/TA_HMAC_SHA384/TA_HMAC_SHA512/TA_HMAC_SM3
	*														  TA_HMAC_SHA3_224/TA_HMAC_SHA3_256/TA_HMAC_SHA3_384/TA_HMAC_SHA3_512
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key				[IN]		密文对称密钥，index为0时有效
	* @param	keyLen			[IN]		密文对称密钥长度，index为0时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		数据长度
	* @param	ctx				[IN|OUT]	上下文
	* @param	ctxLen			[IN|OUT]	ctx长度(首包时长度为0)
	* @param	hmac			[OUT]		HMAC
	* @param	hmacLen			[OUT]		HMAC长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_HMAC(void* hSessionHandle,
		TA_HMAC_ALG hmacAlg,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* ctx, unsigned int* ctxLen,
		unsigned char* hmac, unsigned int* hmacLen);

	/**
	* @brief	对称密钥 HMAC 运算，内部分包，不限制数据长度
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	hmacAlg			[IN]		HMAC算法，目前支持TA_HMAC_SHA224/TA_HMAC_SHA256/TA_HMAC_SHA384/TA_HMAC_SHA512/TA_HMAC_SM3
	*														  TA_HMAC_SHA3_224/TA_HMAC_SHA3_256/TA_HMAC_SHA3_384/TA_HMAC_SHA3_512
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]		密文对称密钥，index为0时有效
	* @param	keyLen			[IN]		密文对称密钥长度，index为0时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		数据长度
	* @param	hmac			[OUT]		HMAC
	* @param	hmacLen			[OUT]		HMAC长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CalculateHmac(void* hSessionHandle,
		TA_HMAC_ALG hmacAlg,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* hmac, unsigned int* hmacLen);

	/**
	* @brief	对称明文密钥 HMAC 运算，内部分包，不限制数据长度
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	hmacAlg			[IN]		HMAC算法，目前支持TA_HMAC_SHA224/TA_HMAC_SHA256/TA_HMAC_SHA384/TA_HMAC_SHA512
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	key				[IN]		明文对称密钥，index为0时有效
	* @param	keyLen			[IN]		明文对称密钥长度，index为0时有效
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		数据长度
	* @param	hmac			[IN]		HMAC
	* @param	hmacLen			[IN]		HMAC长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_PlainKeyCalculateHmac(void* hSessionHandle,
		TA_HMAC_ALG hmacAlg,
		unsigned int index,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* hmac, unsigned int* hmacLen);

	/***************************************************************************
	* 文件操作
	*	Tass_CreateFile
	*	Tass_ReadFile
	*	Tass_WriteFile
	*	Tass_DeleteFile
	****************************************************************************/

	/**
	* @brief	创建文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	* @param	size			[IN]		文件大小，最大8192字节
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CreateFile(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen,
		unsigned int size);

	/**
	* @brief	读文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	* @param	offset			[IN]		偏移
	* @param	length			[IN]		读取长度
	* @param	data			[OUT]		读取到的数据，最大4096字节
	* @param	dataLen			[IN|OUT]	输入时：data大小，输出时：data长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ReadFile(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen,
		unsigned int offset,
		unsigned int length,
		unsigned char* data, unsigned int* dataLen);

	/**
	* @brief	写文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	* @param	offset			[IN]		偏移
	* @param	data			[IN]		写入的数据，最大4096字节
	* @param	dataLen			[IN]		data长度
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_WriteFile(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen,
		unsigned int offset,
		const unsigned char* data, unsigned int dataLen);

	/**
	* @brief	删除文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_DeleteFile(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen);

	/**
	* @brief	 sp800-108密钥派生接口
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	symmAlg			[IN]		对称密钥算法(目前支持AES128算法)
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plainKey		[IN]		外部输入密钥类型，仅密钥索引为 0 时有效，取值TA_TRUE-明文密钥
	* @param	key				[IN]		密文对称密钥，index为0时有效
	* @param	keyLen			[IN]		密文对称密钥长度，index为0时有效
	* @param    label           [IN]        标签，比特串，比如可表示KDF的用途。
	* @param    labelLen        [IN]        标签长度
	* @param	context			[IN]		上下文
	* @param	contextLen		[IN]		上下文长度
	* @param	derivedKey		[OUT]		派生密钥
	* @param	derivedKeyLen	[OUT]		派生密钥长度
	* @return
	*
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_PRKDF_CMAC(void* hSessionHandle,
		TA_SYMM_ALG symmAlg,
		unsigned int index,
		TA_BOOL plainKey,
		const unsigned char* key, unsigned int keyLen,
		const unsigned char* label, unsigned int labelLen,
		const unsigned char* context, unsigned int contextLen,
		unsigned char* derivedKey, unsigned int* derivedKeyLen);
	/**
	* @brief	导出多条密钥
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	proKeyCipher				[IN]		保护密钥密文
	* @param	proKeyCipherLen				[IN]		proKeyCipher长度
	* @param	keyType						[IN]		加密保护密钥的密钥类型，TA_RSA或TA_ECC
	* @param	curve						[IN]		ECC曲线，keyType=TA_ECC是有效，仅支持TA_SM2
	* @param	index						[IN]	    加密保护密钥的索引
	* @param	keyCipherByLmk				[IN]		加密保护密钥的LMK密钥密文,index=0是有效
	* @param    keyCipherByLmkLen			[IN]        keyCipherByLmk长度,index=0是有效
	* @param    expKeyType					[IN]        导出密钥类型，仅支持TA_SYMM
	* @param    expKeyCnt					[IN]        导出密钥数量
	* @param    expKeyIdxs					[IN]        导出密钥索引
	* @param	pad							[IN]	    填充模式
	* @param	proSymmAlg					[IN]		保护密钥的算法
	* @param	mode      					[IN]		加密模式,TA_ECB/TA_CBC
	* @param	iv      					[IN]		IV, mode!=TA_ECB时有效
	* @param    ivLen						[IN]        iv长度
	* @param	expKeyAlgs    				[IN]		密钥算法类型，导出对称密钥时参见TA_SYMM_ALG
	* @param	expKeyCipherByProKey		[OUT]		保护密钥加密的导出密钥密文
	* @param	expKeyCipherByProKeyLen		[OUT]		expKeyCipherByProKey长度
	* @return
	*
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ExportMultiKeys(void* hSessionHandle,
		const unsigned char* proKeyCipher, unsigned int proKeyCipherLen,
		TA_KEY_TYPE keyType, TA_ECC_CURVE curve,
		unsigned int index,
		const unsigned char* keyCipherByLmk, unsigned int keyCipherByLmkLen,
		TA_KEY_TYPE expKeyType,
		unsigned int expKeyCnt,
		unsigned int expKeyIdxs[],
		TA_PAD pad,
		TA_SYMM_ALG proSymmAlg,
		TA_SYMM_MODE mode,
		const unsigned char* iv, unsigned int ivLen,
		unsigned int expKeyAlgs[],
		unsigned char* expKeyCipherByProKey, unsigned int* expKeyCipherByProKeyLen);



	/**
* @brief    产生/装载 系统签名/加密主密钥
*
* @param    hSessionHandle			[in]    初始化获得的句柄
* @param    sysIndex				[in]    系统密钥索引号：0001–1024/K+3B(0x000001-0xFFFFFF); 0为不存储
* @param    keyType					[in]	1 – 签名主密钥; 2 – 加密主密钥; 3 – 签名主密钥和加密主密钥; 固定为 3;
* @param    sysKeyBits				[in]    系统秘钥模长 固定为 256 bit
* @param    storeLabel				[in]    用于在密钥内部存储时标记密钥的标签说明，0-16 个 ASCII 字符;
* @param    sysSignPubKey			[out]   系统签名公钥
* @param    sysSignPubKeyLen		[out]   系统签名公钥长度
* @param    sysEncPubKey			[out]   系统加密公钥
* @param    sysEncPubKeyLen			[out]   系统加密公钥长度
* @param    signPriKeyByLmk			[out]   系统签名私钥
* @param    signPriKeyByLmkLen		[out]   系统签名私钥长度
* @param    encPriKeyByLmk			[out]   系统加密私钥
* @param    encPriKeyByLmkLen		[out]   系统加密私钥长度
*
* @return
* @retval	0		成功
* @retval	其他	失败
*/
	int Tass_M0_GenerateSystemMasterKey(void* hSessionHandle, unsigned int sysIndex, 
		TA_ASYM_USAGE keyType, unsigned int sysKeyBits,const char* storeLabel, unsigned int storeLabelLen,
		unsigned char* sysSignPubKey, unsigned int* sysSignPubKeyLen, 
		unsigned char* sysEncPubKey, unsigned int* sysEncPubKeyLen,
		unsigned char* signPriKeyByLmk, unsigned int* signPriKeyByLmkLen, 
		unsigned char* encPriKeyByLmk, unsigned int* encPriKeyByLmkLen);

	/**
	* @brief    产生用户私钥 (加密/签名、KGC 用)
	*
	* @param    hSessionHandle			[in]    初始化获得的句柄
	* @param    keyType					[in]    1 – 签名主密钥; 2 – 加密主密钥; 3 – 签名主密钥和加密主密钥
	* @param    userPubKeyIndex			[in]	用户主公钥索引  仅支持外部（0）
	* @param    userSignPubKey			[in]    用户签名主公钥,如果为长度 0000，则不输入
	* @param    userSignPubKeyBits		[in]    用户签名主公钥模长，当 KGC 密钥索引为 0 时存在 暂时只允许输入 0
	* @param    userEncPubKey			[in]    用户加密公钥, 长度为模长*2
	* @param    userEncPubKeyBits		[in]	用户加密公钥模长,当 KGC 密钥索引为 0 时存在，Bit
	* @param    userEncMode				[in]	用户加密模式,1- 流加密 2- ECB 3- CBC
	* @param    sysPubKeyIndex			[in]	系统主密钥索引,0001–1024/K+3B(0x000001-0xFFFFFF)
	* @param    userId					[in]	用户id
	* @param    userIdLen				[in]	用户id长度 1-256
	* @param    userPriKeyIndex			[in]	用户私钥存储索引,0001–1024/K+3B(0x000001-0xFFFFFF)9999 为不存储
	* @param    storeLabel				[in]	用户私钥密钥标签,当索引不为 0 时存在
	* @param    signPriKeyPro			[out]	签名私钥保护结构,类型为 1/3 时候存在
	* @param    signPriKeyProLen		[out]	签名私钥保护结构长度,类型为 1/3 时候存在
	* @param    encPriKeyPro			[out]	加密私钥保护结构,类型为 2/3 时候存在
	* @param    encPriKeyProLen			[out]	加密私钥保护结构长度,类型为 2/3 时候存在
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M1_GenerateUserPrivateKey(void* hSessionHandle, TA_ASYM_USAGE keyType, unsigned int userPubKeyIndex, const unsigned char* userSignPubKey, unsigned int userSignPubKeyBits,
		const unsigned char* userEncPubKey, unsigned int userEncPubKeyBits, TA_SM9_ENC_MODE userEncMode, unsigned int sysPubKeyIndex,
		const unsigned char* userId, unsigned int userIdLen, unsigned int userPriKeyIndex, const char* storeLabel,
		unsigned char* signPriKeyPro, unsigned int* signPriKeyProLen, unsigned char* encPriKeyPro, unsigned int* encPriKeyProLen);

	/**
	* @brief    导入用户私钥(加密/签名、运算中心) 
	*			（可同时导入kgc）
	*
	* @param    hSessionHandle			[in]    初始化获得的句柄
	* @param    keyType					[in]    1 – 签名主密钥; 2 – 加密主密钥; 3 – 签名主密钥和加密主密钥
	* @param    userEncPriKeyIndex		[in]	用户加密主私钥索引(系统主密钥),0001–1024/K+3B(0x000001-0xFFFFFF
	* @param    signPriKeyPro			[in]    签名私钥保护结构,类型为 1/3 时候存在
	* @param    signPriKeyProLen		[in]    签名私钥保护结构长度,类型为 1/3 时候存在
	* @param    encPriKeyPro			[in]    加密私钥保护结构,类型为 2/3 时候存在
	* @param    encPriKeyProLen			[in]	加密私钥保护结构长度,类型为 2/3 时候存在
	* @param    userPriKeyIndex			[in]	用户私钥密钥存储索引,0001–1024/K+3B(0x000001-0xFFFFFF)
	* @param    storeLabel				[in]	用户私钥密钥标签
	* @param    KGCPubKeyIndex			[in]	KGC 主公钥存储索引,，当为 0 的时 候，KGC 主公钥不存入加密机
	* @param    KGCstoreLabel			[in]	KGC主公钥存储标签,当索引不为 0 时存在
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M2_ImportUserPrivateKey(void* hSessionHandle, TA_ASYM_USAGE keyType, unsigned int userEncPriKeyIndex,
		const unsigned char* signPriKeyPro, unsigned int signPriKeyProLen, const unsigned char* encPriKeyPro, unsigned int encPriKeyProLen,
		unsigned int userPriKeyIndex, const char* storeLabel, unsigned int KGCPubKeyIndex, const  char* KGCstoreLabel);

	/**
	* @brief    生成 SM9 用户密钥(LMK加密)
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    keyType						[in]    1 – 签名主密钥; 2 – 加密主密钥; 3 – 签名主密钥和加密主密钥
	* @param    preproccess					[in]    预处理域生成标识  
	* @param    sysIndex					[in]    系统主密钥索引,0001–0064  0时使用外部密钥
	* @param    sysSignPriKey				[in]    系统签名主私钥
	* @param    sysSignPriKeyLen			[in]    系统签名主私钥长度
	* @param    sysSignPubKey				[in]    系统签名主公钥
	* @param    sysSignPubKeyLen			[in]    系统签名主公钥长度
	* @param    sysEncPriKey				[in]    系统加密主私钥
	* @param    sysEncPriKeyLen				[in]    系统加密主私钥长度
	* @param    sysEncPubKey				[in]    系统加密主公钥
	* @param    sysEncPubKeyLen				[in]    系统加密主公钥长度
	* @param    userId						[in]	用户id
	* @param    userIdLen					[in]    用户id长度 1-256
	* @param    userPriKeyIndex				[in]    用户私钥存储索引 0001–1024/0/K+3B(0x000001-0xFFFFFF) 0 为不存储，
	* @param    storeLabel					[in]	用户私钥存储标签 索引为0时不存在
	* @param    signHid						[in]	签名私钥hid  传入NULL时使用默认0x01
	* @param    encHid						[in]	加密私钥hid  传入NULL时使用默认0x03
	* @param    userSignPriKeyByLmk			[out]	用户签名私钥密文,类型为 1/3 时候存在
	* @param    userSignPriKeyByLmkLen		[out]	用户签名私钥密文长度,类型为 1/3 时候存在
	* @param    userEncPriKeyByLmk			[out]	用户加密私钥密文,类型为 2/3 时候存在
	* @param    userEncPriKeyByLmkLen		[out]	用户加密私钥密文长度,类型为 2/3 时候存在
	* @param    P							[out]	预处理域P 仅当preproccess=TA_TURE时存在
	* @param    PLen						[out]	预处理域P长度
	* @param    QB							[out]	预处理域QB 仅当preproccess=TA_TURE时存在
	* @param    QBLen						[out]	预处理域QB长度
	* 
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_MB_SM9GenerateUserKey(void* hSessionHandle,
		TA_ASYM_USAGE keyType, TA_BOOL preproccess, unsigned int sysIndex,
		const unsigned char* sysSignPriKey, unsigned int sysSignPriKeyLen,
		const unsigned char* sysSignPubKey, unsigned int sysSignPubKeyLen,
		const unsigned char* sysEncPriKey, unsigned int sysEncPriKeyLen,
		const unsigned char* sysEncPubKey, unsigned int sysEncPubKeyLen,
		const unsigned char* userId, unsigned int userIdLen,
		unsigned int userPriKeyIndex, const char* storeLabel,
		const unsigned char signHid, const unsigned char encHid,
		unsigned char* userSignPriKeyByLmk, unsigned int* userSignPriKeyByLmkLen,
		unsigned char* userEncPriKeyByLmk, unsigned int* userEncPriKeyByLmkLen,
		unsigned char* P, unsigned int* PLen,
		unsigned char* QB, unsigned int* QBLen);

	/**
	* @brief    导出系统主公钥(加密/签名)
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    sysIndex					[in]    系统主公钥索引，0001–1024/K+3B(0x000001-0xFFFFFF);
	* @param    keyType						[in]    1 – 签名主密钥; 2 – 加密主密钥; 3 – 签名主密钥和加密主密钥
	* @param    sysSignPubKey				[out]	系统签名主公钥,类型为 1/3 时候存在
	* @param    sysSignPubKeyLen			[out]	系统签名主公钥长度,类型为 1/3 时候存在
	* @param    sysEncPubKey				[out]	系统加密主公钥,类型为 2/3 时候存在
	* @param    sysEncPubKeyLen				[out]	系统加密主公钥长度,类型为 2/3 时候存在
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M3_ExportSystemMasterPublicKey(void* hSessionHandle, unsigned int sysIndex, TA_ASYM_USAGE keyType,
		unsigned char* sysSignPubKey, unsigned int* sysSignPubKeyLen, unsigned char* sysEncPubKey, unsigned int* sysEncPubKeyLen);

	/**
	* @brief    导出 KGC 主公钥
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    KGCIndex					[in]    KGC主公钥索引，0001–1024/K+3B(0x000001-0xFFFFFF);
	* @param    keyType						[in]    1 – 签名密钥; 2 – 加密密钥; 3 – 签名密钥和加密密钥
	* @param    KGCSignPriKey				[out]	KGC签名主私钥,类型为 1/3 时候存在
	* @param    KGCSignPriKeyLen			[out]	KGC签名主私钥长度,类型为 1/3 时候存在
	* @param    KGCEncPriKey				[out]	KGC加密主私钥,类型为 2/3 时候存在
	* @param    KGCEncPriKeyLen				[out]	KGC加密主私钥长度,类型为 2/3 时候存在
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_MH_ExportKGCMasterPublicKey(void* hSessionHandle, unsigned int KGCIndex, TA_ASYM_USAGE keyType,
		unsigned char* KGCSignPriKey, unsigned int* KGCSignPriKeyLen, unsigned char* KGCEncPriKey, unsigned int* KGCEncPriKeyLen);

	/**
	* @brief    密钥封装,使用接收方的 ID 和 KGC 加密主公钥，生成双方的会话密钥。
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    KGCIndex					[in]    KGC 主公钥索引,0001–1024/0/K+3B(0x000001-0xFFFFFF),0时使用外部公钥,9999时使用预处理域
	* @param    KGCEncPubKey				[in]    KGC 加密主公钥,索引为0时存在
	* @param    KGCEncPubKeyBits			[in]	KGC 加密主公钥模长,索引为0时存在
	* @param    g							[in]	预处理域g 仅当索引值为9999时存在
	* @param    gLen						[in]    预处理域g长度 仅当索引值为9999时存在
	* @param    QBId						[in]	预处理域QB 可选域 仅当索引值为9999时存在
	* @param    QBLen						[in]    预处理域QB长度 仅当索引值为9999时存在
	* @param    userId						[in]	用户id
	* @param    userIdLen					[in]    用户id长度 1-256
	* @param    alg							[in]    会话密钥算法,Z/X/Y/P/R/L/M/N/Q
	* @param    hid							[in]    可选域  NULL时内部默认0x03
	* @param	keyPro						[out]	密钥封装结构
	* @param    keyProLen					[out]	密钥封装结构长度
	* @param    sessKeyCipher				[out]	会话密钥密文
	* @param    kcv							[out]	会话密钥校验值
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M4_KeyPackage(void* hSessionHandle, unsigned int KGCIndex,
		const unsigned char* KGCEncPubKey, unsigned int KGCEncPubKeyBits,
		const unsigned char* g, unsigned int gLen,
		const unsigned char* QB, unsigned int QBLen,
		const unsigned char* userId, unsigned int userIdLen, TA_SM9_SYMM_ALG alg,
		const unsigned char hid,
		unsigned char* keyPro, unsigned int* keyProLen, char* sessKeyCipher, unsigned char* kcv);


	/**
	* @brief   密钥解封装,将密钥封装功能生成的封装数据，通过接收方的 ID 和用户私钥，生成双方的会话密钥。
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    userPriKeyIndex				[in]    用户私钥索引,0001–1024/0/K+3B(0x000001-0xFFFFFF),0时使用外部私钥
	* @param    userEncPriKeyByLmk			[in]    用户加密私钥 当传入索引为0时存在
	* @param    userEncPriKeyByLmkLen		[in]    用户加密私钥长度 当传入索引为0时存在
	* @param    userId						[in]	用户id
	* @param    userIdLen					[in]    用户id长度 1-256
	* @param	keyPro						[in]	密钥封装结构
	* @param    keyProLen					[in]	密钥封装结构长度
	* @param    alg							[in]    会话密钥算法,Z/X/Y/P/R/L/M/N/Q
	* @param    sessKeyCipher				[out]	会话密钥密文
	* @param    kcv							[out]	会话密钥校验值
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M5_KeyUnpackage(void* hSessionHandle, unsigned int userPriKeyIndex,
		const unsigned char* userEncPriKeyByLmk,unsigned int userEncPriKeyByLmkLen,
		const unsigned char* userId, unsigned int userIdLen, 
		const unsigned char* keyPro, unsigned int keyProLen,
		TA_SM9_SYMM_ALG alg,char* sessKeyCipher, unsigned char* kcv);

	/**
	* @brief    私钥签名,使用用户签名私钥和 KGC 签名主公钥对数据进行签名。
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    KGCSignPubKeyIndex			[in]    KGC 签名主公钥索引,0001–0064 0时使用外部公钥 9999时使用预处理域
	* @param    KGCSignPubKey				[in]    KGC 签名主公钥,索引为0时存在
	* @param    KGCSignPubKeyLen			[in]	KGC 签名主公钥长度,索引为0时存在
	* @param    g							[in]	预处理域g 仅当索引值为9999时存在
	* @param    gLen						[in]    预处理域g长度 仅当索引值为9999时存在
	* @param    QBId						[in]	预处理域QB 可选域 仅当索引值为9999时存在
	* @param    QBLen						[in]    预处理域QB长度 仅当索引值为9999时存在
	* @param	userSignPriKeyIndex			[in]    用户签名私钥索引,0001–1024/0/K+3B(0x000001-0xFFFFFF),0时使用外部私钥
	* @param	userSignPriKeyByLmk			[in]    用户签名私钥密文,索引为0时存在
	* @param	userSignPriKeyByLmkLen		[in]	用户签名私钥密文长度,索引为0时存在
	* @param	data						[in]	待签名数据
	* @param	dataLen						[in]	待签名数据 1-4096
	* @param    signData					[out]	签名结构数据
	* @param    signDataLen					[out]	签名结构数据长度
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M6_PrivateKeySign(void* hSessionHandle, unsigned int KGCSignPubKeyIndex, 
		const unsigned char* KGCSignPubKey, unsigned KGCSignPubKeyLen,
		const unsigned char* g, unsigned int gLen,
		unsigned int userSignPriKeyIndex, 
		const unsigned char* userSignPriKeyByLmk, unsigned userSignPriKeyByLmkLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* signData, unsigned int* signDataLen);

	/**
	* @brief    公钥验签(内部/外部)(M7)
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    KGCSignPubKeyIndex			[in]    KGC 签名主公钥索引,0001–0064 ,0时使用外部公钥 9999时使用预处理域
	* @param    KGCSignPubKey				[in]    KGC 签名主公钥,索引为0时存在
	* @param    KGCSignPubKeyLen			[in]	KGC 签名主公钥长度,索引为0时存在
	* @param    g							[in]	预处理域g 仅当索引值为9999时存在
	* @param    gLen						[in]    预处理域g长度 仅当索引值为9999时存在
	* @param    P							[in]	预处理域P 可选域 仅当索引值为9999时存在
	* @param    PLen						[in]    预处理域P长度 仅当索引值为9999时存在
	* @param    userId						[in]	用户id
	* @param    userIdLen					[in]    用户id长度 1-256
	* @param	data						[in]	待签名数据
	* @param	dataLen						[in]	待签名数据 1-4096
	* @param    signData					[in]	签名结构数据
	* @param    signDataLen					[in]	签名结构数据长度
	* @param    hid							[in]	可选域 0x00-0xff
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M7_PublicKeyVerify(void* hSessionHandle, unsigned int KGCSignPubKeyIndex,
		const unsigned char* KGCSignPubKey, unsigned KGCSignPubKeyLen,
		const unsigned char* g, unsigned int gLen,
		const unsigned char* P, unsigned int PLen,
		const unsigned char* userId, unsigned int userIdLen,
		const unsigned char* data, unsigned int dataLen, 
		const unsigned char* signData, unsigned int signDataLen,
		const unsigned char hid);

	/**
	* @brief    公钥加密(外部),使用 KGC 加密主公钥和 ID 加密数据。
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    encMode						[in]    加密类型 1-流加密 2-ECB 3-CBC 4-CFB 5-OFB
	* @param    pad							[in]    填充模式 仅当类型非 1-流加密时存在 
	* @param    iv							[in]    初始向量 仅当类型非 1-流加密 2-ECB 时存在 
	* @param    KGCEncPubKeyIndex			[in]	KGC 加密主公钥索引,0001–0064 0时使用外部密钥 9999时使用预处理域
	* @param    KGCEncPubKey				[in]    KGC 加密主公钥,索引为0时存在
	* @param    KGCEncPubKeyLen				[in]	KGC 加密主公钥长度,索引为0时存在
	* @param    g							[in]	预处理域g 仅当索引值为9999时存在
	* @param    gLen						[in]    预处理域g长度 仅当索引值为9999时存在
	* @param    QBId						[in]	预处理域QB 可选域 仅当索引值为9999时存在
	* @param    QBLen						[in]    预处理域QB长度 仅当索引值为9999时存在
	* @param    userId						[in]	用户id
	* @param    userIdLen					[in]    用户id长度 1-256
	* @param	data						[in]	待加密数据
	* @param	dataLen						[in]	待加密数据 当类型为 1-流加密的时候 1-4096 否则为 1-4095
	* @param	hid							[in]	可选域 传入NULL时为默认的0x03
	* @param    cipher						[out]	密文
	* @param    cipherLen					[out]	密文长度
	*
	* @return
	* @retval	0		成功S
	* @retval	其他	失败
	*/
	int Tass_M8_PublicKeyEncrypt(void* hSessionHandle, 
		TA_SM9_ENC_MODE encMode, TA_PAD pad,
		const unsigned char* iv,unsigned int KGCEncPubKeyIndex, 
		const unsigned char* KGCEncPubKey, unsigned KGCEncPubKeyLen,
		const unsigned char* g, unsigned int gLen,
		const unsigned char* QB, unsigned int QBLen,
		const unsigned char* userId, unsigned int userIdLen, 
		const unsigned char* data, unsigned int dataLen, 
		const unsigned char hid,
		unsigned char* cipher, unsigned int* cipherLen);



	/**
	* @brief    私钥解密(M9),使用用户私钥和 ID 解密数据。
	*
	* @param    hSessionHandle				[in]    初始化获得的句柄
	* @param    encMode						[in]    加密类型 1- 流加密 2- ECB 3- CBC
	* @param    pad							[in]    填充模式 仅当类型非 1-流加密时存在 
	* @param    iv							[in]    初始向量 仅当类型非 1-流加密 2-ECB 时存在 
	* @param    userEncPriKeyIndex			[in]	用户加密私钥索引,0001–1024/0/K+3B(0x000001-0xFFFFFF)
	* @param    userEncPriKeyByLmk			[in]    用户加密私钥密文,索引为0时存在
	* @param    userEncPriKeyByLmkLen		[in]	用户加密私钥密文长度,索引为0时存在
	* @param    userId						[in]	用户id
	* @param    userIdLen					[in]    用户id长度 1-256
	* @param	cipher						[in]	待加密数据
	* @param	cipherLen					[in]	待加密数据 当类型为 1-流加密的时候 1-4096 否则为 1-4095
	* @param    palin						[out]	密文
	* @param    plainLen					[out]	密文长度
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_M9_PrivateKeyDecrypt(void* hSessionHandle, 
		TA_SM9_ENC_MODE encMode, TA_PAD pad,
		const unsigned char* iv, unsigned int userEncPriKeyIndex,
		const unsigned char* userEncPriKeyByLmk, unsigned userEncPriKeyByLmkLen,
		const unsigned char* userId, unsigned int userIdLen, 
		const unsigned char* cipher, unsigned int cipherLen, 
		unsigned char* plain, unsigned int* plainLen);

	/**
	* @brief   保护导出用户私钥
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    encMode                     [in]    标识保护密钥加密被导出密钥时的算法模式 00 – ECB 01 – CBC
	* @param    proKeyType                  [in]    用于加密保护被导出密钥的源密钥类型 000 – ZMK/KEK; 109 – MDK; 011 – KMC;
	* @param    proKeyIndex                 [in]    保护密钥索引
	* @param    proKeyCipherByLmk           [in]    保护密钥的密文
	* @param    proDeriveCnt                [in]    保护密钥分散级数，取值范围：0-8
	* @param    proDeriveFactor             [in]    保护密钥分散因子(串联),每级8字节,最多8级
	* @param    sessKeyGenMode              [in]    会话密钥产生模式,TA_SESS_KEY_GEN_NO:00-TA_SESS_KEY_GEN_05:05
	* @param    sessFactor                  [in]    会话密钥因子,当sessKeyGenMode值为01/02/05时有效,01时8字节,02/05时16字节
	* @param    sessFactorLen               [in]    会话密钥因子长度
	* @param    iv				            [in]    初始向量 仅 CBC 加密使用
	* @param    userPriIndex                [in]    被保护密钥索引(用户私钥)0001–1024/0/K+3B(0x000001-0xFFFFFF) 索引为0时使用外部私钥
	* @param    userId						[in]    用户ID 内部索引有效
	* @param    userIdLen					[in]    用户ID长度 内部索引有效
	* @param    userkeyType					[in]    被保护密钥类型(用户私钥)1-签名私钥 2-加密私钥 3-加密/签名私钥
	* @param    userSignPriKey				[in]	用户签名私钥,索引为0时有效
	* @param    userSignPriKeyLen			[in]	用户签名私钥长度,索引为0时有效
	* @param    userEncPriKey				[in]	用户加密私钥,索引为0时有效
	* @param    userEncPriKeyLen			[in]	用户加密私钥长度,索引为0时有效
	* @param    userSignPriKeyPro		    [out]   用户签名私钥保护结构
	* @param    userSignPriKeyProLen	    [out]   用户签名私钥保护结构长度
	* @param    userEncPriKeyPro		    [out]   用户加密私钥保护结构
	* @param    userEncPriKeyProLen			[out]   用户加密私钥保护结构长度
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_ME_ProtectExportUserPrikey(void* hSessionHandle, TA_SYMM_MODE encMode, TA_SYMM_ALG proKeyType, unsigned int proKeyIndex, const unsigned char* proKeyCipherByLmk, unsigned int proKeyCipherByLmkLen,
		unsigned int proDeriveCnt, const unsigned char* proDeriveFactor, TA_SESS_KEY_GEN_MODE sessKeyGenMode, const unsigned char* sessFactor, unsigned int sessFactorLen,
		const unsigned char* iv, unsigned int ivLen, unsigned int userPriIndex, const unsigned char* userId, unsigned int userIdLen, TA_ASYM_USAGE userkeyType,
		const unsigned char* userSignPriKey, unsigned int userSignPriKeyLen, const unsigned char* userEncPriKey, unsigned int userEncPriKeyLen,
		unsigned char* userSignPriKeyPro, unsigned int* userSignPriKeyProLen, unsigned char* userEncPriKeyPro, unsigned int* userEncPriKeyProLen);

	/**
	* @brief    保护导入用户私钥
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    encMode                     [in]    标识保护密钥加密被导出密钥时的算法模式 00 – ECB 01 – CBC
	* @param    proKeyType                  [in]    用于加密保护被导出密钥的源密钥类型 000 – ZMK/KEK; 109 – MDK; 011 – KMC;
	* @param    proKeyIndex                 [in]    保护密钥索引
	* @param    proKeyCipherByLmk           [in]    保护密钥的密文
	* @param    proDeriveCnt                [in]    保护密钥分散级数，取值范围：0-8
	* @param    proDeriveFactor             [in]    保护密钥分散因子(串联),每级8字节,最多8级
	* @param    sessKeyGenMode              [in]    会话密钥产生模式,TA_SESS_KEY_GEN_NO:00-TA_SESS_KEY_GEN_05:05
	* @param    sessFactor                  [in]    会话密钥因子,当sessKeyGenMode值为01/02/05时有效,01时8字节,02/05时16字节
	* @param    sessFactorLen               [in]    会话密钥因子长度
	* @param    iv				            [in]    初始向量 仅 CBC 加密使用
	* @param    ivlen				        [in]    初始向量长度 仅 CBC 加密使用
	* @param    userkeyType					[in]    被保护密钥类型(用户私钥)1-签名私钥 2-加密私钥 3-加密/签名私钥(目前仅支持3)
	* @param    userPriIndex                [in]    被保护密钥存储索引(用户私钥)0001–1024/0/K+3B(0x000001-0xFFFFFF) 索引为0时不存储
	* @param    storeLabel					[in]    被保护密钥存储标签
	* @param    storeLabelLen               [in]    被保护密钥存储标签长度
	* @param    userId						[in]    用户ID 内部索引有效
	* @param    userIdLen					[in]    用户ID长度 内部索引有效
	* @param    userSignPriKeyPro		    [in]	用户签名私钥保护结构
	* @param    userSignPriKeyProLen	    [in]	用户签名私钥保护结构长度
	* @param    userEncPriKeyPro		    [in]	用户加密私钥保护结构
	* @param    userEncPriKeyProLen			[in]	用户加密私钥保护结构长度
	* @param    userSignPriKeyByLmk			[out]	用户签名私钥密文,索引为0时有效
	* @param    userSignPriKeyByLmkLen		[out]	用户签名私钥密文长度,索引为0时有效
	* @param    userEncPriKeyByLmk			[out]	用户加密私钥密文,索引为0时有效
	* @param    userEncPriKeyByLmkLen		[out]	用户加密私钥密文长度,索引为0时有效
	*
	* @Tass_M1_GenerateUserPrivateKey
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_MF_ProtectImportUserPrikey(void* hSessionHandle, TA_SYMM_MODE encMode, TA_SYMM_ALG proKeyType, unsigned int proKeyIndex, const unsigned char* proKeyCipherByLmk, unsigned int proKeyCipherByLmkLen,
		unsigned int proDeriveCnt, const unsigned char* proDeriveFactor, TA_SESS_KEY_GEN_MODE sessKeyGenMode, const unsigned char* sessFactor, unsigned int sessFactorLen,
		const unsigned char* iv, unsigned int ivLen, TA_ASYM_USAGE userkeyType, unsigned int userPriIndex, const char* storeLabel, unsigned int storeLabelLen,const unsigned char* userId, unsigned int userIdLen,
		const unsigned char* userSignPriKeyPro, unsigned int userSignPriKeyProLen, const unsigned char* userEncPriKeyPro, unsigned int userEncPriKeyProLen,
		unsigned char* userSignPriKeyByLmk, unsigned int* userSignPriKeyByLmkLen, unsigned char* userEncPriKeyByLmk, unsigned int* userEncPriKeyByLmkLen);

	/**
	* @brief    导出用户私钥（lmk）
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    userPriKeyIndex             [in]    用户加密私钥索引 0001–1024/K+3B(0x000001-0xFFFFFF);
	* @param    keyType						[in]    密钥类型 1 – 签名密钥; 2 – 加密密钥; 3 – 签名密钥和加密密钥;
	* @param    userSignPriKey				[out]	用户签名私钥
	* @param    userSignPriKeyLen			[out]	用户签名私钥长度
	* @param    userEncPriKey				[out]	用户加密私钥
	* @param    userEncPriKeyLen			[out]	用户加密私钥长度
	*
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_MG_ExportUserKey(void* hSessionHandle, unsigned int userPriKeyIndex, TA_ASYM_USAGE keyType,
		unsigned char* userSignPriKey, unsigned int* userSignPriKeyLen, unsigned char* userEncPriKey, unsigned int* userEncPriKeyLen);




	/**
	* @brief    密钥协商--生成临时密钥
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    KGCEncMasPubKeyIndex        [in]    KGC加密主公钥索引 默认0001-0064. 0时使用外部密钥 9999时使用预处理域Q
	* @param    KGCEncMasPubKey				[in]    KGC加密主公钥 索引为0时存在
	* @param    KGCEncMasPubKeyLen			[in]	KGC加密主公钥长度 
	* @param    peerId						[in]	对方ID  1-256 索引非9999时存在
	* @param    peerIdLen					[in]	对方ID长度
	* @param    Q							[in]	预处理域Q 索引9999时存在
	* @param    QLen						[in]	预处理域Q长度
	* @param    sinHid						[in]	签名私钥hid 传入NULL时使用内部默认hid 0x03
	* @param    randomByLmk					[out]	LMK 加密的随机数 r
	* @param    randomByLmkLen				[out]	LMK 加密的随机数 r长度
	* @param    tmpKey						[out]	临时密钥
	* @param    tmpKeyLen					[out]	临时密钥长度
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_MI_GenerateTemporarySM9Key(void* hSessionHandle, unsigned int KGCEncMasPubKeyIndex,
		const unsigned char* KGCEncMasPubKey, unsigned int KGCEncMasPubKeyLen,
		const unsigned char* peerId, unsigned int peerIdLen,
		const unsigned char* Q, unsigned int QLen,
		const unsigned char sinHid,
		unsigned char* randomByLmk, unsigned int* randomByLmkLen,
		unsigned char* tmpKey, unsigned int* tmpKeyLen);









	/**
	* @brief    预处理
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    preAlg						[in]    预处理标识
	*													0 - 签名 or 验签流程预处理g			  g = e(P1, Ppub-s)
	*													1 - 签名 or 验签流程预处理P			  P = [H1(IDA||hid, N)]P2+Ppub-s
	*													2 - 封装 or 加密流程预处理g			  g = e(Ppub-e, P2)
	*													3 - 封装 or 加密 or 协商流程预处理 QB QB = [H1(IDB||hid, N)]P1+Ppub-e
	* @param    Ppub						[in]    当为签名、验签流程时，此域表示 Ppub-s，格式为xa||xb||ya||yb；
	*												当为其他流程时，此域表示 Ppub-e，格式为 x||y
	* @param    PpubLen						[in]	PpubLen
	* @param    userId						[in]	用户ID  可选域，仅当预处理标识为 1 or 3 时存在
	*													当为验签流程时，此域为 IDA 长度 取值 1-256
	*													当为其他流程时，此域为 IDB 长度 取值 1-256
	* @param    userIdLen					[in]	用户ID 长度
	* @param    signHid						[in]	仅当预处理标识为 1 or 3 时存在 传入NULL时内部默认签名验签 hid 为 0x01，其他流程默认 hid 为 0x03
	* @param    outData						[out]	预处理结果
	* @param    outDataLen					[out]	预处理结果长度
	* @return
	* @retval	0		成功
	* @retval	其他	失败
	*/
	int Tass_MK_SM9Pretreatment(void* hSessionHandle, unsigned int preAlg,
		const unsigned char* Ppub, unsigned int PpubLen,
		const unsigned char* userId, unsigned int userIdLen,
		const unsigned char signHid,
		unsigned char* outData, unsigned int* outDataLen);


	

	int Tass_MJ_SM9ExchangeKeyOutCipherByLMK(void* hSessionHandle,
		TA_EXKEY_MODE mode, unsigned int KGCEncMasPubKeyIndex,
		const unsigned char* KGCEncMasPubKey, unsigned int KGCEncMasPubKeyLen,
		const unsigned char* g, unsigned int gLen,
		unsigned int localEncPriKeyIdx, const unsigned char* localEncPriKey, unsigned int localEncPriKeyLen,
		const unsigned char* localId, unsigned int localIdLen,
		const unsigned char* peerId, unsigned int peerIdLen,
		const unsigned char* localRandomByLmk, unsigned int localRandomByLmkLen,
		const unsigned char* localTmpKey, unsigned int localTmpKeyLen,
		const unsigned char* peerTmpKey, unsigned int peerTmpKeyLen,
		unsigned int exKeyBytes, TA_BOOL operationAlg,
		unsigned char* exKeyByLmk, unsigned int* exKeyByLmkLen,
		unsigned char* option1, unsigned int* option1Len,
		unsigned char* option2, unsigned int* option2Len);

	/**
	* @brief    单包哈希运算
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    alg							[in]    哈希算法标识
	* @param    pubKeyX						[in]    SM2 公钥 X 数据(HASH 算法标识为 20 长度不为 0 时存在);
	* @param    pubKeyXLen					[in]	SM2 公钥 X 长度(HASH 算法标识为 20 时存在)
	* @param    pubKeyY						[in]	SM2 公钥 Y 数据(HASH 算法标识为 20 长度不为 0 时存在);
	* @param    pubKeyYLen					[in]	SM2 公钥 Y 长度(HASH 算法标识为 20 时存在)
	* @param    userId						[in]	用户 ID 仅当 HASH 算法标识为 20 长度不为 0 时存在
	* @param    userIdLen					[in]	用户 ID 长度(范围 0000-0032)仅当 HASH 算法标识为 20 时存在
	* @param    data						[in]	用户加密私钥长度
	* @param    dataLen						[in]	用户加密私钥长度
	* @param    hash						[out]	用于 Hash 的数据
	* @param    hashLen						[out]	用于 Hash 的数据长度（1-8192）
	* 
	* @return
	* @retval	0		成功S
	* @retval	其他	失败
	*/
	int Tass_HashSingle(void* hSessionHandle,
		TA_HASH_ALG alg,
		const unsigned char* pubKeyX, unsigned int pubKeyXLen,
		const unsigned char* pubKeyY, unsigned int pubKeyYLen,
		const unsigned char* userId, unsigned int userIdLen,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* hash, unsigned int* hashLen);


	/**
 * @brief    获取密钥索引信息（支持大密钥容量）
 *
 * @param	hSessionHandle				[in]  初始化获得的句柄
 * @param	type						[in]  密钥类型
 * @param	indexBegin					[in]  密钥偏移值=索引，标识从本索引（包括本索引）开始查找索引信息
 * @param	indexs						[out] 本次查找到的密钥数量（目前最大 1500）
 * @param	nextIndexBegin				[out] 下一次密钥偏移值
 * @param	indexCnt					[out] 获取到的密钥索引的合集
 *
 * @return
 * @retval 0  成功S
 * @retval 其他 失败
 */
	int Tass_GetValidIndex(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int indexBegin,
		unsigned int* indexs,
		unsigned int* nextIndexBegin,
		unsigned int* indexCnt);

	/**
	* @brief    获取当前支持索引存储最大值
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    maxSymmKeyCap				[out]   对称密钥最大支持索引存储的最大值
	* @param    maxRsaCap					[out]   rsa密钥最大支持索引存储的最大值
	* @param    maxEccCap					[out]	ecc密钥最大支持索引存储的最大值
	* @param    maxSm9SysKeyCap				[out]	sm9系统主密钥最大支持索引存储的最大值
	* @param    maxSm9KgcKeyCap				[out]	sm9KGC主密钥最大支持索引存储的最大值
	* @param    maxSm9UserKeyCap			[out]	sm9用户密钥最大支持索引存储的最大值
	* @param    curSymmKeyCap				[out]   对称密钥当前支持索引存储的最大值
	* @param    curRsaCap					[out]   rsa密钥当前支持索引存储的最大值
	* @param    curEccCap					[out]	ecc密钥当前支持索引存储的最大值
	* @param    curSm9SysKeyCap				[out]	sm9系统主密钥当前支持索引存储的最大值
	* @param    curSm9KgcKeyCap				[out]	sm9KGC主密钥当前支持索引存储的最大值
	* @param    curSm9UserKeyCap			[out]	sm9用户密钥当前支持索引存储的最大值
	* 
	* @return
	* @retval	0		成功S
	* @retval	其他	失败
	*/
	int Tass_GetIndexCapacity(void* hSessionHandle,
		unsigned int* maxSymmKeyCap, unsigned int* maxRsaCap, unsigned int* maxEccCap,
		unsigned int* maxSm9SysKeyCap, unsigned int* maxSm9KgcKeyCap, unsigned int* maxSm9UserKeyCap,
		unsigned int* curSymmKeyCap, unsigned int* curRsaCap, unsigned int* curEccCap,
		unsigned int* curSm9SysKeyCap, unsigned int* curSm9KgcKeyCap, unsigned int* curSm9UserKeyCap);


	/**
	* @brief    大数据加解密
	*
	* @param    hSessionHandle              [in]    初始化获得的句柄
	* @param    op							[in]    加密或解密
	* @param    mode						[in]    加/解密模式 支持TA_ECB
	* @param    alg							[in]	算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	* @param    iv							[in]	输入IV，mode不是TA_ECB时有效，
	* @param    ivLen						[in]	inIv长度，mode=TA_XTS时，取值1~16字节
	* @param    index						[in]	索引，大于0时有效，为0时使用外部密钥
	* @param    key							[in]    密钥，index为0时有效
	* @param    keyLen						[in]    密钥长度，index为0时有效
	* @param    groupSize					[in]	输出填充大小最大值
	* @param    cacheCnt					[in]	缓存块
	* @param    cacheBlockSize				[in]	缓存块大小
	* @param    threadNum					[in]	线程数
	* @param    inPath						[in]	输入文件
	* @param    outPath						[out]	输出文件
	* 
	* @return
	* @retval	0		成功S
	* @retval	其他	失败
	*/
	int Tass_BigFileEncryptDecrypt(void* hSessionHandle,
		TA_SYMM_OP op,
		TA_SYMM_MODE mode,
		TA_SYMM_ALG alg,
		unsigned char *iv,unsigned int ivLen,
		unsigned int index, const unsigned char* key,unsigned int keyLen,
		unsigned int groupSize,
		unsigned int cacheCnt,
		unsigned int cacheBlockSize,
		unsigned int threadNum,
		const char* inPath,
		const char* outPath);




	
	/**
	* @brief	创建同步信息
	* @param	message						[IN/OUT]	同步信息 传入前需置空
	* @return
	*/
	TassCommAllMessage* Tass_CommAllMessageNew(TassCommAllMessage** message);

	/**
	* @brief	释放同步信息
	* @param	message						[IN]		同步信息
	* @return
	*/
	void Tass_CommAllMessageFree(TassCommAllMessage* message);

	/**
	* @brief	向所有设备导入LMK加密的密钥
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	index						[IN]		要导入的索引
	* @param	type						[IN]		密钥类型
	* @param	curve						[IN]		ECC曲线，type为TA_ECC时有效
	* @param	alg							[IN]		对称密钥算法，type为TA_SYMM时有效
	* @param	usage						[IN]		非对称密钥用途，type不为TA_SYMM时有效
	* @param	pubKeyN_X					[IN]		公钥N（RSA)或X（ECC)，type不为TA_SYMM时有效
	* @param	pubKeyN_XLen				[IN]		pubKeyN_XLen长度，type不为TA_SYMM时有效
	* @param	pubKeyE_Y					[IN]		公钥E（RSA)或Y（ECC)，type不为TA_SYMM时有效
	* @param	pubKeyE_YLen				[IN]		pubKeyE_YLen长度，type不为TA_SYMM时有效
	* @param	pri_symmKeyCipherByLmk		[IN]		私钥或对称密钥密文
	* @param	pri_symmKeyCipherByLmkLen	[IN]		pri_symmKeyCipherByLmkLen长度
	* @param	symmKcv						[IN]		对称密钥校验值，type为TA_SYMM时有效
	* @param	coverFlag    				[IN]		密钥存在时是否覆盖密钥，0：不覆盖，非0：覆盖
	* @param	message    					[IN]		密钥导入信息
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ImportKeyCipherByLMKSynchronous(void* hSessionHandle,
		unsigned int index,
		TA_KEY_TYPE type,
		TA_ECC_CURVE curve,
		TA_SYMM_ALG alg,
		TA_ASYMM_USAGE usage,
		const unsigned char* pubKeyN_X, unsigned int pubKeyN_XLen,
		const unsigned char* pubKeyE_Y, unsigned int pubKeyE_YLen,
		const unsigned char* pri_symmKeyCipherByLmk, unsigned int pri_symmKeyCipherByLmkLen,
		const unsigned char symmKcv[8],
		unsigned int coverFlag,
		TassCommAllMessage* message);

	/**
	* @brief	销毁所有设备指定索引的密钥
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	type			[IN]	密钥类型
	* @param	index			[IN]	密钥索引
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_DestroyKeySynchronous(void* hSessionHandle,
		TA_KEY_TYPE type,
		unsigned int index,
		TassCommAllMessage* message);


	/**
	* @brief	获取密钥同步状态
	* @param	hSessionHandle	[IN]	与设备建立的会话句柄
	* @param	type			[IN]	密钥类型
	* @param	index			[IN]	密钥索引
	* @param	keyStatus		[IN]	密钥状态 0-正常 1-创建中 2-删除中
	* @param	message			[OUT]	状态信息
	* 
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetKeyStatusSynchronous(void* hSessionHandle, TA_KEY_TYPE type,
		unsigned int index, unsigned int* keyStatus, TassCommAllMessage* message);

	/**
	* @brief	同步创建文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	* @param	size			[IN]		文件大小，最大8192字节
	* @param	message			[OUT]		状态信息
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CreateFileSynchronous(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen,
		unsigned int size, TassCommAllMessage* message);

	/**
	* @brief	同步写文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	* @param	offset			[IN]		偏移
	* @param	data			[IN]		写入的数据，最大4096字节
	* @param	dataLen			[IN]		data长度
	* @param	message			[OUT]		状态信息
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_WriteFileSynchronous(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen,
		unsigned int offset,
		const unsigned char* data, unsigned int dataLen, TassCommAllMessage* message);

	/**
	* @brief	同步删除文件
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	name			[IN]		文件名
	* @param	nameLen			[IN]		name长度，最大128字节
	* @param	message			[OUT]		状态信息
	* 
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_DeleteFileSynchronous(void* hSessionHandle,
		const unsigned char* name, unsigned int nameLen, TassCommAllMessage* message);


	/**
	* @brief	导入受 KEK 加密的会话密钥密文并进行加解密运算（密钥分散）
	* @param	hSessionHandle				[IN]		与设备建立的会话句柄
	* @param	proKeyIdx					[IN]		保护密钥索引 0为使用外部密钥
	* @param	proKeyAlgm					[IN]		保护密钥算法标识
	* @param	proKeyCipherByLmk			[IN]		保护密钥密文		当proKeyIdx=0时存在
	* @param	proKeyCipherByLmkLen		[IN]		保护密钥密文长度	当proKeyIdx=0时存在
	* @param	proKeyKcv					[IN]		保护密钥校验值		当proKeyIdx=0时存在
	* @param	proKeyEncpad				[IN]		保护密钥加密填充方式 仅支持 TA_PAD_PKCS_7 - PKCS#7填充
	* @param	sessKeyCipher				[IN]		会话密钥密文
	* @param	sessKeyCipherLen			[IN]		会话密钥密文长度
	* @param	sessKeyIV					[IN]		会话密钥IV 用于计算会话密钥MAC 固定传入16字节数据 当为DES算法时自动取前8字节
	* @param	sessKeyMac					[IN]		会话密钥MAC （注：此MAC为保护密钥CBC加密会话密钥的结果的后16/8字节，iv为sessKeyIV）
	* @param	sessKeyMacLen				[IN]		会话密钥MAC长度 
	* @param	proKeyEncMode				[IN]		保护密钥加密时的加密模式 仅支持 ECB CBC GCM
	* @param	proKeyEncIV					[IN]		保护密钥加密时的IV		当proKeyEncMode为 CBC GCM 时存在
	* @param	proKeyEncIVLen				[IN]		保护密钥加密时的IV长度  当proKeyEncMode为 CBC GCM 时存在
	* @param	proKeyEncAdd				[IN]		保护密钥加密时的ADD认证数据		当proKeyEncMode为 GCM ，且 proKeyAlgm 不为 DES 算法时存在
	* @param	proKeyEncAddLen				[IN]		保护密钥加密时的ADD认证数据长度 当proKeyEncMode为 GCM ，且 proKeyAlgm 不为 DES 算法时存在
	* @param	proKeyEncTags				[IN]		保护密钥加密时的tags		当proKeyEncMode为 GCM 时存在
	* @param	proKeyEncTagsLen			[IN]		保护密钥加密时的tags长度	当proKeyEncMode为 GCM 时存在
	* @param	sessKeyAlg					[IN]		解密后的会话密钥算法标识
	* @param	deriveCnt					[IN]		会话密钥分散级数 0-8 0时为不分散
	* @param	deriveMode					[IN]		会话密钥分散模式 0-4  当deriveCnt不为0时存在
	*															0 – PBOC 子密钥分散算法;用于分散产生应用子密钥;8 字节分散因子 D，使用源密钥对 16 字节[D|D 的非]采用源密钥的算法标识进行 ECB 模式加密;
	*															1 – ECB 模式加密 16 字节分散因子;
	*															2 – ECB 模式加密 16 字节分散因子，并复制扩展为 32字节长度密钥（仅限会话密钥类型为 05）;
	*															3 – CBC 模式加密 16 字节分散因子;
	*															4 – ECB 模式加密分散因子，分散因子必须为 8 字节倍数，且至少 16 字节。截取加密结果的前后各 8 字节作为子密钥（仅限会话密钥类型为 01）;
	* @param	deriveFactor				[IN]		分散因子 多级分散因子串联 当deriveCnt不为0时存在
	* @param	deriveFactorLen				[IN]		分散因子长度 多级分散因子串联 当deriveCnt不为0时存在
	* @param	subKeyAlg					[IN]		会话密钥分散的子密钥类型  当deriveCnt不为0时存在 仅支持 DES128 AES128 AES256 SM1 SM4
	* @param	op							[IN]		运算类型 TA_ENC为加密  TA_DEC为解密
	* @param	subKeyMode					[IN]		加解密算法模式  仅支持 ECB CBC GCM
	* @param	data						[IN]		需要运算的数据
	*v@param	dataLen						[IN]		需要运算的数据长度 加密小于8192字节 解密小于8192+32字节
	* @param	pad							[IN]		数据填充方式 仅支持 TA_PAD_PKCS_7 - PKCS#7填充
	* @param	iv							[IN]		运算IV		仅当subKeyMode为CBC GCM 时存在
	* @param	ivLen						[IN]		运算IV长度  仅当subKeyMode为CBC GCM 时存在
	* @param	add							[IN]		运算认证数据 AAD		仅当subKeyMode为 GCM 时存在
	* @param	addLen						[IN]		运算认证数据 AAD长度	仅当subKeyMode为 GCM 时存在 取值0-8192
	* @param	tags						[IN]		tags		仅当op=TA_DEC(解密) 且subKeyAlg为GCM时存在
	* @param	tagsLen						[IN]		tags长度	仅当op=TA_DEC(解密) 且subKeyAlg为GCM时存在
	* @param	outData						[OUT]		输出数据
	* @param	outDataLen					[OUT]		输出数据长度
	* @param	outTags						[IN]		输出tags		仅当op=TA_ENC(加密) 且subKeyAlg为GCM时存在
	* @param	outTagsLen					[OUT]		输出tags长度	仅当op=TA_ENC(加密) 且subKeyAlg为GCM时存在
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_ProKeyDiversifyOperation(void* hSessionHandle,
		unsigned int proKeyIdx, TA_SYMM_ALG proKeyAlgm,
		const unsigned char* proKeyCipherByLmk, unsigned int proKeyCipherByLmkLen,
		const unsigned char proKeyKcv[8], TA_PAD proKeyEncpad,
		const unsigned char* sessKeyCipher, unsigned int sessKeyCipherLen,
		const unsigned char* sessKeyIV, const unsigned char* sessKeyMac, unsigned int sessKeyMacLen,
		TA_SYMM_MODE proKeyEncMode, const unsigned char* proKeyEncIV, unsigned int proKeyEncIVLen,
		const unsigned char* proKeyEncAdd, unsigned int proKeyEncAddLen,
		const unsigned char* proKeyEncTags, unsigned int proKeyEncTagsLen,
		TA_SYMM_ALG sessKeyAlg, unsigned int deriveCnt, unsigned int deriveMode, const unsigned char* deriveFactor,unsigned int deriveFactorLen,
		TA_SYMM_ALG subKeyAlg, TA_SYMM_OP op, TA_SYMM_MODE subKeyMode,
		const unsigned char* data, unsigned int dataLen, TA_PAD pad,
		const unsigned char* iv, unsigned int ivLen,
		const unsigned char* add, unsigned int addLen,
		const unsigned char* tags, unsigned int tagsLen,
		unsigned char* outData, unsigned int* outDataLen,
		unsigned char* outTags, unsigned int* outTagsLen);



	/**
	* @brief	将lmk加密的对称密钥密文转换为密钥句柄
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	keyCipherByLmk			[IN]		lmk加密的对称密钥密文
	* @param	keyCipherByLmkLen		[IN]		lmk加密的对称密钥密文长度
	* @param	keyHandle				[OUT]		密钥句柄
	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetKeyHandleFromKeyCipherByLmk(void* hSessionHandle, const unsigned char* keyCipherByLmk, unsigned int keyCipherByLmkLen, void** keyHandle);



	/**
	* @brief	将密钥句柄转换为lmk加密的对称密钥密文
	* @param	hSessionHandle			[IN]		与设备建立的会话句柄
	* @param	keyHandle				[IN]		密钥句柄
	* @param	keyCipherByLmk			[OUT]		lmk加密的对称密钥密文
	* @param	keyCipherByLmkLen		[OUT]		lmk加密的对称密钥密文长度

	*
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GetKeyCipherByLmkFromKeyHandle(void* hSessionHandle, void* keyHandle, unsigned char* keyCipherByLmk, unsigned int* keyCipherByLmkLen);


	/**
	* @brief	对称密钥计算MAC
	* @param	hSessionHandle	[IN]		与设备建立的会话句柄
	* @param	mode			[IN]		计算MAC模式
	* @param	iv				[IN]		IV
	* @param	index			[IN]		索引，大于0时有效，为0时使用外部密钥
	* @param	plain			[IN]		是否为明文密钥
	* @param	key				[IN]		密钥，index为0时有效
	* @param	keyLen			[IN]		密钥长度，index为0时有效
	* @param	alg				[IN]		算法，使用内部密钥时须与其算法一致，实际支持的算法以实际设备为准
	* @param	data			[IN]		数据
	* @param	dataLen			[IN]		data长度，必须为分组长度的整数倍，最大8192字节
	* @param	mac				[OUT]		MAC
	* @param	macLen			[IN|OUT]	输入时：mac大小，输出时：mac长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_CalculateMAC_V2(void* hSessionHandle,
		TA_SYMM_MAC_MODE mode,
		const unsigned char* iv,
		unsigned int index,
		TA_BOOL plain,
		const unsigned char* key, unsigned int keyLen,
		TA_SYMM_ALG alg,
		const unsigned char* data, unsigned int dataLen,
		unsigned char* mac, unsigned int* macLen);



	/**
	* @brief	产生自签名根证
	* @param	hSessionHandle	            [IN]		与设备建立的会话句柄
	* @param	keyType			            [IN]		密钥类型,仅支持TA_RSA,TA_ECC
	* @param	index		            	[IN]		非对称密钥索引 0-1024 0时使用外部密钥
	* @param	usage			            [IN]		密钥使用标识 仅当密钥索引非0时存在
	* @param	curve			            [IN]		ecc曲线标识 仅当密钥索引为0，且密钥类型为TA_SM2时存在
	* @param	priKeyCipherByLmk			[IN]		LMK加密的私钥密文 仅当index=0时存在
	* @param	priKeyCipherByLmkLen		[IN]		LMK加密的私钥密文长度
	* @param	dnType				        [IN]		DN间隔符类型 0 - 逗号分隔 1 - 斜线分隔
	* @param	dn			                [IN]		证书DN
	* @param	dnLen			            [IN]		证书DN长度
	* @param	alg			                [IN]		算法标识TA_SHA1 - Sha1WithRSA/SHA1（非SM2）
																TA_SHA256 - Sha256WithRSA/SHA256（非SM2）
																TA_SM3 - SM3WithSM2（仅SM2）
	* @param	vaildTime			        [IN]	    有效期(天)1 - 3650
	* @param	outCertType			        [IN]		证书输出格式
	* @param	cert			            [OUT]		输出的自签名证书
	* @param	certLen			            [OUT]		输出的自签名证书长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateSignRootCert(void* hSessionHandle,
		TA_KEY_TYPE keyType,
		unsigned int index,
		TA_ASYMM_USAGE usage,
		TA_ECC_CURVE curve,
		const unsigned  char* priKeyCipherByLmk,
		unsigned int priKeyCipherByLmkLen,
		unsigned int dnType,
		const unsigned  char* dn,
		unsigned int dnLen,
		TA_HASH_ALG alg,
		unsigned int vaildTime,
		TA_CERT_TYPE outCertType,
		unsigned  char* cert,
		unsigned  int* certLen);


	/**
	* @brief	产生自签名根证(带扩展属性)
	* @param	hSessionHandle	            [IN]		与设备建立的会话句柄
	* @param	keyType			            [IN]		密钥类型,仅支持TA_RSA,TA_ECC
	* @param	index		            	[IN]		非对称密钥索引 0-1024 0时使用外部密钥
	* @param	usage			            [IN]		密钥使用标识 仅当密钥索引非0时存在
	* @param	curve			            [IN]		ecc曲线标识 仅当密钥索引为0，且密钥类型为TA_SM2时存在
	* @param	priKeyCipherByLmk			[IN]		LMK加密的私钥密文 仅当index=0时存在
	* @param	priKeyCipherByLmkLen		[IN]		LMK加密的私钥密文长度
	* @param	dnType				        [IN]		DN间隔符类型 0 - 逗号分隔 1 - 斜线分隔
	* @param	dn			                [IN]		证书DN
	* @param	dnLen			            [IN]		证书DN长度
	* @param	alg			                [IN]		算法标识TA_SHA1 - Sha1WithRSA/SHA1（非SM2）
																TA_SHA256 - Sha256WithRSA/SHA256（非SM2）
																TA_SM3 - SM3WithSM2（仅SM2）
	* @param	vaildTime			        [IN]	    有效期(天)1 - 3650
	* @param	outCertType			        [IN]		证书输出格式
	* @param	extendedAlg			        [IN]		扩展属性类型 0-3
																0 - 无扩展属性
																1 - nsComment
																2 - basicConstraints
																3 - nsComment + basicConstraints
	* @param	nsComment			        [IN]		扩展属性1 nsComment 仅当扩展属性域标识为1或3时存在
	* @param	nsCommentLen			    [IN]		扩展属性1 nsComment长度 仅当扩展属性域标识为1或3时存在
	* @param	basicConstraints			[IN]		扩展属性2 basicConstraints 仅当扩展属性域标识为2或3时存在
	* @param	basicConstraintsLen			[IN]		扩展属性2 basicConstraintsLen 仅当扩展属性域标识为2或3时存在
	* @param	cert			            [OUT]		输出的自签名证书
	* @param	certLen			            [OUT]		输出的自签名证书长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateSignRootCert_V2(void* hSessionHandle,
		TA_KEY_TYPE keyType,
		unsigned int index,
		TA_ASYMM_USAGE usage,
		TA_ECC_CURVE curve,
		const unsigned  char* priKeyCipherByLmk,
		unsigned int priKeyCipherByLmkLen,
		unsigned int dnType,
		const unsigned  char* dn,
		unsigned int dnLen,
		TA_HASH_ALG alg,
		unsigned int vaildTime,
		TA_CERT_TYPE outCertType,
		unsigned int extendedAlg,
		const unsigned char* nsComment,
		unsigned int nsCommentLen,
		const unsigned char* basicConstraints,
		unsigned int basicConstraintsLen,
		unsigned  char* cert,
		unsigned  int* certLen);


	/**
	* @brief	签发下级证书
	* @param	hSessionHandle	            [IN]		与设备建立的会话句柄
	* @param	supKeyType					[IN]		上级密钥类型，仅支持 TA_RSA TA_ECC
	* @param	supIndex		            [IN]		上级密钥索引 0-1024 0时使用外部密钥
	* @param	supUsage			        [IN]		上级密钥使用标识 仅当上级密钥索引非0时存在
	* @param	supCurve			        [IN]		上级ECC密钥曲线标识，仅当上级密钥索引为0，且密钥类型为TA_ECC时存在
	* @param	supPriKeyCipherByLmk	    [IN]		上级LMK加密的私钥密文，仅当上级密钥索引为0时存在
	* @param	supPriKeyCipherByLmkLen		[IN]		上级LMK加密的私钥密文长度
	* @param	supDNType				    [IN]		 DN间隔符类型 : 0 - 逗号分隔 1 - 斜线分隔
	* @param	superDN			            [IN]		上级证书DN 1-256字节
	* @param	superDNLen			        [IN]		上级证书DN长度
	* @param	issueType					[IN]		签发类型:0 - 证书请求签发  1 - 密钥签发
	* @param	reqCertType			        [IN]	    证书请求类型: TA_DER - DER编码   TA_PEM - PEM格式 ，仅当签发类型为0时存在
	* @param	reqCert			            [IN]		证书请求，仅当签发类型为0时存在
	* @param    reqCertLen                  [IN]        证书请求长度
	* @param	subKeyType					[IN]  		下级密钥类型 仅支持 TA_RSA TA_ECC 仅当签发类型为1时存在
	* @param	subIndex		            [IN]  	    下级密钥索引 仅当签发类型为1时存在 0-1024 0时使用外部密钥
	* @param	subUsage			        [IN]  		下级密钥使用标识 仅当下级密钥索引非0时存在
	* @param	subCurve		            [IN]  	    下级ECC密钥曲线标识 仅当下级密钥索引为0，且密钥类型为TA_ECC时存在
	* @param	subPucKeyDer			    [IN]  		下级密钥公钥（Der编码格式） 仅当签发类型为1且下级密钥索引为0时存在
	* @param	subPucKeyDerLen				[IN]  	    下级密钥公钥（Der编码格式）长度 仅当签发类型为1且下级密钥索引为0时存在
	* @param	subDNType			        [IN]  		DN间隔符类型: 0 - 逗号分隔 1 - 斜线分隔 仅当签发类型为1时存在
	* @param	subDN			            [IN]  		下级证书DN 仅当签发类型为1时存在
	* @param	subDNLen		            [IN]  	    下级证书DN长度                        
	* @param	alg			                [IN]  		算法标识 TA_SHA1 - Sha1WithRSA/SHA1（非SM2）
																 TA_SHA256 - Sha256WithRSA/SHA256（非SM2）
																 TA_SM3 - SM3WithSM2（SM2）
	* @param	vaildTime		            [IN]  	    有效期(天) 1-3650
	* @param	outCertType		            [IN]  	    输出格式： TA_DER - der编码格式   TA_PEM - PEM格式
	* @param	extendedAlg			        [IN]		扩展属性类型 0-3
																0 - 无扩展属性
																1 - nsComment
																2 - basicConstraints
																3 - nsComment + basicConstraints
	* @param	nsComment			        [IN]		扩展属性1 nsComment 仅当扩展属性域标识为1或3时存在
	* @param	nsCommentLen			    [IN]		扩展属性1 nsComment长度 仅当扩展属性域标识为1或3时存在
	* @param	basicConstraints			[IN]		扩展属性2 basicConstraints 仅当扩展属性域标识为2或3时存在
	* @param	basicConstraintsLen			[IN]		扩展属性2 basicConstraintsLen 仅当扩展属性域标识为2或3时存在
	* @param	cert			            [OUT]		输出的自签名证书
	* @param	certLen			            [OUT]	    输出的自签名证书长度
	* @return
	* @retval	0		成功
	* @retval	非0		失败，返回错误代码
	*/
	int Tass_IssueSubordinateCert_V2(void* hSessionHandle,
		TA_KEY_TYPE supKeyType,//上级密钥类型
		unsigned int supIndex,
		TA_ASYMM_USAGE supUsage,
		TA_ECC_CURVE supCurve,
		const unsigned  char* supPriKeyCipherByLmk,
		unsigned int supPriKeyCipherByLmkLen,
		unsigned int supDNType,
		const unsigned  char* supDN,
		unsigned int supDNLen,
		unsigned int issueType, TA_CERT_TYPE reqCertType,
		unsigned char* reqCert, unsigned int reqCertLen,
		//下级密钥类型
		TA_KEY_TYPE subKeyType,
		unsigned int subIndex,
		TA_ASYMM_USAGE subUsage,
		TA_ECC_CURVE subCurve,
		const unsigned  char* subPucKeyDer,
		unsigned int subPucKeyDerLen,
		unsigned int subDNType,
		const unsigned   char* subDN,
		unsigned int subDNLen,
		TA_HASH_ALG alg,
		unsigned int vaildTime, TA_CERT_TYPE outCertType,
		unsigned int extendedAlg,
		const unsigned char* nsComment,
		unsigned int nsCommentLen,
		const unsigned char* basicConstraints,
		unsigned int basicConstraintsLen,
		unsigned char* cert, unsigned int* certLen);




	/**
	* @brief	签发下级证书（带扩展属性）
	* @param	hSessionHandle	            [IN]		与设备建立的会话句柄
	* @param	supKeyType					[IN]		上级密钥类型，仅支持 TA_RSA TA_ECC
	* @param	supIndex		            [IN]		上级密钥索引 0-1024 0时使用外部密钥
	* @param	supUsage			        [IN]		上级密钥使用标识 仅当上级密钥索引非0时存在
	* @param	supCurve			        [IN]		上级ECC密钥曲线标识，仅当上级密钥索引为0，且密钥类型为TA_ECC时存在
	* @param	supPriKeyCipherByLmk	    [IN]		上级LMK加密的私钥密文，仅当上级密钥索引为0时存在
	* @param	supPriKeyCipherByLmkLen		[IN]		上级LMK加密的私钥密文长度
	* @param	supDNType				    [IN]		 DN间隔符类型 : 0 - 逗号分隔 1 - 斜线分隔
	* @param	superDN			            [IN]		上级证书DN 1-256字节
	* @param	superDNLen			        [IN]		上级证书DN长度
	* @param	issueType					[IN]		签发类型:0 - 证书请求签发  1 - 密钥签发
	* @param	reqCertType			        [IN]	    证书请求类型: TA_DER - DER编码   TA_PEM - PEM格式 ，仅当签发类型为0时存在
	* @param	reqCert			            [IN]		证书请求，仅当签发类型为0时存在
	* @param    reqCertLen                  [IN]        证书请求长度
	* @param	subKeyType					[IN]  		下级密钥类型 仅支持 TA_RSA TA_ECC 仅当签发类型为1时存在
	* @param	subIndex		            [IN]  	    下级密钥索引 仅当签发类型为1时存在 0-1024 0时使用外部密钥
	* @param	subUsage			        [IN]  		下级密钥使用标识 仅当下级密钥索引非0时存在
	* @param	subCurve		            [IN]  	    下级ECC密钥曲线标识 仅当下级密钥索引为0，且密钥类型为TA_ECC时存在
	* @param	subPucKeyDer			    [IN]  		下级密钥公钥（Der编码格式） 仅当签发类型为1且下级密钥索引为0时存在
	* @param	subPucKeyDerLen				[IN]  	    下级密钥公钥（Der编码格式）长度 仅当签发类型为1且下级密钥索引为0时存在
	* @param	subDNType			        [IN]  		DN间隔符类型: 0 - 逗号分隔 1 - 斜线分隔 仅当签发类型为1时存在
	* @param	subDN			            [IN]  		下级证书DN 仅当签发类型为1时存在
	* @param	subDNLen		            [IN]  	    下级证书DN长度
	* @param	alg			                [IN]  		算法标识 TA_SHA1 - Sha1WithRSA/SHA1（非SM2）
																 TA_SHA256 - Sha256WithRSA/SHA256（非SM2）
																 TA_SM3 - SM3WithSM2（SM2）
	* @param	vaildTime		            [IN]  	    有效期(天) 1-3650
	* @param	outCertType		            [IN]  	    输出格式： TA_DER - der编码格式   TA_PEM - PEM格式
	* @param	cert			            [OUT]		输出的自签名证书
	* @param	certLen			            [OUT]	    输出的自签名证书长度
	* @return
	* @retval	0		成功
	* @retval	非0		失败，返回错误代码
	*/
	int Tass_IssueSubordinateCert(void* hSessionHandle,
		TA_KEY_TYPE supKeyType,//上级密钥类型
		unsigned int supIndex,
		TA_ASYMM_USAGE supUsage,
		TA_ECC_CURVE supCurve,
		const unsigned  char* supPriKeyCipherByLmk,
		unsigned int supPriKeyCipherByLmkLen,
		unsigned int supDNType,
		const unsigned  char* supDN,
		unsigned int supDNLen,
		unsigned int issueType, TA_CERT_TYPE reqCertType,
		unsigned char* reqCert, unsigned int reqCertLen,
		//下级密钥类型
		TA_KEY_TYPE subKeyType,
		unsigned int subIndex,
		TA_ASYMM_USAGE subUsage,
		TA_ECC_CURVE subCurve,
		const unsigned  char* subPucKeyDer,
		unsigned int subPucKeyDerLen,
		unsigned int subDNType,
		const unsigned   char* subDN,
		unsigned int subDNLen,
		TA_HASH_ALG alg,
		unsigned int vaildTime, TA_CERT_TYPE outCertType,
		unsigned char* cert, unsigned int* certLen);

	/**
	* @brief	产生证书请求
	* @param	hSessionHandle	            [IN]		与设备建立的会话句柄
	* @param	keyType			            [IN]		上级密钥类型 仅支持 TA_RSA/TA_ECC
	* @param	index		            	[IN]		非对称密钥索引 0-1024 0时使用外部密钥
	* @param	usage			            [IN]		密钥使用标识 仅当密钥索引非0时存在
	* @param	curve			            [IN]		ECC曲线标识 仅当密钥索引为0，且密钥类型为TA_ECC时存在
	* @param	priKeyCipherByLmk			[IN]		LMK加密的私钥密文  index为0时有效
	* @param	priKeyCipherByLmkLen		[IN]		LMK加密的私钥密文长度  index为0时有效
	* @param	dnType				        [IN]		DN间隔符类型 0 - 逗号分隔  1 - 斜线分隔
	* @param	dn			                [IN]		证书DN
	* @param	dnLen			            [IN]		证书DN长度
	* @param	alg			                [IN]		算法标识 TA_SHA1 - Sha1WithRSA/SHA1（非SM2）
																 TA_SHA256 - Sha256WithRSA/SHA256（非SM2）
																 TA_SM3 - SM3WithSM2（SM2）
	* @param	outType				        [IN]		输出格式 ： TA_DER - der编码格式   TA_PEM - PEM格式
	* @param	reqCert			            [OUT]		输出的证书请求
	* @param	reqCertLen			        [OUT]	    输出的证书请求长度
	* @return
	*   @retval	0		成功
	*   @retval	非0		失败，返回错误代码
	*/
	int Tass_GenerateCertReq(void* hSessionHandle,
		TA_KEY_TYPE keyType,
		unsigned int index,
		TA_ASYMM_USAGE usage,
		TA_ECC_CURVE curve,
		const unsigned char* priKeyCipherByLmk,
		unsigned int priKeyCipherByLmkLen,
		unsigned int dnType,
		const unsigned  char* dn, unsigned int dnLen,
		TA_HASH_ALG alg,
		TA_CERT_TYPE outType,
		unsigned  char* reqCert, unsigned int* reqCertLen);


#ifdef __cplusplus
}
#endif
