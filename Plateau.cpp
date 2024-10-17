#include "Plateau.h"

Plateau::Plateau()
{

}
Plateau::~Plateau()
{

}

std::vector<Joueur*> Plateau::getlistedejoueur()
{
return listedejoueur;
}

Joueur* Plateau::getjoueur(int nb)
{
return listedejoueur[nb];
}

void Plateau::AjouterJoueur(Joueur *a) ///ajoute un joueur au stockage du plateau
{
    listedejoueur.push_back(a);
}

///fct qui recherche le joueur dans le vecteur et l'affiche
void Plateau::AffichagePlateauPerso(int numerodujoueurdanslevecteur)
{
    listedejoueur[numerodujoueurdanslevecteur]->AfficherJoueur();
}

///On mélange les joueurs pour choisir lequel commence la partie
void Plateau::MelangeJoueur()
{
	std::shuffle(listedejoueur.begin(),listedejoueur.end(),std::default_random_engine());
}

///On affiche la carte piochée par le joueur au début de son tour
void Plateau::piocher(int nb)
{
    std::cout << "Carte piochee : " <<std::endl;
    listedejoueur[nb]->accesDebut();
}

///On supprime la carte du deck car elle a été jouée
void Plateau::Poser(int nb)
{
    listedejoueur[nb]->Supprimer1Carte();
}

///On teste si tous les joueurs sont vivants
bool Plateau::JoueurVivant()
{
    bool a=false;
    for(unsigned int i=0; i<listedejoueur.size(); i++)
    {
        if(listedejoueur[i]->getPtVie()<=0)
        {
            a=true;
        }
        else
        {

        }
    }
    return a;
}

///On test si les joueurs ont au moins un héros soit dans leur deck soit sur le terrain
bool Plateau::listeDeJoueurExistanceHeros()
{
    bool a=false;
    for(unsigned int i=0; i<listedejoueur.size(); i++)
    {
        if(listedejoueur[i]->ExistanceHerosDeck()==0 && listedejoueur[i]->getHerosEnJeu()==0)
        {
            a=true;
        }
        else
        {

        }
    }
    return a;
}

///Sous programme qui pose un héros sur le terrain pour tous les joueurs
void Plateau::PremierTour(int nbJoueurs)
{
    bool b=false;
    std::cout << "Premier tour : chaque joueur pioche automatiquement jusqu a ce qu il trouve un heros puis le joue " << std::endl;
    std::cout << std::endl;
    for(int i=0; i<nbJoueurs; i++)
    {
        listedejoueur[i]->AfficherJoueur();
        std::cout << "Points de vie : " << listedejoueur[i]->getPtVie() << std::endl;
        b=false;
        while(!b)
        {
            if(listedejoueur[i]->ExistanceHerosDeck()==true)        ///S'il existe un héros dans le deck du joueur
            {
                while(listedejoueur[i]->getCategorieDeck(0)!="Heros")       ///On pioche tant qu'on ne trouve pas de héros
                {
                    listedejoueur[i]->deplacerFinDeck();
                }
                b=true;
                piocher(i);     ///On affiche la carte (héros) qu'on vient de piocher
                std::cout << std::endl;
                Heros *h=new Heros(listedejoueur[i]->getNomDeck(0),listedejoueur[i]->getCategorieDeck(0));      ///On crée le héros correspondant
                //listedejoueur[i]->AfficherJoueur();
                //h->affichageHeros();
                listedejoueur[i]->remplissageHeros(h);      ///On donne les caractéristiques aux héros du joueur
                listedejoueur[i]->setHerosEnJeu(true);      ///On a donc un héros sur le terrain
                listedejoueur[i]->Supprimer1Carte();        ///On supprime la carte jouée
            }
            else
            {
                std::cout << "Vous n avez pas de cartes heros dans votre deck vous avez perdu la partie" << std::endl;
                b=true;
                listedejoueur[i]->AfficherJoueur();
            }
        }
    }
}

void Plateau::Tour(int nbJoueurs)
{
    PremierTour(nbJoueurs);
    system("pause");
    system("cls");
    bool quit=false;
    bool active=false;
    bool fin=false;
    bool paralyse1=false;
    bool paralyse2=false;
    bool invincible1=false;
    bool invincible2=false;
    bool atkJoueur1=true;
    bool atkJoueur2=true;       ///Variables pour savoir si le héros du joueur peut attaquer
    int a=0;
    int choix=0;
    while((JoueurVivant()!=1) && (listeDeJoueurExistanceHeros()!=1) && quit!=true)      ///Boucle de jeu qui continue tant que les deux joueurs sont vivants, qu'ils possèdent au moins un héros et tant qu'on ne désire pas sortir du jeu
    {
        for(int i=0; i<nbJoueurs; i++)
        {
            active=false;
            listedejoueur[i]->AfficherJoueur();
            std::cout << "Points de vie : " << listedejoueur[i]->getPtVie() << std::endl;
            if(listedejoueur[i]->getHerosEnJeu()==1)        ///Si le joueur a un héros sur le terrain
            {
                while(!active)
                {
                    while(listedejoueur[i]->getCategorieDeck(0)=="Heros")       ///On pioche tant qu'on trouve une carte héros
                    {
                        listedejoueur[i]->deplacerFinDeck();
                    }
                    piocher(i);
                    std::cout << std::endl;
                    std::cout << "1 Utiliser la carte " << std::endl;
                    std::cout << "2 Jeter la carte " << std::endl;
                    std::cin >> choix;
                    switch (choix)      ///On décide si on souhaite jouer la carte ou non
                    {
                    case 1:
                        active=true;
                        break;
                    case 2:
                        listedejoueur[i]->deplacerFinDeck();
                        break;
                    default:
                        Tour(nbJoueurs);
                        break;
                    }
                    //listedejoueur[i]->affichageDeckJoueur();
                }
                std::cout << std::endl;
                if(listedejoueur[i]->getCategorieDeck(0)=="Energies")       ///Si la carte piochée est une carte énergie
                {
                    Energies e(listedejoueur[i]->getNomDeck(0),listedejoueur[i]->getCategorieDeck(0));
                    listedejoueur[i]->actionEnergies(e);        ///On crée la carte et on l'utilise
                    listedejoueur[i]->deplacerFinDeck();        ///Puis on la replace sous le deck
                }
                else if(listedejoueur[i]->getCategorieDeck(0)=="Speciales")     ///Si la carte piochée est une carte spéciale
                {
                    Speciales s(listedejoueur[i]->getNomDeck(0),listedejoueur[i]->getCategorieDeck(0));     ///On crée la carte
                    std::cout << s.getFonctionnalite() << std::endl;
                    ///En fonction de son nom elle effectue différentes actions
                    if(listedejoueur[i]->getNomDeck(0)=="UP_ATK")
                    {
                        listedejoueur[i]->setAttaque1Heros(30);
                        listedejoueur[i]->setAttaque2Heros(30);
                    }
                    else if(listedejoueur[i]->getNomDeck(0)=="UP_DEF")
                    {
                        listedejoueur[i]->setPtvieHeros(listedejoueur[i]->getPtVieHeros()+50);
                    }
                    else if(listedejoueur[i]->getNomDeck(0)=="INVINCIBILITY")
                    {
                        if(i==0)
                        {
                            invincible1=true;           ///Le héros est invincible pendant un tour
                        }
                        else if(i==1)
                        {
                            invincible2=true;
                        }
                    }
                    else if(listedejoueur[i]->getNomDeck(0)=="COMEBACK")
                    {
                        ///A voir
                    }
                    else if(listedejoueur[i]->getNomDeck(0)=="STUN")
                    {
                        if(i==0)
                        {
                            paralyse2=true;       ///Le héros ne peut pas attaquer (il est paralysé pour un tour)
                        }
                        else if(i==1)
                        {
                            paralyse1=true;
                        }
                    }
                    else if(listedejoueur[i]->getNomDeck(0)=="DOWN_DEF")
                    {
                        if(i==0)
                        {
                            if(30>=listedejoueur[i+1]->getPtVieHeros())
                            {
                                listedejoueur[i+1]->setPtVie(listedejoueur[i+1]->getPtVie()-(30-listedejoueur[i+1]->getPtVieHeros()));
                                listedejoueur[i+1]->setPtvieHeros(0);
                                listedejoueur[i+1]->setHerosEnJeu(false);
                            }
                            else
                            {
                                listedejoueur[i+1]->setPtvieHeros(listedejoueur[i+1]->getPtVieHeros()-30);
                            }
                        }
                        else if(i==1)
                        {
                            if(30>=listedejoueur[i-1]->getPtVieHeros())
                            {
                                listedejoueur[i-1]->setPtVie(listedejoueur[i-1]->getPtVie()-(30-listedejoueur[i-1]->getPtVieHeros()));
                                listedejoueur[i-1]->setPtvieHeros(0);
                                listedejoueur[i-1]->setHerosEnJeu(false);
                            }
                            else
                            {
                                listedejoueur[i-1]->setPtvieHeros(listedejoueur[i-1]->getPtVieHeros()-30);
                            }
                        }
                    }
                    listedejoueur[i]->Supprimer1Carte();
                }
                else
                {

                }
                system("pause");
            }

            else if(listedejoueur[i]->getHerosEnJeu()==0 && listedejoueur[i]->ExistanceHerosDeck()==1)       ///Si le joueur n'a pas de héros posé alors il pioche et pose le premier qu'il trouve
            {
                while(listedejoueur[i]->getCategorieDeck(0)!="Heros")
                {
                    listedejoueur[i]->deplacerFinDeck();
                }
                piocher(i);
                std::cout << std::endl;
                Heros *h=new Heros(listedejoueur[i]->getNomDeck(0),listedejoueur[i]->getCategorieDeck(0));
                listedejoueur[i]->remplissageHeros(h);
                listedejoueur[i]->setHerosEnJeu(true);
                listedejoueur[i]->Supprimer1Carte();
            }

            else
            {
                if(i==0)
                {
                    atkJoueur1=false;
                }
                else if(i==1)
                {
                    atkJoueur2=false;
                }
            }

            if(i==0)
            {
                if(atkJoueur1==true && paralyse1==false && invincible2==false)
                {
                    listedejoueur[i]->attaquerJoueur(listedejoueur[i+1]);
                }
                else
                {
                    if(atkJoueur1==false)
                    {
                        std::cout << "Le joueur n a plus de carte heros" << std::endl;
                    }
                    else if(paralyse1==true)
                    {
                        std::cout << "Le heros actif est paralyse il ne peut pas attaquer" << std::endl;
                        paralyse1=false;
                    }
                    else if(invincible2==true)
                    {
                        std::cout << "Le heros adverse est invincible durant ce tour votre heros ne peut pas attaquer" << std::endl;
                        invincible2=false;
                    }
                }
            }
            else if(i==1)
            {
                if(atkJoueur2==true && paralyse2==false && invincible1==false)
                {
                    listedejoueur[i]->attaquerJoueur(listedejoueur[i-1]);
                }
                else
                {
                    if(atkJoueur2==false)
                    {
                        std::cout << "Le joueur n a plus de carte heros" << std::endl;
                    }
                    else if(paralyse2==true)
                    {
                        std::cout << "Le heros actif est paralyse il ne peut pas attaquer" << std::endl;
                        paralyse2=false;
                    }
                    else if(invincible1==true)
                    {
                        std::cout << "Le heros adverse est invincible durant ce tour votre heros ne peut pas attaquer" << std::endl;
                        invincible1=false;
                    }
                }
            }
            else
            {

            }
            system("pause");
            system("cls");
        }
        if((JoueurVivant()==1) || (listeDeJoueurExistanceHeros()==1))
        {
            fin=true;
        }
        else
        {

        }
        if(fin!=1)
        {
            do
            {
                std::cout << "Saisir 1 pour quitter le jeu et 2 pour continuer " << std::endl;
                std::cin >> a;
                if(a==1)
                {
                    quit=true;
                }
                else
                {

                }
            }
            while(a<1 || a>2);
        }
        else
        {

        }
        system("pause");
        system("cls");
    }
    if(quit==true)
    {
        std::cout << "Vous avez quitte la partie en cours" << std::endl;
    }
    else if(JoueurVivant()==1)
    {
        for(int i=0; i<nbJoueurs; i++)
        {
            if(listedejoueur[i]->getPtVie()<=0)
            {
                if(i==0)
                {
                    std::cout << listedejoueur[i]->getPrenom() << " n a plus de points de vie" << std::endl;
                    std::cout << listedejoueur[i+1]->getPrenom() << " a gagne le combat" << std::endl;
                }
                else if(i==1)
                {
                    std::cout << listedejoueur[i]->getPrenom() << " n a plus de points de vie" << std::endl;
                    std::cout << listedejoueur[i-1]->getPrenom() << " a gagne le combat" << std::endl;
                }
                else
                {

                }
            }
        }
    }
    else if(listeDeJoueurExistanceHeros()==1)
    {
        for(int i=0; i<nbJoueurs; i++)
        {
            if(listedejoueur[i]->ExistanceHerosDeck()==0 && listedejoueur[i]->getHerosEnJeu()==0)
            {
                std::cout << listedejoueur[i]->getPrenom() << " n a plus de carte heros disponible" << std::endl;
                if(i==0)
                {
                    std::cout << listedejoueur[i+1]->getPrenom() << " a gagne le combat" << std::endl;
                }
                else if(i==1)
                {
                    std::cout << listedejoueur[i-1]->getPrenom() << " a gagne le combat" << std::endl;
                }
                else
                {

                }
            }
        }
    }
}
