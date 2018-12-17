//
// Created by eostendarp on 12/3/18.
//

#include "ArrayList.h"
#include <stdexcept>

template <class T>
void ArrayList<T>::doubleCapacity() {
    capacity *= 2;
    T** temp = new T*[capacity];
    for (int i = 0; i < itemCount; i++) {
        temp[i] = array[i]; //new T(*array[i]);
        //delete array[i];
    }
    array = temp;
}

template <class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if (initialCapacity < 1)
        throw std::invalid_argument("initialCapacity < 1");

    array = new T*[initialCapacity];
    itemCount = 0;
    capacity = initialCapacity;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy) {
    itemCount = arrayListToCopy.itemCount;
    capacity = arrayListToCopy.capacity;
    array = new T*[capacity];
    for (int i = 0; i < itemCount; i++)
        array[i] = arrayListToCopy.array[i]; //new T(*arrayListToCopy.array[i]);
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& arrayListToCopy) {
    if (&arrayListToCopy != this) {
//        for (int i = 0; i < itemCount; i++)
//            delete array[i];
//        delete[] array;

        itemCount = arrayListToCopy.itemCount;
        capacity = arrayListToCopy.capacity;
        array = new T*[capacity];
        for (int i = 0; i < itemCount; i++)
            array[i] = arrayListToCopy.array[i]; //new T(*arrayListToCopy.array[i]);
    }
    return *this;
}

template <class T>
ArrayList<T>::~ArrayList() {
//    for (int i = 0; i < itemCount; i++)
//        delete array[i];
//    delete[] array;
}

template <class T>
T& ArrayList<T>::getValueAt(int index) {
    if (0 > index || index >= itemCount)
        throw std::out_of_range("index out of range");
    return *array[index];
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return itemCount == 0;
}

template <class T>
int ArrayList<T>::getItemCount() {
    return itemCount;
}

template <class T>
void ArrayList<T>::clearList() {
//    for (int i = 0; i < itemCount; ++i)
//        delete array[i];
    itemCount = 0;
}

template <class T>
void ArrayList<T>::insertAtEnd(const T& itemToAdd) {
    if (itemCount >= capacity)
        doubleCapacity();
    array[itemCount++] = itemToAdd; //new T(itemToAdd);
}

template <class T>
void ArrayList<T>::insertAtFront(const T& itemToAdd) {
    if (itemCount >= capacity)
        doubleCapacity();

    for (int i = itemCount - 1; i >= 0; i--)
        array[i + 1] = array[i];

    array[0] = new T(itemToAdd);
    itemCount++;
}

template <class T>
void ArrayList<T>::insertAt(const T& itemToAdd, int index) {
    if (0 > index || index > itemCount)
        throw std::out_of_range("index out of range");

    if (itemCount >= capacity)
        doubleCapacity();

    for (int i = itemCount; i >= index ; i--)
        array[i + 1] = array[i];

    array[index] = new T(itemToAdd);
    itemCount++;
}

template <class T>
T ArrayList<T>::removeValueAtEnd() {
    if (itemCount < 1)
        throw std::out_of_range("empty");
    T* temp = array[--itemCount]; //new T(*array[--itemCount]);
//    delete array[itemCount];
    return *temp;
}

template <class T>
T ArrayList<T>::removeValueAtFront() {
    if (itemCount < 1)
        throw std::out_of_range("empty");
    T* temp = array[0]; //new T(*array[0]);
//    delete array[0];
    itemCount--;
    for (int i = 0; i < itemCount; i++)
        array[i] = array[i + 1];
    return *temp;
}

template <class T>
T ArrayList<T>::removeValueAt(int index) {
    if (itemCount < 1)
        throw std::out_of_range("empty");
    T* temp = array[index]; //new T(*array[index]);
//    delete array[index];
    itemCount--;
    for (int i = index; i < itemCount; i++)
        array[i] = array[i + 1];
    return *temp;
}
