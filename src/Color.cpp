#include "Color.h"

// Color Color::operator+ (Color const &c) const {
//    Color other;

//    other.r = NTZ(c.r) + NTZ(r);
//    other.g = NTZ(c.g) + NTZ(g);
//    other.b = NTZ(c.b) + NTZ(b);

//    return other;
// }

// Color Color::operator* (double amount) const {
//    Color other;

//    other.r = r * amount;
//    other.g = g * amount;
//    other.b = b * amount;

//    return other;
// }


///////////////////

float Color::gammaEncode(float c) {
  // As specified at: http://www.w3.org/Graphics/Color/srgb
  if (c <= 0.0031308f)
    return 12.92f * c; 
  else
    return 1.055f * powf(c, 0.4166667f) - 0.055f;
}


void Color::clamp() {
  if (r_ > 1)
    r_ = 1;
  if (g_ > 1)
    g_ = 1;
  if (b_ > 1)
    b_ = 1;
}

void Color::gammaCorrect() {
  r_ = gammaEncode(r_);
  g_ = gammaEncode(g_);
  b_ = gammaEncode(b_);
}

Color Color::operator+=(const Color& other) {
  r_ += other.r_;
  g_ += other.g_;
  b_ += other.b_;
  return *this;
}

Color Color::operator+(const Color& other) const {
  return Color(*this) += other;
}

Color Color::operator*(float k) const {
  return Color(r_ * k, g_ * k, b_ * k);
}

Color Color::operator*(const Color& other) const {
  return Color(r_ * other.r_, g_ * other.g_, b_ * other.b_);
}

Color Color::operator / (float k) const {
  return Color(r_ / k, g_ / k, b_ / k);
}