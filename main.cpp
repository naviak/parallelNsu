#include "NBody.h"

#include <omp.h>
#include <iostream>
#include <chrono>
#include <vector>

int main()
{
  omp_set_num_threads(1);
  NBody nbody(1000);
  std::vector<Vector3> poses(1000);
  std::vector<Vector3> velHalfs(1000);
  for (size_t i = 0; i < 10; ++i) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    nbody.Update(poses, velHalfs);
    const auto difft = std::chrono::high_resolution_clock::now() - t1;
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(difft);
    std::cout << ms_int.count() << std::endl;
  }
  nbody.Update(poses, velHalfs);
  return 1;
}
