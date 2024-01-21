#include <iostream>
#include "../model/Menu.h"

using namespace std;

Menu::Menu(){
    this->foodID[0] = 1;
    this->foodID[1] = 2;
    this->foodID[2] = 3;
    this->foodID[3] = 4;
    this->foodID[4] = 5;
    this->foodID[5] = 6;
    this->foodID[6] = 7;
    this->foodID[7] = 8;
    this->foodID[8] = 9;
    this->foodID[9] = 10;

    this->foodName[0] = "XXL Chicken Chop";
    this->foodName[1] = "DSA Chicken Chop";
    this->foodName[2] = "Carbonara Spaghetti";
    this->foodName[3] = "Fish and Chip";
    this->foodName[4] = "Salmon Set";
    this->foodName[5] = "Beef Burger";
    this->foodName[6] = "Double Beef Burger";
    this->foodName[7] = "Chicken Burger";
    this->foodName[8] = "Cheesy Chic Burger";
    this->foodName[9] = "Cheesy Beef Burger";

    this->foodPrice[0] = 12.00;
    this->foodPrice[1] = 7.80;
    this->foodPrice[2] = 12.00;
    this->foodPrice[3] = 12.00;
    this->foodPrice[4] = 21.30;
    this->foodPrice[5] = 16.00;
    this->foodPrice[6] = 25.00;
    this->foodPrice[7] = 12.00;
    this->foodPrice[8] = 13.00;
    this->foodPrice[9] = 17.00;
}

void Menu::viewMenuCustomer(){
        cout<<endl;
        cout << "=====================================" << endl;
        cout << "||          MENU CUSTOMER          ||" << endl;
        cout << "=====================================" << endl;
        cout << "|| 1. XXL Chicken Chop    RM 12.00 ||" << endl;
        cout << "|| 2. DSA Chicken Chop    RM  7.80 ||" << endl;
        cout << "|| 3. Carbonara Spaghetti RM 12.00 ||" << endl;
        cout << "|| 4. Fish and Chip       RM 12.00 ||" << endl;
        cout << "|| 5. Salmon Set          RM 21.30 ||" << endl;
        cout << "|| 6. Beef Burger         RM 16.00 ||" << endl;
        cout << "|| 7. Double Beef Burger  RM 25.00 ||" << endl;
        cout << "|| 8. Chicken Burger      RM 12.00 ||" << endl;
        cout << "|| 9. Cheesy Chic Burger  RM 13.00 ||" << endl;
        cout << "|| 10.Cheesy Beef Burger  RM 17.00 ||" << endl;
        cout << "=====================================" << endl;
        cout<<endl;
}

int Menu::getMenuSize(){
    return 10;
}

string Menu::getFoodName(int foodID){
    return this->foodName[foodID-1];
}

double Menu::getFoodPrice(int foodID){
    return this->foodPrice[foodID-1];
}



