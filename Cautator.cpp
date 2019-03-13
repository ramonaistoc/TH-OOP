#include "Cautator.h"
#include <iostream>
#include <stdlib.h>
#include "TreasureHunt.h"

using namespace std;

cautator::cautator()
{

}

cautator::cautator(int linie, int coloana)
{

    //ctor
}

cautator_tip1::cautator_tip1()
{
    //ctor
}

cautator_tip1::cautator_tip1(int linie, int coloana)
{
    ok_joc=0;                                           //ok dupa care jucatorul mai e in joc sau nu
    pozitie_coloana = coloana;                          //jucatorul 1 este pozitionat in coltul din stanga sus
    pozitie_linie = linie;
}

cautator_tip2::cautator_tip2()
{

    //ctor
}

cautator_tip2::cautator_tip2(int linie, int coloana)
{
    ok_joc=0;                                            //ok dupa care jucatorul mai e in joc sau nu
    pozitie_coloana = coloana;                          //cautatorul 2 e pozitionat in coltul dreapta sus
    pozitie_linie = linie;
}

cautator_tip3::cautator_tip3()
{

    //ctor
}

cautator_tip3::cautator_tip3(int linie, int coloana)
{
    ok_joc=0;                                           //ok dupa care jucatorul mai e in joc sau nu
    pozitie_coloana = coloana;                          //cautatorul trei e in coltul din dreapta jos
    pozitie_linie = linie;
}

cautator_tip4::cautator_tip4()
{

    //ctor
}

cautator_tip4::cautator_tip4(int linie, int coloana)
{
    ok_joc=0;                                         // ok dupa care jucatorul mai e in joc sau nu
    pozitie_coloana = coloana;                        // cautatorul patru e in coltul din stanga jos
    pozitie_linie = linie;
}

void cautator_tip1::mod_deplasare( joc &h)
{
    //cautatorul merge pe linii in S
    int i=pozitie_linie, j=pozitie_coloana;

    if(ok_joc==0)
    {
        if( j<(h.get_dimensiune_matrice()-1) && i%2==0 && h.matrice_harta[i][j+1]==0 )      //verific daca casuta din dreapta e libera pt linie para
        {
            pozitie_coloana=j+1;
        }
        else if( j<(h.get_dimensiune_matrice()-1) && i%2==0 && h.matrice_harta[i][j+1]==5 ) //verific daca in casuta din dreapta e o comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j+1;
        }

        else if( i < (h.get_dimensiune_matrice()-1) && i%2==0 && h.matrice_harta[i+1][j]==0 ) //verific casuta de dedesubt daca linia e para
        {
            pozitie_linie=i+1;
        }
        else if( i < (h.get_dimensiune_matrice()-1) && i%2==0 && h.matrice_harta[i+1][j]==5 ) //verific daca in casuta de dedesubt e o comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_linie=i+1;
        }

        else  if( i%2==1 && j>=1 && h.matrice_harta[i][j-1]==5 ) //verific daca este o comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j-1;
        }
        else if( i%2==1 && j>=1 && h.matrice_harta[i][j-1]==0 ) //daca linia e impara verific casuta din stanga
        {
            pozitie_coloana=j-1;
        }

        else if( j>=1 && i<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j-1]==0 ) //verific daca casuta de dedesubt stanga e libera
        {
            pozitie_coloana=j-1;
            pozitie_linie=i+1;
        }

        else if( j>=1 && i<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j-1]==5 ) //verific daca se afla o comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j-1;
            pozitie_linie=i+1;
        }

        else if( i<(h.get_dimensiune_matrice()-1) && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j+1]==0 ) //verific daca pozitia de dedesubt dreapta e libera
        {
            pozitie_coloana=j+1;
            pozitie_linie=i+1;
        }

        else if( i<(h.get_dimensiune_matrice()-1) && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j+1]==5 ) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j+1;
            pozitie_linie=i+1;
        }

        else
            ok_joc = -1; //daca nu are nici o posibilitate de deplasare jucaotorul se deplaseaza

    }
}

void cautator_tip2::mod_deplasare( joc &h)
{
    //cautatoru se deplaseasa o casuta in stanga apoi un jos pt matrice de dimensiune impara
    int i=pozitie_linie, j=pozitie_coloana;         // si o casuta in jos si una in stanga pentru dimensiune para

    if(ok_joc==0)
    {
        if( j>=1 && (i+j)%2==0 && h.matrice_harta[i][j-1]==5 ) //daca dim matricei e impara se verifica pozitia din stanga e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j-1;
        }
        else if( j>=1 && (i+j)%2==0 && h.matrice_harta[i][j-1]==0 ) //verific daca casuta e libera
        {
            pozitie_coloana=j-1;
        }

        else if( i < (h.get_dimensiune_matrice()-1) && (i+j)%2==1 && h.matrice_harta[i+1][j]==5 ) //verific daca pozitia de dedesubt e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_linie=i+1;
        }
        else if( i < (h.get_dimensiune_matrice()-1) && (i+j)%2==1 && h.matrice_harta[i+1][j]==0 ) // verific daca pozitia de dedesubt e libera
        {
            pozitie_linie=i+1;
        }

        else ok_joc=-1; // daca jucatorul nu se poate deplasa se blocheaza
    }
}

void cautator_tip3::mod_deplasare( joc &h)
{
    //cautatorul se deplaseaza pe diagonale
    int i=pozitie_linie, j=pozitie_coloana;

    if(ok_joc==0)
    {
        if(i>=1 && j>=1 && h.matrice_harta[i-1][j-1]==0) //verifica daca pozitia de deasupra stanga e libera
        {
            pozitie_coloana=j-1;
            pozitie_linie=i-1;
        }

        else if(i>=1 && j>=1 && h.matrice_harta[i-1][j-1]==5) //verifica daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j-1;
            pozitie_linie=i-1;
        }

        else if(i<(h.get_dimensiune_matrice()-1) && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j+1]==0) //verific daca pozitia de dedesubt dreapta e libera
        {
            pozitie_coloana=j+1;
            pozitie_linie=i+1;
        }

        else if(i<(h.get_dimensiune_matrice()-1) && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j+1]==5 ) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j+1;
            pozitie_linie=i+1;
        }
        else if( i<(h.get_dimensiune_matrice()-1) && j>=1 && h.matrice_harta[i+1][j-1]==0 ) //verific pozitia de dedesubt stanga
        {
            pozitie_coloana=j-1;
            pozitie_linie=i+1;
        }

        else if( i<(h.get_dimensiune_matrice()-1) && j>=1 && h.matrice_harta[i+1][j-1]==5 ) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j-1;
            pozitie_linie=i+1;
        }

        else if( i>=1 && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i-1][j+1]==0 ) //verific daca pozitia de deasupra dreapta e libera
        {
            pozitie_coloana=j+1;
            pozitie_linie=i-1;
        }

        else if( i>=1 && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i-1][j+1]==5 ) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_coloana=j+1;
            pozitie_linie=i-1;
        }

        else ok_joc = -1; // daca nu se poate deplasa jucatorul se blocheaza
    }
}

void cautator_tip4::mod_deplasare( joc &h)
{
    //cautatorul se deplaseaza  in zig-zag apoi pe diagonale
    int i=pozitie_linie, j=pozitie_coloana;

    if(ok_joc==0)
    {
        if( i>=1 && j>=1 && h.matrice_harta[i-1][j-1]==0 ) //verific daca pozitia de deasupra stanga e libera
        {
            pozitie_linie=i-1;
            pozitie_coloana=j-1;
        }

        else if( i>=1 && j>=1 && h.matrice_harta[i-1][j-1]==5 ) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_linie=i-1;
            pozitie_coloana=j-1;
        }

        else if( i>=1 && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i-1][j+1]==0 ) //verific daca pozitia de deasupra dreapta e libera
        {
            pozitie_linie=i-1;
            pozitie_coloana=j+1;
        }

        else if( i>=1 && j<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i-1][j+1]==5 ) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_linie=i-1;
            pozitie_coloana=j+1;
        }

        else if(j>=1 && i<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j-1]==0) //verific daca pozitia de dedesubt stanga e libera
        {
            pozitie_linie=i+1;
            pozitie_coloana=j-1;
        }

        else if(j>=1 && i<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j-1]==5) // verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_linie=i+1;
            pozitie_coloana=j-1;
        }

        else if(j>=1 && i<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j+1]==0) //verific daca pozitia de dedesubt dreapta e libera
        {
            pozitie_linie=i+1;
            pozitie_coloana=j+1;
        }

        else if(j>=1 && i<(h.get_dimensiune_matrice()-1) && h.matrice_harta[i+1][j+1]==5) //verific daca e comoara
        {
            ok_joc=1;
            h.nr_comori_gasite++;
            pozitie_linie=i+1;
            pozitie_coloana=j+1;
        }

        else ok_joc= -1; //daca nu se poate deplasa jucatorul se blocheaza
    }
}

cautator::~cautator()
{
    //dtor
}

cautator_tip1::~cautator_tip1()
{
    //dtor
}

cautator_tip2::~cautator_tip2()
{
    //dtor
}

cautator_tip3::~cautator_tip3()
{
    //dtor
}

cautator_tip4::~cautator_tip4()
{
    //dtor
}
