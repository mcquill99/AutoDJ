//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LINKEDQUEUE_H
#define AUTODJ_LINKEDQUEUE_H

#include <string>
#include "LinkedNode.h"

class LinkedQueue {
private:
    LinkedNode* front;
    LinkedNode* end;
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& queueToCopy);
    LinkedQueue& operator=(const LinkedQueue& queueToCopy);
    ~LinkedQueue();
    void enqueue(std::string item);
    std::string dequeue();
    bool isEmpty();
};


#endif //AUTODJ_LINKEDQUEUE_H
