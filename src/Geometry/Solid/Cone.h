#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include "Vector.h"
#include "Material.h"

class Sphere : public Object
{
public:
  Sphere(Vector origin_coord, float radius, Material *material);

  virtual Intersection intersect(Ray ray);

private:
  Vector origin_coord_;
  float radius_;
};

#endif