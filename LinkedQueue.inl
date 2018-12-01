//
// Created by eostendarp on 11/27/18.
//

#include <stdexcept>
#include "LinkedQueue.h"
template <class T>
LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}
template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& queueToCopy){
    LinkedNode* copyCurr = queueToCopy.front;
    LinkedNode* curr = new LinkedNode(*copyCurr);
    front = curr;
    while (copyCurr->getNext() != nullptr) {
        copyCurr = copyCurr->getNext();
        curr->setNext(new LinkedNode(*copyCurr));
        curr = curr->getNext();
    }
    end = curr;
}
template <class T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& queueToCopy){
    if (&queueToCopy != this) {

        LinkedNode* curr = front;
        while (curr != nullptr) {
            LinkedNode* toDelete = curr;
            curr = curr->getNext();
            delete toDelete;
        }
        delete curr;
        end = nullptr;

        LinkedNode* copyCurr = queueToCopy.front;
        curr = new LinkedNode(*copyCurr);
        front = curr;
        while (copyCurr->getNext() != nullptr) {
            copyCurr = copyCurr->getNext();
            curr->setNext(new LinkedNode(*copyCurr));
            curr = curr->getNext();
        }
        end = curr;
    }
    return *this;
}
template <class T>
LinkedQueue<T>::~LinkedQueue(){
    LinkedNode* curr = front;
    while (curr != nullptr) {
        LinkedNode* toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
}
template <class T>
void LinkedQueue<T>::enqueue(T item){
    LinkedNode* newNode = new LinkedNode(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}
template <class T>
T LinkedQueue<T>::dequeue(){
    if (isEmpty())
        throw std::out_of_range("queue is empty");
    T item = front->getItem();
    LinkedNode* toDelete = front;
    front = front->getNext();
    delete toDelete;
    return item;
}
template <class T>
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr;
}
