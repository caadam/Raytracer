#ifndef LIGHT_H
#define LIGHT_H

#include "Vector.h"
#include "Color.h"

class Light {
public:
  //  Vector position;
  //  double intensity;

//
  Vector origin_coord_;
  float intensity_;
  Color color_;
  float radius_;
//

  //  Light(Vector position_, double intensity_) :
  //   position(position_), intensity(intensity_) {}
};

#endif