#ifndef COLOR_H
#define COLOR_H

/**
 * "NaN To Zero"
 * Converts a NaN value to zero. Otherwise adding values to NaN results in NaN.
 * When adding colors together we usually want to ignore it and use 0 instead.
 */
#include <math.h>

class Color
{
  public:
    Color(float r, float g, float b)
        : r_(r), g_(g), b_(b) {}
    Color() : r_(0), g_(0), b_(0) {}

    float r() { return r_; }
    float g() { return g_; }
    float b() { return b_; }
    float a() { return a_; }

    void clamp();
    void gammaCorrect();

    Color operator+=(const Color &other);
    Color operator+(const Color &other) const;
    Color operator*(float k) const;
    Color operator*(const Color &other) const;
    Color operator/(float k) const;

  private:
    float gammaEncode(float c);

    float r_, g_, b_, a_;
};

#endif