#include <FastLED.h>
#include "NimBLEDevice.h"
#include "pin_def.h"

CRGB leds[NUM_LEDS];
// vroombaCode.ino
void ledController(std::string typedChar); // Prototype for ledController
void fillSolid(CRGB color);               // Prototype for fillSolid
void motorController(const std::string& command);

class MyServerCallbacks : public NimBLEServerCallbacks {
    void onConnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo) override {
        Serial.println("Client connected!");
        Serial.flush(); // Ensure full transmission of the message
    }

    void onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason) override {
        Serial.println("Client disconnected!");
        Serial.print("Reason: ");
        Serial.println(reason);
        NimBLEDevice::getAdvertising()->start(); // Restart advertising
    }
};

class MyCallbacks : public NimBLECharacteristicCallbacks {
    void onWrite(NimBLECharacteristic *characteristic, NimBLEConnInfo& connInfo) override {
        std::string value = characteristic->getValue();
        if (!value.empty()) {

            // Correct string comparison
            if (value == "b" | value == "o") {
                ledController(value);
            }
            else if (value == "w" | value == "a" | value == "s" |value == "d")
                motorController(value);
        }
    }
};




void setup() {
    Serial.begin(115200);
    delay(2000); // Allow time for Serial Monitor to initialize
    Serial.println("Starting BLE Server...");

    NimBLEDevice::init("NimBLE_Server");

    NimBLEServer *pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    NimBLEService *pService = pServer->createService("ABCD");
    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic(
        "1234",
        NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::NOTIFY | NIMBLE_PROPERTY::INDICATE
    );

    pCharacteristic->setValue("Hello BasdasdLE");
    pCharacteristic->setCallbacks(new MyCallbacks());
    pService->start();

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID("ABCD");
    pAdvertising->start();

    Serial.println("BLE Server is running...");
    Serial.println("Motor tests");

    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();  // Clear all LEDs initially
    FastLED.show();   // Send data to turn off all LEDs

    // Set motor pins as outputs
    pinMode(MOTOR1_PWM1, OUTPUT);
    pinMode(MOTOR1_PWM2, OUTPUT);
    pinMode(MOTOR2_PWM1, OUTPUT);
    pinMode(MOTOR2_PWM2, OUTPUT);

    // Ensure motors are stopped initially
    stopMotors();


}

void loop() {

    
  }
