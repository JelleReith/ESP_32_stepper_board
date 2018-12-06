import oscP5.*;
import netP5.*;
import controlP5.*;

ControlP5 cp5;

OscP5 oscP5;
NetAddress myRemoteLocation;


int stepper0 = 0;
int stepper1 = 0;
int stepper2 = 0;
int stepper3 = 0;
int stepper4 = 0;
int stepper5 = 0;
int stepper6 = 0;
int stepper7 = 0;
int stepper8 = 0;

int minStep = -400; 
int maxStep = 400;

void setup() {
  size(800, 800);
  background(0);
  strokeWeight(3);
  stroke(255);
  oscP5 = new OscP5(this, 12000);
  myRemoteLocation = new NetAddress("192.168.178.23", 8888); //IP of the ESP!

  cp5 = new ControlP5(this);

  cp5.addSlider("stepper0")
    .setPosition(20, 20)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper1")
    .setPosition(20, 120)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper2")
    .setPosition(20, 220)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper3")
    .setPosition(220, 20)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper4")
    .setPosition(220, 120)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper5")
    .setPosition(220, 220)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper6")
    .setPosition(420, 20)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper7")
    .setPosition(420, 120)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;

  cp5.addSlider("stepper8")
    .setPosition(420, 220)
    .setSize(200, 20)
    .setRange(minStep, maxStep)
    ;
  send_accels(100, 100, 100, 100, 100, 100, 100, 100, 100);
  send_speeds(200, 200, 200, 200, 200, 200, 200, 200, 200);
  send_pos();
}


void draw() {
}

void mouseReleased() {
  send_pos();
}

void send_speeds(int sp0, int sp1, int sp2, int sp3, int sp4, int sp5, int sp6, int sp7, int sp8) {
  OscBundle myBundle = new OscBundle();
  OscMessage steppers = new OscMessage("/speeds");
  steppers.add(sp0);
  steppers.add(sp1);
  steppers.add(sp2);
  steppers.add(sp3);
  steppers.add(sp4);
  steppers.add(sp5);
  steppers.add(sp6);
  steppers.add(sp7);
  steppers.add(sp8);
  myBundle.add(steppers);
  oscP5.send(myBundle, myRemoteLocation);
}

void send_accels(int ac0, int ac1, int ac2, int ac3, int ac4, int ac5, int ac6, int ac7, int ac8 ) {
  OscBundle myBundle = new OscBundle();
  OscMessage steppers = new OscMessage("/accels");
  steppers.add(ac0);
  steppers.add(ac1);
  steppers.add(ac2);
  steppers.add(ac3);
  steppers.add(ac4);
  steppers.add(ac5);
  steppers.add(ac6);
  steppers.add(ac7);
  steppers.add(ac8);
  myBundle.add(steppers);
  oscP5.send(myBundle, myRemoteLocation);
}
void send_pos() {
  OscBundle myBundle = new OscBundle();
  OscMessage steppers = new OscMessage("/steppers");
  steppers.add(stepper0);
  steppers.add(stepper1);
  steppers.add(stepper2);
  steppers.add(stepper3);
  steppers.add(stepper4);
  steppers.add(stepper5);
  steppers.add(stepper6);
  steppers.add(stepper7);
  steppers.add(stepper8);
  myBundle.add(steppers);
  oscP5.send(myBundle, myRemoteLocation);
}