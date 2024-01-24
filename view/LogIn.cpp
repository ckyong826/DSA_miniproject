#include <iostream>
#include <string>

#include "../controller/ListNode.cpp"
#include "../controller/Node.cpp"
#include "../controller/CustomerList.cpp"
#include "../controller/ChefList.cpp"
#include "../view/OrderCustomer.cpp"
#include "../controller/ListNode.cpp"
#include "../view/UpdateOrderChef.cpp"
#include "../view/ViewOrderChef.cpp"

using namespace std;

bool authentication(string username, string password, int choice, CustomerList* customerList, ChefList *chefList){

    if(choice == 1){
       Customer *customer =  customerList->findCustomer(username);
        if(customer != NULL && customer->getCustomerPassword()==password)
        return 1;
    }
    else if (choice == 2){
        Chef *chef =  chefList->findChef(username);
        if(chef != NULL && chef->getChefPassword()==password)
        return 1;
    }
    cout<<"Log in failed. No user found or incorrect password."<<endl;
    return 0;
}

void displayMenu(int choice){
    int task;
    QueueOrder *qOrder = new QueueOrder;
    StackOrder *sOrder = new StackOrder;

    if (choice==1){
        cout<<"Welcome! What would you like to do ?"<<endl;
        cout<<"1. View order\n2. Add order\n0. Exit"<<endl;
        cin>>task;
        while (task==1||task==2){
            if (task==1)
            viewOrderCustomer(sOrder);
            else
            AddOrderCustomer(qOrder,sOrder);
        }
    }

    if (choice == 2){
        cout<<"Welcome! What would you like to do ?"<<endl;
        cout<<"1. View order\n2. Update order\n0. Exit"<<endl;
        cin>>task;
        while (task==1||task==2){
            if (task==1)
            viewOrdersChef(qOrder);
            else
            updateOrderStatusChef(qOrder);
        }
    }
}


int main(){

    CustomerList* customerList;
    ChefList* chefList;

    string username, password;
    int choice;
    bool valid = 0;
    do{
        cout<<"Please select your role:"<<endl;
        cout<<"1. Customer\n2. Chef"<<endl;
        cin>>choice;
        cout<<"== Log In =="<<endl;
        cout<<"User ID: "<<endl;
        cin.ignore();
        getline(cin, username);
        cout<<"Password: ";
        cin.ignore();
        getline(cin, password);
        
        valid = authentication(username, password, choice, customerList, chefList);
    }
    while (valid == 0);
    displayMenu(choice);
    return 0;
}
