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

#include "hal_sys_param.h"
#include "stdint.h"

#define HEX_A               0xa
#define CHAR_NUM_OFFSET     0x30
#define CHAR_CAPITAL_OFFSET 0x37
#define SERIAL_LEN          8
#define UID_LEN             16
#define UID_SHIFT           4
#define UID_HIGH_MASK       0xf0
#define UID_LOW_MASK        0x0f

static const char OHOS_DEVICE_TYPE[] = {"****"};
static const char OHOS_DISPLAY_VERSION[] = {"OpenHarmony 1.0.1"};
static const char OHOS_MANUFACTURE[] = {"****"};
static const char OHOS_BRAND[] = {"****"};
static const char OHOS_MARKET_NAME[] = {"****"};
static const char OHOS_PRODUCT_SERIES[] = {"****"};
static const char OHOS_PRODUCT_MODEL[] = {"****"};
static const char OHOS_SOFTWARE_MODEL[] = {"****"};
static const char OHOS_HARDWARE_MODEL[] = {"****"};
static const char OHOS_HARDWARE_PROFILE[] = {"aout:true,display:true"};
static const char OHOS_BOOTLOADER_VERSION[] = {"bootloader"};
static const char OHOS_ABI_LIST[] = {"****"};
static const char OHOS_SERIAL[] = {"1234567890"};  // provided by OEM.
static const int OHOS_FIRST_API_VERSION = 1;

static const char EMPTY_STR[] = {""};
static char serialNumber[(SERIAL_LEN >> 1) + 1];

const char* HalGetDeviceType(void)
{
    return OHOS_DEVICE_TYPE;
}

const char* HalGetManufacture(void)
{
    return OHOS_MANUFACTURE;
}

const char* HalGetBrand(void)
{
    return OHOS_BRAND;
}

const char* HalGetMarketName(void)
{
    return OHOS_MARKET_NAME;
}

const char* HalGetProductSeries(void)
{
    return OHOS_PRODUCT_SERIES;
}

const char* HalGetProductModel(void)
{
    return OHOS_PRODUCT_MODEL;
}

const char* HalGetSoftwareModel(void)
{
    return OHOS_SOFTWARE_MODEL;
}

const char* HalGetHardwareModel(void)
{
    return OHOS_HARDWARE_MODEL;
}

const char* HalGetHardwareProfile(void)
{
    return OHOS_HARDWARE_PROFILE;
}

static char Hex2Char(uint8_t hex)
{
    if (hex < HEX_A) {
        return hex + CHAR_NUM_OFFSET;
    } else {
        return hex + CHAR_CAPITAL_OFFSET;
    }
}

const char* HalGetSerial(void)
{
    int i;
    int j = 0;
    uint8_t UidTmp[SERIAL_LEN];
    uint8_t Uid[UID_LEN];
    
    if (sys_device_uid_get(Uid) == 0) {
        UidTmp[0] = Uid[3];
        UidTmp[1] = Uid[4];
        UidTmp[2] = Uid[5];
        UidTmp[3] = Uid[6];
        UidTmp[4] = Uid[10];
        UidTmp[5] = Uid[13];
        UidTmp[6] = Uid[14];
        UidTmp[7] = Uid[15];
    }

    for (i = 0; i < SERIAL_LEN; i++) {
        uint8_t highFour, lowFour;
        highFour = (UidTmp[i] & UID_HIGH_MASK) >> UID_SHIFT;
        serialNumber[j] = Hex2Char(highFour);
        j++;
        lowFour = UidTmp[i] & UID_LOW_MASK;
        serialNumber[j] = Hex2Char(lowFour);
        j++;
    }

    return serialNumber;
}

const char* HalGetBootloaderVersion(void)
{
    return OHOS_BOOTLOADER_VERSION;
}

const char* HalGetAbiList(void)
{
    return OHOS_ABI_LIST;
}

const char* HalGetDisplayVersion(void)
{
    return OHOS_DISPLAY_VERSION;
}

const char* HalGetIncrementalVersion(void)
{
    return INCREMENTAL_VERSION;
}

const char* HalGetBuildType(void)
{
    return BUILD_TYPE;
}

const char* HalGetBuildUser(void)
{
    return BUILD_USER;
}

const char* HalGetBuildHost(void)
{
    return BUILD_HOST;
}

const char* HalGetBuildTime(void)
{
    return BUILD_TIME;
}

int HalGetFirstApiVersion(void)
{
    return OHOS_FIRST_API_VERSION;
}
