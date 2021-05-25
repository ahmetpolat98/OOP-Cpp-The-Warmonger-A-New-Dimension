//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>

using namespace std;

class Faction{
    protected:
        string name;
        Faction* first_enemy;
        Faction* second_enemy;
        int number_of_unit;
        int attack_point;
        int health_point;
        int unit_regeneration_number;
        int total_health;
        bool is_alive;

    public:
        Faction(string="", int=0, int=0, int=0, int=0);
        //~Faction();
        void AssignEnemies(Faction*, Faction*);
        virtual void PerformAttack() = 0;
        virtual void ReceiveAttack(string, int) = 0;
        virtual int PurchaseWeapons(int) = 0;
        virtual int PurchaseArmors(int) = 0;
        virtual void Print() const;
        void EndTurn();

        
        //getters
        string getName()const;
        Faction* getFirst_enemy()const;
        Faction* getSecond_enemy()const;
        int getNumber_of_unit()const;
        int getAttack_point()const;
        int getHealth_point()const;
        int getUnit_regeneration_number()const;
        int getTotal_health()const;
        bool IsAlive()const;

        //setters
        void setName(string);
        void setFirst_enemy(Faction*);
        void setSecond_enemy(Faction*);
        void setNumber_of_unit(int);
        void setAttack_point(int);
        void setHealth_point(int);
        void setUnit_regeneration_number(int);
        void setTotal_health(int);
        void setIs_alive(bool);
        

};
