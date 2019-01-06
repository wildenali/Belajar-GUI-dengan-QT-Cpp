#include <QCoreApplication>
#include <QDebug>

class Point {
private:
  double x;
  double y;

public:
  Point(double x, double y);
  void setX(double x);
  double getX();
  void setY(double y);
  double getY();
};

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

void Point::setX(double x) {
  this->x = x;
}

double Point::getX() {
  return this->x;
}

void Point::setY(double y) {
  this->y = y;
}

double Point::getY() {
  return this->y;
}

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QList<Point *> points;

  points.append(new Point(0, 0));
  points.append(new Point(1, 1));
  points.append(new Point(2, 2));
  points.append(new Point(3, 3));

  for (int i = 0; i < points.size(); i++) {
    qDebug() << "("
             << points.at(i)->getX()
             << ","
             << points.at(i)->getY()
             << ")";
  }

  return apps.exec();
}
