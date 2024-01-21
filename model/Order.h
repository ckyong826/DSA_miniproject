#include <iostream>
#pragma once
using namespace std;

class Order{
  private:
    int foodID;
    string foodName;
    double price;
    int quantity;
  public:
    Order();
    Order(int foodID, string foodName, double price, int quantity);
    int getFoodID();
    string getFoodName();
    int getPrice();
    int getQuantity();
    void setFoodID(int foodID);
    void setFoodName(string foodName);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setNameANDPrice(string foodID);
    void printOrder();
};