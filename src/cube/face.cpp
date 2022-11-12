#include "face.h"

#include <QDebug>

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
  neighbourFaces = QList<Face *>(4);
  neighbourStartIndices = QList<int>(4);
}

Face::Face(QString colorString) {
  colors = QList<QColor>(COLOR_NUMBER);
  for (int i = 0; i < COLOR_NUMBER; i++) {
    colors[i] = charToColor(colorString[i]);
  }
}

void Face::paint(QPoint offset, QPainter &painter) const {
  for (int i = 0; i < COLOR_NUMBER; i++) {
    QPoint faceOffset = COLOR_CORS[i] * SIDE;
    QRect rect(offset * SIDE * 3 + faceOffset, QSize(SIDE, SIDE));
    painter.fillRect(rect, colors[i]);
  }
}

void Face::rotate() {
  QList<QColor> next = colors.sliced(6) << colors.first(6);
  colors = next;

  int tempIndex = neighbourStartIndices[0];
  QList<QColor> temp(3);
  for (int i = 0; i < 3; i++) {
    int index = (tempIndex + i) % COLOR_NUMBER;
    temp[i] = neighbourFaces[0]->colors[index];
  }

  for (int i = 0; i < 4; i++) {
    Face *first = neighbourFaces[i];
    Face *second = neighbourFaces[(i + 1) % 4];
    for (int j = 0; j < 3; j++) {
      int firstIndex = (neighbourStartIndices[i] + j) % COLOR_NUMBER;
      int secondIndex = (neighbourStartIndices[(i + 1) % 4] + j) % COLOR_NUMBER;
      first->colors[firstIndex] = second->colors[secondIndex];
    }
  }

  Face *last = neighbourFaces[3];
  for (int i = 0; i < 3; i++) {
    int index = (neighbourStartIndices[3] + i) % COLOR_NUMBER;
    last->colors[index] = temp[(tempIndex + i) % 3];
  }
}

void Face::connect(int index, Face *neighbourFace, int neighbourStartIndex) {
  neighbourFaces[index] = neighbourFace;
  neighbourStartIndices[index] = neighbourStartIndex;
}

char *Face::toString() const {
  static char result[9];
  for (int i = 0; i < COLOR_NUMBER; i++) {
    result[i] = colorToChar(colors[i]);
  }
  result[8] = 0;
  return result;
}

char Face::colorToChar(QColor color) {
  if (color == "yellow")
    return 'y';
  if (color == "green")
    return 'g';
  if (color == "red")
    return 'r';
  if (color == "blue")
    return 'b';
  if (color == "orange")
    return 'o';
  if (color == "white")
    return 'w';
  return 'b';
}

QColor Face::charToColor(QChar c) {
  if (c == 'y')
    return QColor("yellow");
  if (c == 'g')
    return QColor("green");
  if (c == 'r')
    return QColor("red");
  if (c == 'b')
    return QColor("blue");
  if (c == 'o')
    return QColor("orange");
  if (c == 'w')
    return QColor("white");
  return QColor("black");
}

bool operator==(const Face &lhs, const Face &rhs) {
  for (int i = 0; i < Face::COLOR_NUMBER; i++) {
    if (lhs.colors[i] != rhs.colors[i]) {
      return false;
    }
  }
  return true;
}
