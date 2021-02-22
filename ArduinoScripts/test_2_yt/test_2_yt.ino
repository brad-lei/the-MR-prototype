#include <Servo.h> 
#include <SPI.h>
#include <Wire.h>


 
Servo myservo;  

// Control and feedback pins
int servoPin = 9;
int feedbackPin = A0;

// Calibration values
int minDegrees;
int maxDegrees;
int minFeedback;
int maxFeedback;
int tolerance = 2; // max feedback measurement error
int reading = 0;
int minimum = 2000;
int maximum = 0;

void calibrate(Servo servo, int analogPin, int minPos, int maxPos)
{
  // Move to the minimum position and record the feedback value
  servo.write(minPos);
  minDegrees = minPos;
  delay(2000); // make sure it has time to get there and settle
  minFeedback = analogRead(analogPin);
  
  // Move to the maximum position and record the feedback value
  servo.write(maxPos);
  maxDegrees = maxPos;
  delay(2000); // make sure it has time to get there and settle
  maxFeedback = analogRead(analogPin);
}


 
void setup() 
{ 
  Serial.begin(9600);
  
  myservo.attach(servoPin); 
  
  calibrate(myservo, feedbackPin, 0, 30);  // calibrate for the 20-270 degree range
  
  pinMode(feedbackPin, INPUT);

 
  displayPosition(); 
    
} 

void loop()
{

  displayPosition();
  
  
  
}

void displayPosition()
{
  
  //reading = abs(map(analogRead(feedbackPin), minFeedback, maxFeedback, minDegrees, maxDegrees));
  reading = analogRead(feedbackPin);
  if(reading < minimum) minimum = reading;
  if(reading > maximum) maximum = reading;
  //if (reading < 0) reading = 0;
  //if (reading > 360) reading = 360;
  // Serial.println("Position");
  Serial.println( reading );
  //Serial.print(minimum);
  //Serial.println(maximum);
  //delay(2000);
  //myservo.write(reading);
  
}
