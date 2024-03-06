#include <ezButton.h> // importamos de library manager ezButton

ezButton boton(10);

int valorX = 0;
int valorY = 0;
int valorB = 0;

void setup() {
  // inicia el serial
  Serial.begin(9600);
  boton.setDebounceTime(50);
}

void loop() {
  boton.loop();

  // Lee los valores X e Y de la palanca 
  valorX = analogRead(A1);
  valorY = analogRead(A0);

  //Lee el estado del boton
  valorB = boton.getState();

  if (boton.isPressed()) {
    Serial.println("Boton presionado");
  }

  if (boton.isReleased()) {
    Serial.println("Boton liberado");
  }

  // Imprime la informacion al puerto serial
  Serial.print("x = ");
  Serial.print(valorX);
  Serial.print(", y = ");
  Serial.println(valorY);
  delay(200);

}
