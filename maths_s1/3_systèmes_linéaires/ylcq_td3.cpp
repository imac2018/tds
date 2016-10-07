// Compiler avec :
//     g++ -Wall -std=c++11 ylcq_td3.cpp -o ylcq_td3

#include <iostream>
#include <Eigen/Dense>
#include <cassert.h>

using namespace std;
using namespace Eigen;

static float getreiuzghuegz

static VectorXf GaussSeidel(const MatrixXf &sys, const VectorXf &sol, size_t n) {
    assert(sys.cols() == sol.size());
    VectorXf tmp(sol.size());
    for(size_t i=0 ; i<sol.size() ; ++i) {
        tmp(i) = sol(i);
        for(size_t j=0 ; j<sol.size() ; ++j)
            if(j!=i)
                tmp(i) += sys(i,j);
        tmp(i) /= sys(i,i);
    }
}

int main(int argc, char *argv[]) {
    MatrixXf sys(3,3);
    sys << 5, -3, 1, -1, 6, -4, 3, -3, 9;
    VectorXf sol(3);
    sol << 10, 5, -7;
    VectorXf x = GaussSeidel(sys, sol);
    cout << x << endl;
    return 0;
}
