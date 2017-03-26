#pragma once

#include <cstddef>
#include <climits>
#include <list>

template <typename T>
class Arbre {
    std::list<Arbre*> m_enfants;
public:
    T val;

    Arbre() : m_enfants({}) {}
    Arbre(std::list<Arbre*> enfants) : m_enfants(enfants) {}
    ~Arbre() {}

    std::list<Arbre*> enfants() const { return enfants; }
    size_t taille() const {
        size_t taille = 1;
        for(auto i : m_enfants)
            taille += i->taille();
        return taille;
    }

    bool feuille() const {
        return m_enfants.empty();
    }
    bool recherche(T x) const {
        if(val == x)
            return true;
        for(auto i : m_enfants)
            if(i->recherche(x))
                return true;
        return false;
    }
    friend int max(const Arbre<int> &arbre, int m=INT_MIN) {
        for(auto i : arbre.m_enfants)
            m = std::max(m, max(*i, m));
        return std::max(m, arbre.val);
    }
    template <typename Y>
    friend int arite(const Arbre<Y> &arbre, int m=INT_MIN) {
        for(auto i : arbre.m_enfants)
            m = std::max(m, arite(*i, m));
        return std::max(m, (int)arbre.m_enfants.size());
    }
};

//QUESTION 5) : t^h
