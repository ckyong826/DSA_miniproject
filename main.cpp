#include <iostream>
#include "view/LogIn.cpp"

using namespace std;

int main(){
    CustomerList* customerList = new CustomerList;
    ChefList* chefList = new ChefList;
    chefList->createSampleChefList();
    customerList->createSampleCustomerList();
    string username, password;
    int choice;
    bool valid = 0;
    do{
        cout<<"Please select your role:"<<endl;
        cout<<"1. Customer \n2. Chef"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        system("cls");
        cout<<"== Log In =="<<endl;
        cout<<"User ID : ";
        cin.ignore();
        getline(cin, username);
        cout<<"Password: ";
        getline(cin, password);
        system("cls");
        valid = authentication(username, password, choice, customerList, chefList);
    }
    while (valid == 0);
    displayMenu(choice);
    return 0;
}