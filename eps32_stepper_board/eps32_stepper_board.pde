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
  send_accel(100);
  send_speed(200);
  send_pos();
}


void draw() {
}

void mouseReleased() {
  send_pos();
}

void send_speed(int sp0) {
  OscMessage speeds = new OscMessage("/speed");
  speeds.add(sp0);
  oscP5.send(speeds, myRemoteLocation);
}

void send_accel(int ac0) {
  OscMessage accels = new OscMessage("/accel");
  accels.add(ac0);
  oscP5.send(accels, myRemoteLocation);
}

void send_pos() {
  OscMessage stepper0_pos = new OscMessage("/stepper0");
  stepper0_pos.add(stepper0);
  oscP5.send(stepper0_pos, myRemoteLocation);

  OscMessage stepper1_pos = new OscMessage("/stepper1");
  stepper1_pos.add(stepper1);
  oscP5.send(stepper1_pos, myRemoteLocation);

  OscMessage stepper2_pos = new OscMessage("/stepper2");
  stepper2_pos.add(stepper2);
  oscP5.send(stepper2_pos, myRemoteLocation);

  OscMessage stepper3_pos = new OscMessage("/stepper3");
  stepper3_pos.add(stepper3);
  oscP5.send(stepper3_pos, myRemoteLocation);

  OscMessage stepper4_pos = new OscMessage("/stepper4");
  stepper4_pos.add(stepper4);
  oscP5.send(stepper4_pos, myRemoteLocation);

  OscMessage stepper5_pos = new OscMessage("/stepper5");
  stepper5_pos.add(stepper5);
  oscP5.send(stepper5_pos, myRemoteLocation);

  OscMessage stepper6_pos = new OscMessage("/stepper6");
  stepper6_pos.add(stepper6);
  oscP5.send(stepper6_pos, myRemoteLocation);

  OscMessage stepper7_pos = new OscMessage("/stepper7");
  stepper7_pos.add(stepper7);
  oscP5.send(stepper7_pos, myRemoteLocation);

  OscMessage stepper8_pos = new OscMessage("/stepper8");
  stepper8_pos.add(stepper8);
  oscP5.send(stepper8_pos, myRemoteLocation);
}