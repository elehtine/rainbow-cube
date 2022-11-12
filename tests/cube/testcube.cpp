#include <QTest>

#include "cube.h"
#include "cubebuilder.h"

namespace QTest {
char *toString(const Cube &cube) { return QTest::toString(cube.toString()); }
} // namespace QTest

class TestCube : public QObject {
  Q_OBJECT

private:
  CubeBuilder cubeBuilder;

private slots:
  void init() { cubeBuilder = CubeBuilder(); }

  void simpleEqualFace() {
    Face first(QColor("red"));
    Face second(QColor("red"));
    QCOMPARE_EQ(first, second);
  }
  void simpleUnequalFace() {
    Face first(QColor("red"));
    Face second(QColor("blue"));
    QCOMPARE_NE(first, second);
  }
  void equalInitialCube() {
    Cube first = cubeBuilder.getCube();
    Cube second = cubeBuilder.getCube();
    QCOMPARE_EQ(first, second);
  }
  void rotateFrontTest() {
    Cube first = cubeBuilder.getCube();
    first.front->rotate();
    QList<QString> faces = {
        "yyyybbby", "bbwwwbbb", "rrrrrrrr", "ygggggyy", "oooooooo", "gggwwwww",
    };
    Cube second = Cube(faces);
    QCOMPARE_EQ(first, second);
  }
  void lfrFlipTest() {
    cubeBuilder.lfrFlip();
    Cube first = cubeBuilder.getCube();
    QList<QString> faces = {
        "oyyrrbbo", "bbrwwbbb", "yygwwrrr", "yyoggggg", "bowwwoyy", "ggooowrr",
    };
    Cube second = Cube(faces);
    QCOMPARE_EQ(first, second);
  }
  void everyFaceFlipTest() {
    cubeBuilder.everyFaceFlip();
    Cube first = cubeBuilder.getCube();
    QList<QString> faces = {
        "booggrro", "ybgwwwwy", "yyowwbor", "yybwwrrg", "yyrbrggo", "brggoobb",
    };
    Cube second = Cube(faces);
    QCOMPARE_EQ(first, second);
  }
  void superFlipTest() {
    cubeBuilder.superFlip();
    Cube first = cubeBuilder.getCube();
    QList<QString> faces = {
        "yoygyryb", "bybrbwbo", "ryrgrwrb", "gygogwgr", "oyobowog", "wrwgwowb",
    };
    Cube second = Cube(faces);
    QCOMPARE_EQ(first, second);
  }
};

QTEST_MAIN(TestCube)
#include "testcube.moc"
