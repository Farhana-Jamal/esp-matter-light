# ESP-Matter Light Example with ESP Standard HTTPS OTA Update

This project demonstrates how to build and flash the ESP-Matter light example project. Additionally, it shows how to initialize a button on an ESP32 that triggers an ESP standard HTTPS OTA update when pressed for 7 seconds.

## Prerequisites

### Install ESP-IDF

1. Install the required packages:

   ```bash
   sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
   ```

2. Clone the ESP-IDF repository and install:

   ```bash
   mkdir -p ~/esp
   cd ~/esp
   git clone --recursive https://github.com/espressif/esp-idf.git
   cd esp-idf
   git checkout v5.2.1
   git submodule update --init --recursive
   ./install.sh
   cd ..
   ```

3. Configure the shell environment:

   ```bash
   cd esp-idf
   source ./export.sh
   cd ..
   ```

### Install ESP-Matter

1. Install the necessary packages:

   ```bash
   sudo apt-get install git gcc g++ pkg-config libssl-dev libdbus-1-dev \
   libglib2.0-dev libavahi-client-dev ninja-build python3-venv python3-dev \
   python3-pip unzip libgirepository1.0-dev libcairo2-dev libreadline-dev
   ```

2. Clone the ESP-Matter repository and install:

   - Ensure the ESP-IDF environment is configured:

     ```bash
     cd esp-idf
     source ./export.sh
     cd ..
     ```

   - Clone the repository:

     ```bash
     git clone --depth 1 https://github.com/espressif/esp-matter.git
     cd esp-matter
     git submodule update --init --depth 1
     cd ./connectedhomeip/connectedhomeip
     ./scripts/checkout_submodules.py --platform esp32 linux --shallow
     cd ../..
     ./install.sh
     ```

## Building the Project

### Clone the Project Repository

1. Clone this repository into your desired folder:

   ```bash
   git clone https://github.com/Farhana-Jamal/esp-matter-light.git
   cd esp-matter-light
   ```

2. Configure the environment:

   ```bash
   source ~/esp/esp-idf/export.sh
   source ~/esp/esp-matter/export.sh
   ```

### Configure Wi-Fi SSID, Password, and IP Address for Your Server

1. Open the configuration menu:

   ```bash
   idf.py menuconfig
   ```

2. Set the Firmware Upgrade URL in `Example Configuration`:
   - Find your IP address by running `ifconfig` and noting the IPv4 `inet addr`.
   - Set the Firmware Upgrade URL using the format `https://<host-ip-address>:<host-port>/<firmware-image-filename>`, e.g., `https://192.168.2.106:8070/light.bin`.

3. Set the Wi-Fi SSID and password:

   - Navigate to `Example Connection Configuration` > `Wi-Fi SSID`.
   - Enter your Wi-Fi SSID.
   - Navigate to `Wi-Fi Password` and enter your Wi-Fi password.

4. Save the configuration and exit the menu.

### Create an SSL Certificate

1. Refer [this guide](https://github.com/espressif/esp-idf/tree/v5.3/examples/system/ota) if you have any doubt.

2. Run the command to create the SSL certificate:

   ```bash
   mkdir server && cd server
   openssl req -x509 -newkey rsa:2048 -keyout ca_key.pem -out ca_cert.pem -days 365 -nodes
   ```

3. Enter your host IP address when prompted for `Common Name (CN)`.

4. Copy the generated files into the OTA component folder:

   ```bash
   cp ca_key.pem ../components/ota/server_certs/
   cp ca_cert.pem ../components/ota/server_certs/
   ```

### Start the OTA Update Server

1. Copy the built binary file to the server folder:

   ```bash
   cp ../build/light.bin .
   ```

2. Start the server in another terminal:

   ```bash
   openssl s_server -WWW -key ca_key.pem -cert ca_cert.pem -port 8070
   ```

### Set Target, Build, and Flash

1. Set the target, build the project, and flash the firmware:

   ```bash
   cd ..
   idf.py set-target esp32
   idf.py build
   idf.py flash monitor
   ```

2. Specify the port if the port is not found:

   ```bash
   idf.py -p /dev/<your-port> flash monitor
   ```

## Testing the Project

Press the button configured on pin 5 for 7 seconds. This will trigger the OTA update, initiating the download of the firmware from the server. Once the bin file is received, the ESP32 will reboot and run the new firmware.


