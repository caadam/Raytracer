#ifndef VECTOR_H
#define VECTOR_H

class Vector {
// public:

//    double x, y, z;

//    Vector() : x(0), y(0), z(0) {}
//    Vector(double in) : x(in), y(in), z(in) {}
//    Vector(double in_x, double in_y, double in_z) : x(in_x), y(in_y), z(in_z) {}

//    Vector normalize();
//    Vector cross(Vector const & v) const;
//    double dot(Vector const & v) const;
//    double length() const;

//    Vector operator + (Vector const & v) const;
//    Vector & operator += (Vector const & v);
//    Vector operator - (Vector const & v) const;
//    Vector & operator -= (Vector const & v);
//    Vector operator * (Vector const & v) const;
//    Vector & operator *= (Vector const & v);
//    Vector operator / (Vector const & v) const;
//    Vector & operator /= (Vector const & v);
//    Vector operator * (double const s) const;
//    Vector & operator *= (double const s);
//    Vector operator / (double const s) const;
//    Vector & operator /= (double const s);

 public:  
  Vector(float x, float y, float z) : x_(x), y_(y), z_(z) {}
  Vector() : x_(0), y_(0), z_(0) {}

  float x() const { return x_; }
  float y() const { return y_; }
  float z() const { return z_; }

  Vector operator+=(const Vector& other);
  Vector operator-=(const Vector& other);
  Vector operator+(const Vector& other) const;
  Vector operator-(const Vector& other) const;
  Vector operator-() const;
  Vector operator*(float k) const;
  Vector operator/(float k) const;

  float length() const;
  Vector unit() const;
  float dot(const Vector& other) const;
  Vector cross(const Vector& other) const;

 private:
  float x_, y_, z_;

};

#endif
