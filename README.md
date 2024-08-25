# Weather Monitoring Station

## Project Overview

Create a weather station that collects data on temperature, humidity, and atmospheric pressure and displays it on a web dashboard. This project uses the DHT22 sensor for temperature and humidity, the BMP180 sensor for atmospheric pressure, and includes a microcontroller with a Wi-Fi module to send data to a web server.

## Project Structure


```
weather-monitoring-station/
├── src/
│   ├── weather_station.ino
├── web/
│   ├── index.html
│   ├── styles.css
│   ├── script.js
└── README.md

```


## Components
- **Microcontroller**: ESP8266 or similar with Wi-Fi capability
- **Sensors**: DHT22 (Temperature and Humidity), BMP180 (Atmospheric Pressure)
- **Web Server**: Hosted on the microcontroller

## How to Use

### 1. Microcontroller Setup
1. Open `weather_station.ino` in the Arduino IDE.
2. Replace `your_SSID` and `your_PASSWORD` with your Wi-Fi credentials.
3. Upload the code to your microcontroller.

### 2. Web Dashboard
1. Upload `index.html`, `styles.css`, and `script.js` to your web server.
2. Update the `fetchWeatherData` URL in `script.js` to point to your microcontroller's IP address.

### 3. Accessing the Dashboard
1. Open a web browser and navigate to the URL where your web dashboard is hosted.
2. View the real-time weather data from your monitoring station.

## Deployment
1. Ensure your microcontroller is connected to Wi-Fi.
2. Deploy the web dashboard files to a web server or host it locally on the microcontroller.

## License
See the LICENSE file for more details.

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

## Notes
- Ensure the sensors are correctly wired to the microcontroller.
- Adjust the data fetching interval and other settings based on your specific requirements.

