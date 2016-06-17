#ifndef SERPENT_H
#define SERPENT_H

#include <deque>

#include "Pomme.h"

enum Direction
{
    HAUT,
    BAS,
    GAUCHE,
    DROITE
};

class Pomme;
class Serpent
{
    public:
        Serpent();
        ~Serpent();

        void seDeplacerAvecFleches();
        void seDeplacerAvecLettres();

        bool seCogne() const;
        bool seCogneAvecSerpent(const Serpent &s) const;
        bool seCogneAvecTeteSerpent(const Serpent &s) const;
        bool mangePomme(const Pomme &p) const;
        void ajouterQueue();
        void dessiner(int couleur) const;
        int getTaille() const {return _taille;}
        int getPosTeteX() const {return _posTeteX;}
        int getPosTeteY() const {return _posTeteY;}
        int getCoodX(int indice) const;
        int getCoodY(int indice) const;
        int getScore() const {return _score;}
        void augmenterScore() {_score++;}
        void effacerQueue() const;
        void augmenterVitesse();
        void setPosition(int posTeteX, int posTeteY);
        void setDirection(const Direction &direction);
        void setDx(int dx);
        void setDy(int dy);

    private:
        static int compteur;
        std::deque<int> _coodX;
        std::deque<int> _coodY;

        int _posTeteX;
        int _posTeteY;

        int _dx;
        int _dy;

        float _vitesse;
        int _taille;

        Direction _dir;

        int _score;

        void _majCood();
        void _majDir();
};

#endif // SERPENT_H
