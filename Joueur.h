#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Classes.h"

class Plateau;
class Heros;
class Energies;

class Deck
{
private:
    ///Attributs
	std::vector<Cartes> paquet;
public:
    ///Constructeur et destructeur
    Deck();
    ~Deck();

    ///Méthodes
    void AjouterCartes(Cartes *c);
    void afficherDeck();
    void shuffle();
    bool RechercheCartesHeros();
    void Supprimer();
    void rechercheCartesDeck(int nb);
    void deplacerEnQueue();

    ///Getters et setters
    Cartes Get_paquet(int nb);
    std::string getCategorieCarte(int nb);
    std::string getNomCarte(int nb);
};

class Joueur
{
private:
    ///Attributs
    std::string m_prenom;
    Deck d;
	int m_ptdevie;
	Heros *h;
	bool m_herosEnJeu;
public:
    ///Constructeur et destructeur
    Joueur(std::string prenom, int id);
    Joueur();
    ~Joueur();

    ///Méthodes
    void remplissagejoueur();
    void AfficherJoueur();
    void ajouterAuDeck(Cartes *c);
    void affichageDeckJoueur();
    void saisirNomJoueur(int nbJoueurs,Plateau *p);
    void melangerCartesJoueurs();
    bool ExistanceHerosDeck();
    void accesDebut();
    void Supprimer1Carte();
    void deplacerFinDeck();
    void afficherHeros();
    void remplissageHeros(Heros *h1);
    void attaquerJoueur(Joueur *j);
    void actionEnergies(Energies e);
    void destructionHeros();

    ///Getters et setters
    std::string getPrenom();
    int getPtVie();
    void setPtVie(int ptv);
    void setHerosEnJeu(bool b);
    bool getHerosEnJeu()const;
	Deck Get_main();
    Cartes getPaquetJoueurs(int nb);
    std::string getCategorieDeck(int nb);
    std::string getNomDeck(int nb);
    void setPtvieHeros(int ptv);
    int getPtVieHeros()const;
    void setAttaque1Heros(int a);
    void setAttaque2Heros(int a);
};


#endif // JOUEUR_H_INCLUDED
