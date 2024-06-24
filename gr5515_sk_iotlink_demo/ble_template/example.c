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

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "gr_includes.h"
#include "user_app.h"
#include "los_task.h"
#include "app_io.h"

#define BLE_TASK_STACK_SIZE   4096
#define BLE_TASK_PRIO         25
#define MS_1000     1000

/**@brief Stack global variables for Bluetooth protocol stack. */
STACK_HEAP_INIT(heaps_table);

static void *BLE_Task(const char *arg)
{
    (void)arg;
    const uint8_t test_bd_addr[SYS_BD_ADDR_LEN] = {0x20, 0x15, 0x55, 0x1c, 0x00, 0x92};
    SYS_SET_BD_ADDR(test_bd_addr);

    printf("Initialize the BLE stack.\r\n");

    /* init ble stack */
    ble_stack_init(&ble_evt_handler, &heaps_table);

    uint64_t lastTick = LOS_SysCycleGet();

    while (1) {
        osDelay(MS_1000);
    }
}

LosTaskCB *g_bleTcb = NULL;

void BLE_TaskEntry(void)
{
    osThreadAttr_t attr;

    attr.name       = "BLE_Task";
    attr.attr_bits  = 0U;
    attr.cb_mem     = NULL;
    attr.cb_size    = 0U;
    attr.stack_mem  = NULL;
    attr.stack_size = BLE_TASK_STACK_SIZE;
    attr.priority   = BLE_TASK_PRIO;

    g_bleTcb = osThreadNew((osThreadFunc_t)BLE_Task, NULL, &attr);

    LOS_ASSERT_COND(g_bleTcb != NULL);

    pwr_mgmt_mode_set(PMR_MGMT_SLEEP_MODE);
}

SYS_RUN(BLE_TaskEntry);
