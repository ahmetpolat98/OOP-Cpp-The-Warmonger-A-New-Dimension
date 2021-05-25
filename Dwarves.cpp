//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Dwarves.h"

using namespace std;

Dwarves::Dwarves(string name, int number_of_unit, int attack_point, int health_point, int unit_regeneration_number)
    :Faction(name, number_of_unit, attack_point, health_point, unit_regeneration_number){}



void Dwarves::PerformAttack(){
    int num_enemy = 0; //alive number of enemy
    int who_alive = 0; //if one enemy is alive, which one? 1:first, 2:second, 0:no one, 3:both alive
    if(first_enemy->IsAlive()){
        num_enemy += 1;
        who_alive = 1;
    }
    if(second_enemy->IsAlive()){
        num_enemy += 1;
        who_alive = 2;
    }

    int attack_point1 = 0; //attacking point for first enemy
    int attack_point2 = 0;  //for second enemy
    int army1 = 0; // number of unit to attack first enemy
    int army2 = 0; //for second enemy

    if(num_enemy == 1){ //only one enemy alive
        army1 = this->number_of_unit;
        attack_point1 = army1 * this->attack_point;

        if (who_alive == 1) //attack first enemy
        {
            this->first_enemy->ReceiveAttack(this->name, attack_point1);
        }
        else{//attack second enemy
            this->second_enemy->ReceiveAttack(this->name, attack_point1);
        }      
    }
    else if(num_enemy == 2){ //both enemy alive
        army1 = (50 * this->number_of_unit) / 100;
        army2 = number_of_unit - army1;

        attack_point1 = army1 * this->attack_point;
        attack_point2 = army2 * this->attack_point;

        this->first_enemy->ReceiveAttack(this->name, attack_point1);
        this->second_enemy->ReceiveAttack(this->name, attack_point2);
    }
    else{ //there is no alive enemy
        cout << "There is no enemy to attack" << endl;
    }
}

void Dwarves::ReceiveAttack(string attacked_name, int attacked_point){ 
    int received_attack = attacked_point;
    int reduced_unit = received_attack / this->health_point;
    this->number_of_unit -= reduced_unit;
}

int Dwarves::PurchaseWeapons(int purchased_weapons){
    this->attack_point += purchased_weapons;
    return 10 * purchased_weapons;
}

int Dwarves::PurchaseArmors(int purchased_armors){
    this->health_point += (2 * purchased_armors);
    return 3 * purchased_armors;
}

void Dwarves::Print()const{
    cout << "\"Taste the power of our axes!\"" << endl;
    Faction::Print();
}