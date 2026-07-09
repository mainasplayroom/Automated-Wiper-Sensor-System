// Language: C++ (Arduino IDE)
// Project: Automatic Rain Sensing Car Wiper
// Name: KIMATHI MARK COLLINS MAINA

#include <Servo.h>

const int sensorPin = A0; 
const int servoPin = 9;   

Servo wiper;

int threshold = 600; 

void setup() {
 
  Serial.begin(9600);
  
  wiper.attach(servoPin);
  
  wiper.write(0);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  if (sensorValue < threshold) {
    
    Serial.println("Rain Detected - Wiping");
    wiper.write(180); 
    delay(1000);      
    wiper.write(0);   
    delay(1000);      
  } else {
    
    Serial.println("Dry - Wiper Off");
    wiper.write(0);
  }
  
  delay(100); 
}