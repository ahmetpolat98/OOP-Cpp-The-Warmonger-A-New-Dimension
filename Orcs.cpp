//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////

#include <iostream>
#include "Orcs.h"

using namespace std;


Orcs::Orcs(string name, int number_of_unit, int attack_point, int health_point, int unit_regeneration_number)
    :Faction(name, number_of_unit, attack_point, health_point, unit_regeneration_number){}


void Orcs::PerformAttack(){
    int num_enemy = 0; //alive number of enemy
    int who_alive = 0; //if one enemy is alive, which one? 1:first, 2:second, 0:no one, 3:both alive
    string first_enemy_name, second_enemy_name;
    if(first_enemy->IsAlive()){
        num_enemy += 1;
        who_alive = 1;
        first_enemy_name = this->first_enemy->getName();
    }
    if(second_enemy->IsAlive()){
        num_enemy += 1;
        who_alive = 2;
        second_enemy_name = this->second_enemy->getName();
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
        if(first_enemy_name == "Elves"){
            army1 = (70 * this->number_of_unit) / 100;
            army2 = number_of_unit - army1;
        }
        else{
            army2 = (70 * this->number_of_unit) / 100;
            army1 = number_of_unit - army2;
        }
        attack_point1 = army1 * this->attack_point;
        attack_point2 = army2 * this->attack_point;

        this->first_enemy->ReceiveAttack(this->name, attack_point1);
        this->second_enemy->ReceiveAttack(this->name, attack_point2);
    }
    else{ //there is no alive enemy
        cout << "There is no enemy to attack" << endl;
    }
}

void Orcs::ReceiveAttack(string attacked_name, int attacked_point){
    int received_attack;
    if(attacked_name == "Elves"){
        received_attack = (75 * attacked_point) / 100;
    }
    else if(attacked_name == "Dwarves"){
        received_attack = (80 * attacked_point) / 100;
    }
    else{
        cout << "Invalid receive attack" << endl;
    }    
    int reduced_unit = received_attack / this->health_point;
    this->number_of_unit -= reduced_unit;
}

int Orcs::PurchaseWeapons(int purchased_weapons){
    this->attack_point += (2 * purchased_weapons);
    return 20 * purchased_weapons;
}

int Orcs::PurchaseArmors(int purchased_armors){
    this->health_point += (3 * purchased_armors);
    return purchased_armors;
}

void Orcs::Print()const{
    cout << "\"Stop running, you'll only die tired!\"" << endl;
    Faction::Print();
}
