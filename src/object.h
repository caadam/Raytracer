#ifndef OBJECT_H
#define OBJECT_H

#include "Intersection.h"
//class Boundaries;
#include "Ray.h"
#include "Material.h"

/**
 * Base class for all objects that can be ray traced.
 */

class Object {
public:
    //virtual Intersection intersect(Ray) = 0;
    //virtual Boundaries getBounds() = 0;

    Material* material_;
    virtual Intersection intersect(Ray ray) = 0;
};


#endif