#include "mainwindow.h"
#include "cubewindow.h"

#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), cubeWindow(new CubeWindow) {
  setCentralWidget(cubeWindow);

  QMenuBar *menubar = new QMenuBar;
  QAction *up = menubar->addAction("up");
  QAction *left = menubar->addAction("left");
  QAction *front = menubar->addAction("front");
  QAction *right = menubar->addAction("right");
  QAction *back = menubar->addAction("back");
  QAction *down = menubar->addAction("down");

  connect(up, &QAction::triggered, this,
          [this]() { cubeWindow->rotate(CubeWindow::Face::Up); });
  connect(left, &QAction::triggered, this,
          [this]() { cubeWindow->rotate(CubeWindow::Face::Left); });
  connect(front, &QAction::triggered, this,
          [this]() { cubeWindow->rotate(CubeWindow::Face::Front); });
  connect(right, &QAction::triggered, this,
          [this]() { cubeWindow->rotate(CubeWindow::Face::Right); });
  connect(back, &QAction::triggered, this,
          [this]() { cubeWindow->rotate(CubeWindow::Face::Back); });
  connect(down, &QAction::triggered, this,
          [this]() { cubeWindow->rotate(CubeWindow::Face::Down); });
  setMenuBar(menubar);
}

MainWindow::~MainWindow() {}
