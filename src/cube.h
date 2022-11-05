#ifndef CUBE_H
#define CUBE_H

#include <QColor>

class Cube {
public:
  Cube();

  QColor getTop() const;
  QColor getFront() const;
  QColor getRight() const;
  QColor getBack() const;
  QColor getLeft() const;
  QColor getDown() const;

private:
  QColor top;
  QColor front;
  QColor right;
  QColor back;
  QColor left;
  QColor down;
};

#endif // CUBE_H
