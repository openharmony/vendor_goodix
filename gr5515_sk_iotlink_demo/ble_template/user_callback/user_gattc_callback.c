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

/*
 * INCLUDE FILES
 *****************************************************************************************
 */
#include "gr55xx_sys.h"

/*
* LOCAL FUNCTION DECLARATION
******************************************************************************************
*/
static void app_gattc_srvc_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_srvc_disc_t *p_prim_srvc_disc);
static void app_gattc_inc_srvc_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_incl_disc_t *p_inc_srvc_disc);
static void app_gattc_char_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_char_disc_t *p_char_disc);
static void app_gattc_char_desc_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_char_desc_disc_t *p_char_desc_disc);
static void app_gattc_read_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_read_rsp_t *p_read_rsp);
static void app_gattc_write_cb(uint8_t conn_idx, uint8_t status, uint16_t handle);
static void app_gattc_ntf_ind_cb(uint8_t conn_idx, const ble_gattc_ntf_ind_t *p_ntf_ind);
static void app_gattc_srvc_browse_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_browse_srvc_t *p_browse_srvc);

/*
 * GLOBAL VARIABLE DEFINITIONS
 *****************************************************************************************
 */
const gattc_cb_fun_t app_gattc_callback =
{
    .app_gattc_srvc_disc_cb      = app_gattc_srvc_disc_cb,
    .app_gattc_inc_srvc_disc_cb  = app_gattc_inc_srvc_disc_cb,
    .app_gattc_char_disc_cb      = app_gattc_char_disc_cb,
    .app_gattc_char_desc_disc_cb = app_gattc_char_desc_disc_cb,
    .app_gattc_write_cb          = app_gattc_write_cb,
    .app_gattc_read_cb           = app_gattc_read_cb,
    .app_gattc_ntf_ind_cb        = app_gattc_ntf_ind_cb,
    .app_gattc_srvc_browse_cb    = app_gattc_srvc_browse_cb,
};

/*
 * LOCAL FUNCTION DEFINITIONS
 *****************************************************************************************
 */
/**
 *****************************************************************************************
 * @brief This callback function will be called when primary service has been discovered.
 *
 * @param[in] conn_idx:         The connection index.
 * @param[in] status:           The status of GATTC operation.
 * @param[in] p_prim_srvc_disc: The information of primary service. See @ref ble_gattc_srvc_disc_t.
 *****************************************************************************************
 */
static void app_gattc_srvc_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_srvc_disc_t *p_prim_srvc_disc)
{

}

/**
 *****************************************************************************************
 * @brief This callback function will be called when service relationship has been discovered.
 *
 * @param[in] conn_idx:        The connection index.
 * @param[in] status:          The status of GATTC operation.
 * @param[in] p_inc_srvc_disc: The information of service relationship. See @ref ble_gattc_incl_disc_t.
 *****************************************************************************************
 */
static void app_gattc_inc_srvc_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_incl_disc_t *p_inc_srvc_disc)
{

}

/**
 *****************************************************************************************
 * @brief This callback function will be called when descriptor(s) has been discovered.
 *
 * @param[in] conn_idx:        The connection index.
 * @param[in] status:          The status of GATTC operation.
 * @param[in] p_char_disc: The information of descriptor(s). See @ref ble_gattc_char_disc_t.
 *****************************************************************************************
 */
static void app_gattc_char_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_char_disc_t *p_char_disc)
{

}

/**
 *****************************************************************************************
 * @brief This callback function will be called when characteristic(s) has been discovered.
 *
 * @param[in] conn_idx:         The connection index.
 * @param[in] status:           The status of GATTC operation.
 * @param[in] p_char_desc_disc: The information of characteristic(s). See @ref ble_gattc_char_desc_disc_t.
 *****************************************************************************************
 */
static void app_gattc_char_desc_disc_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_char_desc_disc_t *p_char_desc_disc)
{

}

/**
 *****************************************************************************************
 * @brief This callback function will be called when receiving read response.
 *
 * @param[in] conn_idx:   The connection index.
 * @param[in] status:     The status of GATTC operation.
 * @param[in] handle:     The handle of attribute.
 *****************************************************************************************
 */
static void app_gattc_write_cb(uint8_t conn_idx, uint8_t status, uint16_t handle)
{

}

/**
 *****************************************************************************************
 * @brief This callback function will be called when receiving read response.
 *
 * @param[in] conn_idx:   The connection index.
 * @param[in] status:     The status of GATTC operation.
 * @param[in] p_read_rsp: The information of read response. See @ref ble_gattc_read_rsp_t.
 *****************************************************************************************
 */
static void app_gattc_read_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_read_rsp_t *p_read_rsp)
{

}

/**
 *****************************************************************************************
 * @brief This callback function will be called when receiving notification or indication.
 *
 * @param[in] conn_idx:  The connection index.
 * @param[in] status:    The status of GATTC operation.
 * @param[in] p_ntf_ind: The information of notification or indication. See @ref ble_gattc_ntf_ind_t.
 *****************************************************************************************
 */
static void app_gattc_ntf_ind_cb(uint8_t conn_idx, const ble_gattc_ntf_ind_t *p_ntf_ind)
{
    if (BLE_GATT_INDICATION == p_ntf_ind->type)
    {
        ble_gattc_indicate_cfm(conn_idx, p_ntf_ind->handle);
    }
}

/**
 *****************************************************************************************
 * @brief This callback function will be called when receiving browse service indication.
 *
 * @param[in] conn_idx:      The connection index.
 * @param[in] status:        The status of GATTC operation.
 * @param[in] p_browse_srvc: The information of service browse. See @ref ble_gattc_browse_srvc_t.
 *****************************************************************************************
 */
static void app_gattc_srvc_browse_cb(uint8_t conn_idx, uint8_t status, const ble_gattc_browse_srvc_t *p_browse_srvc)
{

}
