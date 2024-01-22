#include <iostream>
#include "Order.h"
#include "Customer.h"
#include <vector>
#pragma once
using namespace std;

struct NodeOrder {
    public:
        vector <Order> order;
        NodeOrder *next;
        void displayOrder();
};

class SortOrder{
    public:
        void quickSortOrder(int left, int right, NodeOrder *node);
        void partitionOrder(int left, int right, int &i, int &j, NodeOrder *node);
        void swapOrder(int left, int right, NodeOrder *node);
};

struct NodeCustomer {
    public:
        Customer customer;
        NodeCustomer *next;
};