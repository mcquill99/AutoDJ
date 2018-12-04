//
// Created by eostendarp on 12/4/18.
//

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    front = end = nullptr;
    count = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    clearList();
}

template <class T>
T& LinkedList<T>::getValueAt(int index) {
    if (0 > index || index >= count)
        throw std::out_of_range("out of range");

    LinkedNode<T>* curr = front;
    for (int i = 0; i < index; i++)
        curr = curr->getNext();
    return curr->getItem();
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return !count;
}

template <class T>
int LinkedList<T>::getItemCount() {
    return count;
}

template <class T>
void LinkedList<T>::clearList() {
    while (!isEmpty())
        removeValueAtEnd();
}

template <class T>
void LinkedList<T>::insertAtEnd(const T& itemToAdd) {
    if (front == nullptr)
        insertAtFront(itemToAdd);
    else {
        end->setNext(new LinkedNode<T>(itemToAdd));
        end = end->getNext();
        count++;
    }
}

template <class T>
void LinkedList<T>::insertAtFront(const T& itemToAdd) {
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    newNode->setNext(front);
    if (front == nullptr)
        end = newNode;
    front = newNode;
    count++;
}

template <class T>
void LinkedList<T>::insertAt(const T& itemToAdd, int index) {
    if (0 > index || index > count)
        throw std::out_of_range("out of range");

    if (index == 0)
        insertAtFront(itemToAdd);
    else if (index == count)
        insertAtEnd(itemToAdd);
    else {
        LinkedNode<T>* curr = front;
        for (int i = 0; i < index - 1; i++)
            curr = curr->getNext();
        LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
        count++;
    }
}

template <class T>
T LinkedList<T>::removeValueAtEnd() {
    if (isEmpty())
        throw std::out_of_range("empty");

    T* item;
    if (count == 1) {
        item = &front->getItem();
        delete front;
        front = nullptr;
    } else {
        LinkedNode<T>* curr = front;
        while (curr->getNext()->getNext() != nullptr)
            curr = curr->getNext();
        LinkedNode<T>* end = curr->getNext();
        item = &end->getItem();
        delete end;
        curr->setNext(nullptr);
    }
    count--;
    return *item;
}

template <class T>
T LinkedList<T>::removeValueAtFront() {
    if (isEmpty())
        throw std::out_of_range("empty");

    LinkedNode<T>* newFront = front->getNext();
    T item = front->getItem();
    delete front;
    front = newFront;
    count--;
    return item;
}

template <class T>
T LinkedList<T>::removeValueAt(int index) {
    if (0 > index || index >= count)
        throw std::out_of_range("out of range");

    if (index == 0)
        return removeValueAtFront();
    else if (index == count - 1)
        return removeValueAtEnd();
    else {
        LinkedNode<T>* curr = front;
        for (int i = 0; i < index - 1; i++)
            curr = curr->getNext();
        LinkedNode<T>* toRemove = curr->getNext();
        T item = toRemove->getItem();
        curr->setNext(toRemove->getNext());
        delete toRemove;
        count--;
        return item;
    }
}
