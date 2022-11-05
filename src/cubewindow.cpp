#include "cubewindow.h"
#include "cube.h"

#include <QPainter>
#include <QPoint>

const int CubeWindow::FACE_NUM = 6;
const int CubeWindow::SIDE = 50;
const int CubeWindow::EDGE = SIDE * 3;
const QSize CubeWindow::FACE_SIZE = QSize(EDGE, EDGE);
const QSize CubeWindow::RECT_SIZE = QSize(SIDE, SIDE);

CubeWindow::CubeWindow(QWidget *parent) : QWidget(parent), cube(new Cube) {}

CubeWindow::~CubeWindow() {}

QSize CubeWindow::minimumSizeHint() const {
  return QSize(3 * 4 * SIDE, 3 * 3 * SIDE);
}

QSize CubeWindow::sizeHint() const { return QSize(4 * EDGE, 3 * EDGE); }

void CubeWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QVector<QPoint> facePoints = {
      {EDGE, 0},        {0, EDGE},        {EDGE, EDGE},
      {2 * EDGE, EDGE}, {3 * EDGE, EDGE}, {EDGE, 2 * EDGE},
  };
  QVector<QColor> faceColors = {
      cube->getTop(),  cube->getFront(), cube->getRight(),
      cube->getBack(), cube->getLeft(),  cube->getDown(),
  };

  for (int i = 0; i < FACE_NUM; i++) {
    painter.fillRect(QRect(facePoints[i], RECT_SIZE).translated(SIDE, SIDE),
                     faceColors[i]);
  }
}
