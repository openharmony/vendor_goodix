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
#include "gpio_if.h"
#include "driver_test.h"
#include "uart_if.h"

static DevHandle uart_handle = NULL;

static void uart_test_case(DevHandle uart_handle)
{
    static int state = 0;
    int32_t ret;
    uint32_t baudrate;
    struct UartAttribute attr;
    uint8_t send_data[] = "Hello OpenHarmony\r\n";
    uint8_t recv_data[16];

    switch (state)
    {
        case 0:
            ret = UartSetBaud(uart_handle, 115200);
            if (ret != 0) {
                LOG_E("%s, state[%d] failed", __func__, state);
                return;
            }
            state++;
            break;
        case 1:
            ret = UartGetBaud(uart_handle, &baudrate);
            if (ret != 0) {
                LOG_E("%s, state[%d] failed", __func__, state);
                return;
            }
            state++;
            LOG_I("get baudrate = %d", baudrate);
            break;
        case 2:
            attr.dataBits = UART_ATTR_DATABIT_8;
            attr.parity = UART_ATTR_PARITY_NONE;
            attr.stopBits = UART_ATTR_STOPBIT_1;
            ret = UartSetAttribute(uart_handle, &attr);
            if (ret != 0) {
                LOG_E("%s, state[%d] failed", __func__, state);
                return;
            }
            state++;
            break;
        case 3:
            ret = UartWrite(uart_handle, send_data, strlen(send_data));
            if (ret != 0) {
                LOG_E("%s, state[%d] failed", __func__, state);
                return;
            }
            //state = 4;
            break;
        case 4:
            ret = UartRead(uart_handle, recv_data, sizeof(recv_data) - 1);
            if (ret > 0)
            {
                recv_data[ret] = 0;
                LOG_I("%s, state[%d] recv:%s", __func__, state, recv_data);
            }
            else
            {
                LOG_I("%s, state[%d] no data received", __func__, state);
            }
            state = 3;
            break;
    }
}

void uart_test()
{
    static int uart_state = 0;

    switch (uart_state)
    {
        default:
        case 0:
            uart_handle = UartOpen(1);
            if (NULL == uart_handle) {
                LOG_E (">>>uart open failed");
            } else {
                LOG_I (">>>uart open success");
                uart_state++;
            }
            break;
        case 1:
            if (uart_handle)
            {
                uart_test_case(uart_handle);
            }
            break;
    }
}
