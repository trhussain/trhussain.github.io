#include <Arduino.h>
#include <FastLED.h>


#define LED_PIN 2
#define NUM_LEDS 1
#define AIN1 6
#define AIN2 7
#define BIN1 8
#define BIN2 9
CRGB led[NUM_LEDS];


void setup() {
 delay(1000);






 // Initialize the LED
 FastLED.addLeds<WS2812B, LED_PIN, GRB>(led, NUM_LEDS);
 FastLED.setBrightness(50); // Brightness level (0-255)
 led[0] = CRGB::Blue;
 FastLED.show();
 // USBSerial.begin(9600);
 pinMode(AIN1, OUTPUT);
 pinMode(AIN2, OUTPUT);
 pinMode(BIN1, OUTPUT);
 pinMode(BIN2, OUTPUT);
}


void loop() {

 Serial.println("test");
 delay(2000);
}



