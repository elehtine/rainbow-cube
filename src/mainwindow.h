#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cubewindow.h"

#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  CubeWindow *cubeWindow;
};
#endif // MAINWINDOW_H
