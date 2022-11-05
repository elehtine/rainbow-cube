#include "mainwindow.h"
#include "cubewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), cubeWindow(new CubeWindow) {
  setCentralWidget(cubeWindow);
}

MainWindow::~MainWindow() {}
