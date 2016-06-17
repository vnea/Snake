#include <windows.h>
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include <stdio.h>
#include <conio.h>
#include <deque>

using namespace std;

#include "../include/Serpent.h"
#include "../outils.h"
#include "../global.h"


Serpent::Serpent()
    : _posTeteX(10), _posTeteY(10), _dx(1), _dy(0), _vitesse(0.1), _dir(DROITE), _score(0)
{
    _coodX.push_front(_posTeteX);
    _coodY.push_front(_posTeteY);
    _taille = _coodX.size();
}

Serpent::~Serpent()
{
    _coodX.clear();
    _coodY.clear();
}

void Serpent::seDeplacerAvecFleches()
{
    if (kbhit())
    {
        char codeTouche = getch();
        fflush(stdin);

        switch(codeTouche)
        {
            // Pour le haut
            case 72 :
            {
                if (_dir != BAS)
                {
                    _dx = 0;
                    _dy = -1;
                }
            }
            break;

            // Pour le bas
            case 80 :
            {
                if (_dir != HAUT)
                {
                    _dx = 0;
                    _dy = 1;
                }
            }
            break;

            // Pour la gauche
            case 75 :
            {
                if (_dir != DROITE)
                {
                    _dx = -1;
                    _dy = 0;
                }
            }
            break;

            // Pour la droite
            case 77 :
            {
                if (_dir != GAUCHE)
                {
                    _dx = 1;
                    _dy = 0;
                }
            }
            break;

            default:
            break;
        }
    }

    static clock_t tpsPrec = clock();

    if ((((float)clock() - (float)tpsPrec) / 1000000.0F ) * 1000 > _vitesse)
    {
        effacerQueue();
        _majDir();
        _majCood();
        tpsPrec = clock();
    }
}

void Serpent::seDeplacerAvecLettres()
{
    if (kbhit())
    {
        char codeTouche = getch();
        fflush(stdin);

        switch(codeTouche)
        {
            // Pour le haut
            case 122 :
            {
                if (_dir != BAS)
                {
                    _dx = 0;
                    _dy = -1;
                }
            }
            break;

            // Pour le bas
            case 115 :
            {
                if (_dir != HAUT)
                {
                    _dx = 0;
                    _dy = 1;
                }
            }
            break;

            // Pour la gauche
            case 113 :
            {
                if (_dir != DROITE)
                {
                    _dx = -1;
                    _dy = 0;
                }
            }
            break;

            // Pour la droite
            case 100 :
            {
                if (_dir != GAUCHE)
                {
                    _dx = 1;
                    _dy = 0;
                }
            }
            break;

            default:
            break;
        }
    }

    static clock_t tpsPrec = clock();

    if ((((float)clock() - (float)tpsPrec) / 1000000.0F ) * 1000 > _vitesse)
    {
        effacerQueue();
        _majDir();
        _majCood();
        tpsPrec = clock();
    }
}

void Serpent::_majCood()
{
    // Décalage des coordonnées du serpent
    for (int i = 0; i < _taille - 1; i++)
    {
       _coodX[i] = _coodX[i + 1];
       _coodY[i] = _coodY[i + 1];
    }

    _posTeteX += _dx;
    _posTeteY += _dy;

    if (_posTeteX < 0)
        _posTeteX = LARGEUR - 1;
    else if (_posTeteX >= LARGEUR)
        _posTeteX = 0;

    if (_posTeteY < 0)
        _posTeteY = HAUTEUR - 1;
    else if (_posTeteY >= HAUTEUR)
        _posTeteY = 0;

    // Mise à jour de la position de la tête
    _coodX[_taille - 1] = _posTeteX;
    _coodY[_taille - 1] = _posTeteY;
}

bool Serpent::seCogne() const
{
    for (int i = 0; i < _taille - 1; i++)
    {
        if (_posTeteX == _coodX[i] && _posTeteY == _coodY[i])
            return true;
    }

    return false;
}

bool Serpent::seCogneAvecSerpent(const Serpent &s) const
{
    for (int i = 0; i <  s._taille - 1; i++)
    {
        if (_posTeteX == s._coodX[i] && _posTeteY == s._coodY[i])
            return true;
    }

    return false;
}

bool Serpent::seCogneAvecTeteSerpent(const Serpent &s) const
{
    if (_posTeteX == s._posTeteX && _posTeteY == s._posTeteY)
            return true;

    return false;
}

bool Serpent::mangePomme(const Pomme &p) const
{
    return _posTeteX == p.getPosX() && _posTeteY == p.getPosY();
}

void Serpent::ajouterQueue()
{
    if (_taille == 1)
    {
        switch(_dir)
        {
            case HAUT :
            {
                _coodX.push_front(_coodX[0]);
                _coodY.push_front(_coodY[0] + 1);
            }
            break;

            case BAS :
            {
                _coodX.push_front(_coodX[0]);
                _coodY.push_front(_coodY[0] - 1);
            }
            break;

            case GAUCHE :
            {
                _coodX.push_front(_coodX[0] + 1);
                _coodY.push_front(_coodY[0]);
            }
            break;

            case DROITE :
            {
                _coodX.push_front(_coodX[0] - 1);
                _coodY.push_front(_coodY[0]);
            }
            break;

            default :
            break;
        }
    }
    else
    {
        if (_coodX[0] == _coodX[1])
        {
            _coodX.push_front(_coodX[0]);

            if (_coodY[0] < _coodY[1])
                _coodY.push_front(_coodY[0] - 1);
            else if (_coodY[0] > _coodY[1])
                _coodY.push_front(_coodY[0] + 1);
        }
        else if (_coodY[0] == _coodY[1])
        {
            _coodY.push_front(_coodY[0]);

            if (_coodX[0] < _coodX[1])
                _coodX.push_front(_coodX[0] - 1);
            else if (_coodX[0] > _coodX[1])
                _coodX.push_front(_coodX[0] + 1);
        }
    }

    _taille = _coodX.size();
    _majCood();
}

void Serpent::dessiner(int couleur) const
{
    textcolor(couleur);
    for (int i = 0; i < _taille - 1; i++)
    {
        gotoxy(_coodX[i], _coodY[i]);
        cout << '*' << flush;
    }

    gotoxy(_posTeteX, _posTeteY);
    cout << 'O' << flush;
    textcolor(7);
}

void Serpent::effacerQueue() const
{
    gotoxy(_coodX[0], _coodY[0]);
    cout << ' ' << flush;
}

int Serpent::getCoodX(int indice) const
{
    if (indice < 0 || indice >= _taille)
    {
        cerr << "Serpent::getCoodX : Erreur d'indice.\n";
        exit(1);
    }

    return _coodX[indice];
}

int Serpent::getCoodY(int indice) const
{
    if (indice < 0 || indice >= _taille)
    {
        cerr << "Serpent::getCoodX : Erreur d'indice.\n";
        exit(1);
    }

    return _coodY[indice];
}

void Serpent::_majDir()
{
    if (_dx == 0 && _dy == -1)
        _dir = HAUT;
    else if (_dx == 0 && _dy == 1)
        _dir = BAS;
    else if (_dx == 1 && _dy == 0)
        _dir = DROITE;
    else if (_dx == -1 && _dy == 0)
        _dir = GAUCHE;
}

 void Serpent::augmenterVitesse()
 {
     _vitesse -= 0.0002;

     if (_vitesse <= 0.0)
        _vitesse = 0.0;
 }

 void Serpent::setDirection(const Direction &direction)
 {
     _dir = direction;
 }

 void Serpent::setDx(int dx)
 {
     if (dx != 0 && dx != 1)
     {
        cerr << "Serpent::setDx : Erreur de dx.\n";
        exit(1);
     }

     _dx = dx;
 }

void Serpent::setDy(int dy)
{
    if (dy != 0 && dy != 1)
     {
        cerr << "Serpent::setDx : Erreur de dy.\n";
        exit(1);
     }

     _dy = dy;
}

void  Serpent::setPosition(int posTeteX, int posTeteY)
{
    if (posTeteX < 0 || posTeteY < 0 || posTeteX >= LARGEUR || posTeteY >= HAUTEUR)
    {
        cerr << "Serpent::setPosition : Erreur de position.\n";
        exit(1);
    }

    _posTeteX = posTeteX;
    _posTeteY = posTeteY;
    _coodX[_taille - 1] = _posTeteX;
    _coodY[_taille - 1] = _posTeteY;
}
