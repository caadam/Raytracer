#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <limits>
#include "Maths/Vector.h"
// #include "Object.h"
#include "Color.h"
// #include "Ray.h"
// #include "Material.h"

class Intersection
{
public:
  //  Ray ray;
  //  bool didIntersect;
  //  Vector intersection;
  //  double distance;
  //  Vector normal;
  //  Material* startMaterial;
  //  Material* endMaterial;
  //  Object* object;

  //
  bool happened_;
  Vector contact_coord_;
  Vector normal_unit_vec_;
  //

  //  Intersection(Ray ray_, Vector intersection_, double distance_, Vector normal_,
  //   Material* startMaterial_, Material* endMaterial_, Object* object_) :
  //   ray(ray_), didIntersect(true), intersection(intersection_), distance(distance_),
  //   normal(normal_), startMaterial(startMaterial_), endMaterial(endMaterial_),
  //   object(object_) {}

  //  Intersection() : ray(Ray()), didIntersect(false),
  //   intersection(Vector()), distance(std::numeric_limits<double>::max()),
  //    normal(Vector()), startMaterial(NULL), endMaterial(NULL), object(NULL) {}

  //  Color getColor() const;
};

#endif