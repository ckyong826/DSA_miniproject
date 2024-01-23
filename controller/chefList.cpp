// chefList.cpp
#include "../model/ChefList.h"

ChefNode::ChefNode() : next(NULL) {}

ChefNode::ChefNode(Chef chef) : chef(chef), next(NULL) {}

ChefList::ChefList() : head(NULL) {}

void ChefList::addChef(string chefID, string chefName, string chefPassword) {
    Chef chef(chefID, chefName, chefPassword);
    ChefNode* newNode = new ChefNode(chef);

    if (head == NULL) {
        head = newNode;
    } else {
        ChefNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void ChefList::deleteChef(string chefID) {
    if (head == NULL) {
        cout << "Chef list is empty. Cannot delete." << endl;
        return;
    }

    if (head->chef.getChefID() == chefID) {
        ChefNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Chef with ID " << chefID << " deleted successfully." << endl;
        return;
    }

    ChefNode* current = head;
    ChefNode* previous = NULL;

    while (current != NULL && current->chef.getChefID() != chefID) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Chef with ID " << chefID << " not found in the list." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Chef with ID " << chefID << " deleted successfully." << endl;
}

Chef* ChefList::findChef(string chefID) {
    ChefNode* current = head;

    while (current != NULL) {
        if (current->chef.getChefID() == chefID) {
            return &(current->chef);
        }
        current = current->next;
    }

    return NULL;
}