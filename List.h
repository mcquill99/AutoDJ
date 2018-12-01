//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LIST_H
#define AUTODJ_LIST_H


#include <stdexcept>
#include <string>

class List {
private:
    List(const List& listToCopy);
    List& operator=(const List& listToCopy);
public:
    List() {}
    virtual ~List() {}
    virtual void insertAtEnd(int itemToAdd)=0;
    virtual int getValueAt(int index)=0;
    virtual std::string toString()=0;
    virtual bool isEmpty()=0;
    virtual int itemCount()=0;
    virtual void clearList()=0;
    virtual int find(int numToFind)=0;
    virtual int findLast(int numToFind)=0;
    virtual int findMaxIndex()=0;
    virtual void insertAtFront(int itemToAdd)=0;
    virtual void insertAt(int itemToAdd, int index)=0;
    virtual int removeValueAtEnd()=0;
    virtual int removeValueAtFront()=0;
    virtual int removeValueAt(int index)=0;
};


#endif //AUTODJ_LIST_H
