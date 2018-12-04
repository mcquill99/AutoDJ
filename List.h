//
// Created by eostendarp on 12/3/18.
//

#ifndef AUTODJ_LIST_H
#define AUTODJ_LIST_H


template <class T>
class List {
private:
    List(const List& listToCopy);
    List& operator=(const List& listToCopy);
public:
    List() {}
    virtual ~List() {}
    virtual T& getValueAt(int index)=0;
    virtual bool isEmpty()=0;
    virtual int getItemCount()=0;
    virtual void clearList()=0;
    virtual void insertAtEnd(const T& itemToAdd)=0;
    virtual void insertAtFront(const T& itemToAdd)=0;
    virtual void insertAt(const T& itemToAdd, int index)=0;
    virtual T removeValueAtEnd()=0;
    virtual T removeValueAtFront()=0;
    virtual T removeValueAt(int index)=0;
};


#endif //AUTODJ_LIST_H
