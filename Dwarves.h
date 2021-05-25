//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>
#include "Faction.h"

using namespace std;

class Dwarves:public Faction{

    public:
        Dwarves(string="", int=0, int=0, int=0, int=0);
        //~Dwarves();
        void PerformAttack();
        void ReceiveAttack(string, int);
        int PurchaseWeapons(int);
        int PurchaseArmors(int);
        void Print()const;
};

