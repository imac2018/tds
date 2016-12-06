#pragma once

#include <iostream>
#include <list>

using namespace std;

template <typename T> class Arbre {
private:
  T val;
  list<Arbre*> enfants;
public:
  Arbre();
  Arbre(list<Arbre*> enfants);
  ~Arbre();

  list<Arbre*> enfant();

  int taille() const;
  bool feuille() const;
  bool recherche(T x) const;
  int max(const Arbre<int> &);
};
