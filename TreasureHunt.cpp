#include "TreasureHunt.h"
#include "Cautator.h"
#include<iostream>
#include<cstdlib>

joc::joc(int dim)//:c[0](0,0), c2(0,dim-1), c3(dim-1, dim-1), c4(dim-1,0) //initializez pozitia initiala a jucatorilor prin liste de initializare
{
    dimensiune_matrice=dim;
    nr_comori_gasite=0;

    matrice_harta=new int*[dimensiune_matrice];             // aloc matricea dinamic

    int i, j;
    for(i=0; i<dimensiune_matrice; i++)
        matrice_harta[i]=new int[dimensiune_matrice];

    for(i=0; i<dimensiune_matrice; i++)
        for(j=0; j<dimensiune_matrice; j++)
            matrice_harta[i][j]=0;              //initial fiecare pozitie din matrice are valoarea 0
    //asez cautatorii pe pozitii
    matrice_harta[0][0]=1;              // jucatorul 1 stanga sus
    matrice_harta[0][dimensiune_matrice-1]=2; //jucatorul 2 dreapta sus
    matrice_harta[dimensiune_matrice-1][0]=4; //jucatorul 4 stanga jos
    matrice_harta[dimensiune_matrice-1][dimensiune_matrice-1]=3; //jucatorul 3 dreapta jos

    int nr_comori_adaugate=0; //contorul se actualizeaza pe masura ce adaug comori
    int k, p;

    while(nr_comori_adaugate<3)             //pozitionez comorile random si verific sa nu fie in colturile matricei
    {
        //si sa nu fie pe o pozitie pe care se gaseste deja o comoara
        k=rand()%(dimensiune_matrice-1);
        p=rand()%(dimensiune_matrice-1);

        if((k!=0 && p!=(dimensiune_matrice-1) ) && (p!=0 && k!=0) && (p!=0 && k!=(dimensiune_matrice-1) ) && (k!=(dimensiune_matrice-1) && p!=(dimensiune_matrice-1) ))
        {
            if(nr_comori_adaugate>1)        //dupa ce am adaugat prima comoara verific ca pozitia sa nu fie ocupata de o alta comoara
            {
                if(matrice_harta[k][p]==0)
                    matrice_harta[k][p]=5;
                nr_comori_adaugate++;
            }
            else
            {
                matrice_harta[k][p]=5; //comorile au nr 5
                nr_comori_adaugate++;
            }
        }
    }

    c=new cautator*[4];

    c[0]=new cautator_tip1(0,0);
    c[1]=new cautator_tip2(0, dim-1);
    c[2]=new cautator_tip3(dim-1, dim-1);
    c[3]=new cautator_tip4(dim-1, 0);

    //ctor
}

joc::~joc()
{
    int i;
    for(i=0; i<dimensiune_matrice; i++)
        delete[]matrice_harta[i];
    delete[]matrice_harta;
    //dtor
}

void joc::afisare()
{

    cout<<"--------"<<endl;
    int i, j;
    for(i=0; i<dimensiune_matrice; i++)
    {
        for(j=0; j<dimensiune_matrice; j++)
            cout<<matrice_harta[i][j]<<" ";
        cout<<endl;
    }
    cout<<"--------"<<endl;
}

int joc::get_dimensiune_matrice()
{
    return dimensiune_matrice;
}

void joc::runda(joc &j, int &ok_joc )
{
    int i;

    for(i=0;i<4;i++)
    {
    cout<<"Pozitia jucatorului "<<i+1<<" inaite de deplasare: "<< c[i]->pozitie_linie << " ,"<< c[i]->pozitie_coloana<<endl; //afisez pozitia inainte
    c[i]->mod_deplasare(j);
    cout<<"Pozitia jucatorului "<<i+1<<" dupa deplasare: "<< c[i]->pozitie_linie << " ,"<< c[i]->pozitie_coloana<<endl;// si dupa mutare
    cout<<"Rezultat: ";//afisez starea in care se afla jucatorul 1
    if(c[i]->ok_joc == 0)
    {
        cout<<"Jucatorul "<<i+1<<" este in joc";
    }
    else if (c[i]->ok_joc == -1)
    {
        cout << "Jucatorul "<<i+1<<" s-a blocat";
    }
    else
    {
        cout<<"Jucatorul "<<i+1<<" a gasit o comoara";
    }
    j.matrice_harta[c[i]->pozitie_linie][c[i]->pozitie_coloana] = i+1;  //actualizez pozitia din matrice pe care se muta cautatorul 1
    cout<<endl<<endl;
    }
    /*
    cout<<"Pozitia jucatorului 1 inaite de deplasare: "<< c1.pozitie_linie << " ,"<< c1.pozitie_coloana<<endl; //afisez pozitia inainte
    c1.mod_deplasare(j);
    cout<<"Pozitia jucatorului 1 dupa deplasare: "<< c1.pozitie_linie << " ,"<< c1.pozitie_coloana<<endl;// si dupa mutare
    cout<<"Rezultat: ";//afisez starea in care se afla jucatorul 1
    if(c1.ok_joc == 0)
    {
        cout<<"Jucatorul 1 este in joc";
    }
    else if (c1.ok_joc == -1)
    {
        cout << "Jucatorul 1 s-a blocat";
    }
    else
    {
        cout<<"Jucatorul 1 a gasit o comoara";
    }
    j.matrice_harta[c1.pozitie_linie][c1.pozitie_coloana] = 1;  //actualizez pozitia din matrice pe care se muta cautatorul 1
    cout<<endl<<endl;

    cout<<"Pozitia jucatorului 2 inainte de deplasare "<< c2.pozitie_linie << " ,"<< c2.pozitie_coloana<<endl;//afisez pozitia inainte
    c2.mod_deplasare(j);
    cout<<"Pozitia jucatorului 2 dupa deplasare "<< c2.pozitie_linie << " ,"<< c2.pozitie_coloana<<endl;//si dupa mutare
    cout<<"Rezultat: "; //afisez starea jucatorului 2
    if(c2.ok_joc == 0)
    {
        cout<<"Jucatorul 2 este in joc";
    }
    else if (c2.ok_joc == -1)
    {
        cout <<"Jucatorul 2 s-a blocat";
    }
    else
    {
        cout<<"Jucatorul 2 a gasit o comoara";
    }
    j.matrice_harta[c2.pozitie_linie][c2.pozitie_coloana] = 2; //acutalizez pozitia din matrice pe care se muta 2
    cout<<endl<<endl;

    cout<<"Pozitia jucatorului 3 inaite de deplasare "<< c3.pozitie_linie << " ,"<< c3.pozitie_coloana<<endl;//afisez pozitia pe care se afla
    c3.mod_deplasare(j);
    cout<<"Pozitia jucatorului 3 dupa deplasare "<< c3.pozitie_linie << " ,"<< c3.pozitie_coloana<<endl;//si pe care se va muta
    cout<<"Rezultat: "; //afisez starea jucatorului
    if(c3.ok_joc == 0)
    {
        cout<<"Jucatorul 3 este in joc";
    }
    else if (c3.ok_joc == -1)
    {
        cout << "Jucatorul 3 s-a blocat";
    }
    else
    {
        cout<<"Jucatorul 3 a gasit o comoara";
    }
    j.matrice_harta[c3.pozitie_linie][c3.pozitie_coloana] = 3; //actualizez pozitia din matrice pe care se muta jucatorul 3
    cout<<endl<<endl;

    cout<<"Pozitia jucatorului 4 inainte de deplasare "<< c4.pozitie_linie << " ,"<< c4.pozitie_coloana<<endl;//afisze pozitia initiala
    c4.mod_deplasare(j);
    cout<<"Pozitia jucatorului 4 dupa deplasare "<< c4.pozitie_linie << " ,"<< c4.pozitie_coloana<<endl;//si cea pe care se va afla jucatorul
    cout<<"Rezultat: ";//afisez starea jucatorului 4
    if(c4.ok_joc == 0)
    {
        cout<<"Jucatorul 4 este in joc";
    }
    else if (c4.ok_joc == -1)
    {
        cout << "Jucatorul 4 s-a blocat";
    }
    else
    {
        cout<<"Jucatorul 4 a gasit o comoara";
    }
    j.matrice_harta[c4.pozitie_linie][c4.pozitie_coloana] = 4; //actualizez pozitia din matrice pe care se muta jucatorul 4
    cout<<endl<<endl;

    cout<<"Nr. comori gasite: "<<nr_comori_gasite<<endl;//afizes nr comorilor gasite
*/
    if(c[0]->ok_joc!=0 && c[1]->ok_joc!=0 && c[2]->ok_joc!=0 && c[3]->ok_joc!=0) //daca fiecare jucator s-a blocat sau a gasit o comoara jocut se termina
        cout<<endl<<"Jocul s-a terminat"<<endl;
    else if(nr_comori_gasite==3) // jocul se termina si cand au fost gasite cele 3 comori
        cout<<"Toate comorile au fost gasite - jocul s-a sfarsit"<<endl;

}
