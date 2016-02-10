#include <Servo.h> 

Servo MyServoMotor;
              
void setup() 
{ 
  MyServoMotor.attach(5);
} 
 
void loop() 
{ 

  int AmountOfLight = analogRead(0);
  int ServoPosition = map(AmountOfLight, 0, 1000, 179, 0);  
  MyServoMotor.write(ServoPosition);
  
} 
