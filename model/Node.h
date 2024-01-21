#include <iostream>
#include "Order.h"
#include "Customer.h"
#include <vector>
#pragma once
using namespace std;

class NodeOrder {
    public:
        vector <Order> order;
        NodeOrder *next;
};

class NodeCustomer {
    public:
        Customer customer;
        NodeCustomer *next;
};