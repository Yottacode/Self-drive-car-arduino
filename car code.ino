#include <HCSR04.h>
#include <Servo.h>


                                  //Variablen festlegen
Servo S1;
int LED=8;
int in1 = 9;
int in2 = 8;
int Led = 13;
int Trigger = 2;
int Echo = 3;
int Time;
int Distance;
int MIN_DISTANCE = 10;


void setup() 
{
    Serial.begin(9600);
    S1.attach(12);
    pinMode (Led, OUTPUT);
    pinMode (9, OUTPUT);
    pinMode (8, OUTPUT);
    pinMode (12, OUTPUT);
    pinMode (Echo, INPUT);
    pinMode (Trigger, OUTPUT);
}


void loop() 
{
LEDFlash();
}



void EStop()
{
digitalWrite(in1, LOW); // stop the Engine
digitalWrite(in2, LOW);
delay(1000);
}
void EB()
{
digitalWrite(in1, LOW); //drives back
digitalWrite(in2, HIGH);
delay(1000);
}
void EF()
{
digitalWrite(in1, HIGH); //drive Forward
digitalWrite(in2, LOW);
delay(1000);
}
void SL()
{
S1.write(165); // turns the servo left 165 is how far
delay(1000);
}
void SF()
{
S1.write(120); // turns the servo Forward 120 is the mid
delay(1000);
}
void SR()
{
S1.write(65); // turns the servo right 65 is how far
delay(1000);
}
void LEDFlash()
{
digitalWrite(Led, HIGH); //flash the LED 
delay(1000);
digitalWrite(Led, LOW);
delay(1000);
}
void SensorRead()
{
  digitalWrite(Trigger, LOW);
  delay(5);
  digitalWrite(Trigger, HIGH); //US-Sound is being sent 
  delay(10);
  digitalWrite(Trigger, LOW);
  Time = pulseIn(Echo, HIGH); //Time integer gets the value of the time from the recieved echo
  Distance = (Time/2)*0.3432; //Distance is Time/2 because the sound has to go back and forth, multiplied by the speed of sound to get distance in meters
  Distance = Distance/10; //By dividing ditance /10 distance is now in centimeters
  Serial.println(Distance);
  if (Distance < MIN_DISTANCE)
  {
    digitalWrite(Led, HIGH);
    EStop();
    EB();
    delay(3000);
    EStop();
  }
  else
  {
    digitalWrite(Led, LOW);
  }
}
//S is for Servo R/L/F is in which diretion
//E is for Engine F/B is for forward or backwards
