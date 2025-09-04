#include <Servo.h>
Servo myServo;

// Adjust these times (in ms) after testing your door mechanism
const int openTime  = 500;   // how long it takes to rotate from closed → open
const int closeTime = 500;   // how long it takes to rotate from open → closed

void setup() 
{
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Type 0 to close, 90 to open");
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    int inputAngle = Serial.parseInt();   // read input
    while (Serial.available()) Serial.read();  // clear buffer

    if (inputAngle == 90) 
    {
      Serial.println("Opening door...");
      myServo.write(0);          // rotate one way
      delay(openTime);
      myServo.write(90);         // stop
    } 
    else if (inputAngle == 0) 
    {
      Serial.println("Closing door...");
      myServo.write(180);        // rotate opposite way
      delay(closeTime);
      myServo.write(90);         // stop
    }
    else
    {
      Serial.println("Invalid input. Type 0 to close, 90 to open.");
    }
  }
}
