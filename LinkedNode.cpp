//
// Created by eostendarp on 11/27/18.
//

#include "LinkedNode.h"

template <class T>
LinkedNode<T>::LinkedNode(T* item){
    this->item = item;
    next = nullptr;
}

template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}

template <class T>
T* LinkedNode<T>::getItem(){
    return item;
}

template <class T>
LinkedNode<T>* LinkedNode<T>::getNext(){
    return next;
}

template <class T>
void LinkedNode<T>::setItem(T* newItem){
    item = newItem;
}

template <class T>
void LinkedNode<T>::setNext(LinkedNode* newNext){
    next = newNext;
}
