#include "Classes.h"

///Fonction qui permet de revenir au menu ou de commencer la partie une fois que les joueurs ont constitué leur deck
void Jouer(int nbJoueurs, Plateau *p)
{
    int choix=0;
    std::cout << "1 Retour menu" << std::endl;
    std::cout << "2 Jouer la partie" << std::endl;
    std::cin >> choix;
    system("cls");
    switch (choix)
    {
        case 1:
            menu();
            break;
        case 2:
            p->Tour(nbJoueurs);
            p->~Plateau();
            break;
        default:
            Jouer(nbJoueurs,p);
            break;
    }
}

// Récupère les informations pour lancer la sauvegarde
void PartieS(int nb)
{
    Plateau *e=new Plateau(); // On cree un plateau pour jouer la sauvegarde
    std::ifstream f("Sauvegarde.txt");
    std::string mot,mot1,mot2;
    int i=0;
    if(!f.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        while(std::getline(f,mot))
        {
            if(i==0) // à la ligne 0 pour récuperer le joueur 1
                mot1=mot;

            if(i==16) // à la ligne 16 pour récuperer le joueur 2
                mot2=mot;
            i++;
        }
        f.close();

    }
if(mot1.find( "Joueur :" ) != std::string::npos) // Efface le mot "Joueur :" pour n'avoir que le prenom du joueur 1
   {  mot1.erase(0,8); }
if(mot2.find( "Joueur :" ) != std::string::npos) // Efface le mot "Joueur :" pour n'avoir que le prenom du joueur 2
   {  mot2.erase(0,8); }

    Joueur *j1=new Joueur(mot1,0); // Crée le joueur 1 en récuperant le nom du joueur du fichier
    e->AjouterJoueur(j1); // on l'ajoute au plateau (dans le vector)
    Joueur *j2=new Joueur(mot2,1); // Crée le joueur 2 en récuperant le nom du joueur du fichier
    e->AjouterJoueur(j2); // on l'ajoute au plateau (dans le vector)

    for(int i=0; i<nb; i++)
    {
        e->AffichagePlateauPerso(i); // Affiche le joueur
        if(i==0)
        {
            //Joueur 1
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
                while(std::getline(fichier1,mot))
                {
                    if(i!=0 && i<16) // Recupère la carte entre la ligne 1 et 15
                    {
                        std::cout << mot << std::endl;
                        decoupage(mot,nom,categorie);
                        Cartes *c=new Cartes(nom,categorie); // Crée la carte par le nom et le type depuis le fichier
                        j1->ajouterAuDeck(c); // On l'ajoute au deck
                    }
                    i++;
                }
                std::cout << std::endl;
                fichier1.close();
            }
            j1->melangerCartesJoueurs(); // Mélange l'ordre des cartes dans le deck
            j1->affichageDeckJoueur();
            system("pause");
            system("cls");
        }
        else if(i==1)
        {
            // Joueur 2
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
                while(std::getline(fichier2,mot))
                {
                    if(i>16) // Recupère la carte après la ligne 16
                    {
                    std::cout << mot << std::endl;
                    decoupage(mot,nom,categorie);
                    Cartes *c=new Cartes(nom,categorie); // Crée la carte par le nom et le type depuis le fichier
                    j2->ajouterAuDeck(c); // On l'ajoute au deck
                    }
                    i++;

                }
                std::cout << std::endl;
                fichier2.close();
            }
            j2->melangerCartesJoueurs(); // Mélange l'ordre des cartes dans le deck
            j2->affichageDeckJoueur();
            system("pause");
            system("cls");
        }
    }
    e->MelangeJoueur(); // Mélange l'ordre des Joueurs (vector)
    Jouer(nb,e); // Joue la sauvegarde
	system("pause");
	system("cls");
}

// Affiche La Collection du Joueur à l'aide d'un fichier
void AfficheCartesCollection(std::ifstream& fichier1)
{
    std::string mot;
    if(!fichier1.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        std::cout << "Inventaire des cartes disponibles : " << std::endl;
        std::cout << std::endl;
        while(std::getline(fichier1,mot))
        {
            std::cout << mot << std::endl;
            Sleep(50);
        }
        std::cout << std::endl;
        fichier1.close();
    }
}

// Saisit une carte et on recherche depuis le fichier si il s'y trouve
void Choisit_Et_RechercheCartes(std::ifstream& fichier3)
{
    std::string w;
    std::string type;
    std::string m;
    if(!fichier3.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        std::cout << "Saisir le nom de la carte a ajouter dans votre deck" << std::endl;
        do
        {
           std::cin >> w;
        } while (w!="Saranos" && w!="Dragotor" && w!="Mirmir" && w!="Dalnarma" && w!="Halddis" && w!="Valanto" && w!="Grishnarz" && w!="Gonlor" && w!="STUN" && w!="UP_ATK" && w!="INVINCIBILITY"&& w!="UP_DEF" && w!="DOWN_DEF" && w!="God1" && w!="God2" && w!="Hunter1" && w!="Hunter2" && w!="COMEBACK" && w!="Demon1" && w!="Demon2" && w!="Assassin1" && w!="Assassin2" );
        // Saisit que ces noms de cartes
        std::cout << "Saisir la categorie de la carte (Heros, Energies ou Speciales) a ajouter dans votre deck : " << std::endl;
        do{
            std::cin >> type;
        }while(type!="Heros" && type!="Energies" && type!="Speciales");
        // Blindage des types de cartes
        while(std::getline(fichier3,m))
        {
            if (m.find(w) != std::string::npos && m.find(type) != std::string::npos) // Trouve le mot dans chaque ligne du fichier
            {
                DeckFichier(w,type); // Ecrit la carte de notre deck dans le fichier
            }
            else
            {
                //std::cout <<" Pas trouve" << std::endl;
            }
        }
        fichier3.close();
    }
}

// Ecrit la carte de notre deck dans le fichier
void DeckFichier(std::string w,std::string t)
{
    std::ofstream fichier2("Sauvegarde.txt",std::ios::app);
    if(!fichier2.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        fichier2 << w << " " << t << std::endl;
        fichier2.close();
    }
}

// Ecrit le nom du joueur
void SauvegardeJoueurs(Joueur *a)
{
    std::ofstream fichier2("Sauvegarde.txt",std::ios::app);
    if(!fichier2.is_open())
    {
        std::cout << "Erreur d ouverture du fichier" << std::endl;
    }
    else
    {
        fichier2 << "Joueur : " << a->getPrenom() << std::endl;
        fichier2.close();
    }
}
