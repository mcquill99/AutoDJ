//
// Created by eostendarp on 12/16/18.
//

#ifndef AUTODJ_QUEUE_H
#define AUTODJ_QUEUE_H

template <class T>
class Queue {
private:
    Queue(const Queue& queueToCopy);
    Queue& operator=(const Queue& queueToCopy);
public:
    Queue() {}
    virtual ~Queue() {}
    virtual void enqueue(const T& item)=0;
    virtual T dequeue()=0;
    virtual bool isEmpty()=0;
    virtual int getSum()=0;
};


#endif //AUTODJ_QUEUE_H
