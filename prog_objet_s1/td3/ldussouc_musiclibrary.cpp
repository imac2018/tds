/*
 * Lucas Dussouchaud - Music Library
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Artists
class Artist{
private:
  string name;
  string genre;
  int yearofbirth;
public:
  static int id;
  Artist(string name, string genre, int yearofbirth) : name(name), genre(genre), yearofbirth(yearofbirth) {
    id++;
  }

  ~Artist(){
    id--;
  }

  // Getters
  string getName() const{
    return this->name;
  }
  string getGenre() const{
    return this->genre;
  }
  int getYearofbirth() const{
    return this->yearofbirth;
  }

  // Setters
  void editName(string name) {
    this->name = name;
  }
  void editGenre(string genre) {
    this->genre = genre;
  }
  void editYearofbirth(int yearofbirth) {
    this->yearofbirth = yearofbirth;
  }
};

// Album & tracks
class Album {
private:
  static int id;
  string name;
  string genre;
  double length;
  Artist artist;
public:
  Album(string name, string genre, double length) : name(name), genre(genre), length(length), artist(artist){
    id++;
  }

  ~Album(){
    id--;
  }

  // Getters
  string getName() const{
    return this->name;
  }

  string getGenre() const{
    return this->genre;
  }

  double getLength() const{
    return this->length;
  }

  // Setters
  void editName(string name) {
    this->name = name;
  }
  void editGenre(string genre) {
    this->genre = genre;
  }
  void editlength(double length) {
    this->length = length;
  }

};

class Track : Album {};

class Library{
private:
  std::vector<Artist> artists;
public:
  Library(){
  }
  void add(Artist artist)
  {
    artists.push_back(artist);
  }
  void print(){
    for(unsigned int i=0; i<artists.size();i++)
      std::cout << artists[i].getName() <<  artists[i].getGenre() << endl;
  }
  // Album & search(string name) {/*you know how to do this...*/}
  // void backup() {/*save to a file*/}
};

int Artist::id = 0;

int main(){
  Library myMusic = Library();
  Artist joseGarcia = Artist("jose Garcia", "Rockabilly", 1966);
  Artist iggyPop = Artist("Iggy Pop", "Garage Rock", 1947);
  myMusic.add(joseGarcia);
  myMusic.add(iggyPop);

  myMusic.print();
  return 0;
}
