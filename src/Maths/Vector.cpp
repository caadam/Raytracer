#include <math.h>
#include "Vector.h"

// Vector Vector::normalize() {
//    return (*this) /= this->length();
// }

// Vector Vector::cross(Vector const & v) const {
//    return Vector(y*v.z - v.y*z, v.x*z - x*v.z, x*v.y - v.x*y);
// }

// double Vector::dot(Vector const & v) const {
//    return x*v.x + y*v.y + z*v.z;
// }

// double Vector::length() const {
//    return sqrtf(x*x + y*y + z*z);
// }

// Vector Vector::operator + (Vector const & v) const {
//    return Vector(x+v.x, y+v.y, z+v.z);
// }

// Vector & Vector::operator += (Vector const & v) {
//    x += v.x;
//    y += v.y;
//    z += v.z;

//    return * this;
// }

// Vector Vector::operator - (Vector const & v) const {
//    return Vector(x-v.x, y-v.y, z-v.z);
// }

// Vector & Vector::operator -= (Vector const & v) {
//    x -= v.x;
//    y -= v.y;
//    z -= v.z;

//    return * this;
// }

// Vector Vector::operator * (Vector const & v) const {
//    return Vector(x*v.x, y*v.y, z*v.z);
// }

// Vector & Vector::operator *= (Vector const & v) {
//    x *= v.x;
//    y *= v.y;
//    z *= v.z;

//    return * this;
// }

// Vector Vector::operator / (Vector const & v) const {
//    return Vector(x/v.x, y/v.y, z/v.z);
// }

// Vector & Vector::operator /= (Vector const & v) {
//    x /= v.x;
//    y /= v.y;
//    z /= v.z;

//    return * this;
// }

// Vector Vector::operator * (double const s) const {
//    return Vector(x*s, y*s, z*s);
// }

// Vector & Vector::operator *= (double const s) {
//    x *= s;
//    y *= s;
//    z *= s;

//    return * this;
// }

// Vector Vector::operator / (double const s) const {
//    return Vector(x/s, y/s, z/s);
// }

// Vector & Vector::operator /= (double const s) {
//    x /= s;
//    y /= s;
//    z /= s;

//    return * this;
// }

Vector Vector::operator+=(const Vector &other)
{
  x_ += other.x_;
  y_ += other.y_;
  z_ += other.z_;
  return *this;
}

Vector Vector::operator-=(const Vector &other)
{
  x_ -= other.x_;
  y_ -= other.y_;
  z_ -= other.z_;
  return *this;
}

Vector Vector::operator+(const Vector &other) const
{
  return Vector(*this) += other;
}

Vector Vector::operator-(const Vector &other) const
{
  return Vector(*this) -= other;
}

Vector Vector::operator-() const
{
  return Vector(-x_, -y_, -z_);
}

Vector Vector::operator*(float k) const
{
  return Vector(x_ * k, y_ * k, z_ * k);
}

Vector Vector::operator/(float k) const
{
  return Vector(x_ / k, y_ / k, z_ / k);
}

float Vector::length() const
{
  return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

Vector Vector::unit() const
{
  float len = length();
  return Vector(x_ / len, y_ / len, z_ / len);
}

float Vector::dot(const Vector &other) const
{
  return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
}

Vector Vector::cross(const Vector &other) const
{
  return Vector(y_ * other.z_ - z_ * other.y_,
                z_ * other.x_ - x_ * other.z_,
                x_ * other.y_ - y_ * other.x_);
}