#include <climits>
#include <Graphe.hpp>

using namespace std;
using namespace Eigen;

Graphe::Graphe(size_t n) : mat(n,n) {}
Graphe::Graphe(const MatrixXi &M) : mat(M) {}
Graphe::Graphe(const Graphe &G) : mat(G.mat) {}
Graphe::~Graphe() {}

ostream& operator<<(ostream& stream, const Graphe& g) {
    return stream << g.mat;
}
size_t Graphe::ordre() const {
    return mat.rows();
}
bool   Graphe::voisins(size_t i, size_t j) const {
    if(i>=ordre())
        throw out_of_range("i est trop gros !");
    if(j>=ordre())
        throw out_of_range("j est trop gros !");
    return mat(i,j) && mat(j,i);
}

static bool contains(const vector<size_t> &V, size_t nb){
    for(size_t i=0; i<V.size(); i++)
        if(nb == V[i])
            return true;
    return false;
}

static size_t findMinIndex(const size_t *ary, size_t cnt) {
    size_t minindex, minval=SIZE_MAX;
    for(size_t i=0 ; i<cnt ; ++i)
        if(ary[i] < minval) {
            minval = ary[i];
            minindex = i;
        }
    return minindex;
}
vector<size_t> Graphe::dijkstra(size_t i) const {
    vector<size_t> P, d(ordre(), SIZE_MAX);
    d[i] = 0;
    while(P.size() < ordre()){
        size_t a = findMinIndex(d.data(), d.size());
        P.push_back(a);
        for(size_t b=0 ; b<ordre() ; ++b)
            if(mat(a,b) && !contains(P, b))
                d[b] = min(d[b], d[a] + mat(a,b));
    }
    return d;
}

bool Graphe::connexe() const {
    for(size_t i=0; i<ordre(); i++)
        if(contains(dijkstra(i), SIZE_MAX))
            return false;
    return true;
}
VectorXd Graphe::spectre() const {
    return SelfAdjointEigenSolver<MatrixXd>(mat.cast<double>()).eigenvalues();
}
