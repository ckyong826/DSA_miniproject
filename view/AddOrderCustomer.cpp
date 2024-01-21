#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"
#include "../controller/Menu.cpp"
#include "../controller/Order.cpp"
#include <string>
#include <vector>

using namespace std;

void displayOrder(NodeOrder* newOrder){
    //display each order in the order
    double total = 0;
    cout<<fixed<<setprecision(2);
    cout << "=====================================" << endl;
    cout << "||          ORDER                  ||" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < newOrder->order.size(); i++){
        newOrder->order[i].printOrder();
    }
    cout << "=====================================" << endl;
    cout << "||          TOTAL                  ||" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < newOrder->order.size(); i++){
        total += newOrder->order[i].getPrice() * newOrder->order[i].getQuantity();
    }
    cout << "Total: RM" << total << endl;
    cout << "=====================================" << endl;
    cout<<endl;
}

void OrderCustomer(QueueOrder* qOrder){
    Menu menu;
    NodeOrder* newOrder = new NodeOrder;
    int id;
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
        if (choice==1){
                cout << "Add Food" << endl;
                cout<<"Here is the menu !"<<endl;
                menu.viewMenuCustomer();
                cout << "Enter Food ID : ";
                cin >> id;
                cin.ignore();
                string name = menu.getFoodName(id);
                double price = menu.getFoodPrice(id);
                cout << "Enter Quantity: ";
                cin >> quantity;
                cin.ignore();
                newOrder->order.push_back(Order{id, name, price, quantity});
                i++;
        }
        else if (choice==2){
                cout << "Delete Food" << endl;
                
                }
        else if (choice==3){
                cout << "View Menu" << endl;
                menu.viewMenuCustomer();
                }
        else if (choice==4){
                int choice2;
                cout << "View Order" << endl;
                cout << "Unsorted Order - 1" << endl;
                cout << "Sorted Order   - 2" << endl;
                cout << "Choose: ";
                cin >> choice2;
                switch (choice2){
                    case 1:
                        cout << "Unsorted Order" << endl;
                        displayOrder(newOrder);
                        break;
                    case 2:
                        cout << "Sorted Order" << endl;
                        break;
                    default:
                        cout << "Wrong Input" << endl;
                        break;
                }
                }
        else if (choice==5){
                cout << "Checkout" << endl;
                }
        else if (choice==6){
                cout << "Back" << endl;
                }
        else{
                cout << "Wrong Input" << endl;
                
        }
    }
    while (choice !=0);


}



int main(){
    QueueOrder* order = new QueueOrder();
    OrderCustomer(order);
    return 0;
}