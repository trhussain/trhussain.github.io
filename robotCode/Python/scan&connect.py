import asyncio
from bleak import BleakClient

# Replace this with the macOS-generated device UUID from the scan
DEVICE_UUID = "1659743F-315B-A06B-0E96-61703438E1A3"

# Service and characteristic UUIDs from Arduino code
SERVICE_UUID = "ABCD"
CHARACTERISTIC_UUID = "1234"

async def connect_and_read():
    async with BleakClient(DEVICE_UUID) as client:
        print(f"Connected to device: {DEVICE_UUID}")
        
        # Read characteristic value
        value = await client.read_gatt_char(CHARACTERISTIC_UUID)
        print(f"Characteristic value: {value.decode('utf-8')}")

asyncio.run(connect_and_read())


# 23973315-B6D8-F8AE-1009-D0E463051F9A

''' 
async def scan_devices():
    devices = await BleakScanner.discover()
    for device in devices:
        print(f"Device Address: {device.address}, Name: {device.name or 'Unknown'}, UUIDs: {device.metadata.get('uuids')}")

asyncio.run(scan_devices())
'''

'''
 arduino code that worked
 #include "NimBLEDevice.h"

void setup() {
    Serial.begin(115200); // Start the Serial Monitor for debugging
    Serial.println("Starting BLE...");

    NimBLEDevice::init("NimBLE");
    Serial.print("Device Bluetooth Address: ");
    Serial.println(NimBLEDevice::getAddress().toString().c_str());

    NimBLEServer *pServer = NimBLEDevice::createServer();
    NimBLEService *pService = pServer->createService("ABCD");
    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic("1234");

    pService->start();
    pCharacteristic->setValue("Hello BLnbhvc hngfcghfrcdE");

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID("ABCD");
    pAdvertising->start();

    Serial.println("BLE service started.");
}

void loop() {
    // Nothing here for now
    Serial.println("testtest");
    delay(1000);
}

'''
