#include <iostream>
#pragma once

using namespace std;

class Chef{
  private:
    string chefID;
    string chefName;
    string chefPassword;
  public:
    Chef();
    Chef(string chefID, string chefName, string chefPassword);
    string getChefID();
    string getChefName();
    string getChefPassword();
    void setChefID(string chefID);
    void setChefName(string chefName);
    void setChefPassword(string chefPassword);
    void printChef();
};