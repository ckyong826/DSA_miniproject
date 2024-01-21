#include <iostream>
#pragma once
using namespace std;

class Menu{
  private:
    int  foodID[10] ;
    string foodName[10] ;
    double foodPrice[10] ;
  public:
    Menu();
    void viewMenuCustomer();
    int getMenuSize();
    string getFoodName(int foodID);
    double getFoodPrice(int foodID);
};