const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

portMUX_TYPE synch = portMUX_INITIALIZER_UNLOCKED;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink_isr, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink_isr() {
  portENTER_CRITICAL(&synch);
  state = !state;
  portEXIT_CRITICAL(&synch);
}
