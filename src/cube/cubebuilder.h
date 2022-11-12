#ifndef CUBEBUILDER_H
#define CUBEBUILDER_H

#include "cube.h"

class CubeBuilder {
public:
  CubeBuilder();

  void lfrFlip();
  void everyFaceFlip();
  void superFlip();
  Cube getCube();

private:
  Cube cube;
};

#endif // CUBEBUILDER_H
