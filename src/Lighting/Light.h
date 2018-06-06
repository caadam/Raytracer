#ifndef LIGHT_H
#define LIGHT_H

#include "Maths/Vector.h"
#include "Color.h"

class Light
{
public:
  Vector origin_coord_;
  float intensity_;
  Color color_;
  float radius_;
};

#endif