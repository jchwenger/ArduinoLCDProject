// https://ictronic.wordpress.com/2016/07/02/interfacing-16x2-lcd-with-arduino-without-potentiometer/

#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 8, 9, 10, 11);

int frame = 0;

int switch1 = LOW;
int switch2 = LOW;

int index;

long time = 0;
long debounce = 200;

String words[] = {
  "automatonophobic",
  "aggressivenesses",
  "alphanumerically",
  "associationistic",
  "astrophotography",
  "asynchronousness",
  "absentmindedness",
  "chronogeometries",
  "circumnavigators",
  "coquettishnesses",
  "counterblockades",
  "corruptibilities",
  "cruelheartedness",
  "curmudgeonliness",
  "interfertilities",
  "machineabilities",
  "mechanotherapist",
  "operationalistic",
  "nymphomaniacally",
  "obstreperousness",
  "procrastinations",
  "recontemplations"
};


void setup() {

  lcd.begin(16, 2);

  index = 0;

  Serial.begin(9600);

  pinMode(6, INPUT);
  pinMode(7, INPUT);



  randomizeWord();

}

void loop() {

  switch1 = digitalRead(7);
  switch2 = digitalRead(6);

  switches();

  vanisher();

  frame++;
}

// every 50'000 frame, one character (blank or not) will be replaced
// by a blank character

void vanisher() {
  if (frame % 50000 == 0) {
    int randomSpot = int(random(0, 16));
    int pos = randomizer();
    lcd.setCursor(randomSpot, pos);
    lcd.blink();
    delay(60);
    lcd.noBlink();
    lcd.print(" ");
    delay(30);
  }
}

// two buttons: one to pick another random distribution of the letters on the LCD screen
// the other to switch between words in the array

void switches() {

  if (switch1 == HIGH && millis() - time > debounce) {
    lcd.clear();
    delay(50);
    switchWord();
    time = millis();
    delay(50);
    randomizeWord();
    time = millis();
  }

  if (switch2 == HIGH && millis() - time > debounce) {
    lcd.clear();
    delay(50);
    randomizeWord();
    time = millis();
  }
}

void switchWord() {
  index = int(random(0, 23));
  Serial.println(index);
}

// randomises the position of letters in either the upper or lower row of the LCD

void randomizeWord() {

  String upString = "";
  String downString = "";

  for (int i = 0; i < words[index].length(); i++) {
    int pos = randomizer();
    lcd.setCursor(i, pos);
    lcd.print(words[index].charAt(i));

    if (pos == 0) {
      upString += words[index].charAt(i);
    } else {
      upString += " ";
    }

    if (pos == 0) {
      downString += " ";
    } else {
      downString += words[index].charAt(i);
    }
  }

  Serial.println(upString);
  Serial.println(downString);
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
