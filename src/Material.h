#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"

class Material {
public:
  float kAmbient, kDiffuse, kOcclusion, kReflection, kSpecular, shininess;
  Color cDiffuse, cReflection, cSpecular;
};

#endif