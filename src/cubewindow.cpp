#include "cubewindow.h"
#include "cube.h"

#include <QPainter>
#include <QPoint>

const int CubeWindow::FACE_NUM = 6;
const int CubeWindow::SIDE = 100;
const QSize CubeWindow::RECT_SIZE = QSize(SIDE, SIDE);

CubeWindow::CubeWindow(QWidget *parent) : QWidget(parent), cube(new Cube) {}

CubeWindow::~CubeWindow() {}

QSize CubeWindow::minimumSizeHint() const { return QSize(4 * SIDE, 3 * SIDE); }

QSize CubeWindow::sizeHint() const { return QSize(4 * SIDE, 3 * SIDE); }

void CubeWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QVector<QPoint> facePoints = {
      {SIDE, 0},        {0, SIDE},        {SIDE, SIDE},
      {2 * SIDE, SIDE}, {3 * SIDE, SIDE}, {SIDE, 2 * SIDE},
  };
  QVector<QColor> faceColors = {
      cube->getTop(),  cube->getFront(), cube->getRight(),
      cube->getBack(), cube->getLeft(),  cube->getDown(),
  };

  for (int i = 0; i < FACE_NUM; i++) {
    painter.fillRect(QRect(facePoints[i], RECT_SIZE), faceColors[i]);
  }
}
