#include "NBody.h"

#include "Body.h"
#include "Globs.h"

#include <memory>
#include <random>


NBody::NBody(size_t iNumBodies)
{
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_real_distribution<> dis(1., 500.); // distribution in range [1, 6]

  for (size_t i = 0; i < iNumBodies; ++i) {
    _apBodies.emplace_back(std::make_shared<Body>(Vector3(dis(gen), dis(gen), dis(gen)), Vector3(dis(gen), dis(gen), dis(gen)), 2.));
   }
}

void NBody::Update(std::vector<Vector3>& iPoses, std::vector<Vector3>& iVelsHalf) const
{
  #pragma omp parallel for
  for (int i = 0; i < _apBodies.size(); ++i) {
	  const auto& pBody = _apBodies[i];
	  const auto force = CalculateForce(pBody);
	  const Vector3 vHalf = pBody->_velocity + force * (Globs::timeStep / (2 * pBody->_mass));
	  iPoses[i] = pBody->_position + vHalf * Globs::timeStep;
	  iVelsHalf[i] = vHalf;
  }
  #pragma omp parallel for
  for (int i = 0; i < _apBodies.size(); ++i) {
    const auto& pBody = _apBodies[i];
    const auto force = CalculateForce(iPoses, i);
    const Vector3 vFull = iVelsHalf[i] + force * (Globs::timeStep / (2 * pBody->_mass));
    pBody->_velocity = vFull;
	  pBody->_position = iPoses[i];
  }
}

Vector3 NBody::CalculateForce(const BodyPtr& ipBody) const
{
  Vector3 force;
  for (int i = 0; i < _apBodies.size(); ++i) {
    const auto& pBody2 = _apBodies[i];
    if (ipBody == pBody2)
      continue;
    const auto direction = (ipBody->_position - pBody2->_position).Normalized();
    force += direction * (ipBody->_mass * pBody2->_mass / ipBody->_position.GetDistance2(pBody2->_position));
  }
  return force;
}

Vector3 NBody::CalculateForce(const std::vector<Vector3>& iapPoses, int i) const
{
  Vector3 force;
  for (int j = 0; j < iapPoses.size(); ++j) {
    if (i == j)
      continue;
    const auto direction = (iapPoses[i] - iapPoses[j]).Normalized();
    force += direction * (_apBodies[i]->_mass * _apBodies[j]->_mass / iapPoses[i].GetDistance2(iapPoses[j]));
  }
  return force;
}
