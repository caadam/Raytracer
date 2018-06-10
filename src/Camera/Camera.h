#ifndef CAMERA_H
#define CAMERA_H

#include "Maths/Vector.h"

using namespace std;

class Camera
{
public:
  Vector origin_coord_;
  Vector plane_center_coord_;
  float plane_width_;
  float plane_height_;
protected:
private:
};

#endif