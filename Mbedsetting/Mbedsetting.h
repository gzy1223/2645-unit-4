#ifndef Mbedsetting_H
#define Mbedsetting_H
#include "Joystick.h" 
#include "N5110.h"
#include "graphvalue.h"
#include "MMA8452.h"
#include "math.h"
struct coordinate
{
    float x = 0,y = 0,z = 0;
};
struct Map
{
    float x =0, y =0,z=0 ;
    int num;
};
struct return_monster
{
    float x =0, y =0 ;
    bool hurt;
};
matrix load_object(matrix block,Map map);
coordinate new_object_position(coordinate abs_value);

#endif
