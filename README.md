# Description

ESP32 MCU's have a built-in ADC calibration, In the YouTube video how to use it in the Arduino IDE.
It is easy to use; it requires no extra components and no extra code, just replace "analogRead()" with "analogReadMilliVolts()".

# Check out the video:
I will show you how it works and show the accuracy improvement with 2 ESP32 boards:  
1. ESP32 “classic”
2. ESP32 S2 Mini

The tests also reveal that the new ESP32 S & C series perform much better at low ADC voltages compared to ESP32 "Classic".

[![Watch the video](https://img.youtube.com/vi/XR9e3-A5Q-0/maxresdefault.jpg)](https://youtu.be/XR9e3-A5Q-0)



# Test setup

<img src="Test_setup.jpg" width="50%"> 

# Files:
ESP32_calibration_demo.ino  
Returns calibrated and non-calibrated ADC results in Serial monitor for comparison

