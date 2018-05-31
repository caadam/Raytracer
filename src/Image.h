#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <string>

#include "Color.h"

class Image {
public:
    Image(int width, int height);
    ~Image();

    uint32_t& at(int x, int y);
    void set(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    Color get(int x, int y);

    // if scale_color is true, the output targa will have its color space scaled
    // to the global max, otherwise it will be clamped at 1.0
    void WriteTga(const char *outfile, bool scale_color = true);

    //void GenTestPattern();

    // property accessors
    // Color pixel(int x, int y);
    // void pixel(int x, int y, Color pxl);
    // int width() const { return _width; }
    int height() const { return height_; }
    double max() const { return _max; }

private:
    uint32_t* buffer_;
    int width_;
    int height_;
    // Color *_pixmap;
    double _max;
};

#endif
