#include <Servo.h> 

Servo MyServoMotor;

void setup() 
{ 
  MyServoMotor.attach(5);
} 
 
void loop() 
{ 
  int HowMuchForce = analogRead(0);  
  int ServoPosition = map(HowMuchForce, 0, 1023, 179, 0);  
  MyServoMotor.write(ServoPosition);  
} 


