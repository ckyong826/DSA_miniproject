#include <iostream>
#include "Node.h"

using namespace std;

class QueueOrder {
    private:
        NodeOrder *head;
        NodeOrder *tail;
        int size;
    public:
        QueueOrder();
        bool isEmpty();
        void enqueue(vector <Order> order, int price);
        void dequeue();
        int getSize();
        vector <Order> getFront();
};
