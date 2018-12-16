//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLISTSCOLLECTION_H
#define AUTODJ_PLAYLISTSCOLLECTION_H

#include "LinkedList.h"
#include "PlaylistQueue.h"
#include <random>
#include "PlaylistCollection.h"


class LinkedPlayListsCollection : public PlaylistCollection{
private:
    LinkedList<PlaylistQueue> *collection;
public:
    LinkedPlayListsCollection();
    LinkedPlayListsCollection(const LinkedPlayListsCollection& CollectionToCopy);
    LinkedPlayListsCollection& operator=(const LinkedPlayListsCollection& collectionToCopy);
    ~LinkedPlayListsCollection();

    std::string printPlayList(std::string listName);

    void addPlayList(const PlaylistQueue& playListToAdd);
    void removePlayList();

    void addRandomPlayList(int size, const Library& lib);

    LinkedList<PlaylistQueue>* getCollection() const;

    friend std::ostream& operator<<(std::ostream& os, const LinkedPlayListsCollection& a);
};


#endif //AUTODJ_PLAYLISTSCOLLECTION_H
