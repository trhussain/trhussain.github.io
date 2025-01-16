void stopMotors() {
    analogWrite(AIN1, 0);
    analogWrite(AIN2, 0);
    analogWrite(BIN1, 0);
    analogWrite(BIN2, 0);
    ledcWrite(escPin,pulseToDuty(1100, freq, resolution) );

    fillSolid(CRGB::Blue);
}

void motorController(const std::string& command) {
    if (command == "w") {
        setMotor1(true, SPEED);  // Move Motor 1 forward at speed 150
        setMotor2(true, SPEED);  // Move Motor 2 forward at speed 150
        Serial.println("Moving forward");
    } else if (command == "s") {
        setMotor1(false, SPEED); // Move Motor 1 backward at speed 150
        setMotor2(false, SPEED); // Move Motor 2 backward at speed 150
        Serial.println("Moving backward");
    } else if (command == "a") {
        setMotor1(false, SPEED); // Motor 1 backward
        setMotor2(true, SPEED);  // Motor 2 forward
        Serial.println("Turning left");
    } else if (command == "d") {
        setMotor1(true, SPEED);  // Motor 1 forward
        setMotor2(false, SPEED); // Motor 2 backward
        Serial.println("Turning right");
    }

}
// Motor 1 Control
void setMotor1(bool forward, int speed) {
    analogWrite(AIN1, forward ? speed : 0); // Set PWM for AIN1
    analogWrite(AIN2, forward ? 0 : speed); // Set PWM for AIN2
}

// Motor 2 Control
void setMotor2(bool forward, int speed) {
    analogWrite(BIN1, forward ? speed : 0); // Set PWM for BIN1
    analogWrite(BIN2, forward ? 0 : speed); // Set PWM for BIN2
}
