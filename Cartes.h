#ifndef CARTES_H_INCLUDED
#define CARTES_H_INCLUDED

#include "Classes.h"

class Cartes
{
protected:
    ///Attributs
    std::string m_nom;
    std::string m_categorie;
public:
    ///Constructeurs et destructeur
    Cartes();
    Cartes(std::string nom,std::string categorie);
	~Cartes();

	///Méthodes
	void affichageCartes();

    ///Getters et setters
    std::string getNom();
    std::string getCategorie();
};

class Heros : public Cartes
{
private:
    ///Attributs
    std::string m_type;
    int m_ptvie;
    int m_attaque1;
    std::string m_nomAttaque1;
    int m_attaque2;
    std::string m_nomAttaque2;
    int m_ptEnergie;
public:
    ///Constructeur et destructeur
    Heros(std::string nom,std::string categorie);
    ~Heros();

    ///Méthodes
    void attaquer(Heros *h);
    void affichageHeros();

    ///Getters et setters
    void setPtVie(int ptv);
    void setPtEnergie(int pte);
	int getPtVie()const;
	std::string getType()const;
	void setNom(std::string nom);
	void setCategorie(std::string categorie);
	int getAttaque1()const;
	int getAttaque2()const;
	void setAttaque1(int a);
	void setAttaque2(int a);
	std::string getNomAttaque1()const;
	std::string getNomAttaque2()const;
	int getPtEnergie()const;
};

class Energies : public Cartes
{
private:
    ///attributs
    std::string m_type;
    int m_ptEnergie;
public:
    ///Constructeur et destructeur
    Energies(std::string nom,std::string categorie);
    ~Energies();

    ///Méthodes
    void affichageEnergies();
    void action(Heros *h);
};

class Speciales : public Cartes
{
private:
    ///Attributs
    std::string m_fonctionnalite;
public:
    ///Constructeur et destructeur
    Speciales(std::string nom,std::string categorie);
    ~Speciales();

    ///Méthodes
    void affichageSpeciales();
    void fonctionnalite(Heros *h);

    ///Getters et setters
    std::string getFonctionnalite()const;
};



#endif // CARTES_H_INCLUDED
