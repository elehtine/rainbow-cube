#ifndef FACE_H
#define FACE_H

#include <QColor>
#include <QPainter>
#include <QPoint>

class Face {
public:
  Face(QColor color);
  void paint(QPoint offset, QPainter &painter) const;

private:
  const QColor center;
  static const int SIDE;
  static const int COLOR_NUMBER;
  static const QList<QPoint> COLOR_CORS;

  QList<QColor> colors;
};

#endif // FACE_H