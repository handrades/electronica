#include <Servo.h> // instala la libreria de servo en library manager

int trigIn = 12; // numero del pin trig
int echoIn = 11; // numero del pin echo

int trigOut = 6; // numero del pin trig
int echoOut = 5; // numero del pin echo

Servo miServo;
int pinServo = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trigIn, OUTPUT); // configura pin trig como salida
  pinMode(echoIn,INPUT);   // configura pin echo como entrada

  pinMode(trigOut, OUTPUT); // configura pin trig como salida
  pinMode(echoOut,INPUT);   // configura pin echo como entrada

  miServo.attach(pinServo);
}

void loop() {
  //////////////////////////////////
  // secuencia de lectura del 'IN'
  //////////////////////////////////
  digitalWrite(trigIn, LOW);  // apaga trig 
  delay(2);                 // espera 2 milisegundos
  digitalWrite(trigIn, HIGH); // enciende trig
  delay(10);                // espera 10 milisegundos
  digitalWrite(trigIn, LOW);  // apaga trig

  int duracion = pulseIn(echoIn, HIGH);    // lee el valor de echo y guarda en variable 'duracion'
  int distancia = (duracion / 2) / 29.1; // calcula la distancia y guarda valor en variable 'distancia'
  Serial.println(distancia);             // imprime la distancia en serial
  delay(100);                            // espera 100 milisegundos

  ////////////////////////////////////
  // secuencia de lectura del 'OUT'
  ////////////////////////////////////
  digitalWrite(trigOut, LOW);  // apaga trig 
  delay(2);                 // espera 2 milisegundos
  digitalWrite(trigOut, HIGH); // enciende trig
  delay(10);                // espera 10 milisegundos
  digitalWrite(trigOut, LOW);  // apaga trig

  int duracion2 = pulseIn(echoOut, HIGH);    // lee el valor de echo y guarda en variable 'duracion'
  int distancia2 = (duracion2 / 2) / 29.1; // calcula la distancia y guarda valor en variable 'distancia'
  Serial.println(distancia2);             // imprime la distancia en serial
  delay(100);                            // espera 100 milisegundos

  if((distancia <= 100) && (distancia2 > 100)){
    miServo.write(90);
  }

  if((distancia2 <= 100) && (distancia > 100)){
    miServo.write(0);
  }

  if((distancia2 > 100) && (distancia > 100)){
    miServo.write(0);
  }

}
