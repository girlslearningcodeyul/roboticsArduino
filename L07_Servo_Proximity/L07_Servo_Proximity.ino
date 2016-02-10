#include <Servo.h> 
 
Servo MyServoMotor;
int SampleCounter = 0;
int DistanceToObject = 0;
 
void setup() 
{ 
  MyServoMotor.attach(5);
} 
  
void loop() 
{ 
  DistanceToObject += analogRead(0);  
  SampleCounter = SampleCounter + 1;
  if (SampleCounter == 100) {
    DistanceToObject = DistanceToObject / 100;
    int ServoPosition = map(DistanceToObject, 0, 110, 0, 179);  
    MyServoMotor.write(ServoPosition); 
    DistanceToObject = 0;
    SampleCounter = 0;
  }
  delay(10);
} 


