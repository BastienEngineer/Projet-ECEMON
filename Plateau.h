#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "Classes.h"
class Deck;
class Joueur;
class Heros;

class Plateau
{
private:
    ///Attributs
    std::vector<Joueur*> listedejoueur;
public:
    ///Constructeur et destructeur
    Plateau();
    ~Plateau();

    ///Méthodes
    void AjouterJoueur(Joueur *a);
    void AffichagePlateauPerso(int numerodujoueurdanslevecteur);
    void piocher(int nb);
    void MelangeJoueur();
    void Poser(int nb);
    void Tour(int nbJoueurs);
    void PremierTour(int nbJoueurs);
    bool JoueurVivant();
    bool listeDeJoueurExistanceHeros();

    ///Getters et setters
    Joueur* getjoueur(int nb);
    std::vector<Joueur*> getlistedejoueur();
};

#endif // PLATEAU_H_INCLUDED
