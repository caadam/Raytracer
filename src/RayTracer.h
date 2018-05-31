//#pragma once
#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include "Object.h"
#include "Image.h"
#include "Camera.h"
#include "Light.h"
#include "Scene.h"

class RayTracer {
 public:
    Scene* scene;

  Color trace(Ray ray, int reflected = 0);
  Image render(int width, int height);

 private:
  bool getFirstObject(Ray ray, Object** object, Intersection* intersection);
};

#endif
