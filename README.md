# I2C_Between_Arduino_and_ESP32
**I2C communication between Arduino and ESP32 (ex. M5Camera).**

Can be used between Arduinos.

## Preparation for connection
### Main microcomputer: M5Camera
### Sub microcomputer: Arduino M0 PRO
### How to connect

- Use Grove connector of M5 Camera
- Arduino is powered by M5 Camera

| M5Camera | Arduino M0 PRO |
| --- | --- |
| GND | GND |
| 5V | Vin |
| SDA (13) | SDA (16) |
| SCL (4) | SCL (17) |

<img src="README/circuit_diagram.jpg" width="600">

## I2C Communicate between microcomputers
1. [I2C_Scanner.ino](I2C_Scanner/I2C_Scanner.ino) that supports ESP32 by editing [I2cScanner](https://playground.arduino.cc/Main/I2cScanner/)

2. Use [I2C_Main.ino](I2C_Main/I2C_Main.ino) and [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) that merges the following two files
- [Master Writer/Slave Receiver](https://www.arduino.cc/en/Tutorial/MasterWriter)

```[File] > [Examples] > [Wire] > [master_writer]```

```[File] > [Examples] > [Wire] > [slave_receiver]```

- [Master Reader/Slave Sender](https://www.arduino.cc/en/Tutorial/MasterReader)

```[File] > [Examples] > [Wire] > [master_reader]```

```[File] > [Examples] > [Wire] > [slave_sender]```

## Modify the sketch to suit your environment

**3 files: If you use Arduino, comment out the line below.**

```
#define MICON_ESP32              // undefined if Arduino
```

**[I2C_Sub.ino](I2C_Sub/I2C_Sub.ino): Change the address defined below.**

```
#define ADDRESS 0x8
```

## Find connected device addresses
1. No problem if the address defined in [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) is found

<img src="README/I2C_Scanner.png" width="600">

Serial monitor output on the Main side.

```
I2C device found at address 0x08  ! ← Sub
I2C device found at address 0x28  ! ← Main
```

## Check the behavior on the serial monitor

### Main: ESP32, Sub: Arduino
| M5Camera | Arduino M0 PRO | Operation check |
| --- | --- | --- |
| [I2C_Main.ino](I2C_Main/I2C_Main.ino) | [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) | OK |

<img src="README/I2C_Code.png" width="600">

Serial monitor output on the Main side.

```
writer:                   ← write("x is 16");
reader: hello             ← read();
```

Serial monitor output on the Sub side.

```
receiveEvent: x is 16     ← read();
requestEvent:             ← write("hello\n");
```

### Main: Arduino, Sub: ESP32
| M5Camera | Arduino M0 PRO | Operation check |
| --- | --- | --- |
| [I2C_Sub.ino](I2C_Sub/I2C_Sub.ino) | [I2C_Main.ino](I2C_Main/I2C_Main.ino) | NG (Error output) |

**ESP32 Arduino Core does not implement I2C sub functionality as of August 15, 2020.**

If you want to implement, see https://www.arduino.cc/reference/en/libraries/esp32-i2c-slave/

