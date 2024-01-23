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

