//
// Created by eostendarp on 11/27/18.
//

#include "LinkedList.h"

LinkedList::LinkedList(){
    front = nullptr;
    count = 0;
}

LinkedList::~LinkedList(){
    clearList();
}

void LinkedList::insertAtEnd(int itemToAdd){
    if (front == nullptr)
        insertAtFront(itemToAdd);
    else {
        LinkedNode *curr = front;
        while (curr->getNext() != nullptr)
            curr = curr->getNext();
        curr->setNext(new LinkedNode(itemToAdd));
        count++;
    }
}

int LinkedList::getValueAt(int index){
    if (0 > index || index >= count)
        throw std::out_of_range("index out of range");

    LinkedNode* curr = front;
    for (int i = 0; i < index; i++)
        curr = curr->getNext();
    return curr->getItem();
}

std::string LinkedList::toString(){
    if (count == 0)
        return "{}";

    std::string str = "{";
    LinkedNode* curr = front;
    for (int i = 0; i < count - 1; i++) {
        str += std::to_string(curr->getItem()) + ", ";
        curr = curr->getNext();
    }
    str += std::to_string(curr->getItem()) + "}";
    return str;
}

bool LinkedList::isEmpty(){
    return front == nullptr;
}

int LinkedList::itemCount(){
    return count;
}

void LinkedList::clearList(){
    while (!isEmpty())
        removeValueAtFront();
}

int LinkedList::find(int numToFind){
    if (!isEmpty()) {
        LinkedNode* curr = front;
        for (int i = 0; i < count; i++) {
            if (curr->getItem() == numToFind)
                return i;
            curr = curr->getNext();
        }
    }
    return -1;
}

int LinkedList::findLast(int numToFind){
    int index = -1;
    if (!isEmpty()) {
        LinkedNode* curr = front;
        for (int i = 0; i < count; i++) {
            if (curr->getItem() == numToFind)
                index = i;
            curr = curr->getNext();
        }
    }
    return index;
}

int LinkedList::findMaxIndex(){
    if (isEmpty())
        throw std::out_of_range("no item to remove");

    int max = front->getItem();
    int maxIndex = 0;
    LinkedNode* curr = front;
    for (int i = 0; i < count; i++) {
        if (curr->getItem() > max) {
            max = curr->getItem();
            maxIndex = i;
        }
        curr = curr->getNext();
    }
    return maxIndex;
}

void LinkedList::insertAtFront(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    newNode->setNext(front);
    front = newNode;
    count++;
}

void LinkedList::insertAt(int itemToAdd, int index){
    if (0 > index || index > count)
        throw std::out_of_range("index out of range");

    if (index == 0) {
        insertAtFront(itemToAdd);
    } else if (index == count) {
        insertAtEnd(itemToAdd);
    } else {
        LinkedNode* curr = front;
        for (int i = 0; i < index - 1; i++)
            curr = curr->getNext();
        LinkedNode* newNode = new LinkedNode(itemToAdd);
        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
        count++;
    }
}

int LinkedList::removeValueAtEnd(){
    if (isEmpty())
        throw std::out_of_range("no item to remove");

    int item;
    if (count == 1) {
        item = front->getItem();
        delete front;
        front = nullptr;
    } else {
        LinkedNode* curr = front;
        while (curr->getNext()->getNext() != nullptr)
            curr = curr->getNext();
        LinkedNode* end = curr->getNext();
        item = end->getItem();
        delete end;
        curr->setNext(nullptr);
    }
    count--;
    return item;
}

int LinkedList::removeValueAtFront(){
    if (isEmpty())
        throw std::out_of_range("no item to remove");

    LinkedNode* newFront = front->getNext();
    int item = front->getItem();
    delete front;
    front = newFront;
    count--;
    return item;
}

int LinkedList::removeValueAt(int index){
    if (0 > index || index >= count)
        throw std::out_of_range("index out of range");

    if (index == 0)
        return removeValueAtFront();
    else if (index == count - 1)
        return removeValueAtEnd();
    else {
        LinkedNode* curr = front;
        for (int i = 0; i < index - 1; i++)
            curr = curr->getNext();
        LinkedNode* toRemove = curr->getNext();
        int item = toRemove->getItem();
        curr->setNext(toRemove->getNext());
        delete toRemove;
        count--;
        return item;
    }
}
