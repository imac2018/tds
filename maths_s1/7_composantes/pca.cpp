// g++ -Wall -I ~/eigen/ pca.cpp  ioEigen.cpp ioEigen.hpp 
// Vincent, mod. Bruno

#include <iostream>
#include <Eigen/Eigenvalues>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

#include "ioEigen.hpp"

using namespace Eigen;
using namespace std;


int main(int argc, char **argv) {
    // load the data
    MatrixXd A;
    loadMatrix(A,"data.mat");

    double *moyennes = new double[A.cols()];

    // Perform a PCA on the matrix A
    for(long x=0 ; x<A.cols() ; ++x) {
        double somme = 0;
        for(long y=0 ; y<A.rows() ; ++y)
            somme += A(y,x);
        moyennes[x] = somme/A.rows();
        for(long y=0 ; y<A.rows() ; ++y)
            A(y,x) -= moyennes[x];
    }

    cout << "Taux de fertilité moyen : " << moyennes[1] << endl;

    double *moyennes_abs = new double[A.cols()];

    for(long x=0 ; x<A.cols() ; ++x) {
        double somme = 0;
        for(long y=0 ; y<A.rows() ; ++y)
            somme += abs(A(y,x));
        moyennes_abs[x] = somme/A.rows();
        for(long y=0 ; y<A.rows() ; ++y)
            A(y,x) /= moyennes_abs[x];
    }

    cout << "A\n" << A << endl;

    // Ex 4.
    double N = A.rows();
    MatrixXd C = (A.transpose()*A)/(N-1);

    cout << endl << endl;
    cout << "C\n" << C << endl << endl;
    cout << "trace\n" << C.trace() << endl << endl;

    // Ex 5
    SelfAdjointEigenSolver<MatrixXd> es(C);
    auto valeurs_propres  = es.eigenvalues();
    auto vecteurs_propres = es.eigenvectors();

    std::vector<double> vp;
    for(long i=0 ; i<A.cols() ; ++i)
        vp.push_back(real(valeurs_propres(i)));
    //sort(vp.begin(), vp.end(), greater<double>());
    cout << endl << "Valeurs propres de C : " << endl;
    for(long i=0 ; i<A.cols() ; ++i)
        cout << vp[i] << endl;

    cout << "\nVecteurs propres :\n" << vecteurs_propres << endl;
    // Que vaut le produit scalaire de deux vecteurs propres ?
    cout << vecteurs_propres.col(0).dot(vecteurs_propres.col(1)) << endl;
    // OMG ça vaut zéro
    //
    //map<double, VectorXd> ma_map;

    delete[] moyennes_abs;
    delete[] moyennes;
    return EXIT_SUCCESS;
}

