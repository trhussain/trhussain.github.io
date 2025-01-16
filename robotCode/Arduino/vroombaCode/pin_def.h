// pin_definitions.h

#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H

// Pin assignments: Use IOx 

#define M1_AIN1 3
#define LED_PIN 2
#define NUM_LEDS 1


#define AIN1 6  // AIN1 for Motor 1
#define AIN2 7  // AIN2 for Motor 1
#define BIN1 8  // BIN1 for Motor 2
#define BIN2 9  // BIN2 for Motor 2


#define PWM_CHANNEL 0  // PWM channel
#define PWM_FREQUENCY 50  // Frequency in Hz (50Hz for ESC)
#define PWM_RESOLUTION 16  // Resolution in bits
#define SPEED 200
const int escPin = 1;        // PWM pin for ESC
const int freq = 50;         // ESC frequency (50 Hz)
const int escChannel = 0;    // PWM channel
const int resolution = 12;   // 12-bit resolution (0-4095)
int brushThresh = 0;
#endif // PIN_DEFINITIONS_H
