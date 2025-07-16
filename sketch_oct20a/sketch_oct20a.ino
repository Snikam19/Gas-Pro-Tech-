// YouTube | Tech at Home

#include <Servo.h>

Servo myservo;
int mq_sensor = A0;
byte buzzer = 10;
int led = 10;
int relay = 2;

int gas_threshold = 400;  //Change the gas detection threshold value based on your sensor

void setup()
{
  Serial.begin(9600);
  myservo.attach(3);
  pinMode(mq_sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  
  myservo.write(0);   //Change the servo degree based on your hardware setup
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(relay, HIGH);
  delay(25);
}


void loop()
{
  int sensor_data = analogRead(mq_sensor);
  Serial.println(sensor_data);

  if(sensor_data > gas_threshold)
  {
    Serial.println(sensor_data);
    myservo.write(35);      //Change the servo degree based on your hardware setup
    digitalWrite(led, HIGH);
    digitalWrite(relay, LOW);
    analogWrite(buzzer, 200);
    delay(110);
    analogWrite(buzzer, 100);
    delay(110);
  }
  else
  {
    Serial.println(sensor_data);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, HIGH);
    // myservo.write(0); //uncomment if regulator need to turn on when gas leakage clears
  }
}