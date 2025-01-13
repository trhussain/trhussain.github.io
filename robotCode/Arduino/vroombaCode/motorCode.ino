void stopMotors() {
    analogWrite(AIN1, 0);
    analogWrite(AIN2, 0);
    analogWrite(BIN1, 0);
    analogWrite(BIN2, 0);
}

void motorController(const std::string& command) {
    if (command == "w") {
        setMotor1(true, 100);  // Move Motor 1 forward at speed 150
        setMotor2(true, 100);  // Move Motor 2 forward at speed 150
        Serial.println("Moving forward");
    } else if (command == "s") {
        setMotor1(false, 100); // Move Motor 1 backward at speed 150
        setMotor2(false, 100); // Move Motor 2 backward at speed 150
        Serial.println("Moving backward");
    } else if (command == "a") {
        setMotor1(false, 100); // Motor 1 backward
        setMotor2(true, 100);  // Motor 2 forward
        Serial.println("Turning left");
    } else if (command == "d") {
        setMotor1(true, 100);  // Motor 1 forward
        setMotor2(false, 100); // Motor 2 backward
        Serial.println("Turning right");
    }
    else if (command == "q") {
        analogWrite(ESC_PIN, 128);

    }
    else if (command == "e") {
        analogWrite(ESC_PIN, 0);
      
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

void testESC() { 
  for (int speed = 1000; speed <= 2000; speed += 10) {
      esc.writeMicroseconds(speed);  // Set throttle
      Serial.println(speed);
      delay(50);  // Adjust speed gradually
    }

    // Hold at maximum throttle
    delay(2000);

    // Gradually decrease throttle back to 0%
    for (int speed = 2000; speed >= 1000; speed -= 10) {
      esc.writeMicroseconds(speed);  // Set throttle
      Serial.println(speed);
      delay(50);  // Adjust speed gradually
    }

    delay(2000);  // Hold at minimum throttle


}