//GYRO*
#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);
//GYRO


//LCD*
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//LCD


//ULTRASONIC*
int trigPin = 9;
int echoPin = 10;
float duration, distance;
//ULTRASONIC

 
 float height=0;


void setup() {

  //LCD*
  lcd.begin(16, 2);
  //LCD


  //ULTRASONIC*
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //ULTRASONIC


  //GYRO*
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  //GYRO
}

void loop() {

  //ULTRASONIC*
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = ((duration*0.0343)/2)+30;
  
//  Serial.print("Distance: ");
//  Serial.println(distance);

  //ULTRASONIC


  lcd.setCursor(0,0);
  lcd.print("D:");
  lcd.setCursor(2,0);
  lcd.print(distance);
  
  mpu6050.update();
  lcd.setCursor(9,0);
  lcd.print("A:");
  lcd.setCursor(11,0);
  lcd.print(mpu6050.getAngleX());

  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.setCursor(2,1);
  height=(distance*tan(mpu6050.getAngleX()*0.01744));
  lcd.print(height);



}
