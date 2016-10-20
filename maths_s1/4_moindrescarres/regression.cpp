#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <cassert>
#include <iomanip>

#include "ioEigen.hpp"

using namespace Eigen;

// g++ -Wall -O2 -I ~/eigen/ regression.cpp  ioEigen.cpp ioEigen.hpp 

// Cette fonction calcule... la matrice pseudo-inverse d'une matrice A.
// Elle fait aussi une petite vérification. Ca ne DEVRAIT PAS être un
// assert(), mais ça suffit à nos besoins.
static MatrixXd pseudoInverse(MatrixXd A) {
    FullPivLU<MatrixXd> piv(A.transpose()*A);
    assert(piv.isInvertible());
    return (A.transpose()*A).inverse()*A.transpose();
}

int main(int argc, char **argv)
{
  if(argc != 2){
    std::cerr << "usage : " << argv[0] << " data.mat" << std::endl;
    exit(0);
  }
  
  // charger les données
  MatrixXd A;
  loadMatrix(A,argv[1]);

  // extraire le vecteur des observables à expliquer
  VectorXd y = A.leftCols(1);
  std::cout << "y\n" << y << std::endl;

  // la première colonne de A est remplie par des 1
  A.leftCols(1) = VectorXd::Ones(A.rows());
  std::cout << "A\n" << A << std::endl;

  //Régression linaéaire, cf. l'énoncé.
  VectorXd beta = pseudoInverse(A) * y;
  VectorXd u = y - A*beta;
  std::cout << "beta : \n" << beta << std::endl;
  std::cout << "u : \n" << u << std::endl;

  return 0;
}




