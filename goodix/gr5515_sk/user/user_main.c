/*
 * user.c
 *
 *  Created on: 2021年8月23日
 *      Author: jwrr
 */

#include "ohos_init.h"
#include "user_source.h"
#include "user_library.h"
#include <stddef.h>

void UserMain(void)
{
	UserSource(0, NULL);
	UserLibrary(0, NULL);
}

SYS_RUN(UserMain);  // add the function to system loader
