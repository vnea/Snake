#ifndef JEU_H
#define JEU_H

#include <vector>

#include "Serpent.h"
#include "Pomme.h"
#include "Menu.h"

class Jeu
{
    public:
        Jeu();
        ~Jeu();

        void init();
        void run();

    private:
        Serpent _serpent;
        Pomme _pomme;
        Menu _menu;

        std::vector<Serpent> _serpents;

        void _afficherBarreBas() const;
        void _mode1J();
        void _mode2J();
};

#endif // JEU_H
