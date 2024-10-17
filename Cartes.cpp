#include "Cartes.h"

Cartes::Cartes()
{

}

Cartes::Cartes(std::string nom,std::string categorie):m_nom(nom),m_categorie(categorie)
{
    ///Rien à faire
}

Cartes::~Cartes()
{
    ///Rien à faire pour l'instant
}

std::string Cartes::getNom()
{
    return m_nom;
}

std::string Cartes::getCategorie()
{
    return m_categorie;
}

void Cartes::affichageCartes()
{
    std::cout << getNom() <<" "<< getCategorie() << std::endl;
}







