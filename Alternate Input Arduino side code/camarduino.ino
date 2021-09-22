#define led LED_BUILTIN
#include<Servo.h>
#include<string.h>
String data;
Servo servo;

//Arduino side code for alternate input 
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  servo.write(0);
  servo.attach(4,430,2400); //uses Wemos D2 pin for servo motor
}
char data1;
void loop() {
  while(Serial.available()){
    data1 = Serial.read();          //Since Python contacts WeMos using the serial communication( COM Port), our code listens for serial input
    data = String(data1,HEX);       //converts incoming ASCII string to hexadecimal 
    Serial.print(data);
    for (int i = 0; i < data.length(); i++)       //this takes every hexadecimal character in the string, and assigns it a specific angle 
    {
      if (data.charAt(i) == 'A' || data.charAt(i)=='a'){
        servo.write(10);
        delay(1000);
      }
      if (data.charAt(i) == 'B' || data.charAt(i)=='b'){
        servo.write(20);
        delay(1000);
      }
      if (data.charAt(i) == 'C' || data.charAt(i)=='c'){
        servo.write(30);
        delay(1000);
      }
      if (data.charAt(i) == 'D' || data.charAt(i)=='d'){
        servo.write(40);
        delay(1000);
      }
      if (data.charAt(i) == 'E' || data.charAt(i)=='e'){
        servo.write(50);
        delay(1000);
      }
      if (data.charAt(i) == 'F' || data.charAt(i)=='f'){
        servo.write(60);
        delay(1000);
      }
      if (data.charAt(i) == '0'){
        servo.write(70);
        delay(1000);
      }
      if (data.charAt(i) == '1'){
        servo.write(80);
        delay(1000);
      }
      if (data.charAt(i) == '2'){
        servo.write(90);
        delay(1000);
      }
      if (data.charAt(i) == '3'){
        servo.write(100);
        delay(1000);
      }
      if (data.charAt(i) == '4'){
        servo.write(110);
        delay(1000);
      }
      if (data.charAt(i) == '5'){
        servo.write(120);
        delay(1000);
      }
      if (data.charAt(i) == '6'){
        servo.write(130);
        delay(1000);
      }
      if (data.charAt(i) == '7'){
        servo.write(140);
        delay(1000);
      }
      if (data.charAt(i) == '8'){
        servo.write(150);
        delay(1000);
      }
      if (data.charAt(i) == '9'){
        servo.write(160);
        delay(1000);
      }
    }
  }
}
