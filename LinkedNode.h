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
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    T* getItem();
    LinkedNode* getNext();
    void setItem(T* newItem);
    void setNext(LinkedNode* newNext);
};


#endif //AUTODJ_LINKEDNODE_H
