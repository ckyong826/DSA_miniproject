#ifndef CHEFLIST.H
#define CHEFLIST_H

#include "Chef.h"
using namespace std;

class ChefNode {
public:
    Chef chef;
    ChefNode* next;

    ChefNode();
    ChefNode(Chef chef);
};

class ChefList {
private:
    ChefNode* head;

public:
    ChefList();
    void addChef(string chefID, string chefName, string chefPassword);
    void deleteChef(string chefID);
    Chef* findChef(string chefID);
};

#endif