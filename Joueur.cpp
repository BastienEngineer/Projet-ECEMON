#include "Joueur.h"

Joueur::Joueur(std::string prenom, int id):m_prenom(prenom)
{
    m_ptdevie=150;
    m_herosEnJeu=false;
}

Joueur::Joueur()
{
    m_ptdevie=150;
    m_herosEnJeu=false;
}

Joueur::~Joueur()
{

}

void Joueur::remplissagejoueur()
{
    std::cout << "Saisir le prenom du joueur : " << std::endl;
    std::cin >> m_prenom;
}

std::string Joueur::getPrenom()
{
    return m_prenom;
}

void Joueur::setPtVie(int ptv)
{
    if(ptv<=0)
    {
        m_ptdevie=0;
    }
    else
    {
        m_ptdevie=ptv;
    }
}

///On ajoute une carte au deck du joueur
void Joueur::ajouterAuDeck(Cartes *c)
{
    d.AjouterCartes(c);
}

void Joueur::affichageDeckJoueur()
{
    d.afficherDeck();
}

void Joueur::AfficherJoueur()
{
    std::cout  << "Joueur " << ": " << getPrenom() << std::endl;
}

Cartes Joueur::getPaquetJoueurs(int nb)
{
    return d.Get_paquet(nb);
}

///On mélange le deck du joueur
void Joueur::melangerCartesJoueurs()
{
    d.shuffle();
}

int Joueur::getPtVie()
{
    return m_ptdevie;
}

///On cherche s'il y a une carte Heros dans le deck
bool Joueur::ExistanceHerosDeck()
{
    return d.RechercheCartesHeros();
}

///On supprime la première carte du deck du joueur
void Joueur::Supprimer1Carte()
{
    d.Supprimer();
}

///Sous programme qui affiche la première cartes du deck du joueur
void Joueur::accesDebut()
{
    d.rechercheCartesDeck(0);
}

void Joueur::deplacerFinDeck()
{
    d.deplacerEnQueue();
}

std::string Joueur::getCategorieDeck(int nb)
{
    return d.getCategorieCarte(nb);
}

std::string Joueur::getNomDeck(int nb)
{
    return d.getNomCarte(nb);
}

void Joueur::setPtvieHeros(int ptv)
{
    h->setPtVie(ptv);
}

void Joueur::setAttaque1Heros(int a)
{
    h->setAttaque1(a);
}

void Joueur::setAttaque2Heros(int a)
{
    h->setAttaque2(a);
}

void Joueur::setHerosEnJeu(bool b)
{
    m_herosEnJeu=b;
}

///On cherche si le joueur a un Heros posé sur le terrain
bool Joueur::getHerosEnJeu()const
{
    return m_herosEnJeu;
}

int Joueur::getPtVieHeros()const
{
    return h->getPtVie();
}

void Joueur::remplissageHeros(Heros *h1)
{
    h=h1;
}

void Joueur::afficherHeros()
{
    h->affichageHeros();
}

void Joueur::destructionHeros()
{
    h->~Heros();
}

///On utilise la fonctionnalité de la carte Energies sur le Heros du joueur
void Joueur::actionEnergies(Energies e)
{
    if(getHerosEnJeu()==1)
    {
        e.action(h);
    }
    else
    {
        std::cout << "Il n y a pas de Heros sur le terrain la carte energie ne peut pas etre utilise " << std::endl;
    }
}

///Sous programme qui gère l'attaque des joueurs durant la boucle de jeu
void Joueur::attaquerJoueur(Joueur *j)
{
    int choix=0;
    h->affichageCartes();
    std::cout << "Points d energie : " << h->getPtEnergie() << std::endl;
    std::cout << "Attaque 1 : " << h->getNomAttaque1() << " " << h->getAttaque1() << " degats " << "prix 1 pt de magie" << std::endl;
    std::cout << "Attaque 2 : " << h->getNomAttaque2() << " " << h->getAttaque2() << " degats " << "prix 2 pts de magie" << std::endl;
    std::cout << std::endl;
    std::cout << "Points de vie de l ennemi : " << j->getPtVieHeros() << std::endl;
    std::cout << std::endl;
    if(h->getPtVie()>0 && h->getPtEnergie()==1 && getPtVie()>0)     ///Si le héros a un point d'énergie il utilse obligatoire sa première attaque (il faut évidemment que le joueur et le héros soient vivants)
    {
        std::cout << "Attaque 1 : " << h->getNomAttaque1() << " " << h->getAttaque1() << " degats " << std::endl;
        if(h->getAttaque1()>=j->getPtVieHeros())     ///Si l'attaque du héros est supérieure ou égale aux points de vie du héros du joueur attaqué
        {
            j->setPtVie(j->getPtVie()-(h->getAttaque1()-j->getPtVieHeros()));       ///On retire aux ptv du joueur le supplément de dégats
            j->setPtvieHeros(0);        ///On met les ptv du héros à 0
            j->setHerosEnJeu(false);        ///L'adversaire n'a donc plus de héros sur le terrain
            //j->destructionHeros();
        }
        else        ///Sinon on retire simplement à la vie du héros adverse les dégats de l'attaque
        {
            j->setPtvieHeros(j->getPtVieHeros()-h->getAttaque1());
        }
        h->setPtEnergie(-1);        ///On lui retire le coût de son attaque
    }
    else if(h->getPtVie()>0 && h->getPtEnergie()>1 && getPtVie()>0)     ///Même chose que précédement sauf que cette fois ci le héros a 2 pts d'énergie ou plus
    {
        do
        {
            std::cout << "Choisir l attaque a effectuer" << std::endl;      ///On demande aux joueurs quelle attaque veut il choisir
            std::cout << "1 Attaque 1" << std::endl;
            std::cout << "2 Attaque 2" << std::endl;
            std::cin >> choix;
        }
        while(choix <1 || choix>2);
        switch(choix)
        {
        case 1:
            std::cout << "Attaque 1 : " << h->getNomAttaque1() << " " << h->getAttaque1() << " degats " << std::endl;
            if(h->getAttaque1()>=j->getPtVieHeros())
            {
                j->setPtVie(j->getPtVie()-(h->getAttaque1()-j->getPtVieHeros()));
                j->setPtvieHeros(0);
                j->setHerosEnJeu(false);
                //j->destructionHeros();
            }
            else
            {
                j->setPtvieHeros(j->getPtVieHeros()-h->getAttaque1());
            }
            h->setPtEnergie(-1);
            break;

        case 2:
            std::cout << "Attaque 2 : " << h->getNomAttaque2() << " " << h->getAttaque2() << " degats " << std::endl;
            if(h->getAttaque2()>=j->getPtVieHeros())
            {
                j->setPtVie(j->getPtVie()-(h->getAttaque2()-j->getPtVieHeros()));
                j->setPtvieHeros(0);
                j->setHerosEnJeu(false);
                //j->destructionHeros();
            }
            else
            {
                j->setPtvieHeros(j->getPtVieHeros()-h->getAttaque2());
            }
            h->setPtEnergie(-2);
            break;
        }
    }
    else    ///Boucle si aucune des conditions n'est remplie
    {
       if(getPtVie()<=0)
       {
           std::cout << "Le joueur n a plus de points de vie il ne peut pas attaquer" << std::endl;
       }
       else if(h->getPtEnergie()==0)
       {
           std::cout << "Le heros n a pas assez de points d energies il ne peut pas attaquer" << std::endl;
       }
       else if(h->getPtVie()<=0)
       {
           std::cout << "Le heros n a plus de points de vie il ne peut pas attaquer" << std::endl;
       }
    }
    std::cout << "Points de vie de l ennemi : " << j->getPtVieHeros() << std::endl;
    std::cout << "Points de vie du joueur adverse : " << j->getPtVie() << std::endl;
}
