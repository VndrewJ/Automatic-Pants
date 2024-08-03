#include <FastLED.h>
#include <Arduino.h>

// Define the number of LEDs in the strip
#define NUM_LEDS 12

// Define the data pin connected to the LED strip
#define DATA_PIN 0

// Motor Pins
#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 4
#define MOTOR1_PWM 9

#define MOTOR2_PIN1 12
#define MOTOR2_PIN2 13
#define MOTOR2_PWM 10

// Create an array to hold the LED data
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);

  // Setup motors pins
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR1_PWM, OUTPUT);

  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(MOTOR2_PWM, OUTPUT);

  analogWrite(MOTOR1_PWM, 200);

  // Initialize the LED strip
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  // Set all LEDs to red
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  
  // Update the LED strip to show the color
  FastLED.show();
}

void loop() {
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(1000);

  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(500);
}
