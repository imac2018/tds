#include <iostream>
#include <math.h>
using namespace std;

struct Integ {
  float valMin, valMax, aire;

  Integ(float valMin, float valMax, float aire) :
    valMin(valMin),
    valMax(valMax),
    aire(aire)
  {}
};

float poly(float x){
  return -pow(x,4) + 2 * pow(x,3) + 3;
}

typedef float (*func)(float);

// Méthode des rectangles / trapèze
Integ rectTrapezInteg(int debut, int fin, int subdivision, func f){
  float pas = (float)(fin-debut) / subdivision;
  float valMax = 0.0f;
  float valMin = 0.0f;
  float aire = 0.0f;

  for(int i = 0; i < subdivision; ++i){
    valMax += max(f(debut + i * pas), f(debut + (i+1)* pas)) * pas;
    valMin += min(f(debut + i * pas), f(debut + (i+1)* pas)) * pas;
  }

  aire = (valMin + valMax) / 2;

  return Integ(valMin, valMax, aire);
}

int main(){

  Integ aireRect = rectTrapezInteg(-1, 3, 100, poly);

  cout << aireRect.valMin << " < " << aireRect.aire << " < " << aireRect.valMax << endl;

  return 0;
}
