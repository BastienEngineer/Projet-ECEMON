#include "Deck.h"

Deck::Deck()
{

}

Deck::~Deck()
{

}

///On affiche le vecteur de cartes (=deck)
void Deck::afficherDeck()
{
    std::cout << "Le deck :"<< std::endl;
    for(unsigned int i=0; i<paquet.size(); i++)
    {
        paquet[i].affichageCartes();
    }
}

void Deck::AjouterCartes(Cartes *c)
{
    paquet.push_back(*c);
}

Cartes Deck::Get_paquet(int nb)
{
    return paquet[nb];
}

///Mélange du deck
void Deck::shuffle()
{
    std::shuffle(paquet.begin(),paquet.end(),std::default_random_engine());
}

///On recherche s'il existe une carte Heros dans le deck du joueur
bool Deck::RechercheCartesHeros()
{
    bool b=false;
    int j=0;
    std::string m="Heros";
    for(unsigned int i=0; i<paquet.size(); i++)
    {
        if(paquet[i].getCategorie()==m)
        {
            j++;
        }
        else
        {

        }
    }
    if(j==0)
    {
        b=false;
    }
    else
    {
        b=true;
    }
    return b;
}

///On supprime la première carte du deck
void Deck::Supprimer()
{
    paquet.erase(paquet.begin());
}

///Sous programme qui permet d'afficher n'importe quelle carte dans du vecteur paquet en entrant sa position
void Deck::rechercheCartesDeck(int nb)
{
    paquet[nb].affichageCartes();
}

///On prend la première carte du deck et on la place en dessous de celui-ci
void Deck::deplacerEnQueue()
{
    std::string a;
    std::string b;
    a=paquet[0].getNom();
    b=paquet[0].getCategorie();
    Supprimer();
    Cartes *c=new Cartes(a,b);
    AjouterCartes(c);
}

///On retourne la catégorie de n'importe qu'elle carte du deck
std::string Deck::getCategorieCarte(int nb)
{
    return paquet[nb].getCategorie();
}

///On retourne le nom de n'importe qu'elle carte du deck
std::string Deck::getNomCarte(int nb)
{
    return paquet[nb].getNom();
}
