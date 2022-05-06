#ifndef GRAPHVALUE_H
#define GRAPHVALUE_H
#include "matrixmath.h"


matrix calpoints(std::vector<std::vector<double>> point,vec3d rotatepoints,double angleX = 0, double angleY = 0, double angleZ = 0,    double scale = 2.0f,
    double distance = 2);
bool showimage(std::vector<std::vector<double>> point,float initialpoint);
#endif