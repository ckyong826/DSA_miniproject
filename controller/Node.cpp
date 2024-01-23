#include <iostream>
#include <iomanip>
#include "../model/Node.h"
#include "../model/Order.h"
#include "../model/Customer.h"
#pragma once

using namespace std;

void NodeOrder::displayOrder(){
    
    //display each order in the order
    double total = 0;
    cout<<fixed<<setprecision(2);
    cout << "=====================================" << endl;
    cout << "||          ORDER                  ||" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < order.size(); i++){
        cout << i+1 << " Order " << endl;
        order[i].printOrder();
        cout << endl;
    }
    cout << "=====================================" << endl;
    cout << "||          TOTAL                  ||" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < order.size(); i++){
        total += order[i].getPrice() * order[i].getQuantity();
    }
    cout << "Total: RM" << total << endl;
    cout << "=====================================" << endl;
    cout<<endl;
}

void SortOrder::quickSortOrder(int left, int right, NodeOrder *node) {
    int i, j;
    partitionOrder(left, right, i, j, node);
    if (left < j) {
        quickSortOrder(left, j, node);
    }
    if (i < right) {
        quickSortOrder(i, right, node);
    }
}

void SortOrder::partitionOrder(int left, int right, int &i, int &j, NodeOrder *node) {
    i = left;
    j = right;
    Order pivot = node->order[(left + right) / 2];
    do {
        while (node->order[i].getFoodID() < pivot.getFoodID()) {
            i++;
        }
        while (node->order[j].getFoodID() > pivot.getFoodID()) {
            j--;
        }
        if (i <= j) {
            swapOrder(i, j, node);
            i++;
            j--;
        }
    } while (i <= j);
}

void SortOrder::swapOrder(int left, int right, NodeOrder *node) {
    Order temp = node->order[left];
    node->order[left] = node->order[right];
    node->order[right] = temp;
}