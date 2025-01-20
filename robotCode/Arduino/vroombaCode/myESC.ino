

// Helper function to map pulse width (µs) to duty cycle value
int pulseToDuty(int pulseWidth, int frequency, int resolution) {
  int period = 1000000 / frequency; // Period in microseconds
  int maxDuty = (1 << resolution) - 1; // Max duty cycle value
  return (pulseWidth * maxDuty) / period; // Map pulse width to duty value
}
void escSetup() { 
  ledcAttach(escPin, freq, resolution); // Setup PWM

  // Start with minimum throttle (1100 µs)
  int minThrottle = pulseToDuty(1100, freq, resolution);
  Serial.println("Starting ESC with minimum throttle...");
  for (int i = 0; i < 2; i++) { 
  for (int pulseWidth = 1100; pulseWidth <= 1250; pulseWidth += 10) {
    int duty = pulseToDuty(pulseWidth, freq, resolution);
    ledcWrite(escPin, duty);

    Serial.print("setup Pulse Width: ");
    Serial.print(pulseWidth);
    Serial.print(" µs, Duty Cycle: ");
    Serial.println(duty);

    delay(500); // Wait and observe motor behavior

    // Stop the loop if you find the stable spin
    // You can note the pulse width where it spins stably // okay yeah 1150
  }
  }

}
void brushFlag() { 

}
void brushLoop() {
    // Ensure ESC starts with minimum throttle
    int minThrottle = pulseToDuty(1100, freq, resolution);
    Serial.println("Sending minimum throttle to reinitialize ESC...");
    ledcWrite(escPin, minThrottle);
    delay(2000); // Give the ESC time to arm

    // Start throttle loop
    Serial.println("Starting brushLoop...");

    for (int ix = 0; ix < 4; ix++) { 
      
        for (int pulseWidth = 1100; pulseWidth <= 2000; pulseWidth += 10) {
              int duty = pulseToDuty(pulseWidth, freq, resolution);
              ledcWrite(escPin, duty);

              //Serial.print("loop Pulse Width: ");
              //Serial.print(pulseWidth);
              //Serial.print(" µs, Duty Cycle: ");
              //Serial.println(duty);
              //delay(1000);
              // Wait and observe motor behavior
            
        }
        Serial.println("Next iteration...");
        Serial.print(ix);
    }
}
void offbruhs() { 

}
void brush() {
  int myDuty = pulseToDuty(1200, freq, resolution);
  ledcWrite(escPin,pulseToDuty(1400, freq, resolution) );
  delay(1000); // Stabilize
  ledcWrite(escPin,pulseToDuty(1450, freq, resolution) );
  delay(1000);


}