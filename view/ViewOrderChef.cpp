#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"

using namespace std;

void viewOrdersChef(QueueOrder* qOrder) {
    // Assuming QueueOrder has a method to get the front order
    NodeOrder* frontOrder = qOrder->getFront();

    if (frontOrder == nullptr || frontOrder->order.empty()) {
        cout << "No orders available for processing." << endl;
        return;
    }

    // Displaying orders with status
    cout << "=====================================" << endl;
    cout << "||       ORDERS FOR PROCESSING     ||" << endl;
    cout << "=====================================" << endl;

    for (int i = 0; i < frontOrder->order.size(); i++) {
        cout << i + 1 << ". Order " << endl;
        frontOrder->order[i].printOrder();
        // You can display status here based on the order's status in your model
        cout << "Status: " << frontOrder->order[i].getStatus() << endl;
        cout << "=====================================" << endl;
    }
}