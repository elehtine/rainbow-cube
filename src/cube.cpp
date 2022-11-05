#include "cube.h"

Cube::Cube() {
  top = "yellow";
  front = "red";
  right = "green";
  back = "orange";
  left = "blue";
  down = "white";
}

QColor Cube::getTop() const { return top; }
QColor Cube::getFront() const { return front; }
QColor Cube::getRight() const { return right; }
QColor Cube::getBack() const { return back; }
QColor Cube::getLeft() const { return left; }
QColor Cube::getDown() const { return down; }
