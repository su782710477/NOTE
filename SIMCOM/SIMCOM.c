#include "simcom.h"

uint8_t recvbuff[255];


uint8_t simcom_cmd_with_reply(	const char *cmd,
								const char * DataLen, 
								const char * reply, 
								uint32_t retry,
								uint8_t newline,
							 )
{
	printf("\r\n send the cmd %s to SIMCOM module \r\n",cmd);
	do
	{
		memset(recvbuff, 0, sizeof(recvbuff));		
		if(HAL_UART_Transmit(&huart3, cmd, DataLen, 5000) != HAL_OK)
		{
			return ERROE;
		}
		if(newline == 1)
				if(HAL_UART_Transmit(&huart3, "\r\n", 2, 5000) != HAL_OK)
				{
					return ERROE;
				}
		HAL_Delay(100);
		if(	strstr(	(char const *)recvbuff, reply	) != NULL	)
		{
			return SUCCESS;
		}
	}while( retry-- )
	
	return ERROR
}


uint8_t simcom_cmd_sprintf(	const char *cmd,... )
{
	va_list args;  
	va_start(args,n);  
	while(n>0)  
	{  
	//通过va_arg(args,int)依次获取参数的值   
     sum+=va_arg(args,int);  
     n--;  
	}  
	va_end(args);
	
	
	switch(cmd)
	case tcp:
}





