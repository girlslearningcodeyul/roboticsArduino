#include <Servo.h> 
 
Servo MyServoMotor;
 
void setup() 
{ 
  MyServoMotor.attach(5);
} 
 
void loop() 
{ 
  int CurrentTemperature = analogRead(0);
  int ServoPosition = map(CurrentTemperature, 130, 160, 179, 0);  
  MyServoMotor.write(ServoPosition);
  delay(500);
} 


