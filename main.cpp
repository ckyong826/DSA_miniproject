#include <iostream>
#include "view/OrderCustomer.cpp"

using namespace std;

int main(){
    // Pre Data Set
    // Chef Queue Order
    
    QueueOrder *queueOrder = new QueueOrder;
    queueOrder->createQueue();
    NodeOrder *nodeOrder1 = new NodeOrder;
    NodeOrder *nodeOrder2 = new NodeOrder;
    
    nodeOrder1->order.push_back(Order{1, "XXL Chicken Chop", 12.00 , 2});
    nodeOrder1->order.push_back(Order{2, "Cabin Chicken Chop", 7.80 , 2});
    
    nodeOrder2->order.push_back(Order{4, "Fish n Chip", 12.00 , 2});
    nodeOrder2->order.push_back(Order{5, "Salmon Set", 21.30 , 2});

    queueOrder->enqueue(nodeOrder1);
    queueOrder->enqueue(nodeOrder2);
    
    // Customer Stack Order
    StackOrder *stackOrder = new StackOrder;
    stackOrder->createStack();
    NodeOrder *nodeOrder3 = new NodeOrder;
    NodeOrder *nodeOrder4 = new NodeOrder;
    nodeOrder3->order.push_back(Order{1, "XXL Chicken Chop", 12.00 , 2});
    nodeOrder3->order.push_back(Order{2, "Cabin Chicken Chop", 7.80 , 2});
    nodeOrder4->order.push_back(Order{4, "Fish n Chip", 12.00 , 2});
    nodeOrder4->order.push_back(Order{5, "Salmon Set", 21.30 , 2});
    stackOrder->push(nodeOrder3);
    stackOrder->push(nodeOrder4);
    AddOrderCustomer(queueOrder, stackOrder);
    cout << "Queue Order Size: " << queueOrder->getSize() << endl;
    cout << "Stack Order Size: " << stackOrder->getSize() << endl;
    cout << "Queue Order Front: " << queueOrder->getFront()->order[0].getFoodName() << endl;
    cout << "Stack Order Top: " << stackOrder->getTop()->order[0].getFoodName() << endl;
    viewOrderCustomer(stackOrder);
    return 0;
}