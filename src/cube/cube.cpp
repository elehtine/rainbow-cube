#include "cube.h"
#include "face.h"

#include <QPainter>

Cube::Cube() {
  up = new Face(QColor("yellow"));
  front = new Face(QColor("red"));
  right = new Face(QColor("green"));
  back = new Face(QColor("orange"));
  left = new Face(QColor("blue"));
  down = new Face(QColor("white"));
}

Cube::Cube(QList<QString> faces) {
  up = new Face(faces[0]);
  left = new Face(faces[1]);
  front = new Face(faces[2]);
  right = new Face(faces[3]);
  back = new Face(faces[4]);
  down = new Face(faces[5]);
}

char *Cube::toString() const {
  QString result =
      QString("%1 %2 %3 %4 %5 %6")
          .arg(up->toString(), left->toString(), front->toString(),
               right->toString(), back->toString(), down->toString());
  return (char *)result.toUtf8().data();
}

void Cube::paint(QPainter &painter) const {
  up->paint({1, 0}, painter);
  left->paint({0, 1}, painter);
  front->paint({1, 1}, painter);
  right->paint({2, 1}, painter);
  back->paint({3, 1}, painter);
  down->paint({1, 2}, painter);
}

bool operator==(const Cube &lhs, const Cube &rhs) {
  if (*lhs.up != *rhs.up) {
    return false;
  }
  if (*lhs.left != *rhs.left) {
    return false;
  }
  if (*lhs.front != *rhs.front) {
    return false;
  }
  if (*lhs.right != *rhs.right) {
    return false;
  }
  if (*lhs.back != *rhs.back) {
    return false;
  }
  if (*lhs.down != *rhs.down) {
    return false;
  }
  return true;
}
