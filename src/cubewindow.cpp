#include "cubewindow.h"

#include <QPainter>

CubeWindow::CubeWindow(QWidget *parent) : QWidget(parent) {
  faceColors = {"yellow", "red", "green", "orange", "blue", "white"};
  resize(minimumSize());
}

CubeWindow::~CubeWindow() {}

QSize CubeWindow::minimumSizeHint() const { return QSize(4 * size, 3 * size); }

QSize CubeWindow::sizeHint() const { return QSize(4 * size, 3 * size); }

void CubeWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QVector<QRect> faceRects = {
      {size, 0, size, size},        {0, size, size, size},
      {size, size, size, size},     {2 * size, size, size, size},
      {3 * size, size, size, size}, {size, 2 * size, size, size},
  };

  for (int i = 0; i < faceNum; ++i) {
    painter.fillRect(faceRects[i], faceColors[i]);
  }
}
