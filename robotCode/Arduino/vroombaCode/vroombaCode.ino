#include "NimBLEDevice.h"
void ledController() { 
  Serial.println("motor called");

}
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
            Serial.print("Received: ");
            Serial.println(value.c_str()); // Print the received message
             
            // Correct string comparison
            if (value == "b" | value == "o") {
                motorController();
            }
            
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
}

void loop() {
    // No actions needed in the loop
}
