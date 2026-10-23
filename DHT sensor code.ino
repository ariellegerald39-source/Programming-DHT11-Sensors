const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature Sensor Initializing...");
}

void loop() {
  // Read the voltage from the sensor pin
  int sensorValue = analogRead(sensorPin);
  
  // Convert the analog reading to voltage (5V system, 1024 ADC steps)
  float voltage = sensorValue * (5.0 / 1024.0);
  
  // Convert voltage to Celsius (TMP36 formula: 10 mV per degree C with 500 mV offset)
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C (");
  Serial.print(temperatureF);
  Serial.println(" °F)");

  delay(2000); // Wait 2 seconds between readings
}