#ifndef CUBE_H
#define CUBE_H

#include "face.h"

#include <QPainter>

class Cube {
public:
  Cube();

  void paint(QPainter &painter) const;

private:
  Face *top;
  Face *front;
  Face *right;
  Face *back;
  Face *left;
  Face *down;
};

#endif // CUBE_H
