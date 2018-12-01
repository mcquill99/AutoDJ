//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LINKEDQUEUE_H
#define AUTODJ_LINKEDQUEUE_H

#include <string>
#include "LinkedNode.h"
template <class T>
class LinkedQueue {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* end;
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& queueToCopy);
    LinkedQueue& operator=(const LinkedQueue& queueToCopy);
    ~LinkedQueue();
    void enqueue(T item);
    T dequeue();
    bool isEmpty();
    std::string toString();
};

#include "LinkedQueue.inl"
#endif //AUTODJ_LINKEDQUEUE_H
