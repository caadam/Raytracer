#include "Ray.h"

/**
 * Calculates the fractional direction for the ray to avoid doing it multiple times.
 */
// void Ray::calcFracDirection() {
//    fracDir.x = 1.0f / direction.x;
//    fracDir.y = 1.0f / direction.y;
//    fracDir.z = 1.0f / direction.z;
// }

Ray Ray::reflect(Vector axis_unit_vec) {
  Vector proj = axis_unit_vec * direction_unit_vec_.dot(axis_unit_vec);
  Vector step = proj - direction_unit_vec_;
  return Ray(origin_coord_, direction_unit_vec_ + step * 2);
}