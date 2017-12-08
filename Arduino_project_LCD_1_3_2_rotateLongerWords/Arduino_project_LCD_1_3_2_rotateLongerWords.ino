#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

//String word1 = "catness";
String word1 = "labyrinth";

String rotString = word1;

// what space will the rotate on
int width = 7;

// control speed
int word1Delay = 350;

// control starting point (top left corner)
int word1StartX = 2;

String rotStringTop;
String rotStringBottom;

void setup() {

  lcd.begin(16, 2);


  for (int i = 0; i < (width * 2) - word1.length(); i++) {
    rotString += " ";
  }

  rotStringTop = rotString.substring(0, width);
  rotStringBottom = rotString.substring(width);

}

void loop() {

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

}
