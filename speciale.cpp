#include "Cartes.h"

Speciales::Speciales(std::string nom,std::string categorie):Cartes(nom,categorie)
{
    if(m_nom=="UP_ATK")
    {
        m_fonctionnalite="Augmentation de l attaque du heros jusqu a sa mort";
    }
    else if(m_nom=="UP_DEF")
    {
        m_fonctionnalite="Augmentation des points de vie du heros";
    }
    else if(m_nom=="INVINCIBILITY")
    {
        m_fonctionnalite="Le heros  ne peut pas recevoir de degats pendant un tour";
    }
    else if(m_nom=="COMEBACK")
    {
        m_fonctionnalite="Le joueur peut reprendre une carte de son cimetiere";
    }
    else if(m_nom=="STUN")
    {
        m_fonctionnalite="Le heros adverse ne peut pas attaquer pendant un tour";
    }
    else if(m_nom=="DOWN_DEF")
    {
        m_fonctionnalite="Les points de vie du heros adverse sont baisses";
    }
    else
    {
        m_fonctionnalite="";
    }
}

Speciales::~Speciales()
{
    ///Rien à faire pour l'instant
}

std::string Speciales::getFonctionnalite()const
{
    return m_fonctionnalite;
}

void Speciales::fonctionnalite(Heros *h)
{
    if(m_nom=="UP_ATK")
    {
        h->setAttaque1(30);
        h->setAttaque2(30);
    }
    else if(m_nom=="UP_DEF")
    {
        h->setPtVie(h->getPtVie()+50);
    }
    else if(m_nom=="INVINCIBILITY")
    {
        ///A voir
    }
    else if(m_nom=="COMEBACK")
    {
        ///A voir
    }
    else if(m_nom=="STUN")
    {
        ///A voir
    }
    else if(m_nom=="DOWN_DEF")
    {
        h->setPtVie(h->getPtVie()-30);
    }
}

void Speciales::affichageSpeciales()
{
    Cartes::affichageCartes();
    std::cout << m_fonctionnalite << std::endl;
}
