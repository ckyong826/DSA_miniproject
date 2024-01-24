#include <iostream>
#include <iomanip>
#pragma once
#include "../model/ListNode.h"
#include "../model/Order.h"

using namespace std;

void QueueOrder::createQueue() {
    front = NULL;
    rear = NULL;
    size = 0;
}

void QueueOrder::createSampleQueueOrder(){
    NodeOrder *nodeOrder1 = new NodeOrder;
    NodeOrder *nodeOrder2 = new NodeOrder;
    
    nodeOrder1->order.push_back(Order{1, "XXL Chicken Chop", 12.00 , 2});
    nodeOrder1->order.push_back(Order{2, "Cabin Chicken Chop", 7.80 , 2});
    
    nodeOrder2->order.push_back(Order{4, "Fish n Chip", 12.00 , 2});
    nodeOrder2->order.push_back(Order{5, "Salmon Set", 21.30 , 2});

    enqueue(nodeOrder1);
    enqueue(nodeOrder2);
}
bool QueueOrder::isEmpty() {
    return (front == NULL);
}

void QueueOrder::enqueue(NodeOrder* newNode) {
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void QueueOrder::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        NodeOrder *temp = front;
        front = front->next;
        delete temp;
        size--;
    }
}

int QueueOrder::getSize() {
    return size;
}

NodeOrder* QueueOrder::getFront() {
    return front;
}



void StackOrder::createStack() {
    top = NULL;
    size = 0;
}

void StackOrder::createSampleStackOrder(){
    NodeOrder *nodeOrder3 = new NodeOrder;
    NodeOrder *nodeOrder4 = new NodeOrder;
    nodeOrder3->order.push_back(Order{1, "XXL Chicken Chop", 12.00 , 2});
    nodeOrder3->order.push_back(Order{2, "Cabin Chicken Chop", 7.80 , 2});
    nodeOrder4->order.push_back(Order{4, "Fish n Chip", 12.00 , 2});
    nodeOrder4->order.push_back(Order{5, "Salmon Set", 21.30 , 2});
    push(nodeOrder3);
    push(nodeOrder4);
}



bool StackOrder::isEmpty() {
    return (top == NULL);
}

void StackOrder::push(NodeOrder* newNode) {
    if (isEmpty()) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    size++;
}

void StackOrder::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        NodeOrder *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
}

int StackOrder::getSize() {
    return size;
}

NodeOrder* StackOrder::getTop() {
    return top;
}

