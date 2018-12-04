//
// Created by eostendarp on 12/4/18.
//

#include "LinkedNode.h"

template <class T>
LinkedNode<T>::LinkedNode(const T& item) {
    this->item = new T(item);
    next = nullptr;
}

template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode& nodeToCopy) {
    this->item = nodeToCopy.item;
    next = nullptr;
}

template <class T>
T& LinkedNode<T>::getItem() {
    return *item;
}

template <class T>
LinkedNode<T>* LinkedNode<T>::getNext() {
    return next;
}

template <class T>
void LinkedNode<T>::setItem(const T& newItem) {
    delete item;
    item = newItem;
}

template <class T>
void LinkedNode<T>::setNext(LinkedNode* newNext) {
    next = newNext;
}
