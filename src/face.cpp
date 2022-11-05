#include "face.h"

const int Face::COLOR_NUMBER = 8;
const int Face::SIDE = 50;
const QList<QPoint> Face::COLOR_CORS = {
    {0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}, {1, 2}, {0, 2}, {0, 1},
};

Face::Face(QColor color) : center(color) {
  colors = QList<QColor>(COLOR_NUMBER);
  for (int i = 0; i < COLOR_NUMBER; i++) {
    colors[i] = color;
  }
}

void Face::paint(QPoint offset, QPainter &painter) const {
  for (int i = 0; i < COLOR_NUMBER; i++) {
    QPoint faceOffset = COLOR_CORS[i] * SIDE;
    QRect rect(offset * SIDE * 3 + faceOffset, QSize(SIDE, SIDE));
    painter.fillRect(rect, colors[i]);
  }
}
