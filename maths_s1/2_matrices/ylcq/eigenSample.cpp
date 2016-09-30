//Télécharger la dernière version stable de Eigen;
//Extraire l'archive, et renommer le dossier obtenu en 'eigen'
//Compiler avec :
//    g++ -Wall -Ieigen eigenSample -o eigenSample.out

#include <iostream>
#include <Eigen/Dense>
#include <cassert>
#include <ctime>

static void sample() {
  Eigen::VectorXd v1(5);
  v1 << 1, 2, 3, 4, 5;
  std::cout << "v1 : " << v1.transpose() << std::endl << std::endl;

  Eigen::Vector4f v2 = Eigen::Vector4f::Zero();
  std::cout << "v2 : " << v2.transpose() << std::endl << std::endl;

  v2 = Eigen::Vector4f::Ones();
  std::cout << "v2 : " << v2.transpose() << std::endl << std::endl;

  Eigen::Vector4f v3 = Eigen::Vector4f::Random();
  std::cout << "v3 : " << v3.transpose() << std::endl << std::endl;
  v3 = v3 + v2;
  std::cout << "v3 : " << v3.transpose() << std::endl << std::endl;

  Eigen::MatrixXd A = Eigen::MatrixXd::Random(3,4);	
  std::cout << "A :\n" << A << std::endl << std::endl;

  Eigen::Matrix4d B = Eigen::Matrix4d::Random(4,4);	
  std::cout << "B :\n" << B << std::endl << std::endl;

  Eigen::MatrixXd C(3,4);
  
  clock_t begin = clock();
  C=A*B;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;
  

  std::cout << "temps calcul du produit matriciel: " <<tempsCalc <<"s " << std::endl;
  std::cout << "A + 2*A :\n" << A + 2*A << std::endl << std::endl;
  std::cout << "A * B :\n" << A * B << std::endl << std::endl;
}

float ProduitScalaireXf(const Eigen::VectorXf &u, const Eigen::VectorXf &v) {
    assert(u.size() == v.size());
    float res = 0.f;
    for(long i=0 ; i<u.size() ; ++i)
        res += u[i]*v[i];
    return res;
}

void test_prod_scal() {
    Eigen::VectorXf u(4), v(4);
    u << 1,2,3,4;
    v << 4,3,2,1;
    std::cout << ProduitScalaireXf(u,v) << std::endl;
}


Eigen::MatrixXf ProduitMatricielXfNaiveImpl(const Eigen::MatrixXf a, const Eigen::MatrixXf b) {
    assert(a.rows() == b.cols());
    Eigen::MatrixXf r(a.rows(), b.cols());
    for(long y=0 ; y<a.rows() ; ++y)
        for(long x=0 ; x<b.cols() ; ++x) {
            r(y,x) = 0.f;
            for(long i=0 ; i<a.cols() ; ++i)
                r(y,x) += a(y,i)*b(i,x);
        }
    return r;
}

Eigen::MatrixXf ProduitMatricielXfProduitScalaireImpl(const Eigen::MatrixXf a, const Eigen::MatrixXf b) {
    assert(a.rows() == b.cols());
    Eigen::MatrixXf r(a.rows(), b.cols());
    for(long y=0 ; y<a.rows() ; ++y)
        for(long x=0 ; x<b.cols() ; ++x) {
            Eigen::VectorXf u(a.cols()), v(b.rows());
            for(long i=0 ; i<a.cols() ; ++i) {
                u(i) = a(y,i);
                v(i) = b(i,x);
            }
            r(y,x) = ProduitScalaireXf(u, v);
        }
    return r;
}

void test_mat_mul() {
    Eigen::MatrixXf r(2,2), a(2,2), b(2,2);
    a << 3, 1, 2, 1;
    std::cout << a << std::endl << std::endl;
    b << 3, 2, 4, 1;
    std::cout << b << std::endl << std::endl;
    r = ProduitMatricielXfStrassenImpl(a,b);
    std::cout << r << std::endl << std::endl;
    // Attendu :
    // 13  7
    // 10  5
}

typedef enum {
    COIN_SG = 0,
    COIN_SD = 1,
    COIN_IG = 2,
    COIN_ID = 3
} coinMatrice;

Eigen::MatrixXf SubdiviserMatriceXf(const Eigen::MatrixXf &A, coinMatrice coin) {
    Eigen::MatrixXf r(A.cols()/2, A.rows()/2);
    long x_start, y_start;
    switch(coin) {
    case COIN_SG: x_start=0;        y_start=0;        break;
    case COIN_SD: x_start=r.cols(); y_start=0;        break;
    case COIN_IG: x_start=0;        y_start=r.rows(); break;
    case COIN_ID: x_start=r.cols(); y_start=r.rows(); break;
    }
    for(long ry=0, y=y_start ; y<r.rows() ; ++y, ++ry) 
        for(long rx=0, x=x_start ; x<r.cols() ; ++x, ++rx)
            r(ry,rx) = A(y,x);
    return r;
}

Eigen::MatrixXf ProduitMatricielXfStrassenImpl(const Eigen::MatrixXf &A, const Eigen::MatrixXf &B) {
    assert(A.rows() == B.cols());
    Eigen::MatrixXf res(A.rows(), B.cols());

    if(A.rows() <= 2 || A.cols() <= 2)
        return ProduitMatricielXfNaiveImpl(A,B);

    Eigen::MatrixXf a = SubdiviserMatriceXf(A, COIN_SG);
    Eigen::MatrixXf b = SubdiviserMatriceXf(A, COIN_SD);
    Eigen::MatrixXf c = SubdiviserMatriceXf(A, COIN_IG);
    Eigen::MatrixXf d = SubdiviserMatriceXf(A, COIN_ID);
    Eigen::MatrixXf e = SubdiviserMatriceXf(B, COIN_SG);
    Eigen::MatrixXf f = SubdiviserMatriceXf(B, COIN_SD);
    Eigen::MatrixXf g = SubdiviserMatriceXf(B, COIN_IG);
    Eigen::MatrixXf h = SubdiviserMatriceXf(B, COIN_ID);

    Eigen::MatrixXf p1 = ProduitMatricielXfStrassenImpl(a, f-h);
    Eigen::MatrixXf p2 = ProduitMatricielXfStrassenImpl(c+d, e);
    Eigen::MatrixXf p3 = ProduitMatricielXfStrassenImpl(a+d, e+h);
    Eigen::MatrixXf p4 = ProduitMatricielXfStrassenImpl(a-c, e+f);
    Eigen::MatrixXf p5 = ProduitMatricielXfStrassenImpl(a+b, h);
    Eigen::MatrixXf p6 = ProduitMatricielXfStrassenImpl(d, g-e);
    Eigen::MatrixXf p7 = ProduitMatricielXfStrassenImpl(b-d, g+h);

    Eigen::MatrixXf r = p5+p4-p2+p6;
    Eigen::MatrixXf s = p1+p2;
    Eigen::MatrixXf t = p3+p4;
    Eigen::MatrixXf u = p1+p5-p3-p7;

    //TODO: reconstruire res avec r,s,tu

    return r;
}

int main(){
    //sample(); 
    //test_prod_scal();
    test_mat_mul();
    return 0;
}
