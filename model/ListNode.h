#include <iostream>
#include "Node.h"
#pragma once
using namespace std;

class QueueOrder {
    private:
        NodeOrder *head;
        NodeOrder *tail;
        int size;
    public:
        QueueOrder();
        bool isEmpty();
        void enqueue(NodeOrder* newNode);
        void dequeue();
        int getSize();
        NodeOrder* getFront();
};
