#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "../include/Jeu.h"
#include "../outils.h"
#include "../global.h"

Jeu::Jeu()
{
    srand(time(NULL));
    init();
     Serpent s1, s2;
    _serpents.push_back(s1);
    _serpents.push_back(s2);
}

Jeu::~Jeu()
{}

void Jeu::init()
{
    // On désactive le curseur de la console
    ShowCursor(false);
    system("title Snake");
    system("mode con LINES=32 COLS=60");
}

void Jeu::run()
{
    switch(_menu.run())
    {
        case 1 :
            _mode1J();
        break;

        case 2 :
            _mode2J();
        break;

        case 3 :
            system("cls");
        break;

        default :
        break;
    }
}

void Jeu::_afficherBarreBas() const
{
    for (int i = 0; i < LARGEUR; i++)
    {
        gotoxy(i, HAUTEUR);
        cout << '-';
    }
}

void Jeu::_mode1J()
{
    system("cls");

    bool finJeu;
    _afficherBarreBas();
    gotoxy(1, 31);
    cout << "Score : ";
    cout << _serpents[0].getScore();
    _pomme.posAlea(_serpents[0]);
    _pomme.dessiner();
    finJeu = false;

    while(!finJeu)
    {
        // On presse une touche qui déplace le serpent -> MAJ des cood du serpent
        _serpents[0].seDeplacerAvecFleches();

        _serpents[0].dessiner(14);

        if (_serpents[0].mangePomme(_pomme))
        {
            _serpents[0].ajouterQueue();
            _serpents[0].augmenterVitesse();
            _pomme.effacer();
            _pomme.posAlea(_serpents[0]);
            _pomme.dessiner();

            _serpents[0].augmenterScore();
            gotoxy(1, 31);
            cout << "Score : ";
            cout << _serpents[0].getScore();;
        }

        finJeu = _serpents[0].seCogne();
    }

    system("cls");
    cout << "Score : " << _serpents[0].getScore() << endl;
    system("pause");
}

void Jeu::_mode2J()
{
    system("cls");

    bool finJeu, j1Perdu, j2Perdu;
    _afficherBarreBas();

    gotoxy(1, 31);
    textcolor(14);
    cout << "Score : ";
    cout << _serpents[0].getScore();

    textcolor(11);
    gotoxy(45, 31);
    cout << "Score : ";
    cout << _serpents[1].getScore();



    _serpents[0].setDx(0);
    _serpents[0].setDy(1);
    _serpents[1].setDx(0);
    _serpents[1].setDy(1);
    _serpents[0].setDirection(BAS);
    _serpents[1].setDirection(BAS);
    _serpents[0].setPosition(10, 10);
    _serpents[1].setPosition(50, 10);

    _pomme.posAlea(_serpents[0], _serpents[1]);
    _pomme.dessiner();

    finJeu = j1Perdu = j2Perdu = false;

    while (!finJeu)
    {
        // On presse une touche qui déplace le serpent -> MAJ des cood du serpent
        _serpents[0].seDeplacerAvecLettres();
        _serpents[1].seDeplacerAvecFleches();

        _serpents[0].dessiner(14);
        _serpents[1].dessiner(11);

        gotoxy(30, 31);

        if (_serpents[0].mangePomme(_pomme))
        {
            _serpents[0].ajouterQueue();
            _pomme.effacer();
            _pomme.posAlea(_serpents[0], _serpents[1]);
            _pomme.dessiner();

            _serpents[0].augmenterScore();
            gotoxy(1, 31);
            textcolor(14);
            cout << "Score : ";
            cout << _serpents[0].getScore();
            textcolor(7);
        }
        else if (_serpents[1].mangePomme(_pomme))
        {
            _serpents[1].ajouterQueue();
            _pomme.effacer();
            _pomme.posAlea(_serpents[0], _serpents[1]);
            _pomme.dessiner();

            _serpents[1].augmenterScore();
            gotoxy(45, 31);
            textcolor(11);
            cout << "Score : ";
            cout << _serpents[1].getScore();
            textcolor(7);
        }

        j1Perdu = (_serpents[0].seCogne() || _serpents[0].seCogneAvecSerpent(_serpents[1]) || _serpents[0].seCogneAvecTeteSerpent(_serpents[1]));
        j2Perdu = (_serpents[1].seCogne() || _serpents[1].seCogneAvecSerpent(_serpents[0]) || _serpents[1].seCogneAvecTeteSerpent(_serpents[0]));

        finJeu = (j1Perdu || j2Perdu);

    }

    system("cls");

    if (j1Perdu && j2Perdu)
        cout << "Egalite !\n";
    else if (j1Perdu)
        cout << "J1 a perdu !\n";
    else if (j2Perdu)
        cout << "J2 a perdu !\n";

    system("pause");
}
