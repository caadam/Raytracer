#ifndef RAY_H
#define RAY_H

#include <stdlib.h>
#include "Vector.h"

class Material;

class Ray {
public:
  //  Vector origin;
  //  Vector direction;
  //  Vector fracDir;
  //  int reflectionsRemaining;
  //  Material* material;

  //  Ray() : origin(Vector()), direction(Vector()), reflectionsRemaining(-1),
  //   material(NULL) {
  //     calcFracDirection();
  //  }

  //  Ray(Vector origin_, Vector direction_, int reflections,
  //   Material* material_) : origin(origin_), reflectionsRemaining(reflections),
  //   material(material_) 
  //   {
  //     direction = direction_.normalize();

  //     /* Move intersection slightly forward to avoid intersecting with itself. */
  //     origin += (direction / 1000);

  //     calcFracDirection();
  //   }

//
  Ray() {}
  Ray(Vector origin_coord, Vector direction_unit_vec)
      : origin_coord_(origin_coord), direction_unit_vec_(direction_unit_vec) {}
  
  Ray reflect(Vector axis_unit_vec);

  Vector origin_coord_;
  Vector direction_unit_vec_;
  //

// private:
//    void calcFracDirection();
};

#endif