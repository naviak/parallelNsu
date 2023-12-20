#pragma once
#include <vector>

#include "Body.h"

class NBody
{
public:
  NBody(size_t iNumBodies);
  void Update(std::vector<Vector3>& iPoses, std::vector<Vector3>& iVelsHalf) const;
  Vector3 CalculateForce(const BodyPtr& ipBody) const;
  Vector3 CalculateForce(const std::vector<Vector3>& iapPoses, int i) const;
  
private:
  std::vector<BodyPtr> _apBodies;
};

