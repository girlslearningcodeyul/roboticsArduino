#include <Servo.h> 

Servo MyServoMotor;
              
void setup() 
{ 
  MyServoMotor.attach(5);
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);
} 
 
void loop() 
{ 

  int IsThereMotion = digitalRead(3);  
  
  if (IsThereMotion == 1)
  {
    digitalWrite(13, HIGH); 
    MyServoMotor.write(0);
  }
  else
  {
    digitalWrite(13, LOW); 
    MyServoMotor.write(179);
  }
  delay(4000);
  
} 

