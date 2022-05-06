/**
@file MMA8452.h
 
@brief Header file containing member functions and variables
 
*/
 
#ifndef MMA8452_H
#define MMA8452_H
 
// MMA8452 address is 0x1D by default (see EAGLE schematic of breakout - SA = 1)
#define MMA8452_W_ADDRESS   0x3A
#define MMA8452_R_ADDRESS   0x3B
// Register Descriptions - p18 datasheet
#define OUT_X_MSB           0x01
#define WHO_AM_I            0x0D
#define CTRL_REG1           0x2A
#define XYZ_DATA_CFG        0x0E
 
typedef struct Acceleration Acceleration;
struct Acceleration {
    float x;
    float y;
    float z;
};
 
#include "mbed.h"
 
class MMA8452
{
 
public:
    /** Create a MMA8452 object connected to the specified pins
    *
    * @param sdaPin - mbed SDA pin
    * @param sclPin - mbed SCL pin
    *
    */
    MMA8452(PinName sdaPin, PinName sclPin);
 
    /** Initialise accelerometer
    *
    *   Powers up the accelerometer, sets 100 Hz update rate and ±4g scale
    */
    void init();
 
    /** Get values of acceleration
    *
    *   Reads the x,y,z values in g's
    *   @returns an Acceleration structure with x,y,z members (float)
    */
    Acceleration readValues();
 
 
private:
    void sendByteToRegister(char byte,char reg);
    char readByteFromRegister(char reg);
    void readBytesFromRegister(char reg,int numberOfBytes,char bytes[]);
    void error();
 
public:
 
private:  // private variables
    I2C*    i2c;
    BusOut*  leds;
 
};
 
 
 
#endif