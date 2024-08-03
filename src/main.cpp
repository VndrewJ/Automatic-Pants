#include <FastLED.h>
#include <Arduino.h>

// Define the number of LEDs in the strip
#define NUM_LEDS 12

// Define the data pin connected to the LED strip
#define DATA_PIN 0

// Motor Pins
#define MOTOR1_PIN1 4
#define MOTOR1_PIN2 5
#define MOTOR1_PWM 3

#define MOTOR2_PIN1 12
#define MOTOR2_PIN2 13
#define MOTOR2_PWM 11

// Motor definition for funsies
#define MOTOR1 0
#define MOTOR2 1
#define CW 0
#define CCW 1

// Button Pin
#define BUTTON 7

// Create an array to hold the LED data
CRGB leds[NUM_LEDS];

// Global for state
volatile bool state = 0;

// Toggles state on button press
void button_ISR() {
  // static unsigned long last_interrupt_time = 0;
  // unsigned long interrupt_time = millis();
  // // debounce stuff
  // if (interrupt_time - last_interrupt_time > 200) {
  //   state = !state; // Toggle the state on button press
  // }
  // last_interrupt_time = interrupt_time;
  Serial.println("poop");
}

// Turns motors off
void motor_off(bool motor_select) {
  if(!motor_select){
    digitalWrite(MOTOR1_PIN1, LOW);
    digitalWrite(MOTOR1_PIN2, LOW);
  }else{
    digitalWrite(MOTOR2_PIN1, LOW);
    digitalWrite(MOTOR2_PIN2, LOW);
  }
}

// sets a motors direction, 0 is CW, 1 is CCW
void motor_dir(bool motor_select, bool dir) {
  if(!motor_select){
    digitalWrite(MOTOR1_PIN1, dir);
    digitalWrite(MOTOR1_PIN2, !dir); 
  }else{
    digitalWrite(MOTOR2_PIN1, dir);
    digitalWrite(MOTOR2_PIN2, !dir);
  }
}

void setup() {
  Serial.begin(9600);

  // Setup motors pins
  // pinMode(MOTOR1_PIN1, OUTPUT);
  // pinMode(MOTOR1_PIN2, OUTPUT);
  // pinMode(MOTOR1_PWM, OUTPUT);

  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(MOTOR2_PWM, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(BUTTON), button_ISR, FALLING);

  pinMode(13, OUTPUT);

  analogWrite(MOTOR1_PWM, 100);

  // Initialise default state
  state = 0;

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

  // if(state){
  //   Serial.println("motor on");
  //   motor_dir(MOTOR1, CW);
  //   motor_dir(MOTOR2, CW);
  //   delay(200);
  // }else{
  //   Serial.println("motor off");
  //   motor_off(MOTOR1);
  //   motor_off(MOTOR2);
  //   delay(200);
  // }

  bool button_pressed = digitalRead(BUTTON);

  if(!button_pressed){
    Serial.println("poo");
  }

  if(button_pressed){
    Serial.println("pee");
  }
}
