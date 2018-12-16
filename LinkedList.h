//
// Created by eostendarp on 12/4/18.
//

#ifndef AUTODJ_LINKEDLIST_H
#define AUTODJ_LINKEDLIST_H


#include "List.h"
#include "LinkedNode.h"

template <class T>
class LinkedList : public List<T> {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* end;
    int count;
public:
    LinkedList();
    LinkedList(const LinkedList& arrayListToCopy);
    LinkedList& operator=(const LinkedList& arrayListToCopy);
    ~LinkedList();
    T& getValueAt(int index);
    bool isEmpty();
    int getItemCount();
    void clearList();
    void insertAtEnd(const T &itemToAdd);
    void insertAtFront(const T& itemToAdd);
    void insertAt(const T& itemToAdd, int index);
    T removeValueAtEnd();
    T removeValueAtFront();
    T removeValueAt(int index);
    friend int operator+(const LinkedList& a, const LinkedList& b) {
        return 0; //TODO maybe implement this for real
    }
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& a) {
        if (a.count == 0)
            return os << "[]";
        os << "[";
        LinkedNode<T>* curr = a.front;
        for (int i = 0; i < a.count - 1; i++) {
            os << *curr << " -> ";
            curr = curr->getNext();
        }
        return os << *curr << "]";
    }
};

#include "LinkedList.inl"


#endif //AUTODJ_LINKEDLIST_H
