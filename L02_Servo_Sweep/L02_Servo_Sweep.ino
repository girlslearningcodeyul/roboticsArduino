/*-- STEP 1 ---------------------------------------------------------------------------------------------------------------

  Let's make a servo motor "sweep" from side to side.  First, we need to tell our Arduino board to get ready.  We need to teach it 
  how to control the motor, and to do this we "include" a helper file.

*/

#include <Servo.h> 

/*-- STEP 2 ---------------------------------------------------------------------------------------------------------------

  Now let's create a pretend servo motor inside our Arduino that we can use to control the real servo motor.

*/
 
Servo MyServoMotor;
             
/*-- STEP 3 ---------------------------------------------------------------------------------------------------------------

  In our SETUP function, we tell our Arduino board that our servo is wired up to digital control number 9.

*/
 
void setup() 
{ 
  MyServoMotor.attach(5);
} 
 
/*-- STEP 4 ---------------------------------------------------------------------------------------------------------------

  In our forever LOOP, we do several things.  First we tell the servo to move in steps from left to right, then
  to go back to the beginning and start over again. 

*/
 
void loop() 
{  
  
  for(int A = 0; A < 180; A += 10)  
  {                                  
    MyServoMotor.write(A); 
    delay(15);
  } 
  for(int A = 180; A >= 1; A -= 1)
  {                                
    MyServoMotor.write(A);
    delay(15);
  }

} 


