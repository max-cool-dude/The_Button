#include <Arduino.h>

const int buttonPin = 2;
int buttonState = 0;
int preButtonState = 0;
u_int32_t displayNum = 0;


void displayDigit1(u_int32_t num) {
  u_int8_t digit1 = num % 10;
  Serial.println(digit1);
}


void setup() {
  // Start Serial
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
}

void loop() {
  preButtonState = buttonState;
  buttonState = digitalRead(buttonPin);
  if (buttonState > preButtonState) {
    displayNum = displayNum + 1;
    Serial.println(displayNum);
    //displayDigit1(displayNum);
  }
  delay(30);
}

