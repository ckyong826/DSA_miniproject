#include <iostream>
#include "Order.h"
#include "Customer.h"
#include <vector>

using namespace std;

class NodeOrder {
    public:
        vector <Order> order;
        NodeOrder *next;
        NodeOrder();
        NodeOrder(vector <Order> order);
};

class NodeCustomer {
    public:
        Customer customer;
        NodeCustomer *next;
        NodeCustomer();
        NodeCustomer(Customer customer);
};