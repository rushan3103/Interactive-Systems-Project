#include<Servo.h>
#include<string.h>

String data;
Servo servo;

const int buttonPin = 4;            // 4 is the D2 pin on WeMos
const int ledPin = LED_BUILTIN;     //uses builtin LED to mark every button press 

int ledState = HIGH;               //this is a boolean variable, to check the LED state-either on/off
int buttonState = LOW;             //this is a boolean variable which counts the current button state(either pressed or not)
int lastButtonState = LOW;         //this is the previous button state, to register if the button is already pressed or not


int pause_value = 250;             //This is in microseconds; and this checks whether there is a pause between a dot or a dash 
long signal_length = 0;
long pause = 0;

String morse = "";
String dash = "-";
String dot = "*";
char output =0;                   //This is the ASCII character that is recognised from the morse code input
boolean checker = false;
boolean linechecker = false;

long lastDebounceTime = 0;  
long debounceDelay = 50;  

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  

  while(!digitalRead(buttonPin));
  
  servo.write(0);
  Serial.begin(9600);
  servo.attach(5,430,2400);          //The servo motor is attached to the D1 pin of WeMos; 430 and 2400 specifies that the servo always begins at 0 degree
  servo.write(0);
}

void loop() {
    
   buttonState = digitalRead(buttonPin);

  
  
  if (buttonState && lastButtonState)       // these nested if statements start registering the button state and assign either a dot/dash
  {
    ++signal_length;       
    
  }
  else if(!buttonState && lastButtonState)          //this part of the code happens when the button is released and it send either * or - into the buffer
  {
     
     if (signal_length>50 && signal_length<2*pause_value )
     {
       morse =  morse + dot;                                          //if the signal length is of a certain microseconds, add a dot to the morse string
     } 
      else if (signal_length>2*pause_value)
      {
        morse = morse +  dash;                     //if the length is of a certain microseconds, add a dash to the morse string 
      }
    signal_length=0; 
    digitalWrite(ledPin, LOW);                      //Led is off when the button is not pressed
     
  }
  else if(buttonState && !lastButtonState)          // this part happens when the button is pressed and its use to reset several values
  {
    pause=0;
    digitalWrite(ledPin, HIGH);  
    checker = true;
    linechecker = true;
  }
  else if (!buttonState && !lastButtonState)         //this works to ensure when to quit registering button presses
  {  
    ++pause;
    if (( pause>3*pause_value ) && (checker))
    { 
      print_char(morse);
      checker = false;
      morse = "";
    }
    if ((pause>15*pause_value) && (linechecker))
    {
      Serial.println();
      linechecker = false;
    }
  }
  lastButtonState=buttonState;
  delay(1);
}

void print_char(String morse_ip)   //this function is called when we need to assign asccii value to the morse string and further convert it to hex
{                                   
  if (morse_ip=="*-"){
    Serial.print("A");
    output = 'A';
  }
  else if (morse_ip=="-***") { 
    Serial.print("B");
    output = 'B';
  }
  else if (morse_ip=="-*-*") { 
    Serial.print("C");
    output = 'C';
  }
  else if (morse_ip=="-**") { 
    Serial.print("D");
    output = 'D';
  }
  else if (morse_ip=="*")  {
    Serial.print("E");
    output = 'E';
  }
  else if (morse_ip=="**-*") {
    Serial.print("F");
    output = 'F';
  }
  else if (morse_ip=="--*"){  
    Serial.print("G");
    output = 'G';
  }
  else if (morse_ip=="****") { 
    Serial.print("H");
    output = 'H';
  }
  else if (morse_ip=="**") { 
    Serial.print("I");
    output = 'I';
  }
  else if (morse_ip=="*---"){  
    Serial.print("J");
    output = 'J';
  }
  else if (morse_ip=="-*-") { 
    Serial.print("K");
    output = 'K';
  }
  else if (morse_ip=="*-**"){  
    Serial.print("L");
    output = 'L';
  }
  else if (morse_ip=="--"){  
    Serial.print("M");
    output = 'M';
  }
  else if (morse_ip=="-*") { 
    Serial.print("N");
    output = 'N';
  }
  else if (morse_ip=="---") { 
    Serial.print("O");
    output = 'O';
  }
  else if (morse_ip=="*--*") { 
    Serial.print("P");
    output = 'P';
  }
  else if (morse_ip=="--*-"){  
    Serial.print("Q");
    output = 'Q';
  }
  else if (morse_ip=="*-*") { 
    Serial.print("R");
    output = 'R';
  }
  else if (morse_ip=="***") { 
    Serial.print("S");
    output = 'S';
  }
  else if (morse_ip=="-"){  
    Serial.print("T");
    output = 'T';
  }
  else if (morse_ip=="**-") { 
    Serial.print("U");
    output = 'U';
  }
  else if (morse_ip=="***-"){  
    Serial.print("V");
    output = 'V';
  }
  else if (morse_ip=="*--"){  
    Serial.print("W");
    output = 'W';
  }
  else if (morse_ip=="-**-"){  
    Serial.print("X");
    output = 'X';
  }
  else if (morse_ip=="-*--"){  
    Serial.print("Y");
    output = 'Y';
  }
  else if (morse_ip=="--**"){  
    Serial.print("Z");
    output = 'Z';
  }
  else if (morse_ip=="*----") { 
    Serial.print("1");
    output = '1';
  }
  else if (morse_ip=="**---"){  
    Serial.print("2");
    output = '2';
  }
  else if (morse_ip=="***--"){  
    Serial.print("3");
    output = '3';
  }
  else if (morse_ip=="****-") { 
    Serial.print("4");
    output = '4';
  }
  else if (morse_ip=="*****"){  
    Serial.print("5");
    output = '5';
  }
  else if (morse_ip=="-****"){
    Serial.print("6");
    output = '6';
  }
  else if (morse_ip=="--***") { 
    Serial.print("7");
    output = '7';
  }
  else if (morse_ip=="---**") { 
    Serial.print("8");
    output = '8';
  }
  else if (morse_ip=="----*"){  
    Serial.print("9");
    output = '9';
  }
  else if (morse_ip=="-----") { 
    Serial.print("0");
    output = '0';
  }
  else if (morse_ip=="*******") {
    Serial.println("");
    output = ' ';
  }
  else{
  Serial.print(" ");
  }
  morse_ip="";



    data = String(output,HEX);                //logic to convert ascii to hex
    //mapping hex to their angles
    for (int i = 0; i < data.length(); i++)
    {
      Serial.println(data.charAt(0));
      Serial.println(data.charAt(1));
      if (data.charAt(i) == 'A'){
        servo.write(10);
        delay(500);
      }
      if (data.charAt(i) == 'B'){
        servo.write(20);
        delay(500);
      }
      if (data.charAt(i) == 'C'){
        servo.write(30);
        delay(500);
      }
      if (data.charAt(i) == 'D'){
        servo.write(40);
        delay(500);
      }
      if (data.charAt(i) == 'E'){
        servo.write(50);
        delay(500);
      }
      if (data.charAt(i) == 'F'){
        servo.write(60);
        delay(500);
      }
      if (data.charAt(i) == '0'){
        servo.write(70);
        delay(500);
      }
      if (data.charAt(i) == '1'){
        servo.write(80);
        delay(500);
      }
      if (data.charAt(i) == '2'){
        servo.write(90);
        delay(500);
      }
      if (data.charAt(i) == '3'){
        servo.write(100);
        delay(500);
      }
      if (data.charAt(i) == '4'){
        servo.write(110);
        delay(500);
      }
      if (data.charAt(i) == '5'){
        servo.write(120);
        delay(500);
      }
      if (data.charAt(i) == '6'){
        servo.write(130);
        delay(500);
      }
      if (data.charAt(i) == '7'){
        servo.write(140);
        delay(500);
      }
      if (data.charAt(i) == '8'){
        servo.write(150);
        delay(500);
      }
      if (data.charAt(i) == '9'){
        servo.write(160);
        delay(500);
      }
    }
  //}


  
}
