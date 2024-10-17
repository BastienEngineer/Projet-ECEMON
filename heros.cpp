#include "Cartes.h"

///Constructeur du héros qui remplit les caractéristiques en fonction du nom de la carte
Heros::Heros(std::string nom,std::string categorie):Cartes(nom,categorie)
{
    if(nom=="Saranos")
    {
        m_type="Hunter";
        m_ptvie=100;
        m_attaque1=20;
        m_nomAttaque1="Triple shoot";
        m_attaque2=50;
        m_nomAttaque2="Shotgun death";
        m_ptEnergie=0;
    }
    else if(nom=="Dragotor")
    {
        m_type="Hunter";
        m_ptvie=90;
        m_attaque1=15;
        m_nomAttaque1="Steel claws";
        m_attaque2=55;
        m_nomAttaque2="Draco meteor";
        m_ptEnergie=0;
    }
    else if(nom=="Mirmir")
    {
        m_type="God";
        m_ptvie=80;
        m_attaque1=30;
        m_nomAttaque1="Thunderbolts";
        m_attaque2=80;
        m_nomAttaque2="Light god sword";
        m_ptEnergie=0;
    }
    else if(nom=="Dalnarma")
    {
        m_type="God";
        m_ptvie=85;
        m_attaque1=35;
        m_nomAttaque1="Fireball";
        m_attaque2=75;
        m_nomAttaque2="Volcanic eruption";
        m_ptEnergie=0;
    }
    else if(nom=="Halddis")
    {
        m_type="Demon";
        m_ptvie=140;
        m_attaque1=10;
        m_nomAttaque1="Shadow sword";
        m_attaque2=35;
        m_nomAttaque2="Demoniac rage";
        m_ptEnergie=0;
    }
    else if(nom=="Valanto")
    {
        m_type="Demon";
        m_ptvie=150;
        m_attaque1=15;
        m_nomAttaque1="Bloody scratch";
        m_attaque2=30;
        m_nomAttaque2="Gates of hell";
        m_ptEnergie=0;
    }
    else if(nom=="Grishnarz")
    {
        m_type="Assassin";
        m_ptvie=90;
        m_attaque1=25;
        m_nomAttaque1="Phantom blade";
        m_attaque2=65;
        m_nomAttaque2="Assassination";
        m_ptEnergie=0;
    }
    else if(nom=="Gonlor")
    {
        m_type="Assassin";
        m_ptvie=95;
        m_attaque1=30;
        m_nomAttaque1="Invisibility";
        m_attaque2=60;
        m_nomAttaque2="Prison path";
        m_ptEnergie=0;
    }
    else
    {
        m_type="";
        m_ptvie=0;
        m_attaque1=0;
        m_nomAttaque1="";
        m_attaque2=0;
        m_nomAttaque2="";
        m_ptEnergie=0;
    }
}

Heros::~Heros()
{
    ///Rien à faire pour l'instant
}

void Heros::setPtVie(int ptv)
{
    m_ptvie = ptv;
}

void Heros::setPtEnergie(int pte)
{
    m_ptEnergie += pte;
}

std::string Heros::getType()const
{
    return m_type;
}

int Heros::getPtVie()const
{
    return m_ptvie;
}

void Heros::setNom(std::string nom)
{
    m_nom=nom;
}

void Heros::setCategorie(std::string categorie)
{
    m_categorie=categorie;
}

int Heros::getAttaque1()const
{
    return m_attaque1;
}

void Heros::setAttaque1(int a)
{
    m_attaque1+=a;
}

int Heros::getAttaque2()const
{
    return m_attaque2;
}

void Heros::setAttaque2(int a)
{
    m_attaque2+=a;
}

std::string Heros::getNomAttaque1()const
{
    return m_nomAttaque1;
}

std::string Heros::getNomAttaque2()const
{
    return m_nomAttaque2;
}

int Heros::getPtEnergie()const
{
    return m_ptEnergie;
}

///Sous programme qui permet à un héros d'attaquer un autre héros
void Heros::attaquer(Heros *h)
{
    int choix=0;
    Cartes::affichageCartes();
    std::cout << "Points de magie : " << m_ptEnergie << std::endl;
    std::cout << "Attaque 1 : " << m_nomAttaque1 << " " << m_attaque1 << " degats " << "prix 1 pt de magie" << std::endl;
    std::cout << "Attaque 2 : " << m_nomAttaque2 << " " << m_attaque2 << " degats " << "prix 2 pts de magie" << std::endl;
    std::cout << std::endl;
    std::cout << "L ennemi est : " << h->getNom() << " " << h->getCategorie() << std::endl;
    std::cout << "Points de vie de l ennemi : " << h->getPtVie() << std::endl;
    std::cout << std::endl;
    if(m_ptvie>0 && m_ptEnergie==1)
    {
        std::cout << "Attaque 1 : " << m_nomAttaque1 << " " << m_attaque1 << " degats " << std::endl;
        h->setPtVie(h->getPtVie()-m_attaque1);
        setPtEnergie(-1);
    }
    else if(m_ptvie>0 && m_ptEnergie>1)
    {
        do
        {
            std::cout << "Choisir l attaque a effectuer" << std::endl;
            std::cout << "1 Attaque 1" << std::endl;
            std::cout << "2 Attaque 2" << std::endl;
            std::cin >> choix;
        }
        while(choix <1 || choix>2);
        switch(choix)
        {
        case 1:
            std::cout << "Attaque 1 : " << m_nomAttaque1 << " " << m_attaque1 << " degats " << std::endl;
            h->setPtVie(h->getPtVie()-m_attaque1);
            setPtEnergie(-1);
            break;

        case 2:
            std::cout << "Attaque 2 : " << m_nomAttaque2 << " " << m_attaque2 << " degats " << std::endl;
            h->setPtVie(h->getPtVie()-m_attaque2);
            setPtEnergie(-2);
            break;
        }
    }
    else
    {
        std::cout << "Le heros n a pas assez de points d energies il ne peut pas attaquer" << std::endl;
    }
    std::cout << "Points de vie de l ennemi : " << h->getPtVie() << std::endl;
}

void Heros::affichageHeros()
{
    Cartes::affichageCartes();
    std::cout << "Le heros est de type : " << m_type << std::endl;
    std::cout << "Points de vie : " << m_ptvie << std::endl;
    std::cout << "Points de magie : " << m_ptEnergie << std::endl;
    std::cout << "Attaque 1 : " << m_nomAttaque1 << " " << m_attaque1 << " degats " << std::endl;
    std::cout << "Attaque 2 : " << m_nomAttaque2 << " " << m_attaque2 << " degats " << std::endl;
}


