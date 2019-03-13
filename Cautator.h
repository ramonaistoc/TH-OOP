#ifndef CAUTATOR_H
#define CAUTATOR_H

class joc;

class cautator
{
    // clasa cautator este clasa de baza, cautatorii de fiecare tip sunt clase derivate
public:
    int pozitie_coloana, pozitie_linie;
    int ok_joc;

    cautator();
    cautator(int linie, int coloana);
    ~cautator();
    virtual void mod_deplasare( joc &h)=0;//la mostenire definesc functia pentru fiecare tip de cautator

};

class cautator_tip1:public cautator
{

public:
    cautator_tip1();
    cautator_tip1(int linie, int coloana);
    ~cautator_tip1();
    void mod_deplasare( joc &h);

};

class cautator_tip2:public cautator
{

public:
    cautator_tip2();
    cautator_tip2(int linie, int coloana);
    ~cautator_tip2();
    void mod_deplasare( joc &h);
};

class cautator_tip3:public cautator
{

public:
    cautator_tip3();
    cautator_tip3(int linie, int coloana);
    ~cautator_tip3();
    void mod_deplasare( joc &h);

};

class cautator_tip4:public cautator
{

public:
    cautator_tip4();
    cautator_tip4(int linie, int coloana);
    ~cautator_tip4();
    void mod_deplasare( joc &h);

};

#endif // CAUTATOR_H
