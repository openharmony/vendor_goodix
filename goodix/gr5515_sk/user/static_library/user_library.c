/*
 * user_library.c
 *
 *  Created on: 2021年8月23日
 *      Author: jwrr
 */


#include "user_library.h"

#include <stdio.h>

int UserLibrary(int argc, const char *argv[])
{
	const char *moduleName = CN_MODULENAME;
	printf("%s:Hello world in UserSource\r\n",moduleName);
	return 0;
}

