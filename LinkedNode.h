//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LINKEDNODE_H
#define AUTODJ_LINKEDNODE_H


class LinkedNode {
private:
    int item;
    LinkedNode* next;
public:
    LinkedNode(int item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    int getItem();
    LinkedNode* getNext();
    void setItem(int newItem);
    void setNext(LinkedNode* newNext);
};


#endif //AUTODJ_LINKEDNODE_H
