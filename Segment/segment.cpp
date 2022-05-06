#include "segment.h"


BusOut SegDis(PA_11, PA_12, PB_1, PB_15, PC_8, PB_12, PB_11); //Add remaining pins in correct order

void Segment::init()
{
    SegDis.write(0x00); //turn off the display by setting all segments to '0'
    ThisThread::sleep_for(200ms);
}
void Segment::show_remaining_live(int live)
{
       //cycle through the array and display each number / letter
            SegDis.write(hexDis[live]);


            ThisThread::sleep_for(500ms);

}
