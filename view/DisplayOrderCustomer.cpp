#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"
#include "ViewMenuCustomer.cpp"
#include <string>

using namespace std;

void OrderCustomer(QueueOrder* order){
    NodeOrder* newOrder;
    string id;
    int quantity;
    int i=0;
    int choice;
    do{
        cout << "===== Order =====" << endl;
        cout << "1. Add Food" << endl;
        cout << "2. Delete Food" << endl;
        cout << "3. View Menu" << endl;
        cout << "4. View Order" << endl;
        cout << "5. Checkout " <<endl;
        cout << "0. Back" << endl;
        cout << "Choose: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Add Food" << endl;
                cout << "Enter Food ID: ";
                getline(cin, id);
                newOrder->order[i].setFoodID(id);
                cout << "Enter Food ID: ";
                cin >> quantity;
                newOrder->order[i].setQuantity(quantity);
                i++;
                break;
            case 2:
                cout << "Delete Food" << endl;
                
                break;
            case 3:
                cout << "View Menu" << endl;
                viewMenuCustomer();
                break;
            case 4:
                cout << "View Order" << endl;
                break;
            case 5:
                cout << "Checkout" << endl;
                break;
            case 0:
                cout << "Back" << endl;
                break;
            default:
                cout << "Wrong Input" << endl;
                break;
        }
    }
    while (choice !=0);


}

void displayOrder(NodeOrder* order){
    //display each order in the order
    double total = 0;
    cout<<fixed<<setprecision(2);
    cout << "=====================================" << endl;
    cout << "||          ORDER                  ||" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < order->order.size(); i++){
        order->order[i].printOrder();
    }
    cout << "=====================================" << endl;
    cout << "||          TOTAL                  ||" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < order->order.size(); i++){
        total += order->order[i].getPrice() * order->order[i].getQuantity();
    }
    cout << "Total: RM" << total << endl;
    cout << "=====================================" << endl;
}