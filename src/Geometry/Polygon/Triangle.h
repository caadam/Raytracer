//#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Geometry/Object.h"
#include "Maths/Vector.h"
#include "Shading/Material.h"

class Triangle : public Object
{
public:
  Triangle(Vector p0, Vector p1, Vector p2, Material *material);

  virtual Intersection intersect(Ray ray);

private:
  Vector p0_, p1_, p2_;
};

#endif