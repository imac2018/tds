#pragma once

#include <cstddef>
#include <iostream>
#include <Eigen/Dense>

class Graphe {
    Eigen::MatrixXi mat;
public:
    Graphe(size_t n);
    Graphe(const Eigen::MatrixXi &M);
    Graphe(const Graphe &G);
    ~Graphe();

    friend std::ostream& operator<< (std::ostream& stream, const Graphe& g);
    size_t ordre() const;
    bool voisins(size_t i, size_t j) const;
    std::vector<size_t> dijkstra(size_t i) const;
    bool connexe() const;
    Eigen::VectorXd spectre() const;
};
