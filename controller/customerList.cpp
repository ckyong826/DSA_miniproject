#include <iostream>
#include "../model/customerList.h"
#include "../controller/Customer.cpp"
using namespace std;

CustomerNode::CustomerNode() : next(NULL) {}

CustomerNode::CustomerNode(Customer customer) : customer(customer), next(NULL) {}

CustomerList::CustomerList() : head(NULL) {}

void CustomerList::addCustomer(string customerID, string customerName, string customerAddress, string customerPhone, string customerPassword) {
    Customer customer(customerID, customerName, customerAddress, customerPhone, customerPassword);
    CustomerNode* newNode = new CustomerNode(customer);

    if (head == NULL) {
        head = newNode;
    } else {
        CustomerNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void CustomerList::deleteCustomer(string customerID) {
    if (head == NULL) {
        cout << "Customer list is empty. Cannot delete." << endl;
        return;
    }

    if (head->customer.getCustomerID() == customerID) {
        CustomerNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Customer with ID " << customerID << " deleted successfully." << endl;
        return;
    }

    CustomerNode* current = head;
    CustomerNode* previous = NULL;

    while (current != NULL && current->customer.getCustomerID() != customerID) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Customer with ID " << customerID << " not found in the list." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Customer with ID " << customerID << " deleted successfully." << endl;
}

Customer* CustomerList::findCustomer(string customerID) {
    CustomerNode* current = head;

    while (current != NULL) {
        if (current->customer.getCustomerID() == customerID) {
            return &(current->customer); 
        }
        current = current->next;
    }

    return NULL; 
}