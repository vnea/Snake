#include <windows.h>
#include <iostream>
#include "stdlib.h"
#include <stdio.h>
#include <conio.h>

using namespace std;

#include "../include/Menu.h"
#include "../outils.h"
#include "../global.h"


Menu::Menu()
{}

Menu::~Menu()
{}

int Menu::run() const
{
    system("cls");
    int choix ,y;
    bool finChoix;
    const int POS_TITRE = (LARGEUR - strlen("+----SNAKE----+")) / 2;
    gotoxy(POS_TITRE - 1, 5);
    cout << "+----SNAKE----+";

    gotoxy(POS_TITRE + strlen("Mode 1J")/2, 13);
    cout << "Mode 1J";

    gotoxy(POS_TITRE + strlen("Mode 2J")/2, 15);
    cout << "Mode 2J";

    gotoxy(POS_TITRE + strlen("Quitter")/2, 17);
    cout << "Quitter";

    choix = 1;
    y = 13;
    gotoxy(POS_TITRE - 1, y);
    cout << "-->";

    finChoix = false;

    while (!finChoix)
    {
        while (kbhit())
        {
            char codeTouche = getch();
            fflush(stdin);

            switch(codeTouche)
            {
                // Pour le haut
                case 72 :
                {
                    gotoxy(POS_TITRE - 1, y);
                    cout << "   ";
                    y -=2;
                    choix--;

                    if (choix < 1)
                    {
                        choix = 3;
                        y = 17;
                    }

                    gotoxy(POS_TITRE - 1, y);
                    cout << "-->";
                }
                break;

                // Pour le bas
                case 80 :
                {

                    gotoxy(POS_TITRE - 1, y);
                    cout << "   ";
                    choix++;
                    y += 2;
                    if (choix > 3)
                    {
                         choix = 1;
                         y = 13;
                    }

                    gotoxy(POS_TITRE - 1, y);
                    cout << "-->";

                }
                break;

                // Touche Entree
                case 13 :
                {
                    finChoix = true;
                }
                break;

                default:
                    break;
            }
        }
    }
    return choix;
}
