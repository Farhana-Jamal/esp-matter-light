#pragma once

#define CONFIG_EXAMPLE_USE_CERT_BUNDLE  1
#define CONFIG_EXAMPLE_FIRMWARE_UPGRADE_URL "https://192.168.0.3:8070/hello_world.bin"

void ota_task(void);