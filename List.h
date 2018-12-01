//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LIST_H
#define AUTODJ_LIST_H


#include <stdexcept>
#include <string>

template <class T>
class List {
private:
    List(const List& listToCopy);
    List& operator=(const List& listToCopy);
public:
    List() {}
    virtual ~List() {}
    virtual void insertAtEnd(T valueToAdd)=0;
    virtual T getValueAt(int index)=0;
    virtual std::string toString()=0;
    virtual bool isEmpty()=0;
    virtual int itemCount()=0;
    virtual void clearList()=0;
    virtual int find(T valueToFind)=0;
    virtual int findLast(T valueToFind)=0;
    virtual void insertAtFront(T valueToAdd)=0;
    virtual void insertAt(T valueToAdd, int index)=0;
    virtual T removeValueAtEnd()=0;
    virtual T removeValueAtFront()=0;
    virtual T removeValueAt(int index)=0;
};


#endif //AUTODJ_LIST_H
