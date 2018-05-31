//#pragma once
#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Vector.h"
#include "Material.h"

class Plane : public Object {
 public:
  Plane(Vector origin_coord, Vector normal_unit_vec, Material* material);
  Intersection intersect(Ray ray);

 private:
  Vector origin_coord_;
  Vector normal_unit_vec_;
};

#endif