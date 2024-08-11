#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_ota_ops.h"
#include "esp_http_client.h"
#include "esp_https_ota.h"
#include "string.h"
#ifdef CONFIG_EXAMPLE_USE_CERT_BUNDLE
#include "esp_crt_bundle.h"
#endif

#include "nvs.h"
#include "nvs_flash.h"
#include <sys/socket.h>
#include "esp_wifi.h"
#include "protocol_examples_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define OTA_URL_SIZE 256
#define HASH_LEN 32

void ota_setup(void);
void ota_update_task(void *pvParameter);

#ifdef __cplusplus
}
#endif
