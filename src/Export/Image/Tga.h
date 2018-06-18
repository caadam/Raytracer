#ifndef TGA_H
#define TGA_H

#include <cstdint>
#include <string>

#include "Color.h"
#include "Export/Image.h"

class Tga : public Image
{
public:
  Tga(int width, int height) : Image::Image(width, height)
  {
    _buffer = new uint32_t[width * height];
    _width = width;
    _height = height;
  }

  ~Tga()
  {
    delete[] _buffer;
  }

  virtual void Save(const char *outfile, bool scale_color = true);

private:
};

#endif
