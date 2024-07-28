#include <stdio.h>
#include "button_gpio.h"
#include "iot_button.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUTTON_GPIO   36
#define LONG_PRESS_TIME_MS 7000 // 7 seconds

static const char* TAG  =  "EXAMPLE";

// Array to store button handles
static button_handle_t btn_handle = 0;


// Callback function for the start of a long button press
static void button_long_press_start_cb(void *arg, void *data)
{
    ESP_LOGI(TAG,"BTN: BUTTON_LONG_PRESS_START");
}

void app_main()
{
    // Configuration for the button
    button_config_t btn_cfg = {
        .type = BUTTON_TYPE_GPIO,
        .long_press_time = LONG_PRESS_TIME_MS, // 7 seconds
        .gpio_button_config = {
            .gpio_num = BUTTON_GPIO,
            .active_level = 1,
        },
    };

    // Create and configure the button
    btn_handle = iot_button_create(&btn_cfg);
    iot_button_register_cb(btn_handle, BUTTON_LONG_PRESS_START, button_long_press_start_cb, NULL);

    while (1) {
        vTaskDelay(1);
    }
    
    // Delete button handles when no longer needed
    iot_button_delete(btn_handle);
}
