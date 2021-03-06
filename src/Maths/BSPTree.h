#ifndef BSPTree_H
#define BSPTree_H

#include <math.h>
#include <vector>
#include "Maths/Boundaries.h"
#include "Maths/Ray.h"

class Object;
class Intersection;

#define MIN_OBJECT_COUNT 20

class BSPTree
{
private:
  int depth;
  int axisRetries;
  char axis;
  Boundaries bounds;
  std::vector<Object *> objects;
  BSPTree *left;
  BSPTree *right;

  void build();
  char toggleAxis();

public:
  BSPTree(int depth_, char axis_, std::vector<Object *> objects_) : depth(depth_), axis(axis_), objects(objects_)
  {
    axisRetries = 0;
    left = right = NULL;
    build();
  }

  Intersection getClosestIntersection(const Ray &);
  Intersection getClosestObjectIntersection(const Ray &);
};

#endif
