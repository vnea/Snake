#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "../include/Pomme.h"
#include "../outils.h"
#include "../global.h"

Pomme::Pomme()
{}

Pomme::~Pomme()
{}

void Pomme::dessiner() const
{
    gotoxy(_posX, _posY);
    textcolor(10);
    cout << (char)254 << flush;
    textcolor(7);
}

void Pomme::effacer() const
{
    gotoxy(_posX, _posY);
    cout << ' ' << flush;
}

void Pomme::posAlea(const Serpent &s)
{
    int posAleaX, posAleaY;
    bool posCorrecte;

    posCorrecte = false;

    while (!posCorrecte)
    {
        posAleaX = rand() % LARGEUR;
        posAleaY = rand() % HAUTEUR;

        for (int i = 0; i < s.getTaille(); i++)
        {
            posCorrecte = (posAleaX != s.getCoodX(i) || posAleaY != s.getCoodY(i));

            if (!posCorrecte)
                break;
        }
    }

    _posX = posAleaX;
    _posY = posAleaY;
}

void Pomme::posAlea(const Serpent &s1, const Serpent &s2)
{
    int posAleaX, posAleaY;
    bool posCorrecte;

    posCorrecte = false;

    while (!posCorrecte)
    {
        posAleaX = rand() % LARGEUR;
        posAleaY = rand() % HAUTEUR;

        for (int i = 0; i < s1.getTaille(); i++)
        {
            posCorrecte = (posAleaX != s1.getCoodX(i) || posAleaY != s1.getCoodY(i));

            if (!posCorrecte)
                break;
        }

        for (int i = 0; i < s2.getTaille(); i++)
        {
            posCorrecte = (posAleaX != s2.getCoodX(i) || posAleaY != s2.getCoodY(i));

            if (!posCorrecte)
                break;
        }
    }

    _posX = posAleaX;
    _posY = posAleaY;
}
