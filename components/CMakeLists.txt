set(src_dirs    ota
                button)
       
       
set(include_dirs    ota
                    button)

set(req     driver
            esp_event
            app_update
            esp_http_client
            esp_https_ota
            esp_netif
            nvs_flash
            esp_wifi
            mbedtls
            espressif__button)
                   
idf_component_register( SRC_DIRS ${src_dirs} 
                        INCLUDE_DIRS ${include_dirs} 
                        REQUIRES ${req} 
                        EMBED_TXTFILES ota/server_certs/ca_cert.pem)