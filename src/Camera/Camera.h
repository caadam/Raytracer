#ifndef CAMERA_H
#define CAMERA_H

#include "Maths/Vector.h"

using namespace std;

class Camera
{
public:
  //    Vector position;
  //    Vector up;
  //    Vector lookAt;
  //    Vector w, u, v;
  //    double screenWidth;SS

  //
  Vector origin_coord_;
  Vector plane_center_coord_;
  float plane_width_;
  float plane_height_;
  //

  //    Camera() {
  //       position = Vector(0.0, 0.0, 100.0);
  //       up = Vector(0.0, 1.0, 0.0);
  //       lookAt = Vector(0.0, 0.0, 0.0);
  //       screenWidth = 1000;

  //       calculateWUV();
  //    }

  //    Camera(Vector position_, Vector up_, Vector lookAt_, double screenWidth_) :
  //       position(position_), up(up_), lookAt(lookAt_), screenWidth(screenWidth_) {
  //        calculateWUV();
  //    }

  //    void calculateWUV();
};

#endif