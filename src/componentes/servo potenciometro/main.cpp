#include <Servo.h> // instala la libreria de servo en library manager

Servo miServo;
int val;

void setup() {

  miServo.attach(9); // indicamos el pin digital

}

void loop() {

  val = analogRead(A0);
  val = map(val, 0, 1023, 0, 180);
  miServo.write(val);

  delay(15);

}
