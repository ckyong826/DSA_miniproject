#include <iostream>
#include <iomanip>
#include "../controller/ListNode.cpp"
#include "../controller/Node.cpp"
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
        cout << i+1 << " Order " << endl;
        newOrder->order[i].printOrder();
        cout << endl;
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
                displayOrder(newOrder);
                int i;
                cout << "Enter Order Number: ";
                cin >> i;
                cin.ignore();
                if (i > newOrder->order.size()){
                    cout << "Wrong Input" << endl;
                    continue;
                }
                newOrder->order.erase(newOrder->order.begin() + i - 1);
                displayOrder(newOrder);
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
                displayOrder(newOrder);
                }
        else if (choice==5){
                cout << "Checkout" << endl;
                qOrder->enqueue(newOrder);
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



int main(){
    QueueOrder* order = new QueueOrder();
    OrderCustomer(order);
    return 0;
}