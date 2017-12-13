#include <LiquidCrystal.h>

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("a t m t n p o i ");
  lcd.setCursor(0, 1);
  lcd.print(" u o a o o h b c");
}

void loop() {

}

