# Description

ESP32 MCU's have a built-in ADC calibration, In the YouTube video how to use it in the Arduino IDE.
It is easy to use; it requires no extra components and no extra code, just replace "analogRead()" with "analogReadMilliVolts()".

# Check out the video:
I will show you how it works and show the accuracy improvement with 2 ESP32 boards:  
1. ESP32 “classic”
2. ESP32 S2 Mini

[![Watch the video](https://img.youtube.com/vi/ObJ7VtKhYn0/0.jpg)](https://youtu.be/ObJ7VtKhYn0)

# Test setup

<img src="Test_setup.jpg" width="50%"> 

# Files:
ESP32_calibration_demo.ino  
Returns calibrated and non-calibrated ADC results in Serial monitor for comparison

