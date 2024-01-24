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
        void createSampleQueueOrder();
};


class StackOrder {
    private:
        NodeOrder *top;
        int size;
    public:
        
        void createStack();
        void createSampleStackOrder();
        bool isEmpty();
        void push(NodeOrder* newNode);
        void pop();
        int getSize();
        NodeOrder* getTop();
};
