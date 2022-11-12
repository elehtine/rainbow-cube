#ifndef CUBE_H
#define CUBE_H

#include "face.h"

#include <QPainter>

class Cube {
public:
  Cube(bool test = false);
  Cube(QList<QString> faces);

  char *toString() const;

  void paint(QPainter &painter) const;
  friend bool operator==(const Cube &lhs, const Cube &rhs);
  inline friend bool operator!=(const Cube &lhs, const Cube &rhs) {
    return !(lhs == rhs);
  }

  Face *up;
  Face *front;
  Face *right;
  Face *back;
  Face *left;
  Face *down;
};

#endif // CUBE_H
