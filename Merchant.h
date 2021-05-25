//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>

using namespace std;

#include "Faction.h"
#include "Orcs.h"
#include "Dwarves.h"
#include "Elves.h"

class Merchant{
    private:
        Faction* first_faction;
        Faction* second_faction;
        Faction* third_faction;
        int starting_weapon_point;
        int starting_armor_point;
        int weapon_point;
        int armor_point;
        int revenue;


    public:
        Merchant(int=0, int=0);
        //~Merchant();
        void AssignFactions(Faction*, Faction*, Faction*);
        bool SellWeapons(string, int);
        bool SellArmors(string, int);
        void EndTurn();

        Faction* GetFirst_faction()const;
        Faction* GetSecond_faction()const;
        Faction* GetThird_faction()const;
        int GetStarting_weapon_point()const;
        int GetStarting_armor_point()const;
        int GetWeaponPoints()const;
        int GetArmorPoints()const;
        int GetRevenue()const;

        void setFirst_faction(Faction*);
        void setSecond_faction(Faction*);
        void setThird_faction(Faction*);
        void setStarting_weapon_point(int);
        void setStarting_armor_point(int);
        void setWeapon_point(int);
        void setArmor_point(int);
        void setRevenue(int);


};




