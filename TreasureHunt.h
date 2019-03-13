#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H
#include "Cautator.h"

using namespace std;

class joc
{
public:
    joc(int dim);
    virtual ~joc();
    void afisare();
    void runda(joc &j, int &ok_joc);
    int get_dimensiune_matrice();

protected:
    int nr_comori_gasite, **matrice_harta, dimensiune_matrice;
    friend class cautator;
    friend class cautator_tip1;
    friend class cautator_tip2;
    friend class cautator_tip3;
    friend class cautator_tip4;
    cautator ** c;

};


#endif // TREASUREHUNT_H
