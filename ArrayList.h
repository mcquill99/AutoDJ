//
// Created by eostendarp on 12/3/18.
//

#ifndef AUTODJ_ARRAYLIST_H
#define AUTODJ_ARRAYLIST_H


#include "List.h"
#include <sstream>

template <class T>
class ArrayList {
private:
    T** array;
    int itemCount, capacity;
    void doubleCapacity();
public:
    ArrayList(int initialCapacity=16);
    ArrayList(const ArrayList& arrayListToCopy);
    ArrayList& operator=(const ArrayList& arrayListToCopy);
    ~ArrayList();
    T& getValueAt(int index);
    bool isEmpty();
    int getItemCount();
    void clearList();
    void insertAtEnd(const T& itemToAdd);
    void insertAtFront(const T& itemToAdd);
    void insertAt(const T& itemToAdd, int index);
    T removeValueAtEnd();
    T removeValueAtFront();
    T removeValueAt(int index);
    friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& a) {
        if (a.itemCount <= 0)
            return os << "[]";
        os << "[";
        for (int i = 0; i < a.itemCount - 1; i++)
            os << *(a.array[i]) << ", ";
        return os << *(a.array[a.itemCount - 1]) << "]";
    }
};

#include "ArrayList.inl"


#endif //AUTODJ_ARRAYLIST_H
