#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <AccelStepper.h>

boolean debug = true; //if set to true Serial.println works but stepper

AccelStepper stepper0 (AccelStepper::DRIVER, 15, 2);
AccelStepper stepper1 (AccelStepper::DRIVER, 4, 17);
AccelStepper stepper2 (AccelStepper::DRIVER, 5, 18);
AccelStepper stepper3 (AccelStepper::DRIVER, 23, 32);
AccelStepper stepper4 (AccelStepper::DRIVER, 16, 22); // pin 3 on old board
AccelStepper stepper5 (AccelStepper::DRIVER, 19, 21);
AccelStepper stepper6 (AccelStepper::DRIVER, 33, 25);
AccelStepper stepper7 (AccelStepper::DRIVER, 26, 27);
AccelStepper stepper8 (AccelStepper::DRIVER, 14, 12);

char ssid[] = "YOURSSID";               // your network SSID (name)
char pass[] = "YOURPSK";           // your network password

WiFiUDP Udp;
const IPAddress outIp(10, 40, 10, 105);     // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)

int pos0, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8 = 0;
OSCErrorCode error;

int max_speed = 1000;
int my_speed = 1000;
int my_accel = 1500;

void setup() {

  stepper0.setMaxSpeed(max_speed);
  stepper0.setAcceleration(my_accel);

  stepper1.setMaxSpeed(max_speed);
  stepper1.setAcceleration(my_accel);

  stepper2.setMaxSpeed(max_speed);
  stepper2.setAcceleration(my_accel);

  stepper3.setMaxSpeed(max_speed);
  stepper3.setAcceleration(my_accel);

  stepper4.setMaxSpeed(max_speed);
  stepper4.setAcceleration(my_accel);

  stepper5.setMaxSpeed(max_speed);
  stepper5.setAcceleration(my_accel);

  stepper6.setMaxSpeed(max_speed);
  stepper6.setAcceleration(my_accel);

  stepper7.setMaxSpeed(max_speed);
  stepper7.setAcceleration(my_accel);

  stepper8.setMaxSpeed(max_speed);
  stepper8.setAcceleration(my_accel);
  if (debug) {
    Serial.begin(9600);
    delay(1000);
    Serial.println("Hi, thanks for using my board! Note that debug mode is on, stepper 4 will not work");
    Serial.println("Send a OSC_bundle to ");
  }
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (debug) {
      Serial.print(".");
    }
  }
  if (debug) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("Starting UDP");
  }
  Udp.begin(localPort);
  if (debug) {
    Serial.print("Local port: ");
  }
#ifdef ESP32
  if (debug) {
    Serial.println(localPort);
  }
#else
  if (debug) {
    Serial.println(Udp.localPort());
  }
#endif
  Serial.println("Send a OSC_bundle with 9 interger value's to /stepper to use the board. ");
}

void set_accel(OSCMessage &msg) {
  my_accel = msg.getInt(0);
  stepper0.setMaxSpeed(max_speed);
  stepper0.setAcceleration(my_accel);

  stepper1.setMaxSpeed(max_speed);
  stepper1.setAcceleration(my_accel);

  stepper2.setMaxSpeed(max_speed);
  stepper2.setAcceleration(my_accel);

  stepper3.setMaxSpeed(max_speed);
  stepper3.setAcceleration(my_accel);

  stepper4.setMaxSpeed(max_speed);
  stepper4.setAcceleration(my_accel);

  stepper5.setMaxSpeed(max_speed);
  stepper5.setAcceleration(my_accel);

  stepper6.setMaxSpeed(max_speed);
  stepper6.setAcceleration(my_accel);

  stepper7.setMaxSpeed(max_speed);
  stepper7.setAcceleration(my_accel);

  stepper8.setMaxSpeed(max_speed);
  stepper8.setAcceleration(my_accel);

  if (debug) {

    Serial.print("New acceleration : ");
    Serial.println(my_accel);

  }
}

void set_speed(OSCMessage &msg) {
  max_speed = msg.getInt(0);
  stepper0.setMaxSpeed(max_speed);
  stepper0.setAcceleration(my_accel);

  stepper1.setMaxSpeed(max_speed);
  stepper1.setAcceleration(my_accel);

  stepper2.setMaxSpeed(max_speed);
  stepper2.setAcceleration(my_accel);

  stepper3.setMaxSpeed(max_speed);
  stepper3.setAcceleration(my_accel);

  stepper4.setMaxSpeed(max_speed);
  stepper4.setAcceleration(my_accel);

  stepper5.setMaxSpeed(max_speed);
  stepper5.setAcceleration(my_accel);

  stepper6.setMaxSpeed(max_speed);
  stepper6.setAcceleration(my_accel);

  stepper7.setMaxSpeed(max_speed);
  stepper7.setAcceleration(my_accel);

  stepper8.setMaxSpeed(max_speed);
  stepper8.setAcceleration(my_accel);

  if (debug) {

    Serial.print("New speed : ");
    Serial.println(max_speed);

  }
}
void move0(OSCMessage &msg) {
  pos0 = msg.getInt(0);
  stepper0.moveTo(pos0);
  if (debug) {
    Serial.print("stepper 0 ");
    Serial.println(pos0);
  }
}

void move1(OSCMessage &msg) {
  pos1 = msg.getInt(0);
  stepper1.moveTo(pos1);
  if (debug) {
    Serial.print("stepper 1 ");
    Serial.println( pos1);
  }
}

void move2(OSCMessage &msg) {
  pos2 = msg.getInt(0);
  stepper2.moveTo(pos2);
  if (debug) {
    Serial.print("stepper 2 ");
    Serial.println( pos2);
  }
}

void move3(OSCMessage & msg) {
  pos3 = msg.getInt(0);
  stepper3.moveTo(pos3);
  if (debug) {
    Serial.print("stepper 3 ");
    Serial.println( pos3);
  }
}

void move4(OSCMessage & msg) {
  pos4 = msg.getInt(0);
  stepper4.moveTo(pos4);
  if (debug) {
    Serial.print("stepper 4 ");
    Serial.println( pos4);
  }
}

void move5(OSCMessage & msg) {
  pos5 = msg.getInt(0);
  stepper5.moveTo(pos5);
  if (debug) {
    Serial.print("stepper 5 ");
    Serial.println( pos5);
  }
}

void move6(OSCMessage & msg) {
  pos6 = msg.getInt(0);
  stepper6.moveTo(pos6);
  if (debug) {
    Serial.print("stepper 6 ");
    Serial.println( pos6);
  }
}

void move7(OSCMessage & msg) {
  pos7 = msg.getInt(0);
  stepper7.moveTo(pos7);
  if (debug) {
    Serial.print("stepper 7 ");
    Serial.println( pos7);
  }
}

void move8(OSCMessage & msg) {
  pos8 = msg.getInt(0);
  stepper8.moveTo(pos8);
  if (debug) {
    Serial.print("stepper 8 ");
    Serial.println( pos8);
  }
}



void loop() {
  stepper0.run();
  stepper1.run();
  stepper2.run();
  stepper3.run();
  stepper4.run();
  stepper5.run();
  stepper6.run();
  stepper7.run();
  stepper8.run();

  OSCMessage msg;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/stepper0", move0);
      msg.dispatch("/stepper1", move1);
      msg.dispatch("/stepper2", move2);
      msg.dispatch("/stepper3", move3);
      msg.dispatch("/stepper4", move4);
      msg.dispatch("/stepper5", move5);
      msg.dispatch("/stepper6", move6);
      msg.dispatch("/stepper7", move7);
      msg.dispatch("/stepper8", move8);
      msg.dispatch("/accel", set_accel);
      msg.dispatch("/speed", set_speed);

    } else {
      error = msg.getError();
      if (debug) {
        Serial.print("error: ");
        Serial.println(error);
      }
    }
  }
}
