//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLISTSCOLLECTION_H
#define AUTODJ_PLAYLISTSCOLLECTION_H

#include "LinkedQueue.h"
#include "PlayList.h"


class PlayListsCollection {
private:
    LinkedQueue<PlayList*> *collection;
public:
    PlayListsCollection();
    PlayListsCollection(const PlayListsCollection& CollectionToCopy);
    PlayListsCollection& operator=(const PlayListsCollection& collectionToCopy);
    ~PlayListsCollection();

    std::string allToString();
    std::string toString(std::string listName);

    void addPlayList(PlayList *playListToAdd);
    void removePlayList();

    void addRandomPlayList();

    LinkedQueue<PlayList*>* const getCollection();
};


#endif //AUTODJ_PLAYLISTSCOLLECTION_H
