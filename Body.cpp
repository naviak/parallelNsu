#include "Body.h"

Body::Body(const Vector3& iVelocity, const Vector3& iPosition, double iMass)
  : _velocity(iVelocity), _position(iPosition), _mass(iMass)
{
}
