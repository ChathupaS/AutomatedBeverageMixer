void customjuice() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Are you sure you");
  lcd.setCursor(0, 1);
  lcd.print("need a Custom Juice?");
  lcd.setCursor(0, 3);
  lcd.print("1.YES     0.NO");
  while (true) {
    char surekey = keypadobj.getKey();
    if (surekey != NO_KEY) {
      if (surekey == '1') {
        getCustomJuiceDetails();
        break;
      } else if (surekey == '0') {
        lcd.clear();
        break;
      }
    }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getCustomJuiceDetails() {
  int requiredJuices[5] = { 0, 0, 0, 0, 0 };
  int volumeJuices[5] = { 0, 0, 0, 0, 0 };
  int needIce = 0;
  int needMixing = 0;
  for (int drinkNo = 1; drinkNo <= 7; drinkNo++) {
    if (drinkNo == 6) {
      lcd.clear();
      lcd.print("Do you need ice?");
      lcd.setCursor(0, 2);
      lcd.print("1.YES     2.NO");
      lcd.setCursor(0, 3);
      lcd.print("0.CANCEL");

      while (true) {
        char needIceKey = keypadobj.getKey();
        if (needIceKey != NO_KEY) {
          if (needIceKey == '1') {
            needIce = 1;
            break;
          } else if (needIceKey == '2') {
            break;
          }
        }
      }
      continue;
    }
    if (drinkNo == 7) {
      lcd.clear();
      lcd.print("Do you need to mix?");
      lcd.setCursor(0, 2);
      lcd.print("1.YES     2.NO");
      lcd.setCursor(0, 3);
      lcd.print("0.CANCEL");

      while (true) {
        char needMixingKey = keypadobj.getKey();
        if (needMixingKey != NO_KEY) {
          if (needMixingKey == '1') {
            needMixing = 1;
            break;
          } else if (needMixingKey == '2') {
            break;
          }
        }
      }
      continue;
    }
    lcd.clear();
    lcd.print("Do you need ");
    if (drinkNo==1){
      lcd.print("from");
      lcd.setCursor(0,1);
      lcd.print("bottle 1");
    }
    else if (drinkNo==2){
      lcd.print("from");
      lcd.setCursor(0,1);
      lcd.print("bottle 2");
    }
    else if (drinkNo==3){
      lcd.print("Lime");
      lcd.setCursor(0,1);
      lcd.print("Juice");
    }
    else if (drinkNo==4){
      lcd.print("Fruit");
      lcd.setCursor(0,1);
      lcd.print("Juice");
    }
    else if (drinkNo==5){
      lcd.print("Sprite");
    }
    lcd.print("?");
    lcd.setCursor(0, 2);
    lcd.print("1.YES     2.NO");
    lcd.setCursor(0, 3);
    lcd.print("0.CANCEL");

    while (true) {
      char needDrink = keypadobj.getKey();
      if (needDrink != NO_KEY) {
        if (needDrink == '1') {
          requiredJuices[drinkNo - 1] = 1;
          volumeJuices[drinkNo - 1] = getCusJuiceVolume(drinkNo,volumeJuices[0],volumeJuices[1],volumeJuices[2],volumeJuices[3],volumeJuices[4]);
          break;
        } else if (needDrink == '2') {
          lcd.clear();
          break;
        } else if (needDrink == '0') {
          lcd.clear();
          return;
        }
      }
    }
  }
  if (waterLevel(requiredJuices[2], requiredJuices[3], requiredJuices[4])) {
    makingJuice(requiredJuices, volumeJuices, 7, needIce, needMixing);
  }
  lcd.clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getCusJuiceVolume(int drinkNo,int vol1,int vol2,int vol3,int vol4,int vol5) {
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("C. Volume:");
  lcd.print(vol1+vol2+vol3+vol4+vol5);
  lcd.setCursor(14, 3);
  lcd.print("/250ml");
  lcd.setCursor(0, 0);
  lcd.print("Enter volume (ml):");
  int i = 0;
  int volArray[3] = { -1, -1, -1 };
  int vol = 0;
  while (true) {
    char drink1Volume = keypadobj.getKey();
    if (drink1Volume != NO_KEY) {
      if (drink1Volume == '#') {
        break;
      } else if (drink1Volume == '*' && i > 0) {
        volArray[i] = -1;
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i--;
      } else if (i >= 0 && i < 3 && drink1Volume != '*') {
        volArray[i] = drink1Volume - '0';
        lcd.setCursor(i, 1);
        lcd.print(drink1Volume);
        i++;
      }
    }
  }
  int integersCount = 0;
  for (int j = 0; j < 3; j++) {
    if (volArray[j] != -1) {
      integersCount++;
      switch (j) {
        case 0:
          vol += volArray[j] * 100;
          break;
        case 1:
          vol += volArray[j] * 10;
          break;
        case 2:
          vol += volArray[j];
          break;
        default: break;
      }
    }
  }
  if (integersCount == 1) {
    return vol / 100;
  } else if (integersCount == 2) {
    return vol / 10;
  } else {
    return vol;
  }
}

void makingJuice(int requiredJuices[], int volumeJuices[], int juiceNo, int needIce, int needMixing) {
  int price = volumeJuices[0] * drink1Price + volumeJuices[1] * drink2Price + volumeJuices[2] * drink3Price + volumeJuices[3] * drink4Price + volumeJuices[4] * drink5Price;
  int fullVolume = volumeJuices[0] + volumeJuices[1] + volumeJuices[2] + volumeJuices[3] + volumeJuices[4];
  if (fullVolume>250){
    lcd.clear();
    lcd.print("Volume is too much!");
    startBuzzer();
    return;
  }
  lcd.clear();
  lcd.print("Price - Rs.");
  lcd.print(price);
  lcd.print(".00");
  lcd.setCursor(0,2);
  lcd.print("1.Start Making");
  lcd.setCursor(0,3);
  lcd.print("0.Cancel");
  while (true){
    char priceStop = keypadobj.getKey();
    if (priceStop!=NO_KEY){
      if (priceStop == '1'){
        break;
      }
      else if (priceStop =='0'){
        return;
      }
    }
  }
  lcd.clear();
  lcd.print("Please wait...");
  digitalWrite(directionPin, LOW);
  while (digitalRead(limitSwitch) == HIGH) {
    moveMainStepper(100);
  }

  if (irsensorcheck(IRpin)) {
    lcd.clear();
    lcd.print("Please place the cup");
    lcd.setCursor(0, 1);
    lcd.print("to continue!");
    lcd.setCursor(0, 2);
    lcd.print("9.Continue anyway");
    lcd.setCursor(0, 3);
    lcd.print("0.Cancel order");

    while (irsensorcheck(IRpin)) {
      char cancelKey = keypadobj.getKey();
      if (cancelKey != NO_KEY) {
        if (cancelKey == '0') {
          lcd.clear();
          lcd.print("Cancellig order...");
          digitalWrite(directionPin, HIGH);
          moveMainStepper(1000);
          lcd.clear();
          return;
        } else if (cancelKey == '9') {
          printMakingJuice(juiceNo, price);
          break;
        }
      }
    }
  }
  printMakingJuice(juiceNo, price);

  digitalWrite(directionPin, HIGH);
  delay(1000);
  moveMainStepper(15500);
  delay(1000);

  if (irsensorcheck(IRpin2)) {
    lcd.clear();
    lcd.print("Cup not found.");
    lcd.setCursor(0, 2);
    lcd.print("9.Continue Anyway");
    lcd.setCursor(0, 3);
    lcd.print("0.Cancel");
    while (irsensorcheck(IRpin2)) {
      char cancelKey = keypadobj.getKey();
      if (cancelKey != NO_KEY) {
        if (cancelKey == '0') {
          lcd.clear();
          lcd.print("Cancelling Order...");
          digitalWrite(directionPin, LOW);
          moveMainStepper(15500);
          lcd.clear();
          return;
        } else if (cancelKey == '9') {
          printMakingJuice(juiceNo, price);
          break;
        }
      }
    }
  }

  printMakingJuice(juiceNo, price);

  delay(1000);
  
  if (needIce){
    iceMotor.moveDegreesCW(60);
    delay(1000);
    iceMotor.moveDegreesCW(60);
    delay(2000);
  }

  digitalWrite(directionPin, LOW);
  moveMainStepper(4100);
  if (requiredJuices[0]) {
    waterPump(pumpMotor1, volumeJuices[0] * 43.75);
  }
  moveMainStepper(1900);
  if (requiredJuices[1]) {
    waterPump(pumpMotor2, volumeJuices[1] * 43.75);
  }
  moveMainStepper(1900);
  if (requiredJuices[2]) {
    waterPump(pumpMotor3, volumeJuices[2] * 43.75);
  }
  moveMainStepper(1900);
  if (requiredJuices[3]) {
    waterPump(pumpMotor4, volumeJuices[3] * 43.75);
  }
  moveMainStepper(1900);
  if (requiredJuices[4]) {
    waterPump(pumpMotor5, volumeJuices[4] * 43.75);
  }
  moveMainStepper(3300);

  if (needMixing){
    delay(1000);
    digitalWrite(directionPin2, HIGH);
    delay(1000);
    moveMixingStepper(2500);
    delay(1000);
    digitalWrite(mixingMotor, HIGH);
    delay(5000);
    digitalWrite(mixingMotor, LOW);
    delay(1000);
    digitalWrite(directionPin2, LOW);
    delay(1000);
    moveMixingStepper(2500);
  }

  digitalWrite(directionPin, HIGH);
  delay(1000);
  moveMainStepper(1500);
  lcd.clear();
  lcd.print("Your drink is Ready!");
  startBuzzer();
  lcd.clear();
}

void printMakingJuice(int juiceNo, int price) {
  lcd.clear();
  if (juiceNo == 1) {
    lcd.clear();
    lcd.print("Making Lime Juice...");
  } else if (juiceNo == 2) {
    lcd.clear();
    lcd.print("Making Fruit");
    lcd.setCursor(0, 1);
    lcd.print("Juice...");
  } else if (juiceNo == 3) {
    lcd.clear();
    lcd.print("Making Sprite...");
  } else if (juiceNo == 4) {
    lcd.clear();
    lcd.print("Making Fruity");
    lcd.setCursor(0, 1);
    lcd.print("Vodka...");
  } else if (juiceNo == 5) {
    lcd.clear();
    lcd.print("Making Whiskey");
    lcd.setCursor(0, 1);
    lcd.print("Sour...");
  } else if (juiceNo == 6) {
    lcd.clear();
    lcd.print("Making Vodka with");
    lcd.setCursor(0, 1);
    lcd.print("Sprite...");
  } else if (juiceNo == 7) {
    lcd.clear();
    lcd.print("Making Custom");
    lcd.setCursor(0, 1);
    lcd.print("Juice...");
  }
  lcd.setCursor(0, 3);
  lcd.print("Price - Rs.");
  lcd.print(price);
  lcd.print(".00");
}

void startBuzzer(){
 digitalWrite(buzzer, HIGH);
  lcd.setBacklight(LOW);
  delay(300);
  digitalWrite(buzzer, LOW);
  lcd.setBacklight(HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  lcd.setBacklight(LOW);
  delay(300);
  digitalWrite(buzzer, LOW);
  lcd.setBacklight(HIGH);
  delay(300);
  digitalWrite(buzzer, HIGH);
  lcd.setBacklight(LOW);
  delay(300);
  digitalWrite(buzzer, LOW);
  lcd.setBacklight(HIGH);
  delay(3000); 
}