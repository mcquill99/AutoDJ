//
// Created by eostendarp on 11/27/18.
//

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){
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

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queueToCopy){
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

LinkedQueue::~LinkedQueue(){
    LinkedNode* curr = front;
    while (curr != nullptr) {
        LinkedNode* toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
}

void LinkedQueue::enqueue(std::string item){
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

std::string LinkedQueue::dequeue(){
    if (isEmpty())
        throw std::out_of_range("queue is empty");
    std::string item = front->getItem();
    LinkedNode* toDelete = front;
    front = front->getNext();
    delete toDelete;
    return item;
}

bool LinkedQueue::isEmpty(){
    return front == nullptr;
}
