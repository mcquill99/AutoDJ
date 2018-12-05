//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LIBRARY_H
#define AUTODJ_LIBRARY_H


class Library {
private:
    Library(const Library& listToCopy);
    Library& operator=(const Library& listToCopy);
public:
    Library(){}
    virtual ~Library(){}
};


#endif //AUTODJ_LIBRARY_H
