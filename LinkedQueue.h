//
// Created by eostendarp on 12/4/18.
//

#ifndef AUTODJ_LINKEDQUEUE_H
#define AUTODJ_LINKEDQUEUE_H


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
    void enqueue(const T& item);
    T dequeue();
    bool isEmpty();
    int getSum();
    friend std::ostream& operator<<(std::ostream& os, const LinkedQueue<T>& a) {
        if (a.front == nullptr)
            return os << "[]";
        os << "[";
        LinkedNode<T>* curr = a.front;
        while (curr->getNext() != nullptr) {
            os << *curr << " -> ";
            curr = curr->getNext();
        }
        return os << *curr << "]";
    }
};

#include "LinkedQueue.inl"


#endif //AUTODJ_LINKEDQUEUE_H
