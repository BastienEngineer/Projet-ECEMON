#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include "Classes.h"

enum Color
{
    COLOR_BLACK = 0,
    COLOR_WHITE = 1,
    COLOR_RED = 2,
    COLOR_GREEN = 3,
    COLOR_BLUE = 4,
    COLOR_YELLOW = 5,
    COLOR_PURPLE = 6,
    COLOR_DEFAULT = 7, // gris couleur de base de la console
};

class Console
{
    private:
        // Empecher la cr�ation
        Console();
        ~Console();

        // Empecher la copie d'objet...
        Console& operator= (const Console&){ return *this;}
        Console (const Console&){}

        // Attributs
        static Console* m_instance;

        // M�thodes priv�es
        void _setColor(int front, int back);
    public:
        // M�thodes statiques (publiques)
        static Console* getInstance();
        static void deleteInstance();

        // M�thodes publiques
        void gotoLigCol(int lig, int col);
        bool isKeyboardPressed();
        int getInputKey();
        void setColor(Color col);
};

#endif // CONSOLE_H_INCLUDED
