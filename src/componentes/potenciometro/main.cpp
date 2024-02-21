int potenciometro = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potenciometro = analogRead(A0);
  
  Serial.print(potenciometro);
  Serial.print("\n");
  delay(500);
}