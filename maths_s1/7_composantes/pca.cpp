// Vincent, mod. Bruno

#include <iostream>
#include <Eigen/Eigenvalues>
#include <cstdlib>
#include <iomanip>

#include "ioEigen.hpp"

using namespace Eigen;


int main(int argc, char **argv)
{
  
  // load the data
  MatrixXd A;
  loadMatrix(A,"data.mat");
  std::cout << "A\n" << A << std::endl;

  // Perform a PCA on the matrix A



  return 0;
}

// g++ -Wall -I ~/eigen/ pca.cpp  ioEigen.cpp ioEigen.hpp 



