#ifndef Music_H
#define Music_H
#include "mbed.h"
class Music{
public:
void start_music();
void block_music();
void hurt_music();
void over_music();
private:
void play_note(int frequency);

};
#endif