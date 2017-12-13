// https://ictronic.wordpress.com/2016/07/02/interfacing-16x2-lcd-with-arduino-without-potentiometer/
// https://programmingelectronics.com/tutorial-19-debouncing-a-button-with-arduino-old-version/


int switch1 = LOW;
int switch2 = LOW;

int direction = true;

// two speeds
int speeds[] = {100, 600};
int index;

// tools to stabilize the pushbuttons
long time;
long debounce;

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

void setup() {

  pinMode(6, INPUT);
  pinMode(7, INPUT);

  lcd.begin(16, 2);

  debounce = 200;
  time = 0;

  index = 0;

}

void loop() {

  switch1 = digitalRead(7);
  switch2 = digitalRead(6);

  lcd.print("a l s v n s e e ");//print name
  lcd.setCursor(0, 1); // set the cursor to column 0, line 2
  lcd.print(" l u i e e s s s ");//print name
  directionSwitches();
  lcd.setCursor(0, 0);// set the cursor to column 0, line1

  speedSwitches();
}

// press the two buttons at the same time to increase the speed;
// when it reaches the maximum speed allowed it goes back to the slowest one
// (does not work that well)

void speedSwitches() {
  if (switch1 == HIGH && switch2 == HIGH && millis() - time > debounce) {
    index += 1;
    index = index % 2;
  }
}

// press one button or the other to make the text scroll right- or leftward

void directionSwitches() {
  if (switch1 == HIGH && millis() - time > debounce) {
    direction = true;
    time = millis();
  }
  if (switch2 == HIGH && millis() - time > debounce) {
    direction = false;
    time = millis();
  }

  if (direction == true) {
    delay(speeds[index]);//delay of 0.75sec
    lcd.scrollDisplayLeft();//shifting data on LCD
  } else {
    delay(speeds[index]);//delay of 0.75sec
    lcd.scrollDisplayRight();//shifting data on LCD
  }
}

