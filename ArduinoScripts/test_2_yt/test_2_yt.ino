#include <Servo.h> 
#include <SPI.h>
#include <Wire.h>


 
Servo myservo;  

// Control and feedback pins
int servoPin = 1;
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
  int pos = 0;    // variable to store the servo position
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    
} 

void loop()
{

  displayPosition();
  
  
  
}

void displayPosition()
{
  
  reading = abs(map(analogRead(feedbackPin), minFeedback, maxFeedback, minDegrees, maxDegrees));
  //reading = analogRead(feedbackPin);
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
