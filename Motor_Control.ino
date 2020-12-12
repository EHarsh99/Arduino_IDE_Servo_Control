/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int LED = 13;
int val = 0;
int alreadyOn = 0;
void setup()
{
  pinMode(LED, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    val = Serial.read();

    if (val > 180)
    {
      val = 180;
    }

    Serial.println(val);

    if (val == 0)
    {
      digitalWrite(LED, LOW);
      myservo.write(94);
    }
    digitalWrite(LED, HIGH);

    while (val > 0)
    {
      for (pos = 0; pos <= 180; pos += 5)
      {
        // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                    // waits 15ms for the servo to reach the position
        if (Serial.available() > 0)
        {

          val = Serial.read();
          if (val > 180)
          {
            val = 180;
          }
          if (val == 0)
          {
            digitalWrite(LED, LOW);
            break;
          }
        }
      }
      for (pos = 180; pos >= 0; pos -= 5)
      {
        // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                      // waits 15ms for the servo to reach the position
        if (Serial.available() > 0)
        {

          val = Serial.read();
          if (val > 180)
          {
            val = 180;
          }
          if (val == 0)
          {
            digitalWrite(LED, LOW);
            break;
          }

        }

      }
      Serial.println(val);
    }
  }
}
