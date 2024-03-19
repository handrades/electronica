int trig = 12; // numero del pin trig
int echo = 11; // numero del pin echo

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT); // configura pin trig como salida
  pinMode(echo,INPUT);   // configura pin echo como entrada
}

void loop() {
  // secuencia de lectura
  digitalWrite(trig, LOW);  // apaga trig 
  delay(2);                 // espera 2 milisegundos
  digitalWrite(trig, HIGH); // enciende trig
  delay(10);                // espera 10 milisegundos
  digitalWrite(trig, LOW);  // apaga trig

  int duracion = pulseIn(echo, HIGH);    // lee el valor de echo y guarda en variable 'duracion'
  int distancia = (duracion / 2) / 29.1; // calcula la distancia y guarda valor en variable 'distancia'
  Serial.println(distancia);             // imprime la distancia en serial
  delay(100);                            // espera 100 milisegundos
}
