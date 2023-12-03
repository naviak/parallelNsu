#include "Vector.h"

#include <cmath>

Vector3::Vector3(double iX, double iY, double iZ)
  : _x(iX), _y(iY), _z(iZ)
{
}

Vector3 Vector3::operator+(const Vector3& iOther) const
{
	return { _x + iOther._x, _y + iOther._y, _z + iOther._z };
}

Vector3 Vector3::operator-(const Vector3& iOther) const
{
	return { _x - iOther._x, _y - iOther._y, _z - iOther._z };
}

Vector3 Vector3::operator*(double iC) const
{
	return { _x * iC, _y* iC, _z* iC} ;
}

double Vector3::GetLength() const
{
	return sqrt(GetLength2());
}

double Vector3::GetLength2() const
{
	return _x * _x + _y * _y + _z * _z;
}

Vector3 Vector3::Normalized() const
{
	const double len = GetLength();
	return { _x / len, _y / len, _z / len };
}

Vector3 Vector3::Normalize()
{
	const double len = GetLength();
	_x /= len;
	_y /= len;
	_z /= len;

	return *this;
}

Vector3& Vector3::operator+=(const Vector3& iOther)
{
	_x += iOther._x;
	_y += iOther._y;
	_z += iOther._z;
	return *this;
}

double Vector3::GetDistance2(const Vector3& iVector) const
{
	const auto diffX = iVector._x - _x;
	const auto diffY = iVector._y - _y;
	const auto diffZ = iVector._z - _z;
	return diffX * diffX + diffY * diffY + diffZ * diffZ;
}
