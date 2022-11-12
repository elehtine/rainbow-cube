#include "cubewindow.h"
#include "cube.h"
#include "cubebuilder.h"

#include <QPainter>
#include <QPoint>

const int CubeWindow::FACE_NUM = 6;
const int CubeWindow::SIDE = 50;
const int CubeWindow::EDGE = SIDE * 3;
const QSize CubeWindow::FACE_SIZE = QSize(EDGE, EDGE);
const QSize CubeWindow::RECT_SIZE = QSize(SIDE, SIDE);

CubeWindow::CubeWindow(QWidget *parent) : QWidget(parent) {
  CubeBuilder builder;
  cube = builder.getCube();
}

CubeWindow::~CubeWindow() {}

QSize CubeWindow::minimumSizeHint() const {
  return QSize(3 * 4 * SIDE, 3 * 3 * SIDE);
}

QSize CubeWindow::sizeHint() const { return QSize(4 * EDGE, 3 * EDGE); }

void CubeWindow::rotate(Face face) {
  switch (face) {
  case Face::Up:
    cube.up->rotate();
    break;
  case Face::Left:
    cube.left->rotate();
    break;
  case Face::Front:
    cube.front->rotate();
    break;
  case Face::Right:
    cube.right->rotate();
    break;
  case Face::Back:
    cube.back->rotate();
    break;
  case Face::Down:
    cube.down->rotate();
    break;
  }
  update();
}

void CubeWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);

  for (int i = 0; i < FACE_NUM; i++) {
    cube.paint(painter);
  }
}
