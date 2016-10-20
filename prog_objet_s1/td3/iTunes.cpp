
/*
 * DUCOUX ARTHUR - Music Library
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Track
class Track {
private:
  static int id;
  string name;
  string genre;
  double length;
public:
  Track(string name, string genre, double length) : name(name), genre(genre), length(length){
    id++;
  }

  ~Track(){
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



// Artists
class Artist{
private:
  string name;
  string genre;
  int yearofbirth;
  std::vector<Track> tracks;

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

  std::vector<Track> getTracks() const{
    return this->tracks;
  }

  int getTracksSize(){
    return this->tracks.size();
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



  //Methods Tracks
  void addTrack(Track track)
  {
    tracks.push_back(track);
  }
  void printTracks(){
    for(unsigned int i=0; i < tracks.size() ;i++)
      std::cout << tracks[i].getName() << " - Genre : " <<  tracks[i].getGenre() << " - Length : " << tracks[i].getLength() << endl;
  }



};






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

  void printAll(int i){
    
    std::cout << artists[i].getName() <<  " : " <<endl;
    artists[i].printTracks();

  }

  void printArtist(int i){
      std::cout << i+1 << " " << artists[i].getName() <<endl;
  }

  void printArtistAll(int i){

      std::cout << artists[i].getName() <<" - " << artists[i].getGenre() << " - " << "Number of tracks : " << artists[i].getTracksSize() <<endl;
  }

  void editArtist(int idArtist){   //faire gaffe, peut etre faire -1 
    cout << "What do you want to edit piaf ? "<<endl;
    cout << "(1)  Name  "<< "(2)  Genre  "<< "(3) Year of birth" <<endl;
    int choice;
    cin >> choice;

    if (choice == 1){
      string newName;
      cout << "Choose a new name "<<endl;
      cin >> newName;
      artists[idArtist].editName(newName);
    }
    else if (choice == 2){
      string newGenre;
      cout << "Choose a new genre "<<endl;
      cin >> newGenre;
      artists[idArtist].editGenre(newGenre);
    }
    else if (choice == 3){
      int age;
      cout << "Choose a new Year of birth "<<endl;
      cin >> age;
      artists[idArtist].editYearofbirth(age);
    }


  }



   int menu1() {

   		std::cout << "1.  Open Library      " << "2.  Search Artist      " << "3.  Search Track     " <<endl;
   		std::cout << "4.  Add a new artist  " << "5.  Save your Library  " << "6. Quit              " <<endl;
		std::cout << "Choose an option !"<<endl;

   	int i;
   	scanf ("%d",&i);

   	return i;
   }



   int menuLib(){
   	for(unsigned int i=0; i<artists.size();i++)
   		printArtist(i);

   	int choice;
   	std::cout <<endl;
   	std::cout << "(1) choose an artist  "<< "(2) Edit an artist " <<endl;
   	std::cout << "(3) Remove an artist  "<< "(4) Back           " <<endl;
  	scanf ("%d",&choice);

    if (choice == 1){
      std::cout<< "choose a number corresponding to the wanted artist" <<endl;
      scanf ("%d",&choice);
      return choice;
    }
    else if (choice == 2){
      std::cout<< "choose a number corresponding to the wanted artist" <<endl;
      scanf ("%d",&choice);
      editArtist(choice);
    }
    else if (choice == 3){
      std::cout<< "Removing not ready... :(" <<endl;
    }
    else if (choice == 4){
      std::cout<< "Back thing not ready... :(" <<endl;
    }
   	
   }

   int menuLib1(int nbArtist){

    int choice;

    printArtistAll(nbArtist - 1);
    std::cout << "(1) See his tracks  "<< "(2) Back " <<endl;
    scanf ("%d",&choice);

    if (choice == 1){
      printAll(nbArtist - 1);
    }
    else if (choice == 2){
      std::cout<< "Back thing not ready... :(" <<endl;
    }

    return choice;
   }


   int displayM1(){
    int loop = 0;

    while (loop == 0){

      std::cout <<endl;
      std::cout << "Welcome to the Music Library !" <<endl <<endl;

      int choice = menu1();

      while ( choice > 6){
        std::cout << "Choose a possible option please."<<endl;
          choice = menu1();
      }
      std::cout << endl;

      if (choice == 1){
        std::cout << "Your Artists : "<<endl;
        choice = menuLib();
        menuLib1(choice);
      }
      if (choice == 2){
        std::cout<< "search not ready... :(" <<endl;
      }
      if (choice == 3){
        std::cout<< "search not ready... :(" <<endl;
      }
      if (choice == 4){
        std::cout<< "adding not ready... :(" <<endl;
      }
      if (choice == 5){
        std::cout<< "saving not ready... :(" <<endl;
      }
      if (choice == 6){
        std::cout<< " Good bye ! A Ploutard" << "\n" <<endl; 
        loop = 1;
      }

    }


  }

  // Track & search(string name) {/*you know how to do this...*/}
  // void backup() {/*save to a file*/}
};




int Artist::id = 0;
int Track::id = 0;






int main(){

	int choice;
//creation of library
  Library myMusic = Library();

//creation of artist
  Artist iggyPop = Artist("Iggy Pop", "Garage Rock", 1947);
  Artist beatles = Artist("The Beatles", "Rock", 1947);
  Artist dylan = Artist("Bob Dylan", "Folk", 1947);



// creation of Tracks  
//
//You must add add an Track to an artist
  Track lustforLife = Track("Lust for Life", "Rock", 210);
  Track candy = Track("Candy", "Rock", 321);
  Track yellow = Track("Yellow Submarin", "Pop Rock", 134);


  iggyPop.addTrack(lustforLife);
  iggyPop.addTrack(candy);
  beatles.addTrack(yellow);

  myMusic.add(iggyPop);
  myMusic.add(beatles);
  myMusic.add(dylan);

  //iggyPop.printTracks();
  //std::cout << iggyPop.getTracksSize() <<endl;
 	myMusic.displayM1();




  

  return 0;
}
