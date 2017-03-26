#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

double fx(double x) {
    return -pow(x,4.) + 2.*pow(x,3.) + 3.;
}

typedef double (*func)(double);

struct Iminmax {
    double Imin, Imax;
    Iminmax(double Imin, double Imax) : Imin(Imin), Imax(Imax) {}
};

Iminmax integrale_rectangles(func f, double a, double b, size_t n) {
    double Imin, Imax, h=(b-a)/double(n);
    for(uint_fast32_t i=0 ; i<n ; ++i) {
        Imax += max(f(a+i*h), f(a+(i+1)*h));
        Imin += min(f(a+i*h), f(a+(i+1)*h));
    }
    return Iminmax(h*Imin, h*Imax);
}

// n subdivisions
double integrale_trapezes(func f, double a, double b, size_t n) {
    double somme=0., h = (b-a)/double(n);
    for(uint_fast32_t i=0 ; i<n ; ++i)
        somme += f(a + i*h) + f(a + (i+1)*h);
    return h*somme/2.;
}

double integrale_simpson(func f, double a, double b, size_t n) {
    double si=0., sp=0., h=(b-a)/double(n);
    for(uint_fast32_t i=1 ; i<=n-1 ; i+=2)
        si += f(a + i*h);
    for(uint_fast32_t i=2 ; i<=n-2 ; i+=2)
        sp += f(a + i*h);
    return (f(a) + f(b) + 4.*si + 2.*sp)*h/3.;
}

int main() {
    cout << setprecision(9000);
    Iminmax Imm = integrale_rectangles(fx, -1., 3., 100);
    //cout << Imm.Imin << ", " << Imm.Imax << endl;
    cout << (Imm.Imax + Imm.Imin)/2. << endl;
    cout << integrale_trapezes(fx, -1., 3., 100) << endl;
    cout << integrale_simpson(fx, -1., 3., 100) << endl;
    return 0;
}
