PFont font;
import processing.serial.*;
Serial port;

void setup(){
  size(500, 500);
  frameRate(60);
  font = loadFont("CharterBT-Roman-48.vlw");
  port = new Serial(this "/deb/ttyACM0", 9600);
}

void draw(){
  background(0);
  timeN = second() + minute()*60 + hour()*3600;
  time = timeN - timeS;
  text(time, 0, 0);
  
}

void serialEvent(Serial p){
  val = p.read();
  if(val == a){
    timeS = second() + minute() * 60 + hour() * 3600;
  }
}
