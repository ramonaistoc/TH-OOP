#include <iostream>
#include "TreasureHunt.h"
#include "Cautator.h"

using namespace std;

int main()
{
    int ok=1;
    int n;
    cout<<"Dimensiune matrice: ";
    cin>>n; //citesc dimensiunea matricei de la tastatura
    joc j(n);

    cout<<"Matricea initiala "<<endl; //afisez matricea initiala
    j.afisare();
    int nr_runda=1;

    do
    {
        cout<<"Continuati? 1 - da, 0 altfel"<<endl;
        cin>>ok;

        cout<<"Runda: "<<nr_runda<<endl<<endl;
        nr_runda++;

        j.runda(j, ok);

        j.afisare(); //afisez matricea dupa fiecare runda

    }
    while(ok==1);

    return 0;
}
