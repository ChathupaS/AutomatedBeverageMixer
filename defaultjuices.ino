void juice1() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need Lime Juice?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        if (waterLevel(1, 0, 0)) {
          int requiredJuices[5] = { 0, 0, 1, 0, 0 };
          int volumeJuices[5] = { 0, 0, 250, 0, 0 };
          makingJuice(requiredJuices, volumeJuices, 1,1,1);
        }
        lcd.clear();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}

void juice2() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need Fruit Juice?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        if (waterLevel(0, 1, 0)) {
          int requiredJuices[5] = { 0, 0, 0, 1, 0 };
          int volumeJuices[5] = { 0, 0, 0, 250, 0 };
          makingJuice(requiredJuices, volumeJuices, 2,1,1);
        }
        lcd.clear();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}

void juice3() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need Sprite?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        if (waterLevel(0, 0, 1)) {
          int requiredJuices[5] = { 0, 0, 0, 0, 1 };
          int volumeJuices[5] = { 0, 0, 0, 0, 250 };
          makingJuice(requiredJuices, volumeJuices, 3,1,1);
        }
        lcd.clear();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}

void juice4() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need Fruity Vodka?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        if (waterLevel(0, 1, 0)) {
          int requiredJuices[5] = { 1, 0, 0, 1, 0 };
          int volumeJuices[5] = { 50, 0, 0, 200, 0 };
          makingJuice(requiredJuices, volumeJuices, 4,1,1);
        }
        lcd.clear();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}

void juice5() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need Whyskey Sour?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        if (waterLevel(1, 0, 0)) {
          int requiredJuices[5] = { 0, 1, 1, 0, 0 };
          int volumeJuices[5] = { 0, 50, 200, 0, 0 };
          makingJuice(requiredJuices, volumeJuices, 5,1,1);
        }
        lcd.clear();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}

void juice6() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need Vodka+Sprite?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        if (waterLevel(0, 0, 1)) {
          int requiredJuices[5] = { 1, 0, 0, 0, 1 };
          int volumeJuices[5] = { 50, 0, 0, 0, 200 };
          makingJuice(requiredJuices, volumeJuices, 6,1,1);
        }
        lcd.clear();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}

void moveMainStepper(int count) {
  for (int stepCount = 1; stepCount <= count; stepCount = stepCount + 1) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}

void moveMixingStepper(int count) {
  for (int stepCount = 1; stepCount <= count; stepCount = stepCount + 1) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(500);
  }
}

void waterPump(int pin, int time) {
  delay(1000);
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin, LOW);
  delay(1000);
}