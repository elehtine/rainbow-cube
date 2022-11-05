#include "cube.h"
#include "face.h"

#include <QPainter>

Cube::Cube() {
  top = new Face("yellow");
  front = new Face("red");
  right = new Face("green");
  back = new Face("orange");
  left = new Face("blue");
  down = new Face("white");
}

void Cube::paint(QPainter &painter) const {
  top->paint({1, 0}, painter);
  front->paint({0, 1}, painter);
  right->paint({1, 1}, painter);
  back->paint({2, 1}, painter);
  left->paint({3, 1}, painter);
  down->paint({1, 2}, painter);
}
