#include "Cartes.h"

///Constructeur qui crée la carte énergie correspondant au nom de la carte
Energies::Energies(std::string nom,std::string categorie):Cartes(nom,categorie)
{
    if(m_nom=="Hunter1")
    {
        m_type="Hunter";
        m_ptEnergie=1;
    }
    else if(m_nom=="Hunter2")
    {
        m_type="Hunter";
        m_ptEnergie=2;
    }
    else if(m_nom=="God1")
    {
        m_type="God";
        m_ptEnergie=1;
    }
    else if(m_nom=="God2")
    {
        m_type="God";
        m_ptEnergie=2;
    }
    else if(m_nom=="Demon1")
    {
        m_type="Demon";
        m_ptEnergie=1;
    }
    else if(m_nom=="Demon2")
    {
        m_type="Demon2";
        m_ptEnergie=2;
    }
    else if(m_nom=="Assassin1")
    {
        m_type="Assassin";
        m_ptEnergie=1;
    }
    else if(m_nom=="Assassin2")
    {
        m_type="Assassin";
        m_ptEnergie=2;
    }
    else
    {
        m_type="";
        m_ptEnergie=0;
    }
}

Energies::~Energies()
{
    ///Rien à faire pour l'instant
}

///Sous programme qui permet l'utilisation des cartes énergies
///Elle augmente les points d'énergies du héros si celui-ci est du même type que l'énergie jouée
void Energies::action(Heros *h)
{
    if(m_type==h->getType())
    {
        h->setPtEnergie(m_ptEnergie);
    }
    else
    {
        std::cout << "Le heros n est pas du meme type que la carte energie" << std::endl;
    }
}

void Energies::affichageEnergies()
{
    Cartes::affichageCartes();
    std::cout << "La carte energie est de type : " << m_type << std::endl;
    std::cout << "Elle donne : " << m_ptEnergie << " points de magie" << std::endl;
}
