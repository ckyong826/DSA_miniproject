#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"

using namespace std;

void updateOrderStatusChef(QueueOrder* qOrder) {
    // Assuming QueueOrder has a method to get the front order
    NodeOrder* frontOrder = qOrder->getFront();

    if (frontOrder == nullptr || frontOrder->order.empty()) {
        cout << "No orders available for processing." << endl;
        return;
    }

    // Displaying orders for the chef to select
    cout << "=====================================" << endl;
    cout << "||       SELECT ORDER TO UPDATE    ||" << endl;
    cout << "=====================================" << endl;

    for (int i = 0; i < frontOrder->order.size(); i++) {
        cout << i + 1 << ". Order " << endl;
        frontOrder->order[i].printOrder();
        cout << "Status: " << frontOrder->order[i].getStatus() << endl;
        cout << "=====================================" << endl;
    }

    // Chef selects an order to update
    int choice;
    cout << "Enter the order number to update status: ";
    cin >> choice;

    // Validate the input
    if (choice >= 1 && choice <= frontOrder->order.size()) {
        // Update the status of the selected order
        int statusChoice;
        cout << "Enter the new status (1 for 'preparing', 2 for 'completed'): ";
        cin >> statusChoice;

        if (statusChoice == 1) {
            frontOrder->order[choice - 1].setStatus("Preparing");
        } else if (statusChoice == 2) {
            frontOrder->order[choice - 1].setStatus("Completed");
        } else {
            cout << "Invalid status choice. Status remains unchanged." << endl;
        }

        cout << "Order status updated successfully." << endl;
    } else {
        cout << "Invalid input. Please enter a valid order number." << endl;
    }
}
