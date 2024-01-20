#include <iostream>

using namespace std;

class Customer{
  private:
    string customerID;
    string customerName;
    string customerAddress;
    string customerPhone;
  public:
    Customer();
    Customer(string customerID, string customerName, string customerAddress, string customerPhone);
    string getCustomerID();
    string getCustomerName();
    string getCustomerAddress();
    string getCustomerPhone();
    void setCustomerID(string customerID);
    void setCustomerName(string customerName);
    void setCustomerAddress(string customerAddress);
    void setCustomerPhone(string customerPhone);
    void printCustomer();
};