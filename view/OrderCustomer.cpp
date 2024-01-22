#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"
#include "../controller/Node.cpp"
#include "../controller/Menu.cpp"
#include "../controller/Order.cpp"
#include <string>
#include <vector>

using namespace std;

void viewOrderCustomer(StackOrder* sOrder){
    NodeOrder* temp = sOrder->getTop();
    int count=1;
    cout << "===== History Order =====" << endl;
    while (temp){
        cout << " Previous Order " << count << endl;
        temp->displayOrder();
        temp = temp->next;
    }
        cout << endl;
        cout << "=========================" << endl;
}

void AddOrderCustomer(QueueOrder* qOrder,StackOrder* sOrder){
    Menu menu;
    NodeOrder* newOrder = new NodeOrder;
    
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
        cout<<endl;
        if (choice==1){
                int id, quantity;
                cout <<"====Add Food====" << endl;
                cout <<"Here is the menu"<<endl;
                menu.viewMenuCustomer();
                cout << "Enter Food ID : ";
                cin >> id;
                if (id > menu.getMenuSize()){
                    cout << "Wrong Input" << endl;
                    continue;
                }
                cin.ignore();
                string name = menu.getFoodName(id);
                double price = menu.getFoodPrice(id);
                cout << "Enter Quantity: ";
                cin >> quantity;
                cin.ignore();
                newOrder->order.push_back(Order{id, name, price, quantity});
                cout << "Add Success" << endl;
                cout<<endl;
        }
        else if (choice==2){
                cout << "Delete Food" << endl;
                SortOrder sort;
                sort.quickSortOrder(0, newOrder->order.size() - 1, newOrder);
                newOrder->displayOrder();
                int i;
                cout << "Enter Order Number: ";
                cin >> i;
                cin.ignore();
                if (i > newOrder->order.size()){
                    cout << "Wrong Input" << endl;
                    continue;
                }
                newOrder->order.erase(newOrder->order.begin() + i - 1);
                newOrder->displayOrder();
                cout << "Delete Success" << endl;
                cout<<endl;
                }
        else if (choice==3){
                cout << "View Menu" << endl;
                menu.viewMenuCustomer();
                }
        else if (choice==4){
                int choice2;
                cout << "View Sorted Order" << endl;
                SortOrder sort;
                sort.quickSortOrder(0, newOrder->order.size() - 1, newOrder);
                newOrder->displayOrder();
                }
        else if (choice==5){
                cout << "Checkout" << endl;
                qOrder->enqueue(newOrder);
                sOrder->push(newOrder);
                cout << "Checkout Success" << endl;
                cout<<endl;
                choice = 0;
                }
        else if (choice==6){
                cout << "Back" << endl;
                choice = 0;
                }
        else{
                cout << "Wrong Input" << endl;
                
        }
    }
    while (choice !=0);


}


