#include <Servo.h> 

Servo MyServoMotor;
             
void setup() 
{ 
  MyServoMotor.attach(5);
} 
 
void loop() 
{ 
  int Orientation = analogRead(0);  
  int ServoPosition = map(Orientation, 200, 450, 179, 0);  
  MyServoMotor.write(ServoPosition);  
  delay(100);
} 


