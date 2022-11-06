#include "mainwindow.h"
#include "cubewindow.h"

#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), cubeWindow(new CubeWindow) {
  setCentralWidget(cubeWindow);

  QMenuBar *menubar = new QMenuBar;
  QAction *rotateUp = menubar->addAction("rotate");
  connect(rotateUp, &QAction::triggered, cubeWindow, &CubeWindow::rotateFront);
  setMenuBar(menubar);
}

MainWindow::~MainWindow() {}
