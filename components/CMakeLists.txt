idf_component_register(SRCS "ota.c" "button.c"
                       INCLUDE_DIRS "." 
                       PRIV_REQUIRES driver esp_event app_update esp_http_client esp_https_ota esp_netif nvs_flash esp_wifi espressif__button
                       EMBED_TXTFILES server_certs/ca_cert.pem)