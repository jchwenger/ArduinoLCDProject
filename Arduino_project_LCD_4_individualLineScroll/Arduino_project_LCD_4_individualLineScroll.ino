// found some code here, which lacks the looping feature I am after:
// http://www.instructables.com/id/Scroll-a-Single-LCD-Line-In-How-to/

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

String word1 = "absolutenesses";
String word2 = "accursednesses";

String rotString1;
String rotString2;

int startingPos1 = 0;
int startingPos2 = 0;

int line1 = 0;
int line2 = 1;

int delay1 = 350;
int delay2 = 250;

int frame = 0;

void setup() {

  lcd.begin(16, 2);
  lcd.clear();

  rotString1 = word1;
  rotString2 = word2;

}

void loop() {
  
  scrollLineLeftward(0, 20, 0, rotString1);
  scrollLineRightward(0, 20, 1, rotString2);

  frame++;
}


void scrollLineLeftward (int startingPos, int width, int line, String scrollString) {

  if (scrollString.length() < width) {
    for (int i = 0; i <= width - scrollString.length(); i++) {
      scrollString += " ";
    }
  }

  scrollString = scrollString.substring(frame%width) + scrollString.substring(0, frame%width);
  lcd.setCursor(startingPos, line);
  lcd.print(scrollString);
  delay(delay1);

}


void scrollLineRightward (int startingPos, int width, int line, String scrollString) {

  if (scrollString.length() < width) {
    for (int i = 0; i <= width - scrollString.length(); i++) {
      scrollString += " ";
    }
  }

  lcd.setCursor(startingPos, line);
  lcd.print(scrollString);

  scrollString = scrollString.substring(width - frame%width, width) + scrollString.substring(0, width - frame%width);
  lcd.setCursor(startingPos, line);
  lcd.print(scrollString);
  delay(delay2);

}


