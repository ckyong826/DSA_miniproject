#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"
#include "../controller/Order.cpp" 


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
        cout << "Status: " << frontOrder->order[i].getStatus() << endl;
        cout << "=====================================" << endl;
    }
}

int main() {
    QueueOrder qOrder; 
    // Adding some sample orders for testing
    Order order1(1, "Burger", 10.99, 2);
    Order order2(2, "Pizza", 15.99, 1);

    // Setting different statuses for demonstration
    order1.setStatus("Pending");
    order2.setStatus("Preparing");

    viewOrdersChef(&qOrder);
    return 0;
}