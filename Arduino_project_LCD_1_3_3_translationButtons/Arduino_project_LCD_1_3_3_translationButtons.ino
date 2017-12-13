#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

//String word1 = "catness";
String word1 = "labyrinth";
String rotString = word1;
int width = 7;
int word1Delay = 350;
int word1StartX = 2;

int switch1 = LOW;
int switch2 = LOW;

String rotStringTop;
String rotStringBottom;

void setup() {


  pinMode(6, INPUT);
  pinMode(7, INPUT);

  lcd.begin(16, 2);


  for (int i = 0; i < (width * 2) - word1.length(); i++) {
    rotString += " ";
  }

  rotStringTop = rotString.substring(0, width);
  rotStringBottom = rotString.substring(width);

}

void loop() {

  switch1 = digitalRead(7);
  switch2 = digitalRead(6);

  lcd.setCursor(word1StartX, 0);
  lcd.print(rotStringTop);
  lcd.rightToLeft();
  lcd.setCursor(word1StartX + width - 1, 1);
  lcd.print(rotStringBottom);
  lcd.leftToRight();

  String newRotStringTop = rotStringTop.substring(1, rotStringTop.length()) + rotStringBottom.charAt(0);
  String newRotStringBottom = rotStringBottom.substring(1, rotStringBottom.length()) + rotStringTop.charAt(0);

  rotStringTop = newRotStringTop;
  rotStringBottom = newRotStringBottom;

  delay(word1Delay);

  positionSwitches();

}

void positionSwitches() {

  if (switch1 == HIGH) {
    word1StartX++;
    lcd.setCursor(word1StartX - 1, 0);
    lcd.print(" ");
    lcd.setCursor(word1StartX - 1, 1);
    lcd.print(" ");

  }

  if (switch2 == HIGH) {
    word1StartX--;
    for (int j = 0; j < 16-(word1StartX - width); j++){
    lcd.setCursor(j, 0);
    lcd.print(" ");
    lcd.setCursor(j, 1);
    lcd.print(" ");
    }
  }

}
