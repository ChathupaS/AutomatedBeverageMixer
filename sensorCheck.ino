bool waterLevel(int drink1, int drink2, int drink3) {
  bool isDrink1Empty = false;
  bool isDrink2Empty = false;
  bool isDrink3Empty = false;

  if (drink1 == 1) {
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);

    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = duration1 * 0.034 / 2;

    if (27 - distance1 < 5) {
      isDrink1Empty = true;
    }
  }
  if (drink2 == 1) {
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);

    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = duration2 * 0.034 / 2;

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);

    if (27 - distance2 < 5) {
      isDrink2Empty = true;
    }
  }
  if (drink3 == 1) {
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);

    duration3 = pulseIn(echoPin3, HIGH);
    distance3 = duration3 * 0.034 / 2;

    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);

    if (27 - distance3 < 5) {
      isDrink3Empty = true;
    }
  }

  if (isDrink1Empty && isDrink2Empty && isDrink3Empty) {
    lcd.clear();
    lcd.print("Please fill all");
    lcd.setCursor(0, 1);
    lcd.print("cotainers!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  if (isDrink1Empty && isDrink2Empty) {
    lcd.clear();
    lcd.print("Please fill lime");
    lcd.setCursor(0, 1);
    lcd.print("juice & fruit juice!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  if (isDrink1Empty && isDrink3Empty) {
    lcd.clear();
    lcd.print("Please fill lime");
    lcd.setCursor(0, 1);
    lcd.print("juice & Sprite!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  if (isDrink2Empty && isDrink3Empty) {
    lcd.clear();
    lcd.print("Please fill fruit");
    lcd.setCursor(0, 1);
    lcd.print("juice & Sprite!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  if (isDrink1Empty) {
    lcd.clear();
    lcd.print("Please fill lime");
    lcd.setCursor(0, 1);
    lcd.print("juice!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  if (isDrink2Empty) {
    lcd.clear();
    lcd.print("Please fill fruit");
    lcd.setCursor(0, 1);
    lcd.print("juice!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  if (isDrink3Empty) {
    lcd.clear();
    lcd.print("Please fill Sprite!");
    startBuzzer();
    lcd.clear();
    return false;
  }

  return true;
}

bool irsensorcheck(int irPinNo) {
  if (digitalRead(irPinNo) == LOW) {
    lcd.clear();
    lcd.print("Starting in 3");
    delay(1000);
    lcd.clear();
    lcd.print("Starting in 2");
    delay(1000);
    lcd.clear();
    lcd.print("Starting in 1");
    delay(1000);
    return false;
  } else {
    return true;
  }
}

int displayWaterLevel(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;

  return (27 - distance);
}