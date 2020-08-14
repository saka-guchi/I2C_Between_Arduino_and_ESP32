// <https://www.arduino.cc/en/Tutorial/MasterWriter>
// <https://www.arduino.cc/en/Tutorial/MasterReader>
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI sub device

// Created 29 March 2006

// This example code is in the public domain.

#define MICON_ESP32                 // undefined if Arduino

#ifdef MICON_ESP32
#   define PIN_SDA  4               // GPIO4
#   define PIN_SCL 13               // GPIO13
#endif

// Check using ../I2C_Scanner/I2C_Scanner.ino
#define ADDRESS_SUB 0x8

#include <Wire.h>

void setup() {
#ifdef MICON_ESP32
    Wire.begin( PIN_SDA, PIN_SCL );
#else
    Wire.begin();
#endif

    Serial.begin( 115200 );
    while(!Serial);                 // Leonardo: wait for serial monitor
    Serial.println("\nI2C Main");
}

void loop(void) {
    writer();
    reader();
    delay(500);
}

void writer(void) {
    Serial.println("writer: ");

    static byte x = 0;
    Wire.beginTransmission(ADDRESS_SUB);    // transmit to device #8
    Wire.write("x is ");            // sends five bytes
    Wire.write(x);                  // sends one byte
    Wire.endTransmission();         // stop transmitting
    x++;
}

void reader(void) {
    Serial.print("reader: ");

    Wire.requestFrom(ADDRESS_SUB, 6);   // request 6 bytes from sub device #8

    while( Wire.available() ) {     // sub may send less than requested
        char c = Wire.read();       // receive a byte as character
        Serial.print(c);            // print the character
    }
}
