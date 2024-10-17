#include "Classes.h"

void remplissageplateau(int nbjoueur,Plateau *g,Joueur *j1,Joueur *j2)
{
    for(int i=1;i<=nbjoueur;i++){
        // Pour chaque Joueur dans un vector on remplit son nom
            switch(i)
            {
            case 1 : {g->AjouterJoueur(j1);
            g->getjoueur(i-1)->remplissagejoueur();
                break;}
            case 2 : {g->AjouterJoueur(j2);
            g->getjoueur(i-1)->remplissagejoueur();
                break;}
            }
    }
    for(unsigned int j=0;j<g->getlistedejoueur().size();j++)    //test sert à afficher tout les joueurs
   	{
   	    g->getjoueur(j)->AfficherJoueur();
    }
}

int entrerdelavaleurchoix()
{
    int choix;
    std::cout << "**********************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "********* ********* ******** ********* ********* **      *" << std::endl;
    std::cout << "*         *         *        *   *   * *       * * *     *" << std::endl;
    std::cout << "*         *         *        *   *   * *       * *  *    *" << std::endl;
    std::cout << "*****     *         *****    *   *   * *       * *   *   *" << std::endl;
    std::cout << "*         *         *        *       * *       * *    *  *" << std::endl;
    std::cout << "*         *         *        *       * *       * *     * *" << std::endl;
    std::cout << "********* ********* ******** *       * ********* *      **" << std::endl;
    std::cout << "**********************************************************" << std::endl;
    std::cout << std::endl;
    std::cout <<"B";Sleep(50);std::cout <<"I";Sleep(50);std::cout <<"E";Sleep(50);std::cout <<"N";Sleep(50);std::cout <<"V";Sleep(50);std::cout <<"E";Sleep(50);std::cout <<"N";Sleep(50);std::cout <<"U";Sleep(50);std::cout <<"E"<<std::endl;Sleep(50);
    std::cout << "CHOISSISSEZ UNE OPTION DU MENU" << std::endl;
    std::cout << std::endl;
    std::cout<<"1 NOUVELLE PARTIE"<< std::endl;
    Sleep(50);
    std::cout<<"2 COLLECTION DES JOUEURS"<< std::endl;
    Sleep(50);
    std::cout<<"3 PARTIE SAUVEGARDEE"<< std::endl;
    Sleep(50);
    std::cout<<"4 ACHETER DES CARTES"<<std::endl;
    Sleep(50);
    std::cout<<"5 REGLES DU JEU"<<std::endl;
    Sleep(50);
    std::cout<<"6 DESCRIPTION DES CARTES DU JEU"<<std::endl;
    Sleep(50);
    std::cout<<"7 QUITTER"<<std::endl;
    std::cin >> choix;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    system("cls");
    return choix;
}
/*
void lancerToutAllegro(int largeur, int hauteur)
{
    allegro_init();
    install_keyboard();
    install_mouse();

    /// OUVERTURE MODE GRAPHIQUE (ouverture fenêtre allegro)
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
}

*/
void menu()
{
    //lancerToutAllegro(800,600);
    //BITMAP *p=load_bitmap("natsu.bmp",NULL);;
    //show_mouse(screen);
    int choix=-1;
    int nb=2; // 2 Joueurs

	do{choix=entrerdelavaleurchoix();}while(choix <1 || choix>7);   //Menu
	switch (choix)
	{
	case 1:
	{
		Init(nb);
        system("pause");
		system("cls");
        std::cout << "FIN DE PARTIE " << std::endl;
		break;
	}
        case 2:
            CollectionCartesJoueurs();
            break;
        case 3:
            Sauvegarde(nb);
            break;
        case 4:
            AcheterCartes();
            break;
        case 5:
            RegleJeu();
            break;
        case 6:
            descriptionDesCartes();
            break;

        case 7:
            system("exit");
            break;

        default: menu();

    }
}

int main()
{
    menu();
    return 0;
}


