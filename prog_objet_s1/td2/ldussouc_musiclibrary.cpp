/*
 * Lucas Dussouchaud - Music Library
 */

#include <iostream>
#include <string>

std::vector<Album> albums;

// Album & tracks
class Album {
private:
  static int id;
  string name;
  string genre;
  double length;
  Artist artist;
public:
  Album(string name, string genre, double length) : name(name), genre(genre), length(length){
    id++;
  }

  ~Album(){
    id--;
  }

  string getName() const{
    return this->name;
  }

  string getGenre() const{
    return this->genre;
  }

  double getLength() const{
    return this->length;
  }

};

class Track : Album {
private:
  bool track(true);
public:

};

// Artists
class Artist{
private:
  static int id;
  string name;
  string genre;
  int yearorbirth;
public:
  Artist(string name, int yearorbirth, string genre) : name(name), genre(genre), yearofbirth(yearofbirth) {
    id++;
  }

  ~Artist(){
    id--
  }

  // Getters
  string getName() const{
    return this->name;
  }
  string getGenre() const{
    return this->genre;
  }
  id getYearofbirth() const{
    return this->yearofbirth;
  }

};

/* class GeoObject{
protected:
  static unsigned int geoNum;
};

unsigned int GeoObject::geoNum = 0;

class Point : GeoObject {
private:
  double x;
  double y;
  std::string name;
public:
  static unsigned int num;

  Point(double x, double y){
    this->x = x, this->y = y;
    num++;
    GeoObject::geoNum++;
    std::cout << "geonumber :" << GeoObject::geoNum << std::endl;
  }

  ~Point(){
    Point::num--;
    std::cout << "des :" << Point::num << std::endl;
  }
  static double distance (const Point & p1, const Point & p2){
    double distance;
    distance = p1.x - p2.x / p1.y - p2.y;
    std::cout << distance << std::endl;
  }
  double getX() const{
    return x;
  }
  double getY() const{
    return Y;
  }
  void changeName(std::string name){
    this.name = name;
  }
};

unsigned int Point::num = 0;

int main(){
  Point a(5,7);
  Point b(7,5);
  Point * p = new Point(3,4);

  a.getDistance(b);

  std::cout << "number :" << Point::num << std::endl;

  delete p;

  return 0;

  }*/
