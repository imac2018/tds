
/*
 * DUCOUX ARTHUR, DUSSOUCHAUD LUCAS - Music Library
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
    // id++;
  }

  ~Track(){
    // id--;
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
  void editLength(double length) {
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
    // id++;
  }

  ~Artist(){
    // id--;
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
      std::cout << i+1 <<"." << tracks[i].getName() << " - Genre : " <<  tracks[i].getGenre() << " - Length : " << tracks[i].getLength() << endl;
  }


  void editTrack(int idTrack){   //faire gaffe, peut etre faire -1 
    cout << "What do you want to edit piaf ? "<<endl;
    cout << "(1)  Name  "<< "(2)  Genre  "<< "(3) Length" <<endl;
    int choice;
    cin >> choice;

    if (choice == 1){
      cout << idTrack << endl;
      string beforeName = tracks[idTrack].getName();
      string newName;
      cout << "Choose a new name "<<endl;
      cin >> newName;
      tracks[idTrack].editName(newName);
      cout << endl;
      cout << "The new name for " << beforeName << " is " << tracks[idTrack].getName() << endl;
    }
    else if (choice == 2){
      string newGenre;
      cout << "Choose a new genre "<<endl;
      cin >> newGenre;
      tracks[idTrack].editGenre(newGenre);
    }
    else if (choice == 3){
      int length;
      cout << "Choose a new Length "<<endl;
      cin >> length;
      tracks[idTrack].editLength(length);
    }
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

      std::cout << artists[i].getName() <<" - " << artists[i].getGenre() << " - " << "Born in " << artists[i].getYearofbirth() << " - Number of tracks : " << artists[i].getTracksSize() <<endl;
  }

  void editArtist(int idArtist){
    cout << "What do you want to edit ? "<<endl;
    cout << "(1)  Name  "<< "(2)  Genre  "<< "(3) Year of birth" <<endl;
    int choice;
    cin >> choice;

    if (choice == 1){
      string beforeName = artists[idArtist].getName();
      string newName;
      cout << "Choose a new name "<<endl;
      cin >> newName;
      artists[idArtist].editName(newName);
      cout << endl;
      cout << "The new name for " << beforeName << " is " << artists[idArtist].getName() << endl;
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

   		std::cout << "1.  Open Library      " << "2.  Search       " << "3. Quit    " <<endl;
		  std::cout << "Choose an option !"<<endl;

   	int i;
   	scanf ("%d",&i);

   	return i;
   }


   void menuLib1(int nbArtist){

    int choice;

    printArtistAll(nbArtist - 1);
    cout <<endl;
    cout << "(1) See his tracks  " << "(2) Add a Track  " <<"(3) Home " <<endl;
    cin >> choice;

    if (choice == 1){
      printAll(nbArtist - 1);
      cout <<endl;
      std::cout << "(1) Edit a track  " <<"(2) Remove a track " << "(3)  Home" <<endl;
      cin >> choice;

      if (choice == 1){
        std::cout<< "choose a number corresponding to the wanted track" <<endl;
        cin >> choice;
        artists[nbArtist-1].editTrack(choice-1);
      }
      else if (choice == 2){
        std::cout << "choose a number corresponding to the wanted track" <<endl;
        int idTrack;
        cin >> idTrack;

        cout << artists[nbArtist-1].getTracks()[idTrack-1].getName() << " has been deleted" << endl;
        artists[nbArtist-1].getTracks().erase(artists[nbArtist-1].getTracks().begin() + idTrack - 1);
      }
      else if (choice == 3){
        std::cout<< "Back Home" <<endl;
      }
    }
    else if (choice == 2){
        std::cout<< "You want to add a new track" <<endl;
    }
    else if (choice == 3){
      std::cout<< "Back Home" <<endl;
    }
   }





   void menuLib(){
   	for(unsigned int i=0; i<artists.size();i++)
   		printArtist(i);

   	int choice;
   	std::cout <<endl;
   	std::cout << "(1) choose an artist  "<< "(2) Edit an artist " <<endl;
   	std::cout << "(3) Remove an artist  "<< "(4) Add an artist " << "(5) Home       " <<endl;
  	cin >> choice;

    if (choice == 1){
      std::cout<< "choose a number corresponding to the wanted artist" <<endl;
      cin >> choice;
      menuLib1(choice);
    }
    else if (choice == 2){
      std::cout<< "choose a number corresponding to the wanted artist" <<endl;
      cin >> choice;
      editArtist(choice - 1);
    }
    else if (choice == 3){
      std::cout<< "choose a number corresponding to the wanted artist" <<endl;
      int idArtist;
      cin >> idArtist;
      cout << artists[idArtist-1].getName() << " has been deleted" << endl;
      artists.erase(artists.begin() + idArtist - 1);

    }
    else if (choice == 4){
      string artistName, artistGenre; int artistYear;
      std::cout<< "Type the name of a new artist you want to add" <<endl;
      cin >> artistName;
      std::cout<< "Type the genre of a new artist you want to add" <<endl;
      cin >> artistGenre;
      std::cout<< "Type the year of birth of a new artist you want to add" <<endl;
      cin >> artistYear;
      Artist newArtist = Artist(artistName, artistGenre, artistYear);
      add(newArtist);
      cout << artistName << " has been added to the library"<< endl;
    }
    else if (choice == 5){
      std::cout<< "Back Home " <<endl;
    }
   }

   void displayM1(){
    int loop = 0;

    while (loop == 0){

      std::cout <<endl;
      std::cout << "Welcome to the Music Library !" <<endl <<endl;

      int choice = menu1();

      while ( choice > 3){
        std::cout << "Choose a possible option please."<<endl;
          choice = menu1();
      }
      std::cout << endl;

      if (choice == 1){
        std::cout << "Your Artists : "<<endl;
        menuLib();
      }
      // This is only working for non space names.
      if (choice == 2){
        cout<< "which artist do you want to search ?" <<endl;
        string artistName;
        cin >> artistName;
        for(unsigned int i=0; i<artists.size();i++){
          if(artists[i].getName() == artistName){
            printArtist(i);
          }
        }
      }
      if (choice == 3){
        std::cout<< " Good bye ! A Ploutard" << "\n" <<endl;
        loop = 1;
      }

    }

  }

  // Track & search(string name) {/*you know how to do this...*/}
  // void backup() {/*save to a file*/}
};




// int Artist::id = 0;
// int Track::id = 0;


int main(){

//creation of library
  Library myMusic = Library();

//creation of artist
  Artist iggyPop = Artist("Iggy Pop", "Garage Rock", 1947);
  Artist beatles = Artist("The Beatles", "Rock", 1947);
  Artist dylan = Artist("Bob Dylan", "Folk", 1941);
  Artist johnny = Artist("Johnny Hallyday", "Rock", 1943);
  Artist elvis = Artist("Elvis Presley", "Rock", 1935);
  Artist snoop = Artist("Snoop Dogg", "Rap", 1971);
  Artist daft = Artist("Daft Punk", "Electro", 1983);
  Artist christy = Artist("Christine and th Queens", "Pop", 1980);
  Artist goldman = Artist("Jean Jaques Goldman", "Variety", 1951);
  Artist bruel = Artist("Patrick Bruel", "Variety", 1959);
  Artist clash = Artist("The Clash", "Variety", 1972);
  Artist krzysztof = Artist("Krzysztof Krawczyk", "Variety", 1946);
  Artist niemen = Artist("Czesl,aw Niemen", "Variety", 1939);


// creation of Tracks  
//
//You must add add an Track to an artist
  Track lustforLife = Track("Lust for Life", "Rock", 210);
  Track candy = Track("Candy", "Rock", 321);
  Track yellow = Track("Yellow Submarin", "Pop Rock", 134);
  Track wind = Track("Blowin' in the wind", "Folk", 345);
  Track rolling = Track("Like a Rolling Stone", "Folk", 543);
  Track shoes = Track("Blue Suede Shoes", "Rock", 212);
  Track harder = Track("Harder, Better, Faster, Stronger", "Electro", 344);
  Track lucky = Track("Get Lucky", "Electro", 134);
  Track labas = Track("La Bas", "Variety", 232);
  Track envole = Track("Envole Moi", "Variety", 523);
  Track actes = Track("A Nos Actes Manqués", "Variety", 523);
  Track stay = Track("Should I stay or should I go", "Rock", 322);
  Track byle = Track("byle byl,o tak...", "Variety", 634);
  Track ostatni = Track("Ostatni raz zatanczysz ze mna", "Variety", 623);
  Track dziwny = Track("Dziwny jest ten swiat", "Variety", 434);
  Track sen = Track("Sen o Warszawie", "Variety", 142);
  Track weim = Track("Wiem, ze nie wrocisz", "Variety", 745);


  iggyPop.addTrack(lustforLife);
  iggyPop.addTrack(candy);
  beatles.addTrack(yellow);
  dylan.addTrack(wind);
  dylan.addTrack(rolling);
  elvis.addTrack(shoes);
  daft.addTrack(harder);
  daft.addTrack(lucky);
  goldman.addTrack(labas);
  goldman.addTrack(envole);
  goldman.addTrack(actes);
  clash.addTrack(stay);
  krzysztof.addTrack(byle);
  krzysztof.addTrack(ostatni);
  niemen.addTrack(dziwny);
  niemen.addTrack(sen);
  niemen.addTrack(weim);

//adding to our library
  myMusic.add(iggyPop);
  myMusic.add(beatles);
  myMusic.add(dylan);
  myMusic.add(johnny);
  myMusic.add(elvis);
  myMusic.add(snoop);
  myMusic.add(daft);
  myMusic.add(christy);
  myMusic.add(goldman);
  myMusic.add(bruel);
  myMusic.add(clash);
  myMusic.add(krzysztof);
  myMusic.add(niemen);




  //iggyPop.printTracks();
  //std::cout << iggyPop.getTracksSize() <<endl;
 	myMusic.displayM1();


  return 0;
}










