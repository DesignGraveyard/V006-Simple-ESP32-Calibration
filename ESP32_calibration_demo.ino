// ESP32 ADC Calibration comparison 
// 1. AnalogRead() (non calibrated) 
// 2. analogReadMilliVolts() (factory calibrated)
// Used for ESP32 "classic" & ESP32 S2 Mini


//#define ADC_PIN 7//for ESP32 S2 Mini
#define ADC_PIN 32//For ESP32 "classic"
#define SAMPLES 50//sample  50 times and take average

void setup() {
  Serial.begin(115200);
  
  // Set attenuation to 11dB (allows up to ~3.1V - 3.3V range)
  // ADC_11db is the standard for modern ESP32 Arduino cores
  analogSetAttenuation(ADC_11db); 
  
  // Set resolution to 12-bit (0-4095)
  analogReadResolution(12);

  delay(1000);
  Serial.println("Starting ADC Demonstration...");
}

void loop() {
  uint32_t rawSum = 0;
  uint32_t calSum = 0;

  // Collect samples for averaging
  for(int i = 0; i < SAMPLES; i++) {
    rawSum += analogRead(ADC_PIN);
    calSum += analogReadMilliVolts(ADC_PIN);
  }

  // Calculate averages
  float rawAvg = (float)rawSum / SAMPLES;
  float calAvg = (float)calSum / SAMPLES;

  // The "Uncalibrated" Math: (Avg Raw / 4095) * 3960mV
  float vNonCal = (rawAvg / 4096.0) * 3960.0;//11dB attenuation = 1100mV×3.6=3960mV
  
  // The Calibrated result (already averaged)
  float vCal = calAvg;

  // The Difference
  float error = vNonCal - vCal;

  // Print all in one line as requested
  Serial.print("Raw: ");
  Serial.print((int)rawAvg);
  Serial.print("  |  V-nonCal: ");
  Serial.print((int)vNonCal);
  Serial.print(" mV  | V-Cal: ");
  Serial.print((int)vCal);
  Serial.print(" mV | Error: ");
  Serial.print((int)error);
  Serial.println(" mV");

  delay(500); // 2 readings per second
}