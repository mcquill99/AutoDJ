//
// Created by eostendarp on 12/4/18.
//

#include "LinkedQueue.h"

template <class T>
LinkedQueue<T>::LinkedQueue() {
    front = end = nullptr;
}

template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& queueToCopy) {
    LinkedNode<T>* copyCurr = queueToCopy.front;
    if(copyCurr != nullptr){
        LinkedNode<T>* curr = copyCurr; //new LinkedNode<T>(*copyCurr);
        front = curr;
        while (copyCurr->getNext() != nullptr) {
            copyCurr = copyCurr->getNext();
            curr->setNext(copyCurr); //new LinkedNode<T>(*copyCurr));
            curr = curr->getNext();
        }
        end = curr;
    }
    else if(copyCurr == nullptr){
        end = nullptr;
    }
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& queueToCopy) {
    if (&queueToCopy != this) {

        LinkedNode<T>* curr = front;
//        while (curr != nullptr) {
//            LinkedNode<T>* toDelete = curr;
//            curr = curr->getNext();
//            delete toDelete;
//        }
//        delete curr;
        end = nullptr;

        LinkedNode<T>* copyCurr = queueToCopy.front;
        curr = copyCurr; //new LinkedNode<T>(*copyCurr);
        front = curr;
        while (copyCurr->getNext() != nullptr) {
            copyCurr = copyCurr->getNext();
            curr->setNext(copyCurr); //new LinkedNode<T>(*copyCurr));
            curr = curr->getNext();
        }
        end = curr;
    }
    return *this;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() {
//    LinkedNode<T>* curr = front;
//    while (curr != nullptr) {
//        LinkedNode<T>* toDelete = curr;
//        curr = curr->getNext();
//        delete toDelete;
//    }
}

template <class T>
void LinkedQueue<T>::enqueue(const T& item) {
    LinkedNode<T>* newNode = new LinkedNode<T>(item);
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
T LinkedQueue<T>::dequeue() {
    if (isEmpty())
        throw std::out_of_range("empty");
    T item = front->getItem();
    LinkedNode<T>* toDelete = front;
    front = front->getNext();
//    delete toDelete;
    return item;
}

template <class T>
bool LinkedQueue<T>::isEmpty() {
    return front == nullptr;
}

template <class T>
int LinkedQueue<T>::getSum() {
    int sum = 0;
    LinkedNode<T>* curr = front;
    while (curr != nullptr) {
        sum = sum + curr->getItem();
        curr = curr->getNext();
    }
    return sum;
}
template <class T>
void LinkedQueue<T>::removeFromMiddle(T &songToRemove) {
    LinkedNode<T>* temp = front;
    if(front->getItem() == songToRemove){
        front = nullptr;
        return;
    }
    while(!(temp->getNext()->getItem() == songToRemove)){
        temp = temp->getNext();
        if(temp->getNext() == nullptr){
            return;
        }
    }
    LinkedNode<T>* nextNode = temp->getNext()->getNext();
    temp->setNext(nextNode);
}
