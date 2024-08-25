function fetchWeatherData() {
    fetch('http://your_esp_ip_address/')
    .then(response => response.text())
    .then(data => {
        document.querySelector('#temperature').innerText = data.match(/Temperature: (\d+.\d+)/)[1] + " &deg;C";
        document.querySelector('#humidity').innerText = data.match(/Humidity: (\d+.\d+)/)[1] + " %";
        document.querySelector('#pressure').innerText = data.match(/Pressure: (\d+.\d+)/)[1] + " hPa";
    });
}

// Update weather data every 10 seconds
setInterval(fetchWeatherData, 10000);
fetchWeatherData(); // Fetch data immediately on load
