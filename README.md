# I2C_Between_Arduino_and_ESP32
**I2C communication between Arduino and ESP32 (ex. M5Camera).**

Can be used between Arduinos.

## Preparation for connection

### Main microcomputer: M5Camera
Use of GROVE terminal.

### Sub microcomputer: Arduino M0 PRO

### How to connect

| M5Camera | Arduino M0 PRO |
| --- | --- |
| GND | GND |
| 5V | Vin |
| SDA (13) | SDA (16) |
| SCL (4) | SCL (17) |

<img src="README/circuit_diagram.jpg" width="600">

## Find connected device addresses
1. Using a customized [I2C_Scanner.ino](I2C_Scanner/I2C_Scanner.ino) for ESP32.

Original file is [here](https://playground.arduino.cc/Main/I2cScanner/)

<img src="README/I2C_Scanner.png" width="600">

## I2C Communicate between microcomputers
1. Use [I2C_Main.ino](I2C_Main/I2C_Main.ino) and [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) that merges the following two files
- [Master Writer/Slave Receiver](https://www.arduino.cc/en/Tutorial/MasterWriter)

```[File] > [Examples] > [Wire] > [master_writer]```

```[File] > [Examples] > [Wire] > [slave_receiver]```

- [Master Reader/Slave Sender](https://www.arduino.cc/en/Tutorial/MasterReader)

```[File] > [Examples] > [Wire] > [master_reader]```

```[File] > [Examples] > [Wire] > [slave_sender]```

2. Edit the microcomputer type of code.

**If you use Arduino, comment out the line below.**

```
#define MICON_ESP32              // undefined if Arduino
```

3. Connect two microcomputers to PC.

4. Upload and check the behavior on the serial monitor

| M5Camera | Arduino M0 PRO | Operation check |
| --- | --- | --- |
| [I2C_Main.ino](I2C_Main/I2C_Main.ino) | [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) | OK |
| [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) | [I2C_Main.ino](I2C_Main/I2C_Main.ino) | NG (Error output) |

**ESP32 Arduino Core does not implement I2C sub functionality as of August 15, 2020.**

If you want to implement, see https://www.arduino.cc/reference/en/libraries/esp32-i2c-slave/

<img src="README/I2C_Code.png" width="600">
