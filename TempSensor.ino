/*
 * Temperature Sensor
 * 
 */
 #include<LiquidCrystal.h>
 
 const int tempSensorPin = A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
 int tempSense = analogRead(A0);
 static float prevTemp;
 lcd.setCursor(0,0);
 float temperature = getTempConversion(tempSense);
 
 if(abs(temperature - prevTemp) > .85){
  lcd.print("Temp.: ");
  lcd.print(temperature);
  lcd.print(" degrees");
 //Serial.print(temperature);
 //Serial.println(" degrees Fahrenheit");
 prevTemp = temperature;
 }

 delay(1000);
 
}

//This function converts the ADC reading to temperature in degrees Fahrenheit
float getTempConversion(int tempSense){
 float voltage = (tempSense/1024.0) * 5.0;  //Convert ADC Reading to voltage
 float temperature = (voltage - .5) * 100;  // Convert voltage to Celsius
 return (temperature * 9 / 5.0) + 32;         //Convert Celsius to Farenheit and return value
}

