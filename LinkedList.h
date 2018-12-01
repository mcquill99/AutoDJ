//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LINKEDLIST_H
#define AUTODJ_LINKEDLIST_H


#include "List.h"
#include "LinkedNode.h"

class LinkedList : public List {
private:
    LinkedNode* front;
    int count;

    LinkedList(const LinkedList& arrayListToCopy);
    LinkedList& operator=(const LinkedList& arrayListToCopy);
public:
    LinkedList();
    ~LinkedList();
    void insertAtEnd(int itemToAdd);
    int getValueAt(int index);
    std::string toString();
    bool isEmpty();
    int itemCount();
    void clearList();
    int find(int numToFind);
    int findLast(int numToFind);
    int findMaxIndex();
    void insertAtFront(int itemToAdd);
    void insertAt(int itemToAdd, int index);
    int removeValueAtEnd();
    int removeValueAtFront();
    int removeValueAt(int index);
};


#endif //AUTODJ_LINKEDLIST_H
