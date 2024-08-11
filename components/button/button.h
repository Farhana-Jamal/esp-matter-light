#ifndef _APP_BUTTON_H_
#define _APP_BUTTON_H_

#include "esp_log.h"
#include "button_gpio.h"
#include "iot_button.h"
#include "ota.h"

#ifdef __cplusplus
extern "C"
{
#endif

void firmware_update_btn_setup();

#ifdef __cplusplus
}
#endif

#endif