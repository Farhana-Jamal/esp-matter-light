#include "button.h"
#include "ota.h"

#define BUTTON_GPIO   GPIO_NUM_5
#define LONG_PRESS_TIME_MS 7000          // 7 seconds

static const char* TAG = "Button";

// Variable to store button handle
static button_handle_t btn_handle = 0;

// Callback function for the start of a long button press
static void button_long_press_start_cb(void *arg, void *data)
{
    ESP_LOGI(TAG,"BTN: BUTTON_LONG_PRESS_START");
    xTaskCreate(&ota_update_task, "ota_update_task", 8192, NULL, 5, NULL);
}

void firmware_update_btn_setup(void)
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
}