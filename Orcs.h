//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>
#include "Faction.h"

using namespace std;

class Orcs:public Faction{
    public:
        Orcs(string="", int=0, int=0, int=0, int=0);
        //~Orcs();
        void PerformAttack();
        void ReceiveAttack(string, int);
        int PurchaseWeapons(int);
        int PurchaseArmors(int);
        void Print()const;
};
