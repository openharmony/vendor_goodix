/*
 * Copyright (c) 2024 GOODIX.
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

#ifndef __USER_APP_H__
#define __USER_APP_H__

#include "gr_includes.h"

/*
 * GLOBAL FUNCTION DECLARATION
 *****************************************************************************************
 */
/**
 *****************************************************************************************
 * @brief Function for user ble event handler.
 *****************************************************************************************
 */
void ble_evt_handler(const ble_evt_t *p_evt);

/**
 *****************************************************************************************
 * @brief This callback will be called when ble stack initialized completely
 *****************************************************************************************
 */
void ble_app_init(void);

#endif

