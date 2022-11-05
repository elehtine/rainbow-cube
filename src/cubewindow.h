#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include <QWidget>

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
  const int size = 300;
  const int faceNum = 6;

  QVector<QColor> faceColors;
};

#endif // CUBEWINDOW_H
