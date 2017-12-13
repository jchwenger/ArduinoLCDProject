#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);
int width = 16;
int height = 2;

//String word1 = "rotor";
String word1 = "stressed";

void setup() {
  lcd.begin(width, height);

}

void loop() {

  lcd.setCursor(width / 2 - (word1.length() - 1), 0);
  lcd.print(word1);
  lcd.rightToLeft();
  lcd.setCursor(width / 2 + (word1.length() - 1), 1);
  lcd.print(word1);
  lcd.leftToRight();

}
