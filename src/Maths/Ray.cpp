#include "Maths/Ray.h"

Ray Ray::reflect(Vector axis_unit_vec)
{
  Vector proj = axis_unit_vec * direction_unit_vec_.dot(axis_unit_vec);
  Vector step = proj - direction_unit_vec_;
  return Ray(origin_coord_, direction_unit_vec_ + step * 2);
}