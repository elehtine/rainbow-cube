#include "cubebuilder.h"

CubeBuilder::CubeBuilder() {
  cube = Cube();
  cube.front->connect(0, cube.up, 4);
  cube.front->connect(1, cube.left, 2);
  cube.front->connect(2, cube.down, 0);
  cube.front->connect(3, cube.right, 6);
}

void CubeBuilder::superFlip() {
  cube.up->rotate();
  cube.right->rotate();
  cube.right->rotate();
  cube.front->rotate();
  cube.back->rotate();
  cube.right->rotate();
  cube.back->rotate();
  cube.back->rotate();
  cube.right->rotate();
  cube.up->rotate();
  cube.up->rotate();
  cube.left->rotate();
  cube.back->rotate();
  cube.back->rotate();
  cube.left->rotate();
  cube.back->rotate();
  cube.back->rotate();
  cube.right->rotate();
  cube.up->rotate();
  cube.up->rotate();
  cube.up->rotate();
  cube.down->rotate();
  cube.down->rotate();
  cube.down->rotate();
  cube.right->rotate();
  cube.right->rotate();
  cube.left->rotate();
  cube.back->rotate();
  cube.back->rotate();
  cube.up->rotate();
  cube.up->rotate();
  cube.front->rotate();
  cube.front->rotate();
}

Cube CubeBuilder::getCube() { return cube; }
