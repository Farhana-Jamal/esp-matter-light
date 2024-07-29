idf_component_register(SRCS "ota.c" "button.c"
                       INCLUDE_DIRS "." 
                       PRIV_REQUIRES driver
                       EMBED_TXTFILES server_certs/ca_cert.pem)