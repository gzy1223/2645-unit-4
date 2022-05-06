#include "graphvalue.h"
#include "mbed.h"
#include <cstdio>
matrix calpoints(std::vector<std::vector<double>> points,vec3d rotatepoint,double angleX , double angleY , double angleZ ,    double scale ,
    double distance)
    {
            points = matScale(points, scale);
        matrix drawPoints;
        for (int i = 0; i < points.size(); i++)
        {
            matrix point{{points[i][0]}, {points[i][1]}, {points[i][2]}}; //get the point ready for matrix multiplication
            point[0][0] -= rotatepoint.x;                                 //  the rotation matrix around an arbitrary point can be expressed as moving the rotation point to the origin, rotating around the origin and moving back to the original position: https://bit.ly/3mJ3Q2v
            point[1][0] -= rotatepoint.y;
            point[2][0] -= rotatepoint.z;
            
            rotateX(point, angleX);
            rotateY(point, angleY);
            rotateZ(point, angleZ);
            point[0][0] += rotatepoint.x;
            point[1][0] += rotatepoint.y;
            point[2][0] += rotatepoint.z;
            project(point, distance);
            drawPoints.push_back({point[0][0], point[1][0]});
        }
        for(int i = 0;i<drawPoints.size();i++)
        {
            //printf("%f,%f\n",drawPoints[i][0],drawPoints[i][1]);
            drawPoints[i][0] *= 40;
            drawPoints[i][0] += 33;
            drawPoints[i][1] *= 40;
            drawPoints[i][1] += 13;
        }
        return drawPoints;
    }
    bool showimage(std::vector<std::vector<double>> point,float initialpoint)
    {
        if(point[0][0]*initialpoint>0)
        {
            return true;
        }
        else {
        return false;
        }
    }