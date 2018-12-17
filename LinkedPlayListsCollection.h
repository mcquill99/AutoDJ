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

    void addRandomPlayList(int duration, const Library& lib);

    LinkedList<PlaylistQueue>* getCollection() const;

    Playlist& getPlaylist(std::string name);

    friend std::ostream& operator<<(std::ostream& os, const PlaylistCollection& a);
};


#endif //AUTODJ_PLAYLISTSCOLLECTION_H
