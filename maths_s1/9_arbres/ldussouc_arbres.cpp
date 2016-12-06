#include <list>
#include <iostream>

#include "ldussouc_arbres.hpp"

using namespace std;

Arbre::Arbre(list<Arbre*> enfants) : enfants((enfants)) {}

list<Arbre*> Arbre::enfant(){
  return enfants;
}

int Arbre::taille() const{
  int taille = 1;
  for(auto i : enfants)
    taille += i->taille();
  return taille;
}

bool Arbre::feuille() const{
  if(enfants.empty() == true)
    return true;

  return false;
}

bool Arbre::recherche(T x) const{
  for(auto i : enfants)
    if (i->recherche(x))
      return true;
  return false;
}

int max(const Arbre<int> &){
  int tmp = this->val;
  for(auto i : enfants)
    if(i->max() > tmp)
      tmp = i->max();
  return tmp;
}
