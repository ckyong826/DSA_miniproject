#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"
using namespace std;

class CustomerNode {
public:
    Customer customer;
    CustomerNode* next;

    CustomerNode();
    CustomerNode(Customer customer);
};

class CustomerList {
private:
    CustomerNode* head;

public:
    CustomerList();
    void createCustomerList();
    void addCustomer(string customerID, string customerName, string customerAddress, string customerPhone, string customerPassword);
    void deleteCustomer(string customerID);
    Customer* findCustomer(string customerID);
};

#endif 
