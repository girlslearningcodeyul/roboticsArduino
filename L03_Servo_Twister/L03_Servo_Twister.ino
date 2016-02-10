/*-- STEP 1 ---------------------------------------------------------------------------------------------------------------

  Let's make a servo motor respond to a "twister" which is really a potentiometer.  First, we need to tell our Arduino board
  to get ready.  We need to teach it how to control the motor, and to do this we "include" a helper file.

*/

#include <Servo.h> 

/*-- STEP 2 ---------------------------------------------------------------------------------------------------------------

  Now let's create a pretend servo motor inside our Arduino that we can use to control the real servo motor.

*/
 
Servo MyServoMotor;
             
/*-- STEP 3 ---------------------------------------------------------------------------------------------------------------

  In our SETUP function, we tell our Arduino board that our servo is wired up to digital control number 5.

*/
 
void setup() 
{ 
  MyServoMotor.attach(5);
} 
 
/*-- STEP 4 ---------------------------------------------------------------------------------------------------------------

  In our FOREVER LOOP, we do several things.  First we measure the current twister position, then we convert it to
  an angle, then we send it to our servo motor, which moves our pointer! 

*/
 
void loop() 
{ 
  int TwisterPosition = analogRead(0);  
  int ServoPosition = map(TwisterPosition, 0, 1023, 179, 0);  
  MyServoMotor.write(ServoPosition);  
} 


