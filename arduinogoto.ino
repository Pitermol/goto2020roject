

#include <Servo.h>
char command;
String string;
int servoPin = 3;
Servo Servo1;
#define laz1 13
#define laz2 12
#define laz3 10
#define laz4 11
const int analogInPin = A0;
void setup() {
  Serial.begin(9600);
  pinMode(laz1, OUTPUT);
  pinMode(laz2, OUTPUT);
  pinMode(laz3, OUTPUT);
  pinMode(laz4, OUTPUT);
  Servo1.attach(servoPin);
}
void loop() {
  //Servo1.write(30);

  Serial.println(analogRead(analogInPin));

  if (Serial.available() > 0) {
    string = "";
  }
  while (Serial.available() > 0) {
    command = ((byte)Serial.read());
    if (command == ':') {
      break;
    }
    else {
      string += command;
    }
    delay(1);
  }
  if (string == "LO") {
    LEDlvl1();
  }
  if (string == "LF") {
    LEDOff();
    //Serial.println("FINISH");
  }
  if (string == "L1") {
    Serial.println("L1");
    LEDlvl2();
  }
  if (string == "B1") {
    LEDb1();
  }
  if (string == "B2") {
    LEDb2();
  }
  if (string == "B3") {
    LEDb3();
  }
  if (string == "Lr") {
    LEDr();
  }
  if (string == "Ls") {
    LEDsoundstart();
  }
}


void LEDlvl1() {
  analogWrite(laz1, 255);
  analogWrite(laz2, 0);
  analogWrite(laz3, 0);
  analogWrite(laz4, 0);
  delay(1000);
  analogWrite(laz1, 0);
  analogWrite(laz2, 255);
  analogWrite(laz3, 0);
  analogWrite(laz4, 0);
  delay(1000);
  analogWrite(laz1, 0);
  analogWrite(laz2, 0);
  analogWrite(laz3, 255);
  analogWrite(laz4, 0);
  delay(1000);
  analogWrite(laz1, 0);
  analogWrite(laz2, 0);
  analogWrite(laz3, 0);
  analogWrite(laz4, 255);
  delay(1000);
}

void LEDlvl2() {
  Serial.println("12");

  analogWrite(laz1, 255);

  delay(50);

  analogWrite(laz1, 255);
  delay(10);
  analogWrite(laz1, 0);

  delay(50);

  analogWrite(laz1, 255);
  delay(10);
  analogWrite(laz1, 0);
  delay(10);
  analogWrite(laz1, 0);

  delay(50);

  analogWrite(laz1, 255);
  delay(10);
  analogWrite(laz1, 0);
  delay(10);
  analogWrite(laz1, 0);
  delay(10);
  analogWrite(laz1, 0);

  delay(50);

  analogWrite(laz1, 255);
  delay(10);
  analogWrite(laz1, 0);
  delay(10);
  analogWrite(laz1, 0);
  delay(10);
  analogWrite(laz1, 0);

  delay(50);

  analogWrite(laz1, 255);
  delay(10);
  analogWrite(laz1, 0);
  delay(10);
  analogWrite(laz1, 0);

  delay(50);

  analogWrite(laz1, 255);
  delay(10);
  analogWrite(laz1, 0);

  delay(50);

  analogWrite(laz1, 255);
}

void LEDb1() {
  Serial.println("b1");
  analogWrite(laz1, 255);
  analogWrite(laz2, 255);
  analogWrite(laz3, 255);
  analogWrite(laz4, 255);

  LEDserv();
}

void LEDb2() {
  Serial.println("b2");
  analogWrite(laz1, 255);
  analogWrite(laz1, 0);
  delay(5);
}

void LEDserv() {
  Servo1.write(0);
  delay(500);
  Servo1.write(30);
  delay(500);
  Servo1.write(-30);
  delay(500);
  Servo1.write(60);
  delay(500);
}

void LEDb3() {
  Serial.println("b3");
  analogWrite(laz1, 255);
  analogWrite(laz1, 0);
  delay(50);
}

void LEDr() {
  Serial.println("r");
  analogWrite(laz2, 0);
  analogWrite(laz4, 0);
  analogWrite(laz1, 255);
  analogWrite(laz3, 255);
  delay(700);
  analogWrite(laz1, 0);
  analogWrite(laz3, 0);
  analogWrite(laz2, 255);
  analogWrite(laz4, 255);
  delay(700);
}

void LEDnosound() {
  analogWrite(laz1, 255);
  delay(700);
  analogWrite(laz4, 0);
  delay(700);
  analogWrite(laz2, 255);
  delay(700);
  analogWrite(laz1, 0);
  delay(700);
  analogWrite(laz3, 255);
  delay(700);
  analogWrite(laz2, 0);
  delay(700);
  analogWrite(laz4, 255);
  delay(700);
  analogWrite(laz3, 0);
  delay(700);
}

void LEDsoundstart() {
  Serial.println(analogRead(analogInPin));
  if (analogRead(analogInPin) > 200) {
    LEDsound();
  }
  else {
    LEDnosound();
  }
}

void LEDsound() {
  Serial.println("soundStarted");

  while (analogRead(analogInPin) > 200) {
    analogWrite(laz1, 255);
    analogWrite(laz4, 255);
    analogWrite(laz2, 0);
    analogWrite(laz3, 0);
    Serial.println(analogRead(analogInPin));
    //LEDserv();

    for (int i = 0; i < 50; i += 25) {
      analogWrite(laz1, 255);
      analogWrite(laz1, 0);
      //Servo1.write(15);
      delay(i);
    }
    analogWrite(laz1, 0);



    for (int i = 0; i < 50; i += 25) {
      analogWrite(laz4, 255);
      analogWrite(laz4, 0);
      //Servo1.write(-30);
      delay(i);
    }
    analogWrite(laz4, 0);

    analogWrite(laz2, 255);
    analogWrite(laz3, 255);

    for (int i = 0; i < 50; i += 25) {
      analogWrite(laz2, 255);
      analogWrite(laz2, 0);
      //Servo1.write(45);
      delay(i);
    }
    analogWrite(laz2, 0);

    for (int i = 0; i < 50; i += 25) {
      analogWrite(laz3, 255);
      analogWrite(laz3, 0);
      //Servo1.write(-90);
      delay(i);
    }
    analogWrite(laz3, 0);
  }


  LEDOff();
}

void LEDOff() {
  Serial.println("off");
  analogWrite(laz1, 0);
  analogWrite(laz2, 0);
  analogWrite(laz3, 0);
  analogWrite(laz4, 0);
}
