//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          23/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Merchant.h"

using namespace std;


Merchant::Merchant(int starting_weapon_point, int starting_armor_point)
    :starting_weapon_point(starting_weapon_point), starting_armor_point(starting_armor_point)
    {
        this->first_faction = NULL;
        this->second_faction = NULL;
        this->third_faction = NULL;
        this->revenue = 0;
        this->weapon_point = starting_weapon_point;
        this->armor_point = starting_armor_point;
    }

void Merchant::AssignFactions(Faction* first, Faction* second, Faction* third){
    first_faction = first;
    second_faction = second;
    third_faction = third;
}

bool Merchant::SellWeapons(string selled_name, int amount_of_selled){
    int which_faction = 0;
    if(first_faction->getName() == selled_name){
        which_faction = 1;
    }
    else if(second_faction->getName() == selled_name){
        which_faction = 2;
    }
    else if(third_faction->getName() == selled_name){
        which_faction = 3;
    }
    else{
        cout << "There is no faction with the name you want" << endl;
        return false;
    }

    switch(which_faction) {
        case 1:
            if(first_faction->IsAlive()){
                if(amount_of_selled > this->weapon_point){
                    cout << "You try to sell more weapons than you have in possession" << endl;
                    return false;
                }
                else{
                    this->revenue += first_faction->PurchaseWeapons(amount_of_selled);
                    weapon_point -= amount_of_selled;
                    cout << "Weapons sold!" << endl;
                    return true;
                }              
            }
            else{
                cout << "The faction you want to sell weapons is dead!" << endl;
                return false;
            }
            break;
        case 2:
            if(second_faction->IsAlive()){
                if(amount_of_selled > this->weapon_point){
                    cout << "You try to sell more weapons than you have in possession" << endl;
                    return false;
                }
                else{
                    this->revenue += second_faction->PurchaseWeapons(amount_of_selled);
                    weapon_point -= amount_of_selled;
                    cout << "Weapons sold!" << endl;
                    return true;
                }              
            }
            else{
                cout << "The faction you want to sell weapons is dead!" << endl;
                return false;
            }
            break;
        case 3:
            if(third_faction->IsAlive()){
                if(amount_of_selled > this->weapon_point){
                    cout << "You try to sell more weapons than you have in possession" << endl;
                    return false;
                }
                else{
                    this->revenue += third_faction->PurchaseWeapons(amount_of_selled);
                    weapon_point -= amount_of_selled;
                    cout << "Weapons sold!" << endl;
                    return true;
                }              
            }
            else{
                cout << "The faction you want to sell weapons is dead!" << endl;
                return false;
            }
            break;   
    }
    return false;
}


bool Merchant::SellArmors(string selled_name, int amount_of_selled){
    int which_faction = 0;
    if(first_faction->getName() == selled_name){
        which_faction = 1;
    }
    else if(second_faction->getName() == selled_name){
        which_faction = 2;
    }
    else if(third_faction->getName() == selled_name){
        which_faction = 3;
    }
    else{
        cout << "There is no faction with the name you want" << endl;
        return false;
    }

    switch(which_faction) {
        case 1:
            if(first_faction->IsAlive()){
                if(amount_of_selled > this->armor_point){
                    cout << "You try to sell more armors than you have in possession." << endl;
                    return false;
                }
                else{
                    this->revenue += first_faction->PurchaseArmors(amount_of_selled);
                    armor_point -= amount_of_selled;
                    cout << "Armors sold!" << endl;
                    return true;
                }              
            }
            else{
                cout << "The faction you want to sell armors is dead!" << endl;
                return false;
            }
            break;
        case 2:
            if(second_faction->IsAlive()){
                if(amount_of_selled > this->armor_point){
                    cout << "You try to sell more armors than you have in possession." << endl;
                    return false;
                }
                else{
                    this->revenue += second_faction->PurchaseArmors(amount_of_selled);
                    armor_point -= amount_of_selled;
                    cout << "Armors sold!" << endl;
                    return true;
                }              
            }
            else{
                cout << "The faction you want to sell armors is dead!" << endl;
                return false;
            }
            break;
        case 3:
            if(third_faction->IsAlive()){
                if(amount_of_selled > this->armor_point){
                    cout << "You try to sell more armors than you have in possession." << endl;
                    return false;
                }
                else{
                    this->revenue += third_faction->PurchaseArmors(amount_of_selled);
                    armor_point -= amount_of_selled;
                    cout << "Armors sold!" << endl;
                    return true;
                }              
            }
            else{
                cout << "The faction you want to sell armors is dead!" << endl;
                return false;
            }
            break;   
    }
    return false;
}

void Merchant::EndTurn(){
    weapon_point = starting_weapon_point;
    armor_point = starting_armor_point;
}


Faction* Merchant::GetFirst_faction()const{
    return this->first_faction;
}
Faction* Merchant::GetSecond_faction()const{
    return this->second_faction;
}
Faction* Merchant::GetThird_faction()const{
    return this->third_faction;
}
int Merchant::GetStarting_weapon_point()const{
    return this->starting_weapon_point;
}
int Merchant::GetStarting_armor_point()const{
    return this->starting_armor_point;
}
int Merchant::GetWeaponPoints()const{
    return this->weapon_point;
}
int Merchant::GetArmorPoints()const{
    return this->armor_point;
}
int Merchant::GetRevenue()const{
    return this->revenue;
}

void Merchant::setFirst_faction(Faction* in){
    this->first_faction = in;
}
void Merchant::setSecond_faction(Faction* in){
    this->second_faction = in;
}
void Merchant::setThird_faction(Faction* in){
    this->third_faction = in;
}
void Merchant::setStarting_weapon_point(int in){
    this->starting_weapon_point = in;
}
void Merchant::setStarting_armor_point(int in){
    this->starting_armor_point = in;
}
void Merchant::setWeapon_point(int in){
    this->weapon_point = in;
}
void Merchant::setArmor_point(int in){
    this->armor_point = in;
}
void Merchant::setRevenue(int in){
    this->revenue = in;
}
