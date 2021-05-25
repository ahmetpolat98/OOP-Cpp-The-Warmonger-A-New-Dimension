//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Faction.h"

using namespace std;

Faction::Faction(string name, int number_of_unit, int attack_point, int health_point, int unit_regeneration_number)
    :name(name), number_of_unit(number_of_unit), attack_point(attack_point), health_point(health_point), unit_regeneration_number(unit_regeneration_number)
    {
        first_enemy = NULL;
        second_enemy = NULL;
        is_alive = true;
        total_health = number_of_unit * health_point;
    }

void Faction::AssignEnemies(Faction* first, Faction* second){
    first_enemy = first;
    second_enemy = second;
}

void Faction::Print()const{
    cout << "Faction Name:         " << this->name << endl;
    cout << "Status:               ";
    if(this->is_alive)
        cout << "Alive" << endl;
    else
        cout << "Defeated" << endl;
    cout << "Number of Units:      " << this->number_of_unit << endl;
    cout << "Attack Point:         " << this->attack_point << endl;
    cout << "Health Point:         " << this->health_point << endl;
    cout << "Unit Regen Number:    " << this->unit_regeneration_number << endl;
    cout << "Total Faction Health: " << this->total_health << endl;

}

void Faction::EndTurn(){
    if (number_of_unit <= 0)
    {
        number_of_unit = 0;
        is_alive = false;
    }
    else
    {
        number_of_unit += unit_regeneration_number;
    }   
    total_health = number_of_unit * health_point;
}


string Faction::getName()const{
    return this->name;
}
Faction* Faction::getFirst_enemy()const{
    return this->first_enemy;
}
Faction* Faction::getSecond_enemy()const{
    return this->second_enemy;
}
int Faction::getNumber_of_unit()const{
    return this->number_of_unit;
}
int Faction::getAttack_point()const{
    return this->attack_point;
}
int Faction::getHealth_point()const{
    return this->health_point;
}
int Faction::getUnit_regeneration_number()const{
    return this->unit_regeneration_number;
}
int Faction::getTotal_health()const{
    return this->total_health;
}
bool Faction::IsAlive()const{
    return this->is_alive;
}

void Faction::setName(string name){
    this->name = name;
}
void Faction::setFirst_enemy(Faction* first_enemy){
    this->first_enemy = first_enemy;
}
void Faction::setSecond_enemy(Faction* second_enemy){
    this->second_enemy = second_enemy;
}
void Faction::setNumber_of_unit(int in){
    this->number_of_unit = in;
}
void Faction::setAttack_point(int in){
    this->attack_point = in;
}
void Faction::setHealth_point(int in){
    this->health_point = in;
}
void Faction::setUnit_regeneration_number(int in){
    this->unit_regeneration_number = in;
}
void Faction::setTotal_health(int in){
    this->total_health = in;
}
void Faction::setIs_alive(bool in){
    this->is_alive = in;
}

