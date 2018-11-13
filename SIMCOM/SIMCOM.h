#ifndef _SIMCOM_H_
#define _SIMCOM_H_
 
//SIMCOM通信模块定义	
typedef enum
{
	SIMCOM_SIM900	=	0	,		//默认为SIM900
	SIMCOM_SIM800	=	1	,		//SIM800
	SIMCOM_SIM2000	=	2	,		//SIM2000
	SIMCOM_SIM7600	=	3	,		//SIM7600
	SIMCOM_SIM868	=	4	,		//SIM868
	SIMCOM_SIM7000C	=	5	,		//SIM7000C
	SIMCOM_SIM7200C	=	6	,		//SIM7200C
	SIMCOM_SIM7600C =	7	,		//SIM7600CE
	SIMCOM_INVALID	=	0XFF	,	//无效则默认
}SIMCOM_MODE_TYPE;	
 
//网络注册状态
typedef enum
{
	SIMCOM_NET_NOT = 0,		//未注册
	SIMCOM_NET_YES = 1,		//已经注册
	SIMCOM_NET_SEA = 2,		//未注册,正在搜索
	SIMCOM_NET_TUR = 3,		//注册被拒绝
	SIMCOM_NET_UNK = 4,		//未知
	SIMCOM_NET_ROA = 5,		//已经注册,但是漫游
	SIMCOM_NET_ERROR=0XFF	//错误
}SIMCOM_NETSTATUS;
 
//SIMCOM网络制式
typedef enum
{
	SIMCOM_NETMODE_NOT 			= 	0,	//未注册
	SIMCOM_NETMODE_GSM			=	1,	//GSM
	SIMCOM_NETMODE_GPRS			=	2,	//GPRS
	SIMCOM_NETMODE_EGPRS		=	3,	//EGPRS (EDGE)
	SIMCOM_NETMODE_WCDMA		=	4,	//WCDMA
	SIMCOM_NETMODE_HSDPA		=	5,	//HSDPA only(WCDMA)
	SIMCOM_NETMODE_HSUPA		=	6,	//HSUPA only(WCDMA)
	SIMCOM_NETMODE_HSPA			=	7,	//HSPA (HSDPA and HSUPA, WCDMA)
	SIMCOM_NETMODE_LTE			=	8,	//LTE
	SIMCOM_NETMODE_TDS_CDMA		=	9,	//TDS-CDMA
	SIMCOM_NETMODE_TDS_HSDPA	=	10,	//TDS-HSDPA only（SIM7000C 电信NB也是这个）
	SIMCOM_NETMODE_TDS_HSUPA	=	11,	//TDS-HSUPA only
	SIMCOM_NETMODE_TDS_HSPA		=	12,	//TDS- HSPA (HSDPA and HSUPA)
	SIMCOM_NETMODE_CDMA			=	13,	//CDMA
	SIMCOM_NETMODE_EVDO			=	14,	//EVDO
	SIMCOM_NETMODE_HYBRID		=	15,	//HYBRID (CDMA and EVDO)
	SIMCOM_NETMODE_1XLTE		=	16,	//1XLTE(CDMA and LTE)
	SIMCOM_NETMODE_NULL			=	0xff,	//未知
}SIMCOM_NETMODE_TYPE;
 
 
//SIM卡就绪状态
typedef enum
{
	SIM_READY			=	0,	//SIM卡就绪
	SIM_NOT_READY		=	1,	//SIM卡未就绪
	SIM_UNKNOWN			=	2	//SIM卡状态未知
}SIM_CARDSTATUS;
  
//DCD状态定义
#define DCD_DATA_MODE		0	//数据透传模式
#define DCD_AT_MODE			1	//AT指令模式
 
//相关信息长度限制
#define SIMCOM_INFO_SIZE	24	//信息长度
#define SIMCOM_VER_SIZE		24	//软件版本长度定义
 
//重试次数,防止AT指令操作失败
#define SIMCOM_DEFAULT_RETRY	5 
 
 
//SIMCOM模块相关信息
typedef struct
{
	char Manu[SIMCOM_INFO_SIZE+1];					//制造商
	char Model[SIMCOM_INFO_SIZE+1];					//型号
	char Ver[SIMCOM_VER_SIZE+1];					//软件版本
	char IMEI[SIMCOM_INFO_SIZE+1];					//序列号
}SIMCOM_INFO;
 
 
//NBIOT模式定义
typedef enum
{
	NB_IOT_MODE = 0,		//NBIOT模式
	CAT_M_MODE = 1,			//CAT-M模式
}NBIOT_MODE_TYPE;
 
//网络模式设置
typedef struct
{
	SIMCOM_MODE_TYPE	ModeType;					//模块型号
	NBIOT_MODE_TYPE 	NB_Mode;					//NB模式
	int8_t NB_EnableMode;								//NB模式使能模式,-1:无需设置；0:关闭NB,使能GSM模式；1:使能NB模式
	bool isNB_ScarEnable;							//NB模式扰码使能
}NETWORK_CONFIG_TYPE;
 
 
 
//SIMCOM通信模块句柄
typedef struct
{
	//所需变量
	SIMCOM_MODE_TYPE	SimcomModeType;				//模块型号
	char TelecomCarr[SIMCOM_INFO_SIZE+1];			//运营商名称
	SIMCOM_INFO SimCom_Info;						//SIMCOM通信模块相关信息结构体
	NETWORK_CONFIG_TYPE NetworkConfig;				//网络模式设置
	SIMCOM_NETMODE_TYPE NetworkMode;				//当前网络制式
	uint8_t Singal;										//网络信号强度
	char LocalPhoneNumber[16];						//本机电话号码
	char ServiceCenterPhoneNumber[16];				//短信中心电话号码
	char SIM_CIMI[16];								//SIM卡唯一CIMI号码
}SIMCOM_HANDLE;
 
 
 
#endif /*_SIMCOM_H_*/
