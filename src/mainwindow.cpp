#include "mainwindow.h"
#include "cubewindow.h"

#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), cubeWindow(new CubeWindow) {
  setCentralWidget(cubeWindow);

  QMenuBar *menubar = new QMenuBar;
  QMenu *rotate = menubar->addMenu("rotate");
  QAction *up = rotate->addAction("up");
  QAction *left = rotate->addAction("left");
  QAction *front = rotate->addAction("front");
  QAction *right = rotate->addAction("right");
  QAction *back = rotate->addAction("back");
  QAction *down = rotate->addAction("down");
  connect(up, &QAction::triggered, cubeWindow, &CubeWindow::rotateUp);
  connect(left, &QAction::triggered, cubeWindow, &CubeWindow::rotateLeft);
  connect(front, &QAction::triggered, cubeWindow, &CubeWindow::rotateFront);
  connect(right, &QAction::triggered, cubeWindow, &CubeWindow::rotateRight);
  connect(back, &QAction::triggered, cubeWindow, &CubeWindow::rotateBack);
  connect(down, &QAction::triggered, cubeWindow, &CubeWindow::rotateDown);
  setMenuBar(menubar);
}

MainWindow::~MainWindow() {}
