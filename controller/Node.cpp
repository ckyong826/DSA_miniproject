#include <iostream>
#include <iomanip>
#include "./model/Node.h"

using namespace std;

NodeOrder::NodeOrder() {
    this->next = NULL;
}

NodeOrder::NodeOrder(vector <Order> order) {
    this->order = order;
    this->next = NULL;
}

NodeCustomer::NodeCustomer() {
    this->next = NULL;
}

NodeCustomer::NodeCustomer(Customer customer) {
    this->customer = customer;
    this->next = NULL;
}

