//#pragma once
#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include "Export/Image.h"
#include "Scene.h"

#include "Geometry/Object.h"
#include "Camera/Camera.h"
#include "Lighting/Light.h"

class RayTracer
{
public:
  Scene *scene;

  Color trace(Ray ray, int reflected = 0);
  void render(int width, int height, Image *image);

private:
  bool getFirstObject(Ray ray, Object **object, Intersection *intersection);
};

#endif
