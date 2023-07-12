#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <CheapStepper.h>

int stepPin = 47;
int directionPin = 49;
int stepPin2 = 51;
int directionPin2 = 53;
CheapStepper iceMotor(25, 27, 29, 31);

byte rowPins[4] = { 52, 50, 48, 46 };
byte colPins[3] = { 44, 42, 40 };

char keys[4][3] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
//////////////////////////////////////////////////DRINK PRICES/////////////////////////////////////////////////
int drink1Price = 14;
int drink2Price = 12;
int drink3Price = 3;
int drink4Price = 6;
int drink5Price = 4;
//////////////////////////////////////////////////ULTRASONIC///////////////////////////////////////////////////
const int trigPin1 = 34;
const int echoPin1 = 32;
const int trigPin2 = 26;
const int echoPin2 = 24;
const int trigPin3 = 30;
const int echoPin3 = 28;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int IRpin = 36;
const int IRpin2 = 38;
const int pumpMotor1 = 39;
const int pumpMotor2 = 41;
const int pumpMotor3 = 43;
const int pumpMotor4 = 37;
const int pumpMotor5 = 45;
const int mixingMotor = 35;
const int limitSwitch = 25;
const int buzzer = 23;
long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Keypad keypadobj = Keypad(makeKeymap(keys), rowPins, colPins, 4, 3);
LiquidCrystal_I2C lcd(0x27, 20, 4);

String printJuice1 = "1.Lime Juice";
String printJuice2 = "2.Fruit Juice";
String printJuice3 = "3.Sprite";
String printJuice4 = "0.NEXT PAGE";

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
  pinMode(pumpMotor1, OUTPUT);
  pinMode(pumpMotor2, OUTPUT);
  pinMode(pumpMotor3, OUTPUT);
  pinMode(pumpMotor4, OUTPUT);
  pinMode(pumpMotor5, OUTPUT);
  pinMode(IRpin, INPUT);
  pinMode(IRpin2, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  pinMode(mixingMotor,OUTPUT);
  pinMode(limitSwitch, INPUT);
  pinMode(buzzer, OUTPUT);
  iceMotor.setRpm(17);
}

void loop() {
  lcd.print("+-----Welcome!-----+");
  lcd.setCursor(0, 1);
  lcd.print("| 1.Classic        |");
  lcd.setCursor(0, 2);
  lcd.print("| 2.Custom         |");
  lcd.setCursor(0, 3);
  lcd.print("| 3.Admin          |");

  char mainKey = keypadobj.getKey();


  if (mainKey != NO_KEY) {
    if (mainKey == '1') {
      int currentPage = 1;
      setPage1();
      printJuices();
      while (true) {
        char juiceKey = keypadobj.getKey();

        if (juiceKey != NO_KEY) {
          if (juiceKey == '1') {
            juice1();
            break;
          } else if (juiceKey == '2') {
            juice2();
            break;
          } else if (juiceKey == '3') {
            juice3();
            break;
          } else if (juiceKey == '4') {
            juice4();
            break;
          } else if (juiceKey == '5') {
            juice5();
            break;
          } else if (juiceKey == '6') {
            juice6();
            break;
          } else if (juiceKey == '0') {
            if (currentPage == 2) {
              currentPage = 1;
              setPage1();
              printJuices();
            } else {
              currentPage = 2;
              setPage2();
              printJuices();
            }
          }

          else if (juiceKey == '*') {
            break;
          }
        }
      }
    }

    else if (mainKey == '2') {
      customjuice();
    }

    else if (mainKey == '3') {
      admin();
    }

    else {
      lcd.clear();
      lcd.print("Invalid Input");
      delay(2000);
    }
  }
}

void printJuices() {
  lcd.clear();
  lcd.print(printJuice1);
  lcd.setCursor(0, 1);
  lcd.print(printJuice2);
  lcd.setCursor(0, 2);
  lcd.print(printJuice3);
  lcd.setCursor(0, 3);
  lcd.print(printJuice4);
}

void setPage1() {
  printJuice1 = "1.Lime Juice";
  printJuice2 = "2.Fruit Juice";
  printJuice3 = "3.Sprite";
  printJuice4 = "0.NEXT PAGE";
}

void setPage2() {
  printJuice1 = "4.Fruity Vodka";
  printJuice2 = "5.Whiskey Sour";
  printJuice3 = "6.Vodka + Sprite";
  printJuice4 = "0.PREVIOUS PAGE";
}