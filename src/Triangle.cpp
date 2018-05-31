#include <stdlib.h>
#include "triangle.h"
#include "Object.h"
#include "Vector.h"
#include "Material.h"

namespace {
bool onSameSide(Vector t0, Vector t1, Vector p0, Vector p1) {
  return ((p1-p0).cross(t0 - p0)).dot((p1-p0).cross(t1 - p0)) >= 0;
}
}

Triangle::Triangle(Vector p0, Vector p1, Vector p2, Material* material)
    : p0_(p0), p1_(p1), p2_(p2) {
  material_ = material;
}

Intersection Triangle::intersect(Ray ray) {
  Intersection result;
  result.happened_ = false;

  Vector u, v, normal;
  
  u = p1_ - p0_;
  v = p2_ - p0_;
  normal = u.cross(v);

  Vector p0_to_ray = ray.origin_coord_ - p0_;
  float r, a, b;
  a = - normal.dot(p0_to_ray);
  b = normal.dot(ray.direction_unit_vec_);
  if (abs(b) < 0.0001)
    return result;

  r = a / b;
  if (r < 0)
    return result;

  result.contact_coord_ = ray.origin_coord_ + ray.direction_unit_vec_ * r;

  Vector w = result.contact_coord_ - p0_;
  
  if (onSameSide(w, u, v, Vector(0,0,0)) &&
      onSameSide(w, Vector(0,0,0), u, v) &&
      onSameSide(w, v, Vector(0,0,0), u)) {
    result.happened_ = true;
    result.normal_unit_vec_ = normal.unit();
  }

  return result;
}