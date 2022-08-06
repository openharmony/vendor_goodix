# vendor_goodix

## 介绍

该仓库托管Goodix开发的基于GR551x BLE产品样例代码。

## 产品样例

支持基于Goodix GR5515 SoC的Starter Kit单板进行开发的BLE应用、XTS测试样例。

代码路径：

```
device/                               --- 硬件单板相关仓库
├── boards/goodix                     --- Goodix相关单板
├── soc/goodix                        --- Goodix相关SoC代码
vendor/goodix/                        --- vendor_goodix 仓库路径
├── gr5515_sk_iotlink_demo            --- BLE应用样例
└── gr5515_sk_xts_demo                --- XTS测试样例
```

## 新建样例

用户可以将提供的XTS样例复制一份，然后进行裁剪或者修改，实现自己的产品工程，下面举例说明如何新建一个工程，并实现"点灯"。

### 新建工程

1. 复制一份"gr5515_sk_xts_demo"放在同级目录下，并改名为"gr5515_sk_led_demo"；
2. 进入gr5515_sk_led_demo目录, 编辑config.json文件，修改product_name和product_adapter_dir：

```
"product_name": "gr5515_sk_led_demo"
"product_adapter_dir": "//vendor/goodix/gr5515_sk_led_demo/hals"
```
3. 此工程业务逻辑简单，一些用不到的组件可以去掉，减少源码编译时间，在config.json中可删除xts、security子系统，保留kernel、startup、hiviewdfx、systemabilitymgr等必要的子系统，可移除如下代码段：

```
{
"subsystem": "xts",
"components": [
    { "component": "xts_acts", "features":[] },
    { "component": "xts_tools", "features":[] }
    ]
},
{
"subsystem": "security",
"components": [
    { "component": "huks", "features": 
    [
        "disable_huks_binary  = true",
        "disable_authenticate = false",
        "huks_use_lite_storage = false",
        "huks_use_hardware_root_key = false",
        "huks_config_file = \"hks_config_lite.h\""
    ]
    }
]
}
```

4. 编辑"gr5515_sk_led_demo/BUILD.gn"，修改固件名(这里取名为app_led)，group名：

```
# Set firmware name
fw_img_name = "app_led"

...

group("gr5515_sk_led_demo") {
}

```

### 实现业务

1. 在gr5515_sk_led_demo目录下新建一个led文件夹，用于存放应用源码，并在led目录下新建led.c、BUILD.gn。

2. 编辑led.c，调用Harmony OS标准API创建任务，调用HDF驱动接口驱动LED灯，示例如下代码段所示：

```
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "gpio_if.h"

#define LED_TASK_STACK_SIZE   4096
#define LED_TASK_PRIO         25
#define LED0                  4

static void *LedTask(const char *arg)
{
    (void)arg;

    GpioSetDir(LED0, GPIO_DIR_OUT);

    while (1) {
        GpioWrite(LED0, GPIO_VAL_LOW);
        osDelay(1000);
        GpioWrite(LED0, GPIO_VAL_HIGH);
        osDelay(1000);
    }
}

void LedTaskEntry(void)
{
    osThreadAttr_t attr;

    attr.name = "LedTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = LED_TASK_STACK_SIZE;
    attr.priority = LED_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)LedTask, NULL, &attr) == NULL) {
        printf("Falied to create LedTask!\n");
    }
}

SYS_RUN(LedTaskEntry);

```

3. 编辑"led/BUILD.gn"将led.c业务代码加入编译，参考示例如下：

```
import("//device/board/goodix/${board_name}/liteos_m/config.gni")

static_library("led_demo") {
   configs = []

   sources = [
      "led.c",
   ]

   cflags = board_cflags
   include_dirs = board_include_dirs
}
```
led.c编译后，会在libs目录下生成"libled_demo.a"静态库。

4. 编辑"gr5515_sk_led_demo/BUILD.gn", 将"led_demo"加入工程依赖，移除XTS相关的静态库，并添加"libled_demo.a"静态，如下示例代码所示：

```
executable("${fw_img_name}.elf") {
    deps = [
        "//build/lite:ohos",
        "led:led_demo",
    ]

    ldflags = [
        "-Wl,--whole-archive",
        "-lled_demo",
        "-Wl,--no-whole-archive",
    ]
}
```

### 编译烧录

在OpenHarmony源码根目录下，执行`hb set`, 选中"gr5515_sk_led_demo"工程：

```
goodix
   gr5515_sk_xts_demo
 ❯ gr5515_sk_led_demo
```

继续执行 `hb build -f`, 开始构建工程，待工程构建完毕，生成的固件存放在"**/out/gr5515_sk/gr5515_sk_led_demo/bin/app_led/app_led_fw.bin**", 可使用GProgrammer软件烧录到Flash。

更详细的编译和烧录过程，请参考 [编译烧录教程](https://gitee.com/openharmony-sig/device_soc_goodix/blob/master/README.md)

如果用户使用的是GR5515 Starter Kit开发板，固件烧录成功后，程序启动将观察到开发板上LED0间隔1S闪烁。

至此，基于OpenHarmony的一个简单的示例工程搭建完成，用户可按此方法，搭建自己产品工程。

## 贡献

[如何参与](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/contribute/%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE.md)

[Commit message规范](https://gitee.com/openharmony/device_qemu/wikis/Commit%20message%E8%A7%84%E8%8C%83?sort_id=4042860)


## 相关仓库

[device_soc_goodix](https://gitee.com/openharmony/device_soc_goodix)

[device_board_goodix](https://gitee.com/openharmony/device_board_goodix)
