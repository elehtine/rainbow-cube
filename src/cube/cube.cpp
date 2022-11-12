#include "cube.h"
#include "face.h"

#include <QPainter>

Cube::Cube(bool test) {
  if (test) {
    up = new Face();
    front = new Face();
    right = new Face();
    back = new Face();
    left = new Face();
    down = new Face();
  } else {
    up = new Face("yellow");
    front = new Face("red");
    right = new Face("green");
    back = new Face("orange");
    left = new Face("blue");
    down = new Face("white");
  }
}

void Cube::paint(QPainter &painter) const {
  up->paint({1, 0}, painter);
  left->paint({0, 1}, painter);
  front->paint({1, 1}, painter);
  right->paint({2, 1}, painter);
  back->paint({3, 1}, painter);
  down->paint({1, 2}, painter);
}
