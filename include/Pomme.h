#ifndef POMME_H
#define POMME_H

#include "Serpent.h"

class Serpent;
class Pomme
{
    public:
        Pomme();
        ~Pomme();

        int getPosX() const {return _posX;}
        int getPosY() const {return _posY;}

        void posAlea(const Serpent &s);
        void posAlea(const Serpent &s1, const Serpent &s2);
        void dessiner() const;
        void effacer() const;

    private:
         int _posX;
         int _posY;
};

#endif // POMME_H
