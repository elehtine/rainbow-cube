#ifndef FACE_H
#define FACE_H

#include <QColor>
#include <QPainter>
#include <QPoint>

class Face {
public:
  Face(QColor color);
  Face();
  void paint(QPoint offset, QPainter &painter) const;
  void rotate();

  friend bool operator==(const Face &lhs, const Face &rhs);
  inline friend bool operator!=(const Face &lhs, const Face &rhs) {
    return !(lhs == rhs);
  }

private:
  const QColor center;
  static const int SIDE;
  static const int COLOR_NUMBER;
  static const QList<QPoint> COLOR_CORS;

  QList<QColor> colors;
};

#endif // FACE_H
