//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LINKEDNODE_H
#define AUTODJ_LINKEDNODE_H

template <class T>
class LinkedNode {
private:
    T* item;
    LinkedNode* next;
public:
    LinkedNode(T* item);
    LinkedNode(const LinkedNode& nodeToCopy);
    T* getItem();
    void setItem(T* newItem);
    LinkedNode* getNext();
    void setNext(LinkedNode* newNext);
};


#include "LinkedNode.inl"

#endif //AUTODJ_LINKEDNODE_H
