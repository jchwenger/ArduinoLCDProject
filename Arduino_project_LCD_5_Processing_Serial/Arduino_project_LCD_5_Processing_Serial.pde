import processing.serial.*;
Serial myPort;
PFont font;

int lf = 10;    // Linefeed in ASCII

String upString;
String downString;

void setup() {
  fullScreen();
  //size(400, 400);
  background(0);
  fill(255);

  font = createFont("Courier New", 20);
  textFont(font);
  textAlign(CENTER);

  println("Available serial ports:");
  println(Serial.list());
  myPort= new Serial(this, Serial.list()[1], 9600);
  myPort.clear();

  upString = "";
  downString = "";
}

void draw() {

  while (myPort.available() > 0) {
    background(0);

    delay(20);
    downString = myPort.readStringUntil(lf);
    delay(20);
    upString = myPort.readStringUntil(lf);


    if (upString != null) {
      text(upString, width/2, height/2-20);
      println("upString");
      println(upString);
    }

    if (downString != null) {
      text(downString, width/2, height/2);
      println("downString");
      println(downString);
    }
  }
}