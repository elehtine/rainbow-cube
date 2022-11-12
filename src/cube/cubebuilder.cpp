#include "cubebuilder.h"

CubeBuilder::CubeBuilder() {
  cube = Cube();
  cube.front->connect(0, cube.up, 4);
  cube.front->connect(1, cube.left, 2);
  cube.front->connect(2, cube.down, 0);
  cube.front->connect(3, cube.right, 6);
}

Cube CubeBuilder::getCube() { return cube; }
