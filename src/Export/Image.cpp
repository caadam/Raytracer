#include <cstdlib>
#include <vector>

#include "Export/Image.h"

// Image::Image(int width, int height)
// {
//     buffer_ = new uint32_t[width * height];
//     width_ = width;
//     height_ = height;
// }

// Image::~Image()
// {
//     delete[] buffer_;
// }

// uint32_t &Image::at(int x, int y)
// {
//     return _buffer[x + y * _width];
// }

// void Image::set(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
// {
//     uint32_t &pixel = at(x, y);
//     unsigned char *components = reinterpret_cast<unsigned char *>(&pixel);
//     components[0] = b;
//     components[1] = g;
//     components[2] = r;
//     components[3] = a;
// }

// Color Image::get(int x, int y)
// {
//     uint32_t &pixel = at(x, y);
//     // Convert to color
//     unsigned char *components = reinterpret_cast<unsigned char *>(&pixel);
//     return Color(components[2], components[1], components[0]);
// }