#ifndef CUBEBUILDER_H
#define CUBEBUILDER_H

#include "cube.h"

class CubeBuilder {
public:
  CubeBuilder();

  Cube getCube();

private:
  Cube cube;
};

#endif // CUBEBUILDER_H
