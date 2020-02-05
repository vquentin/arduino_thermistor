/* Read a thermistor with the Arduino
 * Adapted from http://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
 * Quentin Van Overmeere
 * 2020/2/5
 * Copyright YodaCity
 * All rights reserved
 */

int ThermistorPin = A0;
int Vo;
float R1 = 2370; // 1% Resistor, MFR-25FBF52-2K37
float logR2, R2, T;
/* Thermistor info
 * Vishay NTCLE100E3272JB0
 * 2700 2, 3, 5 3977 0.75 Red Violet Red Y 272*B0 272*B0A
 */
float a1 = 0.003354016, b1 = 0.000256985, c1 = 0.000002620131, d1 = 0.00000006383091;
float Rref = 2700 ;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2/Rref);
  T = (1.0 / (a1 + b1*logR2 + c1*logR2*logR2+d1*logR2*logR2*logR2))-273.15;
  
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" degC"); 

  delay(500);
}
