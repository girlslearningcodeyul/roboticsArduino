#include <Servo.h> 
 
Servo MyServoMotor;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
unsigned int HighestSoFar = 0;

void setup() 
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  MyServoMotor.attach(5);
  MyServoMotor.write(179);  
}

void loop() 
{
  unsigned long startMillis = millis();
  unsigned int PeakToPeak = 0;
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
  
  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(5);
    if (sample < 1024)  // toss out spurious readings
    {
      if (sample > signalMax)
      {
        signalMax = sample;  // save just the max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample;  // save just the min levels
      }
    }
  }

  PeakToPeak = signalMax - signalMin;
  if (PeakToPeak > HighestSoFar) { 
    HighestSoFar = PeakToPeak;
  }
  int ServoPosition = map(HighestSoFar, 50, 600, 179, 0);  
  MyServoMotor.write(ServoPosition);
  Serial.println(PeakToPeak);

  if (PeakToPeak >= 450) {
    digitalWrite(13, HIGH);     
    // fire
  } else {
    digitalWrite(13, LOW);     
  }

}

