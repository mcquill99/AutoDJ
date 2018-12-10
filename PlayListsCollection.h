//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLISTSCOLLECTION_H
#define AUTODJ_PLAYLISTSCOLLECTION_H

#include "LinkedList.h"
#include "PlaylistQueue.h"
#include <random>


class PlayListsCollection {
private:
    LinkedList<PlaylistQueue> *collection;
public:
    PlayListsCollection();
    PlayListsCollection(const PlayListsCollection& CollectionToCopy);
    PlayListsCollection& operator=(const PlayListsCollection& collectionToCopy);
    ~PlayListsCollection();

    std::string printPlayList(std::string listName);

    void addPlayList(const PlaylistQueue &playListToAdd);
    void removePlayList();

    void addRandomPlayList();

    LinkedList<PlaylistQueue>* getCollection() const;

    friend std::ostream& operator<<(std::ostream& os, const PlayListsCollection& a);
};


#endif //AUTODJ_PLAYLISTSCOLLECTION_H
