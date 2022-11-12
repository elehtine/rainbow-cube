#include "cubebuilder.h"

CubeBuilder::CubeBuilder() {
  cube = Cube();
  cube.up->connect(0, cube.back, 0);
  cube.up->connect(1, cube.left, 0);
  cube.up->connect(2, cube.front, 0);
  cube.up->connect(3, cube.right, 0);
  cube.left->connect(0, cube.up, 6);
  cube.left->connect(1, cube.back, 2);
  cube.left->connect(2, cube.down, 6);
  cube.left->connect(3, cube.front, 6);
  cube.front->connect(0, cube.up, 4);
  cube.front->connect(1, cube.left, 2);
  cube.front->connect(2, cube.down, 0);
  cube.front->connect(3, cube.right, 6);
  cube.right->connect(0, cube.up, 2);
  cube.right->connect(1, cube.front, 2);
  cube.right->connect(2, cube.down, 2);
  cube.right->connect(3, cube.back, 6);
  cube.back->connect(0, cube.up, 0);
  cube.back->connect(1, cube.right, 2);
  cube.back->connect(2, cube.down, 4);
  cube.back->connect(3, cube.left, 6);
  cube.down->connect(0, cube.front, 4);
  cube.down->connect(1, cube.left, 4);
  cube.down->connect(2, cube.back, 4);
  cube.down->connect(3, cube.right, 4);
}

void CubeBuilder::lfrFlip() {
  // L F R
  cube.left->rotate();
  cube.front->rotate();
  cube.right->rotate();
}

void CubeBuilder::everyFaceFlip() {
  // U L F R B D
  cube.up->rotate();
  cube.left->rotate();
  cube.front->rotate();
  cube.right->rotate();
  cube.back->rotate();
  cube.down->rotate();
}

void CubeBuilder::superFlip() {
  // U R2 F B R B2 R U2 L B2 R U' D' R2 F R' L B2 U2 F2
  cube.up->rotate();    // U
  cube.right->rotate(); // R2
  cube.right->rotate();
  cube.front->rotate(); // F
  cube.back->rotate();  // B
  cube.right->rotate(); // R
  cube.back->rotate();  // B2
  cube.back->rotate();
  cube.right->rotate(); // R
  cube.up->rotate();    // U2
  cube.up->rotate();
  cube.left->rotate(); // L
  cube.back->rotate(); // B2
  cube.back->rotate();
  cube.right->rotate(); // R
  cube.up->rotate();    // U'
  cube.up->rotate();
  cube.up->rotate();
  cube.down->rotate(); // D'
  cube.down->rotate();
  cube.down->rotate();
  cube.right->rotate(); // R2
  cube.right->rotate();
  cube.front->rotate(); // F
  cube.right->rotate(); // R'
  cube.right->rotate();
  cube.right->rotate();
  cube.left->rotate(); // L
  cube.back->rotate(); // B2
  cube.back->rotate();
  cube.up->rotate(); // U2
  cube.up->rotate();
  cube.front->rotate(); // F2
  cube.front->rotate();
}

Cube CubeBuilder::getCube() { return cube; }
