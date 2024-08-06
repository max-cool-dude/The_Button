#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>   

const int buttonPin = 2;
int buttonState = 0;
int preButtonState = 0;
u_int32_t displayNum = 0;

// Pin definitions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void displayDigit1(u_int32_t num) {
  u_int8_t digit1 = num % 10;
  Serial.println(digit1);
}


void setup() {
  // Start Serial
  Serial.begin(115200);
  delay(500);
  Serial.println("Starting");

  pinMode(buttonPin, INPUT);

  // SSD1306 Init
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the buffer.
  display.display();
  delay(2000);
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

