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

  enum class Face { Up, Left, Front, Right, Back, Down };

public slots:
  void rotate(Face face);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  static const QSize RECT_SIZE;
  static const QSize FACE_SIZE;
  static const int SIDE;
  static const int EDGE;
  static const int FACE_NUM;

  Cube cube;
};

#endif // CUBEWINDOW_H
