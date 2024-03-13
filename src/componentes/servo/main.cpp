#include <Servo.h> // instala la libreria de servo en library manager

Servo miServo;
int pos = 0;

void setup() {

  miServo.attach(9); // indicamos el pin digital

}

void loop() {
  
  for (pos = 0; pos <= 180; pos += 1) { // contamos del 0 al 180
    miServo.write(pos);
    delay(15);
  }

  miServo.write(0);
  delay(700);

}
