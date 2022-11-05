#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include <QWidget>

#include <QWidget>

#include "cube.h"

class CubeWindow : public QWidget {
  Q_OBJECT
public:
  explicit CubeWindow(QWidget *parent = nullptr);
  ~CubeWindow();
  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  static const QSize RECT_SIZE;
  static const int SIDE;
  static const int FACE_NUM;

  Cube *cube;
};

#endif // CUBEWINDOW_H
