import asyncio
from bleak import BleakClient
from pynput.keyboard import Listener

# Constants
DEVICE_UUID = "1659743F-315B-A06B-0E96-61703438E1A3"
CHARACTERISTIC_UUID = "00001234-0000-1000-8000-00805f9b34fb"

# Queue to store keyboard strokes
key_queue = []

# Function to send data to the BLE server
async def send_data(client):
    while True:
        if key_queue:
            # Get the next keystroke from the queue
            key = key_queue.pop(0)
            # Send the keystroke to the BLE server
            await client.write_gatt_char(CHARACTERISTIC_UUID, key.encode("utf-8"))
            print(f"\nSent: {key}")

# Function to capture keyboard strokes
def on_press(key):
    try:
        # Convert key to a string and add it to the queue
        key_queue.append(key.char)
    except AttributeError:
        # Handle special keys like space, enter, etc.
        key_queue.append(f"[{key}]")

# Main function to connect and interact with the BLE server
async def main():
    print(f"Connecting to {DEVICE_UUID}...")
    async with BleakClient(DEVICE_UUID) as client:
        print(f"Connected to device: {DEVICE_UUID}")
        
        # Read characteristic value
        value = await client.read_gatt_char(CHARACTERISTIC_UUID)
        print(f"Characteristic value: {value.decode('utf-8')}")
        for service in client.services:
            print(f"Service UUID: {service.uuid}")
            for characteristic in service.characteristics:
                print(f"Characteristic UUID: {characteristic.uuid}")
                print(f"Properties: {characteristic.properties}")
        with Listener(on_press=on_press) as listener:
            # Run the sender loop and listen for keyboard input
            await send_data(client)

# Run the main function
asyncio.run(main())

''''''