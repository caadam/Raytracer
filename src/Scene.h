//#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Geometry/Object.h"
#include "Export/Image.h"
#include "Camera/Camera.h"
#include "Lighting/Light.h"

class Scene
{
  public:
    Camera *camera_;
    std::vector<Light *> lights_;
    std::vector<Object *> objects_;
    Color ambient_;
    int softlight_quality_;
    int occlusion_quality_;
    bool softlight_enabled_;
    bool occlusion_enabled_;
    int max_reflections_;

    Scene() : softlight_quality_(50), occlusion_quality_(100), softlight_enabled_(true), occlusion_enabled_(true), max_reflections_(5) {}

  private:
};

#endif
