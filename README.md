# NodeMCU Monitoring Tool

## Overview

This project sets up a NodeMCU board as a simple monitoring tool that reads sensor data and displays it on a web interface. The tool allows you to view system information, including free memory and CPU frequency, and update Wi-Fi credentials.

## Features

- Connects to a Wi-Fi network.
- Displays real-time sensor data (default is an analog reading from pin A0).
- Shows system information (free memory and CPU frequency).
- Provides a web form for updating Wi-Fi credentials.

## Requirements

### Hardware

- NodeMCU (ESP8266) development board.
- Analog sensor (optional, for testing; can use a potentiometer).

### Software

- Arduino IDE with ESP8266 board package installed.
- Libraries:
  - `ESP8266WiFi`
  - `ESP8266WebServer`
  - `EEPROM`

## Setup Instructions

1. **Install Arduino IDE**: If you haven't already, download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Install ESP8266 Board Package**:
   - Open the Arduino IDE.
   - Go to `File` > `Preferences`.
   - In the "Additional Board Manager URLs" field, add: 
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
   - Go to `Tools` > `Board` > `Board Manager`, search for "ESP8266", and install the package.

3. **Clone or Download the Repository**:
   - Clone this repository or download it as a ZIP file and extract it.

4. **Open the Code**:
   - Open the provided `.ino` file in the Arduino IDE.

5. **Configure Wi-Fi Credentials**:
   - In the code, replace `your_SSID` and `your_PASSWORD` with your actual Wi-Fi credentials.

6. **Upload the Code**:
   - Connect your NodeMCU to your computer.
   - Select the appropriate board and port in the Arduino IDE (`Tools` > `Board` > `NodeMCU 1.0 (ESP-12E Module)` and `Tools` > `Port`).
   - Click the upload button.

7. **Access the Web Interface**:
   - Open the Serial Monitor (`Tools` > `Serial Monitor`) to find the IP address assigned to your NodeMCU.
   - Enter this IP address in a web browser to access the monitoring tool.

## Usage

- The web interface will display the current sensor value, free memory, and CPU frequency.
- Use the provided form to update Wi-Fi credentials.

## Customization

- To read different sensor data, replace the `analogRead(A0)` line in the code with the appropriate reading logic for your sensor.
- Modify the HTML in the `getHTML()` function to customize the web interface.

## License

This project is licensed under the MIT License. Feel free to modify and use the code for your projects.
