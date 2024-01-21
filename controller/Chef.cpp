#include <iostream>
#include <iomanip>
#include "../model/Chef.h"

using namespace std;

Chef::Chef() {
    this->chefID = "";
    this->chefName = "";
    this->chefPassword = "";
}

Chef::Chef(string chefID, string chefName, string chefPassword) {
    this->chefID = chefID;
    this->chefName = chefName;
    this->chefPassword = chefPassword;
}

string Chef::getChefID() {
    return this->chefID;
}

string Chef::getChefName() {
    return this->chefName;
}

string Chef::getChefPassword() {
    return this->chefPassword;
}   

void Chef::setChefID(string chefID) {
    this->chefID = chefID;
}

void Chef::setChefName(string chefName) {
    this->chefName = chefName;
}

void Chef::setChefPassword(string chefPassword) {
    this->chefPassword = chefPassword;
}

