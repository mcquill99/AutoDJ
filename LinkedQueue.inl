//
// Created by eostendarp on 11/27/18.
//

#include <stdexcept>
#include "LinkedQueue.h"
#include "PlayList.h"
template <class T>
LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}
template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& queueToCopy){
    LinkedNode<T>* copyCurr = queueToCopy.front;
    LinkedNode<T>* curr = new LinkedNode<T>(*copyCurr);
    front = curr;
    while (copyCurr->getNext() != nullptr) {
        copyCurr = copyCurr->getNext();
        curr->setNext(new LinkedNode<T>(*copyCurr));
        curr = curr->getNext();
    }
    end = curr;
}
template <class T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& queueToCopy){
    if (&queueToCopy != this) {

        LinkedNode<T>* curr = front;
        while (curr != nullptr) {
            LinkedNode<T>* toDelete = curr;
            curr = curr->getNext();
            delete toDelete;
        }
        delete curr;
        end = nullptr;

        LinkedNode<T>* copyCurr = queueToCopy.front;
        curr = new LinkedNode<T>(*copyCurr);
        front = curr;
        while (copyCurr->getNext() != nullptr) {
            copyCurr = copyCurr->getNext();
            curr->setNext(new LinkedNode<T>(*copyCurr));
            curr = curr->getNext();
        }
        end = curr;
    }
    return *this;
}
template <class T>
LinkedQueue<T>::~LinkedQueue(){
    LinkedNode<T>* curr = front;
    while (curr != nullptr) {
        LinkedNode<T>* toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
}
template <class T>
void LinkedQueue<T>::enqueue(T item){
    LinkedNode<T>* newNode = new LinkedNode<T>(&item);
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
    T* item = front->getItem();
    LinkedNode<T>* toDelete = front;
    front = front->getNext();
    delete toDelete;
    return *item;
}
template <class T>
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr;
}
template <class T>
std::string LinkedQueue<T>::toString(){
    std::string returnString = "{";
    LinkedNode<T>* temp = front;
    while(temp != end){
        returnString+=(*temp->getItem())->toString();
        returnString+=", ";
        temp=temp->getNext();
    }
    returnString+=(*temp->getItem())->toString();
    returnString+="}";
    return returnString;
}
template <class T>
double LinkedQueue<T>::sumItems(){
    LinkedNode<T> temp = *front;
    double sumTotal = 0;
    while(&temp != end){
        sumTotal+=(*temp.getItem())->getDuration();
    }
    return sumTotal;
}

template <class T>
T LinkedQueue<T>::findPlayList(std::string name){
    LinkedNode<T>* temp = front;
    while(name != temp->getItem()->getName()){
        temp = temp->getNext();
    }
    return *temp->getItem();
}