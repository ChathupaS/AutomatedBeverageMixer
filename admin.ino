void admin() {
  lcd.clear();
  lcd.print("Enter Pin:");
  int i = 0;
  int CorrectPassword[4] = { 1, 2, 3, 4 };
  int EnteredPassword[4] = { -1, -1, -1, -1 };
  while (true) {
    char passwordkey = keypadobj.getKey();
    delay(100);
    if (passwordkey != NO_KEY) {
      if (passwordkey == '*' && EnteredPassword[0] == -1) {
        return;
      } else if (passwordkey == '*') {
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        EnteredPassword[i - 1] = -1;
        i--;
      } else if (passwordkey == '#') {
        if (EnteredPassword[0] == CorrectPassword[0] && EnteredPassword[1] == CorrectPassword[1] && EnteredPassword[2] == CorrectPassword[2] && EnteredPassword[3] == CorrectPassword[3]) {
          lcd.clear();
          lcd.print("1.Check Drink Levels");
          lcd.setCursor(0, 1);
          lcd.print("2.Clean Water Pumps");
          lcd.setCursor(0, 2);
          lcd.print("3.Fill ice");
          lcd.setCursor(0, 3);
          lcd.print("0.Back");
          while (true) {
            char adminpanel = keypadobj.getKey();
            if (adminpanel != NO_KEY) {
              if (adminpanel == '1') {
                lcd.clear();
                lcd.print("Lime Juice: ");
                lcd.print(displayWaterLevel(trigPin1, echoPin1));
                lcd.print("cm");
                lcd.setCursor(0, 1);
                lcd.print("Fruit Juice: ");
                lcd.print(displayWaterLevel(trigPin2, echoPin2));
                lcd.print("cm");
                lcd.setCursor(0, 2);
                lcd.print("Sprite: ");
                lcd.print(displayWaterLevel(trigPin3, echoPin3));
                lcd.print("cm");
                lcd.setCursor(0, 3);
                lcd.print("0.Back");
                while (true) {
                  char cancelKey = keypadobj.getKey();
                  if (cancelKey != NO_KEY) {
                    if (cancelKey == '0' || '*') {
                      lcd.clear();
                      lcd.print("1.Check Drink Levels");
                      lcd.setCursor(0, 1);
                      lcd.print("2.Water Pumps");
                      lcd.setCursor(0, 2);
                      lcd.print("3.Fill ice");
                      lcd.setCursor(0, 3);
                      lcd.print("0.Back");
                      break;
                    }
                  }
                }
              } else if (adminpanel == '2') {
                lcd.clear();
                lcd.print("Choose a motor(1-5)");
                lcd.setCursor(0, 1);
                lcd.print("or select 6 for all");
                lcd.setCursor(0, 2);
                lcd.print("motors");
                lcd.setCursor(0, 3);
                lcd.print("0.Back");

                while (true) {
                  char turnPumpMotor = keypadobj.getKey();
                  if (turnPumpMotor != NO_KEY) {
                    if (turnPumpMotor == '1') {
                      turnOnPumpMotor(pumpMotor1);
                    } else if (turnPumpMotor == '2') {
                      turnOnPumpMotor(pumpMotor2);
                    } else if (turnPumpMotor == '3') {
                      turnOnPumpMotor(pumpMotor3);
                    } else if (turnPumpMotor == '4') {
                      turnOnPumpMotor(pumpMotor4);
                    } else if (turnPumpMotor == '5') {
                      turnOnPumpMotor(pumpMotor5);
                    } else if (turnPumpMotor == '6') {
                      turnOnPumpMotor(1);
                    } else if (turnPumpMotor == '*' || turnPumpMotor == '0') {
                      lcd.clear();
                      lcd.print("1.Check Drink Levels");
                      lcd.setCursor(0, 1);
                      lcd.print("2.Clean Water Pumps");
                      lcd.setCursor(0, 2);
                      lcd.print("3.Fill ice");
                      lcd.setCursor(0, 3);
                      lcd.print("0.Back");
                      break;
                    }
                  }
                }
              } else if (adminpanel == '3') {
                lcd.clear();
                lcd.print("Press '1' to rotate");
                lcd.setCursor(0, 1);
                lcd.print("the ice motor.");
                lcd.setCursor(0, 3);
                lcd.print("0.Back");

                while (true){
                  char iceKey = keypadobj.getKey();
                  if (iceKey!=NO_KEY){
                    if (iceKey=='1'){
                      iceMotor.moveDegreesCW (60);
                    }
                    else if (iceKey=='0' || '*'){
                      lcd.clear();
                      lcd.print("1.Check Drink Levels");
                      lcd.setCursor(0, 1);
                      lcd.print("2.Clean Water Pumps");
                      lcd.setCursor(0, 2);
                      lcd.print("3.Fill ice");
                      lcd.setCursor(0, 3);
                      lcd.print("0.Back");
                      break;
                    }
                  }
                }
              } else if (adminpanel == '0' || '*') {
                break;
              }
            }
          }
          return;
        } else {
          lcd.clear();
          lcd.print("Wrong Pin");
          delay(1500);
          lcd.clear();
          lcd.print("Enter Pin:");
          i = 0;
        }
      } else if (i < 4) {
        lcd.setCursor(i, 1);
        lcd.print(passwordkey);
        delay(90);
        lcd.setCursor(i, 1);
        lcd.print("*");
        EnteredPassword[i] = passwordkey - '0';
        i++;
      }
    }
  }
}

void turnOnPumpMotor(int pinNo) {
  lcd.clear();
  lcd.print("Motor");
  if (pinNo == pumpMotor1) {
    lcd.print(" 1 is on...");
  } else if (pinNo == pumpMotor2) {
    lcd.print(" 2 is on...");
  } else if (pinNo == pumpMotor3) {
    lcd.print(" 3 is on...");
  } else if (pinNo == pumpMotor4) {
    lcd.print(" 4 is on...");
  } else if (pinNo == pumpMotor5) {
    lcd.print(" 5 is on...");
  } else if (pinNo == 1) {
    lcd.clear();
    lcd.print("All motors are on...");
  }
  lcd.setCursor(0, 3);
  lcd.print("0. Stop");
  while (true) {
    char stopPumpMotor = keypadobj.getKey();
    if (stopPumpMotor != NO_KEY) {
      if (stopPumpMotor == '0') {
        digitalWrite(pumpMotor1, LOW);
        digitalWrite(pumpMotor2, LOW);
        digitalWrite(pumpMotor3, LOW);
        digitalWrite(pumpMotor4, LOW);
        digitalWrite(pumpMotor5, LOW);
        lcd.clear();
        lcd.print("Choose a motor(1-5)");
        lcd.setCursor(0, 1);
        lcd.print("or select 6 for all");
        lcd.setCursor(0, 2);
        lcd.print("motors");
        lcd.setCursor(0, 3);
        lcd.print("0.Back");
        break;
      }
    }
    if (pinNo == 1) {
      digitalWrite(pumpMotor1, HIGH);
      digitalWrite(pumpMotor2, HIGH);
      digitalWrite(pumpMotor3, HIGH);
      digitalWrite(pumpMotor4, HIGH);
      digitalWrite(pumpMotor5, HIGH);
      delay(100);
    } else {
      digitalWrite(pinNo, HIGH);
      delay(100);
    }
  }
}