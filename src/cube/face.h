#ifndef FACE_H
#define FACE_H

#include <QColor>
#include <QPainter>
#include <QPoint>

class Face {
public:
  Face(QColor color);
  Face(QString colorString);
  void paint(QPoint offset, QPainter &painter) const;

  void rotate();
  void connect(int index, Face *neighbourFace, int neighbourStartIndex);

  char *toString() const;

  friend bool operator==(const Face &lhs, const Face &rhs);
  inline friend bool operator!=(const Face &lhs, const Face &rhs) {
    return !(lhs == rhs);
  }

private:
  const QColor center;
  static const int SIDE;
  static const int COLOR_NUMBER;
  static const QList<QPoint> COLOR_CORS;

  static QColor charToColor(QChar c);
  static char colorToChar(QColor color);

  QList<QColor> colors;
  QList<Face *> neighbourFaces;
  QList<int> neighbourStartIndices;
};

#endif // FACE_H
