#ifndef RAY_H
#define RAY_H

#include <stdlib.h>
#include "Vector.h"

class Material;

class Ray
{
  public:
    Ray() {}
    Ray(Vector origin_coord, Vector direction_unit_vec)
        : origin_coord_(origin_coord), direction_unit_vec_(direction_unit_vec) {}

    Ray reflect(Vector axis_unit_vec);

    Vector origin_coord_;
    Vector direction_unit_vec_;

  private:
};

#endif