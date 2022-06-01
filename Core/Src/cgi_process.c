#include "main.h"
#include "cgi_process.h"
#include <string.h>
#include <stdio.h>
#include "lwip/apps/httpd.h"


const char * led_cgi_handler(int iIndex, int iNumParams, char *pcParam[],char *pcValue[]);
const tCGI LED_CGI ={"/leds.cgi", led_cgi_handler};


tCGI CGI_ARR[1];

const char * led_cgi_handler(int iIndex, int iNumParams, char *pcParam[],char *pcValue[])
{
	if(iIndex == 0)
	{
		   HAL_GPIO_WritePin(GPIOB, GREEN_LED_Pin|RED_LED_Pin|BLUE_LED_Pin, GPIO_PIN_RESET);

		   for (int i = 0; i < iNumParams; i++)
		   {

				  if(strcmp(pcParam[i] ,"led") == 0)
				  {
					  if(strcmp(pcValue[i], "1") == 0)
					  {
						  HAL_GPIO_WritePin(GPIOB,RED_LED_Pin,GPIO_PIN_SET) ;
					  }

					  else if(strcmp(pcValue[i], "2") == 0)
					  {
						  HAL_GPIO_WritePin(GPIOB,BLUE_LED_Pin,GPIO_PIN_SET) ;
					  }

					  else if(strcmp(pcValue[i], "3") == 0)
					  {
						  HAL_GPIO_WritePin(GPIOB,GREEN_LED_Pin,GPIO_PIN_SET) ;
					  }

				  }


		   }


	}
	return "/led_control.html";
}
