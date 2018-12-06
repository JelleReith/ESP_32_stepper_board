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
AccelStepper stepper4 (AccelStepper::DRIVER, 3, 22);//3 = RX-0 pin. Will change in next version
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
int accel0, accel1, accel2, accel3, accel4, accel5, accel6, accel7, accel8 = 0;
int speed0, speed1, speed2, speed3, speed4, speed5, speed6, speed7, speed8 = 0;
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
  }
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    if (debug) {
      Serial.print(".");
    }
    delay(500);
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

}
void accels(OSCMessage &msg) {
  accel0 = msg.getInt(0);
  accel1 = msg.getInt(1);
  accel2 = msg.getInt(2);
  accel3 = msg.getInt(3);
  accel4 = msg.getInt(4);
  accel5 = msg.getInt(5);
  accel6 = msg.getInt(6);
  accel7 = msg.getInt(7);
  accel8 = msg.getInt(8);

  stepper0.setAcceleration(accel0);
  stepper1.setAcceleration(accel1);
  stepper2.setAcceleration(accel2);
  stepper3.setAcceleration(accel3);
  stepper4.setAcceleration(accel4);
  stepper5.setAcceleration(accel5);
  stepper6.setAcceleration(accel6);
  stepper7.setAcceleration(accel7);
  stepper8.setAcceleration(accel8);


  if (debug) {
    Serial.print("accel 0 : " );
    Serial.println(accel0);
    Serial.print("accel 1 : " );
    Serial.println(accel1);
    Serial.print("accel 2 : " );
    Serial.println(accel2);
    Serial.print("accel 3 : " );
    Serial.println(accel3);
    Serial.print("accel 4 : " );
    Serial.println(accel4);
    Serial.print("accel 5 : " );
    Serial.println(accel5);
    Serial.print("accel 6 : " );
    Serial.println(accel6);
    Serial.print("accel 7 : " );
    Serial.println(accel7);
    Serial.print("accel 8 : " );
    Serial.println(accel8);
  }
}

void speeds(OSCMessage &msg) {
    speed0 = msg.getInt(0);
  speed1 = msg.getInt(1);
  speed2 = msg.getInt(2);
  speed3 = msg.getInt(3);
  speed4 = msg.getInt(4);
  speed5 = msg.getInt(5);
  speed6 = msg.getInt(6);
  speed7 = msg.getInt(7);
  speed8 = msg.getInt(8);

  stepper0.setSpeed(speed0);
  stepper1.setSpeed(speed1);
  stepper2.setSpeed(speed2);
  stepper3.setSpeed(speed3);
  stepper4.setSpeed(speed4);
  stepper5.setSpeed(speed5);
  stepper6.setSpeed(speed6);
  stepper7.setSpeed(speed7);
  stepper8.setSpeed(speed8);


  if (debug) {
    Serial.print("speed 0 : " );
    Serial.println(speed0);
    Serial.print("speed 1 : " );
    Serial.println(speed1);
    Serial.print("speed 2 : " );
    Serial.println(speed2);
    Serial.print("speed 3 : " );
    Serial.println(speed3);
    Serial.print("speed 4 : " );
    Serial.println(speed4);
    Serial.print("speed 5 : " );
    Serial.println(speed5);
    Serial.print("speed 6 : " );
    Serial.println(speed6);
    Serial.print("speed 7 : " );
    Serial.println(speed7);
    Serial.print("speed 8 : " );
    Serial.println(speed8);
  }
}

void steppers(OSCMessage &msg) {
  pos0 = msg.getInt(0);
  pos1 = msg.getInt(1);
  pos2 = msg.getInt(2);
  pos3 = msg.getInt(3);
  pos4 = msg.getInt(4);
  pos5 = msg.getInt(5);
  pos6 = msg.getInt(6);
  pos7 = msg.getInt(7);
  pos8 = msg.getInt(8);

  stepper0.moveTo(pos0);
  stepper1.moveTo(pos1);
  stepper2.moveTo(pos2);
  stepper3.moveTo(-pos3);
  stepper4.moveTo(-pos4);
  stepper5.moveTo(-pos5);
  stepper6.moveTo(pos6);
  stepper7.moveTo(pos7);
  stepper8.moveTo(pos8);
  if (debug) {
    Serial.print("stepper 0 : " );
    Serial.println(pos0);
    Serial.print("stepper 1 : " );
    Serial.println(pos1);
    Serial.print("stepper 2 : " );
    Serial.println(pos2);
    Serial.print("stepper 3 : " );
    Serial.println(pos3);
    Serial.print("stepper 4 : " );
    Serial.println(pos4);
    Serial.print("stepper 5 : " );
    Serial.println(pos5);
    Serial.print("stepper 6 : " );
    Serial.println(pos6);
    Serial.print("stepper 7 : " );
    Serial.println(pos7);
    Serial.print("stepper 8 : " );
    Serial.println(pos8);
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

  OSCBundle bundle;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      bundle.fill(Udp.read());
    }
    if (!bundle.hasError()) {
      bundle.dispatch("/accels", accels);
      bundle.dispatch("/speeds", speeds);
      bundle.dispatch("/steppers", steppers);
    } else {
      error = bundle.getError();
    }
  }
}
