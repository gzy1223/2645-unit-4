#include <Mbedsetting.h>
#include <cmath>
#include <cstdio>

matrix load_object(matrix block, Map map)
{
    block = matMove(block,map.x,map.y,0);

    return block;
}
coordinate new_object_position(coordinate abs_value)
{
    coordinate load_position;
    if (abs_value.x <0) {
    load_position.x = -sqrt(-load_position.x);
    }
    else {
    load_position.x = sqrt(load_position.x);
    }
    if (abs_value.y <0) {
    load_position.y = -sqrt(-load_position.y);
    }
    else {
    load_position.y = sqrt(load_position.y);
    }
    if (abs_value.z <0) {
    load_position.z= -sqrt(-load_position.z);
    }
    else {
    load_position.z = sqrt(load_position.z);
    }
    return load_position;
}