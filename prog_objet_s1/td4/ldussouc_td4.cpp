// Is this TD finished yet ?
// NO !

#include <iostream>
#include <string>

using namespace std;
class GeoObject{
protected:
  static unsigned int geoNum;
};

unsigned int GeoObject::geoNum = 0;

class Point : GeoObject {
private:
  double x;
  double y;
  string name;
public:
  static unsigned int num;

  Point(double x, double y){
    this->x = x, this->y = y;
    num++;
    GeoObject::geoNum++;
    cout << "geonumber :" << GeoObject::geoNum << endl;
  }

  ~Point(){
    Point::num--;
  }
  static void distance (const Point & p1, const Point & p2){
    double distance;
    distance = p1.x - p2.x / p1.y - p2.y;
    cout << distance << endl;
  }
  double getX() const{
    return x;
  }
  double getY() const{
    return y;
  }
  void changeName(string name) {
    this->name = name;
  }
};

class Rectangle : GeoObject{
public:
  Point a, b, c, d;
  Rectangle(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d){}
  void print(){ cout << "a : " << a.getX() << a.getY() << endl; }
};

class Circle : GeoObject{
public:
  Point a;
  double radius;
  Circle(Point a, double radius) : a(a), radius(radius){}
  Circle(Rectangle const &r){
    r.a * 6 * this->a;

  }
};

// to convert :  Rectangle(Circle & )

unsigned int Point::num = 0;

int main(){

  Point a(5,7), b(7,5), c(3,4), d(8,1);

  Rectangle rectA(a, b, c, d);

  rectA.print();

  Circle circA(a, 50);

  return 0;

}
