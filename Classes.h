#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <random>
#include <algorithm>
#include "Cartes.h"
#include "Deck.h"
#include "Joueur.h"
#include "Plateau.h"
#include "console.h"

class Cartes;
class Heros;
class Energies;
class Speciales;
class Deck;
class Plateau;
class Joueur;
class Console;

void lancerToutAllegro(int largeur, int hauteur);
void menu();
void remplissageplateau(int nbjoueur,Plateau *g,Joueur *j1,Joueur *j2);
int entrerdelavaleurchoix();
void CollectionCartesJoueurs();
void Boutique();
void Sauvegarde(int nb);
void PartieS(int nb);
void RegleJeu();
void descriptionDesCartes();
void AcheterCartes();
void Init(int nbJoueurs);
void Jouer(int nbJoueurs, Plateau *p);
void decoupage(std::string chaine, std::string& nom, std::string& categorie);

void AfficheCartesCollection(std::ifstream& fichier1);
void DeckFichier(std::string w,std::string t);
void Choisit_Et_RechercheCartes(std::ifstream& fichier3);
void SauvegardeJoueurs(Joueur *a);


#endif // CLASSES_H_INCLUDED
