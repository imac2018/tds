#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <Graphe.hpp>

using namespace std;
using namespace Eigen;

void non() {
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
}

#include <Arbre.hpp>
void oui() {
    using Arbre_i = Arbre<int>;
    using Enfants = std::list<Arbre_i*>;
    Arbre_i a42, a32, a4, a28;
    a42.val=42, a32.val=32, a4.val=4, a28.val=28;
    Enfants e50({&a42});
    Enfants e16({&a32, &a4, &a28});
    Arbre_i a50(e50), a16(e16), a2;
    a50.val=50, a16.val=16, a2.val=2;
    Enfants e100({&a50, &a16, &a2});
    Arbre_i a100(e100);
    a100.val = 100;

#define HELPER(expr) cout << #expr << " = " << (expr) << endl
    HELPER(a100.taille());
    HELPER(a100.feuille());
    HELPER(a42.feuille());
    HELPER(a100.recherche(32));
    HELPER(a100.recherche(33));
    HELPER(max(a100));
    HELPER(arite(a100));
}

int main(void) {
    oui();
    return EXIT_SUCCESS;
}
