// Fonction permettant l'impression de caract�res en couleur sous Windows
// d�velopp�dans le cadre du mini-projet 1 du cours d'algorithmique/langage
// D�partement informatique - IUT d'Orsay
//
#ifndef _WINMP1_H
#define _WINMP1_H


void textcolor(int _color);

void imp(char c)
{
    textcolor(7);
    switch (c)
    {
    case 'R' :
        textcolor(12);
        break;    // LIGHTRED
    case 'V' :
        textcolor(10);
        break;   // LGHTGREEN
    case 'J' :
        textcolor(14);
        break;   // YELLOW
    case 'M' :
        textcolor(13);
        break;   // LIGHTMAGENTA
    case 'B' :
        textcolor(9);
        break;    // LIGHTBLUE
    case 'C' :
        textcolor(11);
        break;   // LIGHTCYAN
    }
    cout << c << " ";
    textcolor(7);
}

void impBis(string c)
{
    textcolor(7);
    if(c == "Rouge")
        textcolor(12); // LIGHTRED
    else if (c == "Vert")
        textcolor(10); // LGHTGREEN
    else if (c == "Jaune")
        textcolor(14); // YELLOW
    else if (c == "Magenta")
        textcolor(13); // LIGHTMAGENTA
    else if (c == "Bleu")
        textcolor(9); // LIGHTBLUE
    else if (c == "Cyan")
        textcolor(11); // LIGHTCYAN

    cout << c << " ";
    textcolor(7);
}

// Nom du fichier : myconio.h
// Auteur : prof.geii37@laposte.net
// Version : Novembre 2004
// Objectif : rem�dier � l'absence de certaines fonctions conio sous DevC++

/* Remarques :
    - Dev-C++ poss�de d�j� une biblioth�que conio dans laquelle les fonctions
      � getch �, � getche �, � kbhit �, � putch � et � ungetch � sont cod�es.
    - � textmode n'a pas �t� r��crite car les modes d'affichage pr�vus sous DOS
      n'ont pas de sens dans une fen�tre console Windows.
    - � window � n'a pas pu �tre �crite... seule une fonction � MYclrwin � a �t�
      cod�e pour remplacer l'appel de � window � suivi d'un � clrscr �.
      Toutefois la zone d'�criture � l'�cran n'est pas limit�e.
    - � MYwindow � redimensionne la fen�tre de la console.
      A noter : le comportement de cette fonction n'a aucun rapport avec celui
      de � window � de conio.
*/

/*#ifndef _MYCONIO_H_
#define _MYCONIO_H_
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <windef.h>
#include <winbase.h>
#include <wincon.h>

#ifdef __cplusplus
extern "C" {
#endif

    struct text_info
    {
        unsigned char winleft;
        unsigned char wintop;
        unsigned char winright;
        unsigned char winbottom;
        unsigned char attribute;
        unsigned char normattr;
        unsigned char currmode;
        unsigned char screenheight;
        unsigned char screenwidth;
        unsigned char curx;
        unsigned char cury;
    };

    enum COLORS { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
                  DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
                  LIGHTMAGENTA, YELLOW, WHITE
                } ;

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2
#define C40 1

    void _setcursortype(int type);
    char *cgets(char *str);
    void clreol();
    void clrscr();
    void delline();

#define cprintf printf
#define cscanf scanf
    /* Les fonctions � cprintf � et � cscanf � n'ont pas �t� r��crites, ceci est
       peut-�tre une erreur...
       En effet, � scanf � lit les donn�es � partir de � stdin � et les fonctions
       d'entr�e de la console lisent les donn�es � partir de � STD_INPUT_HANDLE �.
       Or il semblerait que � fflush(stdin) ; � n'ait pas le m�me effet que
       � FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)) ; �...
       A suivre... */

    int cputs(const char *str) ;

    int Gettext(int left, int top, int right, int bottom, void *destin) ;
#define gettext Gettext
    /* Cette astuce a d� �tre utilis�e car la ligne
       � int gettext(int left, int top, int right, int bottom, void *destin) ; �
       produit un message d'erreur (sous Dev-C++) ! */

    void gettextinfo(struct text_info *_r);

    int MYgetch(void) ;
    int MYgetche(void) ;
    /*  � getch �, � getche � sont d�j� d�finies dans <conio.h> (mingw). Cependant,
        au m�me titre que � getchar � (stdio) ne consomme pas le caract�re <CR>,
        elles ne consomment pas le caract�re saisi par l'utilisateur (c'est � dire :
        elles n'enl�vent pas le caract�re du buffer d'entr�e). � MYgetch �,
        � MYgetche � vident le buffer. Attention, � MYgetch � et � MYgetche �
        n'enl�vent pas un caract�re, mais tous les caract�res disponibles. Gr�ce
        aux directives � #define � inclus dans MYconio.cpp, ce sont les fonctions
        � MYgetch � et � MYgetche � qui seront appel�es si dans un source on fait
        appel � � getch � ou � getche �. */

    void gotoxy(int x, int y);

    void highvideo();
    void insline();
// kbhit : OK d�j� d�fini dans <conio.h> (mingw)
    void lowvideo();
    int movetext(int left, int top, int right, int bottom, int destleft, int desttop);
    void normvideo();
// putch : OK d�j� d�fini dans <conio.h> (mingw)
    int puttext(int left, int top, int right, int bottom, void *source);

    void textattr(int _attr);
    void textbackground(int _color);
//void textcolor(int _color);
    /* BLINK (clignotement) ne fonctionne pas ! Par contre, il est possible
       d'utiliser les oucleurs LIGHT pour le fond d'�cran, ce qui n'est pas le cas
       pour une application DOS.*/

    /* � void textmode(int _mode); � n'a pas �t� r��crite, car  les modes
       d'affichage DOS n'ont aucun sens dans une application console Windows. */
// ungetch : OK d�j� d�fini dans <conio.h> (mingw)
    int wherex();
    int wherey();

    void MYclrwin(int left, int top, int right, int bottom); // efface une zone
    /* La fonction � window � de conio est fr�quemment utilis�e (suivi de
       � clrscr �) pour effacer une zone de l'�cran et modifier sa couleur en
       fonction des attribus mis � jour par � textcolor � ou � textbackground �.
       � MYclrwin � permet cela, mais elle n'interdit pas d'�crire en dehors
       de cette zone.*/

    void MYwindow(int left, int top, int right, int bottom);
    /* � MYwindow � permet de redimensionner la fen�tre de la console. Cependant,
       ce comportement, n'est pas celui de la fonction � window � de conio */

// void window(int left, int top, int right, int bottom);
#ifdef __cplusplus
}
#endif

// #include "myconio.cpp"
// Nom du fichier : myconio.cpp
// Auteur : prof.geii37@laposte.net
// Version : Novembre 2004
// Objectif : rem�dier � l'absence de certaines fonctions conio sous DevC++

/* Remarques :
    - Ce fichier est inclus par myconio.h.
    - Au sein d'un fichier source seule la directive � #include <myconio.h> �
      est n�cessaire. Elle remplace � #include <conio.h> �... La directive
      � #include <conio.cpp> � est inutile.
    - Pour obtenir des informations sur les fonctions de la biblioth�que window
      (wincon, winbase) utilis�s dans ce fichier,
      il faut consulter  � http://www.msdn.microsoft.com/library/default.asp �.
*/

//#ifndef _MYCONIO_C_
//#define _MYCONIO_C_
#include <iostream>
using namespace std;
void _setcursortype(int type)
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    if (type == _NOCURSOR) Info.bVisible = FALSE;
    else if (type == _SOLIDCURSOR) Info.dwSize = 90 ;
    else if (type == _NORMALCURSOR) Info.dwSize = 1;
    SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
}

char *cgets(char *str)
{
    int i=2 ;
    while((str[i]=MYgetch()) != '\r')
    {
        switch(str[i])
        {
        case '\b' :
            if(i<=2) break ; // pas de caract�re � effacer
            printf("\b \b") ;
            i -- ;
            break ;
        case 0    :
        case -32  :
            MYgetch() ; // lire le 2�me caract�re des codes �tendus
        case 9    :           // ne pas tenir compte de la touche [TAB]
        case 27   :
            break ;   // ne pas tenir compte de la touche [ESC]
        default   :
            if(i<=str[0])
                putch(str[i++]) ;
        }
    }
    str[i] = 0 ;
    str[1] = i - 2 ;
    return str + 2 ;
}

void clreol()
{
    COORD coord = {wherex() - 1 , wherey() - 1};
    DWORD dwWritten;
    HANDLE hScreen=GetStdHandle(STD_OUTPUT_HANDLE) ;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    if(GetConsoleScreenBufferInfo(hScreen, &Info))
    {
        FillConsoleOutputCharacter (hScreen, ' ', Info.dwSize.X-coord.X, coord,
                                    &dwWritten);
        FillConsoleOutputAttribute (hScreen, Info.wAttributes,
                                    Info.dwSize.X-coord.X, coord, &dwWritten);
        gotoxy (coord.X, coord.Y) ;
    }
}

void clrscr(void) // efface l'�cran
{
    // Premi�re solution :         OK !
    COORD coord = { 0, 0 } ; //  coord.X = 0;  coord.Y = 0;
    DWORD dwWritten, dwSize ;
    HANDLE hScreen=GetStdHandle(STD_OUTPUT_HANDLE) ;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    if(GetConsoleScreenBufferInfo(hScreen, &Info))
    {
        dwSize = Info.dwSize.X * Info.dwSize.Y ;
        FillConsoleOutputCharacter (hScreen, ' ', dwSize, coord, &dwWritten);
        FillConsoleOutputAttribute (hScreen, Info.wAttributes, dwSize, coord,
                                    &dwWritten);
        gotoxy (1, 1);
    }
    /* Seconde solution : moins efficace - n�cessite plus de temps
                        - ne prend pas en compte les couleurs */
    /*
    system("cls") ;
    */
}

int cputs(const char *str)
{
    return ((printf ("%s\n", str)==EOF)?EOF:(int)*(str+strlen(str)-1)) ;
}

void delline()
{
    int y=wherey() ;
    HANDLE hScreen = GetStdHandle(STD_OUTPUT_HANDLE) ;
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(hScreen, &Info) ;
    {
        COORD dwBufferSize= {Info.dwSize.X, Info.dwSize.Y - y} ;
        COORD dwBufferCoord= {0, 0} ;
        CHAR_INFO Buffer[dwBufferSize.Y][dwBufferSize.X] ;
        SMALL_RECT ReadRegion[2] ;
        ReadRegion[0].Left = 0 ;
        ReadRegion[0].Right = Info.dwSize.X-1 ;
        ReadRegion[0].Top = y ;
        ReadRegion[0].Bottom = Info.dwSize.Y-1 ;

        ReadConsoleOutput(hScreen, (CHAR_INFO*)Buffer, dwBufferSize,
                          dwBufferCoord, ReadRegion) ;
        ReadRegion[0].Top = y-1 ;
        ReadRegion[0].Bottom = Info.dwSize.Y-2 ;
        WriteConsoleOutput(hScreen, (CHAR_INFO*)Buffer, dwBufferSize,
                           dwBufferCoord, ReadRegion) ;
    }
}

int MYgetch(void)
{
    char Temp[3] ;
    int Ret=getch() ;
    if (Ret==0x0D) gets(Temp) ;
    /* Si la touche choisie par l'utilisateur est <CR> alors
       � FlushConsoleInputBuffer � ne fonctionne pas d'o� l'astuce avec gets. */
    else FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)) ;
    /* � fflush(stdin) ;  � ne fonctionne pas ! Sans effet apparent ! */
    return Ret ;
}

int MYgetche(void)
{
    char Temp[3] ;
    int Ret=getche() ;
    if (Ret==0x0D) gets(Temp) ;
    else FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)) ;
    return Ret ;
}

#define getch MYgetch  // permet de remplacer getch (conio, mingw) par MYgetch
#define getche MYgetche

int Gettext(int left, int top, int right, int bottom, void *destin)
{
    int ValueReturn, x, y ;
    HANDLE hScreen = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD dwBufferSize= {right-left+1, bottom-top+1} ;
    COORD dwBufferCoord= {0,0} ;
    CHAR_INFO Buffer[dwBufferSize.Y][dwBufferSize.X] ;
    SMALL_RECT ReadRegion[2] ;
    ReadRegion[0].Left = left-1 ;
    ReadRegion[0].Right = right-1 ;
    ReadRegion[0].Top = top-1 ;
    ReadRegion[0].Bottom = bottom-1 ;

    ValueReturn=ReadConsoleOutput(hScreen, (CHAR_INFO*) Buffer, dwBufferSize,
                                  dwBufferCoord, ReadRegion) ;

    for (x=0 ; x<dwBufferSize.X ; x++)
    {
        for (y=0 ; y<dwBufferSize.Y ; y++)
        {
            *((char*)destin+(2*(dwBufferSize.X*y+x)))=Buffer[y][x].Char.AsciiChar ;
            *((char*)destin+(2*(dwBufferSize.X*y+x)+1))=Buffer[y][x].Attributes ;
        }
    }
    return ValueReturn ;
}

void gettextInfo(struct text_info *_r)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
    _r->winleft = Info.srWindow.Left ;
    _r->winright = Info.srWindow.Right ;
    _r->wintop = Info.srWindow.Top ;
    _r->winbottom = Info.srWindow.Bottom ;
    _r->attribute = Info.wAttributes ;
    _r->normattr = LIGHTGRAY | (BLACK<<4) ;
    _r->currmode = C40 ;
    _r->screenheight = Info.dwSize.Y ;
    _r->screenwidth = Info.dwSize.X ;
    _r->curx = wherex () ;
    _r->cury = wherey () ;
}

void gotoxy(int x, int y)
{
    COORD c ;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void highvideo()
{
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
    textattr(Info.wAttributes | 0x08);
}

void insline()
{
    int y=wherey() ;
    HANDLE hScreen = GetStdHandle(STD_OUTPUT_HANDLE) ;
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(hScreen, &Info) ;
    {
        COORD dwBufferSize= {Info.dwSize.X, Info.dwSize.Y - y} ;
        COORD dwBufferCoord= {0,0} ;
        COORD coord= {0, y-1} ; // pour FillConsoleOutputCharacter
        CHAR_INFO Buffer[dwBufferSize.Y][dwBufferSize.X] ;
        DWORD dwWritten;
        SMALL_RECT ReadRegion[2] ;
        ReadRegion[0].Left = 0 ;
        ReadRegion[0].Right = Info.dwSize.X-1 ;
        ReadRegion[0].Top = y-1 ;
        ReadRegion[0].Bottom = Info.dwSize.Y-2 ;

        ReadConsoleOutput(hScreen, (CHAR_INFO*)Buffer, dwBufferSize, dwBufferCoord, ReadRegion) ;
        ReadRegion[0].Top = y ;
        ReadRegion[0].Bottom = Info.dwSize.Y-1 ;
        WriteConsoleOutput(hScreen, (CHAR_INFO*)Buffer, dwBufferSize, dwBufferCoord, ReadRegion) ;
        FillConsoleOutputCharacter (hScreen, ' ', Info.dwSize.X, coord, &dwWritten); // Effacer ligne
        FillConsoleOutputAttribute (hScreen, Info.wAttributes, Info.dwSize.X, coord, &dwWritten);
    }
}

void lowvideo()
{
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
    textattr(Info.wAttributes & 0xF7);
}

int movetext(int left, int top, int right, int bottom, int destleft, int desttop)
{
//    int ValueReturn, x, y ;
    HANDLE hScreen = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD dwBufferSize= {right-left+1, bottom-top+1} ;
    COORD dwBufferCoord= {0,0} ;
    CHAR_INFO Buffer[dwBufferSize.Y][dwBufferSize.X] ;
    SMALL_RECT ReadRegion[2] ;
    ReadRegion[0].Left = left-1 ;
    ReadRegion[0].Right = right-1 ;
    ReadRegion[0].Top = top-1 ;
    ReadRegion[0].Bottom = bottom-1 ;

    ReadConsoleOutput(hScreen, (CHAR_INFO*) Buffer, dwBufferSize, dwBufferCoord,
                      ReadRegion) ;
    ReadRegion[0].Left = destleft-1 ;
    ReadRegion[0].Right = destleft-1+(dwBufferSize.X-1) ;
    ReadRegion[0].Top = desttop-1 ;
    ReadRegion[0].Bottom = desttop-1+(dwBufferSize.Y-1) ;
    return WriteConsoleOutput(hScreen, (CHAR_INFO*) Buffer, dwBufferSize,
                              dwBufferCoord, ReadRegion) ;
}

void normvideo()
{
    textattr(0x07) ; // LIGHTGRAY
}

int puttext(int left, int top, int right, int bottom, void *source)
{
    int x, y ;
    HANDLE hScreen = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD dwBufferSize= {right-left+1, bottom-top+1} ;
    COORD dwBufferCoord= {0,0} ;
    CHAR_INFO Buffer[dwBufferSize.Y][dwBufferSize.X] ;
    SMALL_RECT ReadRegion[2] ;
    ReadRegion[0].Left = left-1 ;
    ReadRegion[0].Right = right-1 ;
    ReadRegion[0].Top = top-1 ;
    ReadRegion[0].Bottom = bottom-1 ;

    for (x=0 ; x<dwBufferSize.X ; x++)
    {
        for (y=0 ; y<dwBufferSize.Y ; y++)
        {
            Buffer[y][x].Char.AsciiChar = *((char*)source+(2*(dwBufferSize.X*y+x))) ;
            Buffer[y][x].Attributes = *((char*)source+(2*(dwBufferSize.X*y+x)+1)) ;
        }
    }

    return WriteConsoleOutput(hScreen, (CHAR_INFO*) Buffer, dwBufferSize,
                              dwBufferCoord, ReadRegion) ;
}

void textattr(int _attr)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
}

void textbackground(int _color)
{
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
    textattr((Info.wAttributes & 0x0F) | (_color<<4));
}

void textcolor(int _color)
{
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
    textattr((Info.wAttributes & 0xF0) | _color);
}

int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    return Info.dwCursorPosition.X + 1 ;
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    return Info.dwCursorPosition.Y + 1 ;
}

void MYclrwin(int left, int top, int right, int bottom)
// efface une zone de l'�cran
{
    int i ;
    COORD dwCoord = {0, 0} ;
    COORD dwSize = {(right-left+1),(bottom-top+1)} ;
    HANDLE hScreen=GetStdHandle(STD_OUTPUT_HANDLE) ;
    CHAR_INFO Buffer[dwSize.X*dwSize.Y] ;
    SMALL_RECT Region[2] ;
    CONSOLE_SCREEN_BUFFER_INFO Info;

    if(GetConsoleScreenBufferInfo(hScreen, &Info))
    {
        for(i=0 ; i < dwSize.X*dwSize.Y ; i++)
        {
            Buffer[i].Char.AsciiChar=' ' ;
            Buffer[i].Attributes = Info.wAttributes ;
        }
        Region[0].Left = left-1 ;
        Region[0].Right = right-1 ;
        Region[0].Top = top-1 ;
        Region[0].Bottom = bottom-1 ;
        WriteConsoleOutput(hScreen, (CHAR_INFO*) Buffer, dwSize, dwCoord, Region) ;
        gotoxy (left, top);
    }

}

void MYwindow(int left, int top, int right, int bottom)
{
    SMALL_RECT R = {left, top, right, bottom } ;
    SetConsoleWindowInfo (GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &R);
}

//#endif //_MYCONIO_C_



// #endif  //_MYCONIO_H_

#endif _WINMP1_H    // _WINMP1_H_

