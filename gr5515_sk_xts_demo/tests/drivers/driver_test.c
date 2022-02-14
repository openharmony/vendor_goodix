/*
 * Copyright (c) 2021 GOODIX.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "driver_test.h"
#include "cmsis_os2.h"
#include "ohos_init.h"

static void driver_test_task(void *arg)
{
    (void)arg;

    LOG_I(">>>xts driver test task start.");

    while (1) {
        gpio_test();
        uart_test();
        osDelay(1000);
    }
}

static void driver_test(void)
{
    HILOG_INFO(HILOG_MODULE_APP, "HILOG_INFO %s\r\n", __func__);
    osThreadAttr_t attr = {0};
    attr.stack_size = 4096;
    attr.priority = osPriorityNormal;
    attr.name = "driver_test";
    if (osThreadNew((osThreadFunc_t)driver_test_task, NULL, &attr) == NULL) {
        HILOG_ERROR(HILOG_MODULE_APP, "Failed to create driver_test_task\r\n");
    }
}

SYS_RUN(driver_test);
