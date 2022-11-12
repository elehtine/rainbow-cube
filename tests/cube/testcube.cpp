#include <QTest>

#include "cube.h"
#include "cubebuilder.h"

class TestCube : public QObject {
  Q_OBJECT
public:
private:
  CubeBuilder cubeBuilder;

private slots:
  void initTestCase() { cubeBuilder = CubeBuilder(); }

  void emptyTest() { QVERIFY(true); }
};

QTEST_MAIN(TestCube)
#include "testcube.moc"
