
#include "francais.h"
#include entree_sortie_standard
#include bibliotheque_standard

entier principale(entier nombre_d_arguments, pointeur_de(pointeur_de(caractere)) vecteur_d_arguments) {
    octet i;
    pour toujours {
        i devient i plus 2;
        mais quand (i est egal a 8) alors sors de la;
        imprimerf("i vaut %" IMPRIMER_ENTIER NOUVELLE_LIGNE, i);
    }
    imprimerf("Bonjour le monde !" NOUVELLE_LIGNE);
    renvoyer QUITTER_REUSSITE;
}
