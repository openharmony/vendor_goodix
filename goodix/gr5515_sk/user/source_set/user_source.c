/*
 * user_source.c
 *
 *  Created on: 2021年8月23日
 *      Author: jwrr
 */

#include "user_source.h"

#include <stdio.h>

int UserSource(int argc, const char *argv[])
{
	const char *moduleName = CN_MODULENAME;
	printf("%s:Hello world in UserSource\r\n",moduleName);
	return 0;
}
