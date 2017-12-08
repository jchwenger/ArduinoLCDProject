// https://ictronic.wordpress.com/2016/07/02/interfacing-16x2-lcd-with-arduino-without-potentiometer/


#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

int switch1 = LOW;
int switch2 = LOW;

int index = 0;

long time = 0;
long debounce = 200;

String wordsTest[] = {
  "automatonophobic", 
  "aggressivenesses", 
  "alphanumerically", 
  "associationistic", 
  "astrophotography", 
  "asynchronousness"
  };
  
String word1 = wordsTest[index];
//String word1 = "automatonophobic";
int word1StartX = 2;

void setup() {

  pinMode(6, INPUT);
  pinMode(7, INPUT);

  lcd.begin(16, 2);

  randomizeWord();

}

void loop() {

  switch1 = digitalRead(7);
  switch2 = digitalRead(6);

  positionSwitches();

}

// two buttons: one to pick another random distribution of the letters on the LCD screen
// the other to switch between words in the array

void positionSwitches() {

  if (switch1 == HIGH && millis() - time > debounce) {
    lcd.clear();
    randomizeWord();
    time = millis();
  }

  if (switch2 == HIGH && millis() - time > debounce) {
    lcd.clear();
    switchWord();
    delay(50);
    randomizeWord();
    time = millis();
  }

}

// switches to the next word in the array

void switchWord() {
  if (index < 5) {
    index++;
  } else {
    index = 0;
  }
}


// randomises the position of letters in either the upper or lower row of the LCD

void randomizeWord() {
  for (int i = 0; i < wordsTest[index].length(); i++) {
    int pos = randomizer();
    lcd.setCursor(i, pos);
    lcd.print(wordsTest[index].charAt(i));
  }
}

// randomizing function

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
