#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <string>

#include "Color.h"

class Image
{
private:
protected:
  uint32_t *_buffer;
  int _width;
  int _height;
  double _max;

public:
  Image(int width, int height)
  {
    _buffer = new uint32_t[width * height];
    _width = width;
    _height = height;
  }

  ~Image()
  {
    delete[] _buffer;
  }

  // Props
  int height() const { return _height; }
  int width() const { return _width; }
  double max() const { return _max; }

  // Functions
  // uint32_t &at(int x, int y);
  // void set(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
  // Color get(int x, int y);

  uint32_t &at(int x, int y)
  {
    return _buffer[x + y * _width];
  }

  void set(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
  {
    uint32_t &pixel = at(x, y);
    unsigned char *components = reinterpret_cast<unsigned char *>(&pixel);
    components[0] = b;
    components[1] = g;
    components[2] = r;
    components[3] = a;
  }

  Color get(int x, int y)
  {
    uint32_t &pixel = at(x, y);
    // Convert to color
    unsigned char *components = reinterpret_cast<unsigned char *>(&pixel);
    return Color(components[2], components[1], components[0]);
  }

  virtual void Save(const char *outfile, bool scale_color = true) {};
};

#endif
