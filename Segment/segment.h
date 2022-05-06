#ifndef SEGMENT_H
#define SEGMENT_H
#include "mbed.h"
class Segment
{
    public:
    void show_remaining_live(int live);
    void init();
    private:
    int hexDis[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; // Add the rest of the hex values associated with the dispplay items 0-F


};
#endif