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

static uint16_t gpio_led1 = 4;
static uint16_t gpio_led2 = 44;
static uint16_t gpio_button_up   = 12;
static uint16_t gpio_button_down = 13;
static uint16_t gpio_button_left = 14;
static uint16_t gpio_button_righ = 15;
static uint16_t gpio_irq_state = 0;

static void gpio_output_test(void)
{
    static int cnt = 0;

    LOG_I("set gpio %d output\r\n", gpio_led1);
    GpioSetDir(gpio_led1, GPIO_DIR_OUT);
    GpioSetDir(gpio_led2, GPIO_DIR_OUT);

    if (cnt++ % 2)
    {
        LOG_I("set led on\r\n");
        GpioWrite(gpio_led1, GPIO_VAL_LOW);
    }
    else
    {
        LOG_I("set led of\r\n");
        GpioWrite(gpio_led1, GPIO_VAL_HIGH);
    }
}

static void gpio_input_test(void)
{
    int cnt = 0;
    uint16_t val = 1;

    GpioSetDir(gpio_button_up, GPIO_DIR_IN);
    LOG_I("please push up key: >>> ");
    while (cnt++ < 10)
    {
        GpioRead(gpio_button_up, &val);
        if (0 == val)
        {
            LOG_I("up key\r\n");
            break;
        }

        osDelay(100);
    }

    if (val)
        LOG_I("none key\r\n");
}

static int32_t gpio_irq_handler(uint16_t gpio, void *data)
{
    uint16_t val = 0;

    LOG_I("%s enter, gpio = %d, data = %d\r\n", __func__, gpio, *(int *)data);

    gpio_irq_state = *(int *)data;

    return 0;
}

static void gpio_irq_test(void)
{
    static int val = 1234;

    if (0 == gpio_irq_state)
    {
        LOG_I("set key_left (gpio %d) input, @%p\r\n", gpio_button_left, gpio_irq_handler);
        GpioSetDir(gpio_button_left, GPIO_DIR_IN);
        GpioSetIrq(gpio_button_left, GPIO_IRQ_TRIGGER_RISING, (GpioIrqFunc)gpio_irq_handler, &val);
        GpioEnableIrq(gpio_button_left);

        gpio_irq_state = 1;
    }
}

void gpio_test()
{
    gpio_output_test();
    // gpio_input_test();
    // gpio_irq_test();

    // if (gpio_irq_state == 1234)
    // {
    //     static int led2_state = GPIO_VAL_LOW;

    //     GpioWrite(gpio_led2, (enum GpioValue)led2_state);

    //     gpio_irq_state = 1;
    //     led2_state = !led2_state;
    // }
}