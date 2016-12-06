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
 double distance (const Point & p2){
    double distance;
    distance = x - p2.x / y - p2.y;
    return distance;
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

  double operator-(const Point & a){
    double distance;
    distance = x - a.x / y - a.y;
    return distance;
  }

  friend std::ostream & operator<<(std::ostream & co, const Point & a){
    return co << a.x << ' '<< a.y;
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
  // Circle(Rectangle const &r){
  //   r.a * 6 * this->a;
  // }
};

unsigned int Point::num = 0;

int main(){

  Point a(5,7);
  Point b(7,5);

  std::cout << a.distance(b) << std::endl;
  std::cout << a-b << std::endl;
  std::cout << a << std::endl;

  return 0;
}
