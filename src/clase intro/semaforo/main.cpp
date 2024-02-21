void setup() {
    pinMode(10, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop() {
    // Verde
    digitalWrite(6, HIGH);
    delay(5000);
    digitalWrite(6, LOW);
    delay(500);
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);

    // Amarillo
    digitalWrite(8, HIGH);
    delay(3000);
    digitalWrite(8, LOW);

    // Rojo
    digitalWrite(10, HIGH);
    delay(11000);
    digitalWrite(10, LOW);
}