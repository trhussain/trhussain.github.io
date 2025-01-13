void stopMotors() {
    analogWrite(MOTOR1_PWM1, 0);
    analogWrite(MOTOR1_PWM2, 0);
    analogWrite(MOTOR2_PWM1, 0);
    analogWrite(MOTOR2_PWM2, 0);
}

void motorController(const std::string& command) {
    Serial.println("C Called");
    if (command == "w") {
        setMotor1(true, 128);  // Move Motor 1 forward at speed 150
        setMotor2(true, 128);  // Move Motor 2 forward at speed 150
        Serial.println("Moving forward");
    } else if (command == "s") {
        setMotor1(false, 50); // Move Motor 1 backward at speed 150
        setMotor2(false, 50); // Move Motor 2 backward at speed 150
        Serial.println("Moving backward");
    } else if (command == "a") {
        setMotor1(false, 50); // Motor 1 backward
        setMotor2(true, 50);  // Motor 2 forward
        Serial.println("Turning left");
    } else if (command == "d") {
        setMotor1(true, 50);  // Motor 1 forward
        setMotor2(false, 50); // Motor 2 backward
        Serial.println("Turning right");
    }
}
// Motor 1 Control
void setMotor1(bool forward, int speed) {
    analogWrite(MOTOR1_PWM1, forward ? speed : 0); // Set PWM for AIN1
    analogWrite(MOTOR1_PWM2, forward ? 0 : speed); // Set PWM for AIN2
}

// Motor 2 Control
void setMotor2(bool forward, int speed) {
    analogWrite(MOTOR2_PWM1, forward ? speed : 0); // Set PWM for BIN1
    analogWrite(MOTOR2_PWM2, forward ? 0 : speed); // Set PWM for BIN2
}