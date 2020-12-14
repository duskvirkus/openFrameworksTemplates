void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int received = Serial.read();

    if (received == 'A') {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (received == 'B') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}