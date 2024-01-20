#include <iostream>

using namespace std;

class Order{
  private:
    string foodID;
    string foodName;
    double price;
    int quantity;
  public:
    Order();
    Order(string foodID, string foodName, double price, int quantity);
    string getFoodID();
    string getFoodName();
    int getPrice();
    int getQuantity();
    void setFoodID(string foodID);
    void setFoodName(string foodName);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setNameANDPrice(string foodID);
    void printOrder();
};