#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

int x = 0;
int y = 0;
int i = 0;

long frame = 0;

// cat, rat and bat are all running around
String word1 = "cat ";
String word2 = "rat ";
String word3 = "bat ";

String rotString = word1;

int word1Delay = 12000;
int word1StartX = 0;

int word2Delay = 7000;
int word2StartX = 7;

int word3Delay = 5000;
int word3StartX = 14;

void setup() {
  lcd.begin(16, 2);

}

void loop() {

  if (frame % word1Delay == 0) {
    rotateSquareWord(word1, word1StartX);
  }


  if (frame % word2Delay == 0) {
    rotateSquareWord(word2, word2StartX);
  }



  if (frame % word3Delay == 0) {
    rotateSquareWord(word3, word3StartX);
  }

  frame++;
}

void rotateSquareWord(String s, int startX) {
  //void rotateSquareWord(String s, int startX, int rotSpeed) {
  // delay(rotSpeed);

  lcd.setCursor(startX, y);
  lcd.print(s.charAt(i % s.length()));

  lcd.setCursor(startX + 1, y);
  lcd.print(s.charAt((i + 1) % s.length()));

  lcd.setCursor(startX + 1, y + 1);
  lcd.print(s.charAt((i + 2) % s.length()));

  lcd.setCursor(startX, y + 1);
  lcd.print(s.charAt((i + 3) % s.length()));

  i++;

}


// for longer words (that require a width, not just a square of four characters)
// see an example of use in project_LCD_1_4

void rotateLongerWord(String s, int startX, int width, int rotSpeed) {

  if (s.length() > width * 2) {
    rotString = s.substring(0, width);
  } else {
    for (int i = 0; i < (width * 2) - s.length(); i++) {
      rotString += " ";
    }
  }

  String rotStringTop = rotString.substring(0, width);
  String rotStringBottom = rotString.substring(width);

  lcd.setCursor(startX, 0);
  lcd.print(rotStringTop);
  lcd.rightToLeft();
  lcd.setCursor(startX + width, 1);
  lcd.print(rotStringBottom);
  lcd.leftToRight();

  String newRotStringTop = rotStringTop.substring(1, rotStringTop.length()) + rotStringBottom.charAt(rotStringBottom.length());
  String newrotStringBottom = rotStringTop.charAt(0) + rotStringBottom.substring(1, rotStringBottom.length());

  rotStringTop = newRotStringTop;
  rotStringBottom = newrotStringBottom;

  delay(rotSpeed);
}


