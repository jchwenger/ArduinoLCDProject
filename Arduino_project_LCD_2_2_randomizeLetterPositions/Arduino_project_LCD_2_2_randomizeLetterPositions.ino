// https://ictronic.wordpress.com/2016/07/02/interfacing-16x2-lcd-with-arduino-without-potentiometer/


#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

String word1 = "automatonophobic";
int word1StartX = 2;

int switch1 = LOW;
int switch2 = LOW;

void setup() {


  pinMode(6, INPUT);
  pinMode(7, INPUT);

  lcd.begin(16, 2);

  randomizeWord();

}

void loop() {


  switch1 = digitalRead(7);
  switch2 = digitalRead(6);


  //  lcd.print("a l s v n s e e ");
  //  lcd.setCursor(0, 1);
  //  lcd.print(" l u i e e s s s ");
  //  delay(750);
  //  lcd.scrollDisplayLeft();
  //  lcd.setCursor(0, 0);


  positionSwitches();

}

int randomizer() {
  int result;
  float seed = random(-1, 1);
  if (seed < 0) {
    result = 0;
    return result;
  } else {
    result = 1;
    return result;
  }
}

void randomizeWord() {
  for (int i = 0; i < word1.length(); i++) {
    int pos = randomizer();
    lcd.setCursor(i, pos);
    lcd.print(word1.charAt(i));
  }

}

void positionSwitches() {

  if (switch1 == HIGH) {
    lcd.clear();
    randomizeWord();
  }

  if (switch2 == HIGH) {

  }

}
