#include <iostream>
#include "Node.h"
#pragma once
using namespace std;

class QueueOrder {
    private:
        NodeOrder *front;
        NodeOrder *rear;
        int size;
    public:
        void createQueue();
        bool isEmpty();
        void enqueue(NodeOrder* newNode);
        void dequeue();
        int getSize();
        NodeOrder* getFront();
};


class StackOrder {
    private:
        NodeOrder *top;
        int size;
    public:
        void createStack();
        bool isEmpty();
        void push(NodeOrder* newNode);
        void pop();
        int getSize();
        NodeOrder* getTop();
};
