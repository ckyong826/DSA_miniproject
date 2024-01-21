#include <iostream>
#include "../model/Order.h"
#include <iomanip>

using namespace std;

Order::Order() {
    this->foodID = 0;
    this->foodName = "";
    this->price = 0;
    this->quantity = 0;
}

Order::Order(int foodID, string foodName, double price, int quantity) {
    this->foodID = foodID;
    this->foodName = foodName;
    this->price = price;
    this->quantity = quantity;
}

int Order::getFoodID() {
    return this->foodID;
}

string Order::getFoodName() {
    return this->foodName;
} 

int Order::getPrice() {
    return this->price;
}

int Order::getQuantity() {
    return this->quantity;
} 

void Order::setFoodID(int foodID) {
    this->foodID = foodID;
}

void Order::setFoodName(string foodName) {
    this->foodName = foodName;
} 

void Order::setPrice(double price) {
    this->price = price;
} 

void Order::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Order::setNameANDPrice(string foodID){
    
}

void Order::printOrder() {
    cout<<fixed<<setprecision(2);
    cout << "Food ID  :  " << this->foodID << endl;
    cout << "Food Name:  " << this->foodName << endl;
    cout << "Price    :  RM" << this->price << endl;
    cout << "Quantity :  " << this->quantity << endl;
}

