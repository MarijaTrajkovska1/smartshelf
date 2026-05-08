# smartshelf
RFID + weight sensor smart shelf system 

Smart Shelf is an embedded system project that combines load cell weight sensing (HX711) and RFID authentication (MFRC522) to automatically detect products taken from a shelf and calculate charges based on item removal.
The system is designed as a prototype for a smart retail / vending / inventory tracking system.

1. Each product (e.g. water bottle) has a known weight (~500g).
2. The load cell continuously measures total shelf weight.
3. When weight decreases, the system calculates how many items were removed.
4. An RFID card identifies the user/customer.
5. The system calculates total cost and sends a charge event.

Hardware:
- Arduino MKR1000 Wifi
- HX711 Load Cell amplifier
- Load cell (weight sensor)
- MFRC522 RFID module
- RFID cards/tags(i used both)
- Shelf structure (cardboard/wood prototype)


System Logic:

- 1 bottle ≈ 500g
- Price per bottle = 3.5$
- Weight change is converted into item count: items_removed=weight_change/500
- Billing only occurs if a valid RFID user is active.


 Calibration:

The system requires calibration of the HX711 sensor:

1. Measure raw value with empty shelf
2. Measure raw value with known weight (e.g. 500g)
3. Compute scale factor: scale_factor=(raw_with_weight-raw_empty)/500
4. Insert value into:
scale.set_scale(SCALE_FACTOR);

The system communicates via Serial in the following format:
- System boot: SYS|BOOT_OK
- RFID detected: CARD|UDI_CODE
- Weight reading: WEIGHT|1234.56
- Charge event:CHARGE|2|7.00

AUTHOR:
Developed as a student IoT project.

<img width="5712" height="4284" alt="IMG_8503" src="https://github.com/user-attachments/assets/8547ecb8-8060-48bc-9e56-6411fae1b897" />

<img width="4032" height="3024" alt="IMG_8502" src="https://github.com/user-attachments/assets/299b46bd-7f8d-43f1-b905-c21d6e33ce9a" />

