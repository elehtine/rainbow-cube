#include <QTest>

#include "cube.h"
#include "cubebuilder.h"

class TestCube : public QObject {
  Q_OBJECT

private:
  CubeBuilder cubeBuilder;

private slots:
  void initTestCase() { cubeBuilder = CubeBuilder(); }

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
  void EqualInitialCube() {
    Cube first = cubeBuilder.getCube();
    Cube second = cubeBuilder.getCube();
    QCOMPARE_EQ(first, second);
  }
};

QTEST_MAIN(TestCube)
#include "testcube.moc"
