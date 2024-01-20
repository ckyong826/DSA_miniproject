#include <iostream>
#include <iomanip>
#include "./model/ListNode.h"
#include "Order.cpp"

using namespace std;

QueueOrder::QueueOrder() {
    this->head = NULL;
    this->tail = NULL;
}

bool QueueOrder::isEmpty() {
    return (this->head == NULL && this->tail == NULL);
}

void QueueOrder::enqueue(vector <Order> order, int price) {
    NodeOrder *newNode = new NodeOrder(order);
    if (isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

void QueueOrder::dequeue() {
    if (!isEmpty()) {
        NodeOrder *temp = this->head;
        if (this->head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        } else {
            this->head = this->head->next;
        }
        delete temp;
        this->size--;
    }
}

int QueueOrder::getSize() {
    return this->size;
}

vector <Order> QueueOrder::getFront() {
    return this->head->order;
}

