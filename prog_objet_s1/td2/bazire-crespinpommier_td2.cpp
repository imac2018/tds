#include <iostream>
#include <cmath>
#define PI 3.141592653

class GeoObject {
public:
  GeoObject() { num++; }
  ~GeoObject() { num --; }
  static unsigned getNbr() { return num; }
private:
	virtual float perimeter() = 0;
  static unsigned num;
	virtual float area() = 0;
};
unsigned GeoObject::num = 0;
class Point {
protected:
	float x,y;
  static unsigned num;
public :
  Point() : x(0), y(0) { num++; }
  Point(float x, float y) : x(x), y(y) { num++; }
  ~Point(){ num--; }
  static unsigned getNumber(){ return num; }
	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
	void setX(float a){
		x = a;
	}
	void setY(float a){
		y = a;
	}
	float distance(Point b) const {
		return sqrt((b.getX() - x)*(b.getX() - x) + (b.getY() - y)*(b.getY() - y));
	}
	void translate(Point v){
		x += v.getX();
		y += v.getY();
	}
  static double distance (const Point & p1, const Point & p2){
    return p1.distance(p2);
  }
};
unsigned Point::num = 0;
class Vector : public Point{
public :
  Vector() {}
  Vector(float x, float y) : Point(x, y) {}
	float getNorm2(){
		return x*x + y*y;
	}
	float getNorm(){
		return sqrt(getNorm2());
	}
	float dotProduct(Vector v){
		return v.getX() * x + v.getY() * y;
	}
	void add(Vector v){
		x+=v.getX();
		y+=v.getY();
	}
	void substract(Vector v){
		x-=v.getX();
		y-=v.getY();
	}
	float cosSimiliraty(Vector v){
		return dotProduct(v)/(getNorm()*v.getNorm());
	}
};

class Line{
private :
	Point a,b;
public :
  Line(){}
  Line(float x1, float x2, float y1, float y2) : a(x1,x2), b(y1, y2) {}
  Line(Point a, Point b) : a(a), b(b) {}
	void setA(Point p){
		a = p;
	}
	void setB(Point p){
		b = p;
	}
	Point getA(){
		return a;
	}
	Point getB(){
		return b;
	}
	float length(){
		return a.distance(b);
	}
};

class Circle : public GeoObject{
private :
	Point center;
	float radius;
public :
  Circle(){}
  Circle(Point center, float radius) : center(center), radius(radius) {}
	void setCenter(Point p){
		center = p;
	}
	void setRadius (float r){
		radius = r;
	}
	Point getCenter(){
		return center;
	}
	float getRadius(){
		return radius;
	}
	
	float diameter(){
		return radius*2;
	}
	float perimeter(){
		return 2*PI*radius;
	}
	float area(){
		return PI*radius*radius;
	}
};

class Rectangle : public GeoObject{
private :
	Point a,b,c,d;
public :
  Rectangle(){}
  Rectangle(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}
	void setA(Point p){
		a = p;
	}
	void setB(Point p){
		b = p;
	}
	void setC(Point p){
		c = p;
	}
	Point getA(){
		return a;
	}
	Point getB(){
		return b;
	}
	Point getC(){
		return c;
	}
	Point getD(){
		return d;
	}
	float area(){
		return b.distance(a)*b.distance(c);
	}
	float perimeter(){
		return b.distance(a)*2 + b.distance(c)*2;
	}
	float diagonal(){
		return a.distance(c);
	}
};

class Polygon : public GeoObject {
public:
  Polygon(){}
}
using namespace std;
int main(){
  cout << GeoObject::getNbr() << endl;
  Circle c;
  cout << GeoObject::getNbr() << endl;
  return 0;
}
