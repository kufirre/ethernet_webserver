/*
 * ssi_process.c
 *
 *  Created on: May 30, 2022
 *      Author: Kufy Ebong
 */

#include "ssi_process.h"
#include <string.h>
#include "main.h"
#include "lwip/apps/httpd.h"


extern uint32_t g_sensor_value;

char const* ssi_tags[] ={"SENSOR"};
char const** tags = ssi_tags;


uint16_t ssi_handler(int iIndex, char *pcInsert, int iInsertLen)
{
	sprintf(pcInsert,"%ld", g_sensor_value);
	return strlen(pcInsert);
}
