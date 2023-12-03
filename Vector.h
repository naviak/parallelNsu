#pragma once

struct Vector3
{
	Vector3() = default;
	Vector3(double iX, double iY, double iZ);

	Vector3 operator+(const Vector3& iOther) const;
	Vector3 operator-(const Vector3& iOther) const;
	Vector3 operator*(double iC) const;

	double GetLength() const;
	double GetLength2() const;
	Vector3 Normalized() const;
	Vector3 Normalize();
  Vector3& operator+=(const Vector3& iOther);
  double GetDistance2(const Vector3& iVector) const;

  double _x = 0.;
  double _y = 0.;
  double _z = 0.;
};
