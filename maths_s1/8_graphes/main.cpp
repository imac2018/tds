#include <cstdlib>
#include <Graphe.hpp>

using namespace std;
using namespace Eigen;

int main(void) {
    MatrixXi adj(3,3);
    adj << 0,4,2,
           4,0,1,
           2,1,0;
    Graphe g(adj);
    cout << g << endl;
    vector<size_t> dij = g.dijkstra(1);
    cout << "Dikdjlizajdiofei(1) : " << endl;
    for(size_t i=0 ; i<dij.size() ; ++i)
        cout << dij[i] << " ";
    cout << endl;
    cout << g.connexe() << endl;
    cout << g.spectre() << endl;
    return EXIT_SUCCESS;
}
