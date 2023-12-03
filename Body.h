#pragma once

#include "Vector.h"

#include <array>
#include <vector>
#include <memory>

struct Body;
typedef std::shared_ptr<Body> BodyPtr;

struct Body
{
  Body(const Vector3& iVelocity, const Vector3& iPosition, double iMass);
  Vector3 _velocity;
  Vector3 _position;
  double _mass;
};