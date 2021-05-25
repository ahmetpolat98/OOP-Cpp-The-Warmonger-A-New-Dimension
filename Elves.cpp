//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Elves.h"

using namespace std;


Elves::Elves(string name, int number_of_unit, int attack_point, int health_point, int unit_regeneration_number)
    :Faction(name, number_of_unit, attack_point, health_point, unit_regeneration_number){}


void Elves::PerformAttack(){
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
            if(first_enemy_name == "Dwarves"){
                int update_attack_point = (150 * attack_point1) / 100;
                this->first_enemy->ReceiveAttack(this->name, update_attack_point);
            }
            else{
                this->first_enemy->ReceiveAttack(this->name, attack_point1);
            }            
        }
        else{//attack second enemy
            if(second_enemy_name == "Dwarves"){
                int update_attack_point = (150 * attack_point1) / 100;
                this->second_enemy->ReceiveAttack(this->name, update_attack_point);
            }
            else{
                this->second_enemy->ReceiveAttack(this->name, attack_point1);
            }          
        }      
    }
    else if(num_enemy == 2){ //both enemy alive
        if(first_enemy_name == "Orcs"){
            army1 = (60 * this->number_of_unit) / 100;
            army2 = number_of_unit - army1;

            attack_point1 = army1 * this->attack_point;
            attack_point2 = army2 * this->attack_point;

            int update_attack_point = (150 * attack_point2) / 100;            

            this->first_enemy->ReceiveAttack(this->name, attack_point1);
            this->second_enemy->ReceiveAttack(this->name, update_attack_point);
        }
        else{
            army2 = (60 * this->number_of_unit) / 100;
            army1 = number_of_unit - army2;

            attack_point1 = army1 * this->attack_point;
            attack_point2 = army2 * this->attack_point;

            int update_attack_point = (150 * attack_point1) / 100;

            this->first_enemy->ReceiveAttack(this->name, update_attack_point);
            this->second_enemy->ReceiveAttack(this->name, attack_point2);
        }
    }
    else{ //there is no alive enemy
        cout << "There is no enemy to attack" << endl;
    }
}

void Elves::ReceiveAttack(string attacked_name, int attacked_point){
    int received_attack;
    if(attacked_name == "Orcs"){
        received_attack = (125 * attacked_point) / 100;
    }
    else if(attacked_name == "Dwarves"){
        received_attack = (75 * attacked_point) / 100;
    }
    else{
        cout << "Invalid receive attack" << endl;
    }
    int reduced_unit = received_attack / this->health_point;
    this->number_of_unit -= reduced_unit;
}

int Elves::PurchaseWeapons(int purchased_weapons){
    this->attack_point += (2 * purchased_weapons);
    return 15 * purchased_weapons;
}

int Elves::PurchaseArmors(int purchased_armors){
    this->health_point += (4 * purchased_armors);
    return 5 * purchased_armors;
}

void Elves::Print()const{
    cout << "\"You cannot reach our elegance.\"" << endl;
    Faction::Print();
}