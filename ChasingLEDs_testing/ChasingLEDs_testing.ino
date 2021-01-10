byte ledPin[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Create array for LED pins
int ledDelay = 500; // delay between changes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  for (int x=0; x<12; x++) { // set all pins to output
  pinMode(ledPin[x], OUTPUT);
  }
}

void FadeLED() {
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
}

void loop() {
  delay(ledDelay);
  changeLED();
}

void changeLED() {
  for (int x=0; x<12; x++) { // turn off all LED's
    analogWrite(ledPin[x], 255);
  }
  analogWrite(ledPin[currentLED], 0); // turn on the current LED
  currentLED += direction; // increment by the direction value 
  // change direction if we reach the end
  if (currentLED == 12) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}
