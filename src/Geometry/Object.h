#ifndef OBJECT_H
#define OBJECT_H

#include "Maths/Intersection.h"
//class Boundaries;
#include "Maths/Ray.h"
#include "Shading/Material.h"

/**
 * Base class for all objects that can be ray traced.
 */

class Object
{
  public:
    //virtual Intersection intersect(Ray) = 0;
    //virtual Boundaries getBounds() = 0;

    Material *material_;
    virtual Intersection intersect(Ray ray) = 0;
};

#endif