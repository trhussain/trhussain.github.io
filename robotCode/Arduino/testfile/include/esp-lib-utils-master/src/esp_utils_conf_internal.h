/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

// *INDENT-OFF*

/* Handle special Kconfig options */
#ifndef ESP_UTILS_KCONFIG_IGNORE
    #include "sdkconfig.h"
    #ifdef CONFIG_ESP_UTILS_CONF_FILE_SKIP
        #define ESP_UTILS_CONF_FILE_SKIP
    #endif
#endif

#ifndef ESP_UTILS_CONF_FILE_SKIP
    /* If "esp_utils_conf.h" is available from here, try to use it later */
    #ifdef __has_include
        #if __has_include("esp_utils_conf.h")
            #ifndef ESP_UTILS_CONF_INCLUDE_SIMPLE
                #define ESP_UTILS_CONF_INCLUDE_SIMPLE
            #endif
        #elif __has_include("../../esp_utils_conf.h")
            #ifndef ESP_UTILS_CONF_INCLUDE_OUTSIDE
                #define ESP_UTILS_CONF_INCLUDE_OUTSIDE
            #endif
        #else
            #define ESP_UTILS_CONF_INCLUDE_INSIDE
        #endif
    #else
        #define ESP_UTILS_CONF_INCLUDE_OUTSIDE
    #endif
#endif

/* Include type definitions before including configuration header file */
#include "esp_utils_types.h"

/* If "esp_utils_conf.h" is not skipped, include it */
#ifndef ESP_UTILS_CONF_FILE_SKIP
    #ifdef ESP_UTILS_CONF_PATH                          /* If there is a path defined for "esp_utils_conf.h" use it */
        #define __TO_STR_AUX(x) #x
        #define __TO_STR(x) __TO_STR_AUX(x)
        #include __TO_STR(ESP_UTILS_CONF_PATH)
        #undef __TO_STR_AUX
        #undef __TO_STR
    #elif defined(ESP_UTILS_CONF_INCLUDE_SIMPLE)        /* Or simply include if "esp_utils_conf.h" is available */
        #include "esp_utils_conf.h"
    #elif defined(ESP_UTILS_CONF_INCLUDE_OUTSIDE)       /* Or include if "../../esp_utils_conf.h" is available */
        #include "../../esp_utils_conf.h"
    #elif defined(ESP_UTILS_CONF_INCLUDE_INSIDE)        /* Or include the default configuration */
        #include "../esp_utils_conf.h"
    #endif
#endif

#ifndef ESP_UTILS_CONF_INCLUDE_INSIDE
    /**
     * There are two purposes to include the this file:
     *  1. Convert configuration items starting with `CONFIG_` to the required configuration items.
     *  2. Define default values for configuration items that are not defined to keep compatibility.
     *
     */
    #include "esp_utils_conf_kconfig.h"
#endif

// *INDENT-OFF*
