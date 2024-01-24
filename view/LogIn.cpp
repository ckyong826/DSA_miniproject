#include <iostream>
#include <string>

#include "../controller/ListNode.cpp"
#include "../controller/Node.cpp"
#include "../controller/CustomerList.cpp"
#include "../controller/ChefList.cpp"
#include "../view/OrderCustomer.cpp"
#include "../controller/ListNode.cpp"
#include "../view/OrderChef.cpp"

using namespace std;

bool authentication(string username, string password, int choice, CustomerList* customerList, ChefList *chefList){

    if(choice == 1){
       Customer *customer =  customerList->findCustomer(username);
        if(customer != NULL && customer->getCustomerPassword()==password)
        return 1;
    }
    else if (choice == 2){
        Chef *chef =  chefList->findChef(username);
        string chefPassword = chef->getChefPassword();
        if(chef != NULL && password == chefPassword){
            return 1;
        }
    }
    cout<<"Log in failed. No user found or incorrect password."<<endl;
    return 0;
}

void displayMenu(int choice){
    int task;
    QueueOrder *qOrder = new QueueOrder;
    StackOrder *sOrder = new StackOrder;
    qOrder->createQueue();
    sOrder->createStack();
    qOrder->createSampleQueueOrder();
    sOrder->createSampleStackOrder();

    if (choice==1){
        do{
            cout<<"Welcome Customer! What would you like to do ?"<<endl;
            cout<<"1. View order\n2. Add order\n0. Exit"<<endl;
            cin>>task;
            if (task==1){
                viewOrderCustomer(sOrder);
            }
            
            else if (task==2)
            AddOrderCustomer(qOrder,sOrder);
            else
            return;
        }while (task==1||task==2);
    }

    if (choice == 2){
        do{
            cout<<"Welcome Chef! What would you like to do ?"<<endl;
            cout<<"1. View order\n2. Update order\n0. Exit"<<endl;
            cin>>task;
            if (task==1)
            viewOrdersChef(qOrder);
            else if (task==2)
            updateOrderStatusChef(qOrder);
            else 
            return;
        }
        while (task==1||task==2);
    }
}

