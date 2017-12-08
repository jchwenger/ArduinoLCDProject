// Switch/button structure adapted from here:
// https://www.arduino.cc/en/tutorial/switch

#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

int switch1 = LOW;
int switch2 = LOW;

boolean topIsOn = false;
boolean previousTop = false;

boolean bottomIsOn = false;
boolean previousBottom = false;

long time = 0;
long debounce = 200;

void setup() {

  //  Serial.begin(9600);

  pinMode(6, INPUT);
  pinMode(7, INPUT);

  lcd.begin(16, 2);

}

void loop() {

  switch1 = digitalRead(6);
  switch2 = digitalRead(7);

  //  Serial.println(switch1);
  //  Serial.println(switch2);

  //  Serial.println(topIsOn);
  //  Serial.println(bottomIsOn);


  if (topIsOn == true) {
    lcd.setCursor(0, 0);
    lcd.print("a t m t n p o i ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("                ");
  }

  if (bottomIsOn == true) {
    lcd.setCursor(0, 1);
    lcd.print(" u o a o o h b c");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  //writeIt();

  buttonSwitches();
}

void buttonSwitches() {

  if (switch2 == HIGH && previousBottom == false && millis() - time > debounce) {
    if (bottomIsOn == false) {
      bottomIsOn = true;
    } else {
      bottomIsOn = false;
    }
    time = millis();
  }

  previousBottom = switch2;

  if (switch1 == HIGH && previousTop == false && millis() - time > debounce) {
    if (topIsOn == false) {
      topIsOn = true;
    } else {
      topIsOn = false;
    }
    time = millis();
  }

  previousTop = switch1;


}

//void writeIt() {
//
//  if (switch1 == HIGH) {
//    topIsOn = true;
//  }
//
//  if (switch2 == HIGH) {
//    bottomIsOn = true;
//  }
//
//}

