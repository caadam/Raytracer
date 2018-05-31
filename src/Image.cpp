#include <cstdlib>
#include <vector>

#include "Image.h"

Image::Image(int width, int height) {
  buffer_ = new uint32_t[width * height];
  width_ = width;
  height_ = height;
}

Image::~Image() {
  delete [] buffer_;
}

uint32_t& Image::at(int x, int y) {
   return buffer_[x + y * width_];
}

void Image::set(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) 
{
  uint32_t& pixel = at(x, y);
  unsigned char* components = reinterpret_cast<unsigned char*>(&pixel);
  components[0] = b;
  components[1] = g;
  components[2] = r;
  components[3] = a;
}

Color Image::get(int x, int y)
{
    uint32_t& pixel = at(x, y);
    // Convert to color
    unsigned char* components = reinterpret_cast<unsigned char*>(&pixel);
    return Color(components[2],components[1],components[0]);
}

void Image::WriteTga(const char *outfile, bool scale_color)
{
    FILE *fp = fopen(outfile, "w");
    if (fp == NULL)
    {
        perror("ERROR: Image::WriteTga() failed to open file for writing!\n");
        exit(EXIT_FAILURE);
    }
    
    // write 24-bit uncompressed targa header
    // thanks to Paul Bourke (http://local.wasp.uwa.edu.au/~pbourke/dataformats/tga/)
    putc(0, fp);
    putc(0, fp);
    
    putc(2, fp); // type is uncompressed RGB
    
    putc(0, fp);
    putc(0, fp);
    putc(0, fp);
    putc(0, fp);
    putc(0, fp);
    
    putc(0, fp); // x origin, low byte
    putc(0, fp); // x origin, high byte
    
    putc(0, fp); // y origin, low byte
    putc(0, fp); // y origin, high byte

    putc(width_ & 0xff, fp); // width, low byte
    putc((width_ & 0xff00) >> 8, fp); // width, high byte

    putc(height_ & 0xff, fp); // height, low byte
    putc((height_ & 0xff00) >> 8, fp); // height, high byte

    putc(24, fp); // 24-bit color depth

    putc(0, fp);

    // write the raw pixel data in groups of 3 bytes (BGR order)
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            // if color scaling is on, scale 0.0 -> _max as a 0 -> 255 unsigned byte
            unsigned char rbyte, gbyte, bbyte;

            Color color = get(x,height_ - y -1);

            if (scale_color)
            {
                rbyte = (unsigned char)((color.r() / _max) * 255);
                gbyte = (unsigned char)((color.g() / _max) * 255);
                bbyte = (unsigned char)((color.b() / _max) * 255);
            }
            else
            {
                float r = (color.r() > 1.0) ? 1.0 : color.r();
                float g = (color.g() > 1.0) ? 1.0 : color.g();
                float b = (color.b() > 1.0) ? 1.0 : color.b();
                rbyte = (unsigned char)(r * 255);
                gbyte = (unsigned char)(g * 255);
                bbyte = (unsigned char)(b * 255);
            }
            
            putc(color.b(), fp);
            putc(color.g(), fp);
            putc(color.r(), fp);
        }
    }

    fclose(fp);
}