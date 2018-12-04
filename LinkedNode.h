//
// Created by eostendarp on 12/4/18.
//

#ifndef AUTODJ_LINKEDNODE_H
#define AUTODJ_LINKEDNODE_H


#include <sstream>

template <class T>
class LinkedNode {
private:
    T* item;
    LinkedNode* next;
public:
    LinkedNode(const T& item);
    LinkedNode(const LinkedNode& nodeToCopy);
    T& getItem();
    LinkedNode* getNext();
    void setItem(const T& newItem);
    void setNext(LinkedNode* newNext);
    friend std::ostream& operator<<(std::ostream& os, const LinkedNode<T>& a) {
        return os << "(" << *a.item << ")";
    }
};

#include "LinkedNode.inl"


#endif //AUTODJ_LINKEDNODE_H
