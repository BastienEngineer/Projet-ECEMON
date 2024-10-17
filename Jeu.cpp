#include "Classes.h"

///Fonction qui permet de séparer la ligne (string) récupérée dans le fichier Deck.txt en deux strings
void decoupage(std::string chaine, std::string& nom, std::string& categorie)
{
    bool c=false;
    nom="";
    categorie="";
    for(unsigned int i=0;i<chaine.size();i++)
    {
        if(chaine[i]!=' ' && c==false)
        {
            nom+=chaine[i];
        }
        else if(chaine[i]==' ')
        {
            c=true;
        }
        else if(chaine[i]!=' ' && c==true)
        {
            categorie+=chaine[i];
        }
    }
}

// Regle du jeu
void RegleJeu()
{
    int c=0;
    std::cout << "Regles du jeu : " << std::endl;
    std::cout << std::endl;
    Sleep(100);
    std::cout << "Le jeu est une bataille entre 2 joueurs." << std::endl;
    Sleep(100);
    std::cout << "Choisit tes cartes depuis l inventaire pour remplir ton deck." << std::endl;
    Sleep(100);
    std::cout << "Il y a 3 types de cartes : Heros, Energies et Speciales." << std::endl;
    Sleep(100);
    std::cout << "Les cartes Energies permettent de gagner des points d energies pour que le heros attaque." << std::endl;
    Sleep(100);
    std::cout << "Chaque tour on pioche une carte. On peut soit la jeter soit la poser (jouer)." << std::endl;
    Sleep(100);
    std::cout << "Le but est de battre l adversaire en attaquant a l aide des heros." << std::endl;
    Sleep(100);
    std::cout << "Si le joueur n a plus de point de vie ou plus de cartes Heros alors il a perdu." << std::endl;
    Sleep(100);
    std::cout << std::endl;
    std::cout << "1 Retour menu" << std::endl;
    std::cin >> c;
    system("cls");
    switch(c)
    {
        case 1:
            menu();
            break;

        default: RegleJeu();
    }
}

// Acheter Une carte
void Boutique()
{
    int choix=0;
    std::cout << "Quel joueur qui veut acheter des cartes(1 ou 2) ? " << std::endl;
            do{
            std::cin >> choix;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }while(choix<1 || choix>2);
            if(choix==1)
            {
            std::ifstream f("Collection1.txt");
            std::ofstream f1("Collection1.txt",std::ios::app);
            std::string mot,w,type;
            if(!f.is_open() && !f1.is_open())
            {
                std::cout << "Erreur d ouverture du fichier" << std::endl;
            }
            else
            {
                while(std::getline(f,mot))
                {
                    std::cout << mot << std::endl;
                    Sleep(50);
                }
                    std::cout <<"Quelle carte voulez vous acheter (type) ? "<<std::endl;
                   do{
                    std::cin >> type;
                    }while(type!="Heros" && type!="Energies" && type!="Speciales"); // Choisit Uniquement ces types
                    do{
                    std::cin >> w;
                    } while (w!="Saranos" && w!="Dragotor" && w!="Mirmir" && w!="Dalnarma" && w!="Halddis" && w!="Valanto" && w!="Grishnarz" && w!="Gonlor" && w!="STUN" && w!="UP_ATK" && w!="INVINCIBILITY"&& w!="UP_DEF" && w!="DOWN_DEF" && w!="God1" && w!="God2" && w!="Hunter1" && w!="Hunter2" && w!="COMEBACK" && w!="Demon1" && w!="Demon2" && w!="Assassin1" && w!="Assassin2" );
                    // Choisit Uniquement ces cartes Heros
                    f1 << std::endl << w << " " << type;
                f.close();
                f1.close();
            }

            }
            if(choix==2)
            {
            std::ifstream f("Collection2.txt");
            std::ofstream f1("Collection2.txt",std::ios::app);
            std::string mot,w,type;
            if(!f.is_open() && !f1.is_open())
            {
                std::cout << "Erreur d ouverture du fichier" << std::endl;
            }
            else
            {
                while(std::getline(f,mot))
                {
                    std::cout << mot << std::endl;
                    Sleep(50);
                }
                    std::cout <<"Quelle carte voulez vous acheter (type) ? "<<std::endl;
                   do{
                    std::cin >> type;
                    }while(type!="Heros" && type!="Energies" && type!="Speciales"); // Choisit Uniquement ces types
                    std::cout <<"Quelle carte voulez vous acheter (nom) ? "<<std::endl;
                    do{
                    std::cin >> w;
                    } while (w!="Saranos" && w!="Dragotor" && w!="Mirmir" && w!="Dalnarma" && w!="Halddis" && w!="Valanto" && w!="Grishnarz" && w!="Gonlor" && w!="STUN" && w!="UP_ATK" && w!="INVINCIBILITY"&& w!="UP_DEF" && w!="DOWN_DEF" && w!="God1" && w!="God2" && w!="Hunter1" && w!="Hunter2" && w!="COMEBACK" && w!="Demon1" && w!="Demon2" && w!="Assassin1" && w!="Assassin2" );
                    // Choisit Uniquement ces cartes Heros
                    f1 << std::endl << w << " " << type;
                f.close();
                f1.close();
            }

            }

}

// Menu pour choisir d'acheter une carte ou retourner au menu
void AcheterCartes()
{
    int c=0;
    Boutique();
    std::cout << std::endl;
    std::cout << "1 Retour menu" << std::endl;
    std::cout << "2 Acheter une carte" << std::endl;
    std::cin >> c;
    system("cls");
    switch(c)
    {
        case 1:
            menu();
            break;
        case 2:
        {
            Boutique();
            AcheterCartes();
            break;
        }
        default: menu();
    }
}

// Affiche collection d'un des 2 Joueurs
void CollectionCartesJoueurs()
{
    int c=0,choix=0;
    std::cout << "Quel joueur pour montrer sa collection de Cartes (1 ou 2) ? " << std::endl;
        do{
        std::cin >> choix;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(choix<1 || choix>2);
        if(choix==1)
        {
            std::ifstream f("Collection1.txt");
            std::string mot;
            if(!f.is_open())
            {
                std::cout << "Erreur d ouverture du fichier" << std::endl;
            }
            else
            {
                while(std::getline(f,mot))
                {
                    std::cout << mot << std::endl;
                    Sleep(50);
                }
                f.close();
            }

        }
        if(choix==2)
        {
            std::ifstream f("Collection2.txt");
            std::string mot;
            if(!f.is_open())
            {
                std::cout << "Erreur d ouverture du fichier" << std::endl;
            }
            else
            {
                while(std::getline(f,mot))
                {
                    std::cout << mot << std::endl;
                    Sleep(50);
                }
                f.close();
            }
        }
    std::cout << "1 Retour menu" << std::endl;
    std::cin >> c;
    system("cls");
    switch(c)
    {
        case 1:
            menu();
            break;
        default: CollectionCartesJoueurs();
    }
}

// Montre le fichier Sauvegarde.txt
void Sauvegarde(int nb)
{
    int c=0;
    std::ifstream f("Sauvegarde.txt");
    std::string mot;
    if(!f.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        while(std::getline(f,mot))
        {
            std::cout << mot << std::endl;
        }
        f.close();
    }
    system("pause");
    system("cls");
    std::cout << "1 Retour menu" << std::endl;
    std::cout << "2 Jouer la Sauvegarde" << std::endl;
    std::cin >> c;
    system("cls");
    switch(c)
    {
        case 1:
            menu();
            break;
        case 2:
            PartieS(nb);
            break;

        default: Sauvegarde(nb);
    }
}

void descriptionDesCartes()
{
    int c=0;
    std::cout << "VOUS TOUVEREZ ICI LA DESCRIPTION DES DIFFERENTES CARTES QUI COMPOSENT LE JEU ECEMON." << std::endl;
    std::cout << std::endl;
    std::cout << "LES HEROS : " << std::endl;
    std::cout << std::endl;
    std::cout << "Saranos type hunter" << std::endl;
    std::cout << "Dragotor type hunter" << std::endl;
    std::cout << "Mirmir type god" << std::endl;
    std::cout << "Dalnarma type god" << std::endl;
    std::cout << "Halddis type demon" << std::endl;
    std::cout << "Valanto type demon" << std::endl;
    std::cout << "Grishnarz type assassin" << std::endl;
    std::cout << "Gonlor type assassin" << std::endl;
    std::cout << std::endl;
    std::cout << "LES ENERGIES : " << std::endl;
    std::cout << std::endl;
    std::cout << "Hunter1 donne 1 pt d energie aux heros de type hunter" << std::endl;
    std::cout << "Hunter2 donne 2 pts d energie aux heros de type hunter" << std::endl;
    std::cout << "God1 donne 1 pt d energie aux heros de type god" << std::endl;
    std::cout << "God2 donne 2 pts d energie aux heros de type god" << std::endl;
    std::cout << "Demon1 donne 1 pt d energie aux heros de type demon" << std::endl;
    std::cout << "Demon2 donne 2 pts d energie aux heros de type demon" << std::endl;
    std::cout << "Assassin1 donne 1 pt d energie aux heros de type assassin" << std::endl;
    std::cout << "Assassin2 donne 2 pts d energie aux heros de type assassin" << std::endl;
    std::cout << std::endl;
    std::cout << "LES SPECIALES : " << std::endl;
    std::cout << std::endl;
    std::cout << "UP_ATK augmente l attaque du heros actif jusqu a sa mort" << std::endl;
    std::cout << "UP_DEF augmente les points de vie du heros actif" << std::endl;
    std::cout << "DOWN_DEF diminue les points de vie du heros adverse" << std::endl;
    std::cout << "INVINCIBILITY le heros actif ne peut pas etre attaque durant un tour" << std::endl;
    std::cout << "STUN le heros adverse est paralyse durant un tour" << std::endl;
    std::cout << "COMEBACK le joueur reprend un heros de son cimetiere" << std::endl;
    std::cout << std::endl;
    std::cout << "1 Retour menu" << std::endl;
    std::cin >> c;
    system("cls");
    switch(c)
    {
        case 1:
            menu();
            break;

        default: descriptionDesCartes();
    }
}

// Pour choisir et sauvegarder les cartes de chaque joueur
void Init(int nbJoueurs)
{
    Plateau *e=new Plateau();  // Déclare un nouveau Plateau
	Joueur *j1=new Joueur();   // Déclare 2 Joueurs
	Joueur *j2=new Joueur();
    std::ifstream f1("Collection1.txt");
    std::ifstream f2("Collection2.txt");
    std::ofstream file("Sauvegarde.txt", std::ios::trunc);
    file.clear();
    remplissageplateau(nbJoueurs,e,j1,j2);
    system("pause");
	system("cls");
    std::string m;
    std::string q;

    for(int i=0; i<nbJoueurs; i++)
    {
        e->AffichagePlateauPerso(i);
        if(i==0)
        {
            // Joueur 1
            SauvegardeJoueurs(j1); // Sauvegarde Nom Joueur
            AfficheCartesCollection(f1); // Affiche la collection de cartes du joueur 1
            std::cout << "Chaque joueur doit choisir 15 cartes pour constituer son deck" << std::endl;
            std::cout << std::endl;
            for(int j=0; j<15; j++) // Choisit 15 cartes
            {
                std::ifstream f3("Collection1.txt");
                Choisit_Et_RechercheCartes(f3); // Rechercher la carte que l'on veut
            }
            std::cout << std::endl;
            std::ifstream fichier1("Sauvegarde.txt");
            std::string mot;
            std::string nom;
            int i=0;
            std::string categorie;
            if(!fichier1.is_open())
            {
                std::cout << "Erreur d ouverture du fichier" << std::endl;
            }
            else
            {
                std::cout << std::endl;
                while(std::getline(fichier1,mot))
                {
                    if(i != 0 ) // Ne lis pas la ligne 0
                    {
                        std::cout << mot << std::endl; // Affiche la carte depuis le fichier
                        decoupage(mot,nom,categorie);
                        Cartes *c=new Cartes(nom,categorie); // Creer Cartes
                        j1->ajouterAuDeck(c); // Ajoute la carte au deck
                    }
                    i++;
                }
                std::cout << std::endl;
                fichier1.close();
            }
            j1->melangerCartesJoueurs(); // melange les cartes du Joueur
            std::cout << "Deck melange " << std::endl;
            j1->affichageDeckJoueur(); // Affiche le Deck mélangé du Joueur
            system("pause");
            system("cls");
        }
        else if(i==1)
        {
            // Joueur 2
            SauvegardeJoueurs(j2); // Sauvegarde Nom Joueur
            AfficheCartesCollection(f2); // Affiche la collection de cartes du joueur 2
            std::cout << "Chaque joueur doit choisir 15 cartes pour constituer son deck" << std::endl;
            std::cout << std::endl;
            for(int j=0; j<15; j++) // Choisit 15 cartes
            {
                std::ifstream f4("Collection2.txt");
                Choisit_Et_RechercheCartes(f4); // Rechercher la carte que l'on veut
            }
            std::cout << std::endl;
            std::ifstream fichier2("Sauvegarde.txt");
            std::string mot;
            std::string nom;
            std::string categorie;
            int i=0;
            if(!fichier2.is_open())
            {
                std::cout << "Erreur d ouverture du fichier" << std::endl;
            }
            else
            {
                std::cout << std::endl;
                while(std::getline(fichier2,mot))
                {
                    if(i>16) // Ne lis pas la ligne 0 à 16
                    {
                    std::cout << mot << std::endl; // Affiche la carte depuis le fichier
                    decoupage(mot,nom,categorie);
                    Cartes *c=new Cartes(nom,categorie); // Creer Cartes
                    j2->ajouterAuDeck(c); // Ajoute la carte au deck
                    }
                    i++;

                }
                std::cout << std::endl;
                fichier2.close();
            }
            j2->melangerCartesJoueurs(); // melange les cartes du Joueur
            std::cout << "Deck melange " << std::endl;
            j2->affichageDeckJoueur(); // Affiche le Deck mélangé du Joueur
            system("pause");
            system("cls");
        }
    }
    e->MelangeJoueur(); // Mélange l'ordre des joueurs (Joueur qui commence est aléatoire)
    Jouer(nbJoueurs,e);
	system("pause");
	system("cls");
}

