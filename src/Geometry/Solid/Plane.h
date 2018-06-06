//#pragma once
#ifndef PLANE_H
#define PLANE_H

#include "Maths/Vector.h"
#include "Shading/Material.h"

#include "Geometry/Object.h"

class Plane : public Object
{
public:
  Plane(Vector origin_coord, Vector normal_unit_vec, Material *material);
  Intersection intersect(Ray ray);

private:
  Vector origin_coord_;
  Vector normal_unit_vec_;
};

#endif