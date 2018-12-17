//
// Created by mcqui on 12/9/2018.
//

#ifndef AUTODJ_PLAYLISTCOLLECTION_H
#define AUTODJ_PLAYLISTCOLLECTION_H

#include <iostream>
#include "PlaylistQueue.h"
#include "LinkedList.h"
#include "Library.h"

class PlaylistCollection {

private:
    PlaylistCollection(const PlaylistCollection& collectionToCopy);
    PlaylistCollection& operator=(const PlaylistCollection& collectionToCopy);
public:
    PlaylistCollection() {}
    virtual ~PlaylistCollection() {}
    virtual std::string printPlayList(std::string listName) = 0;
    virtual void addPlayList(const PlaylistQueue &playListToAdd) = 0;
    virtual void removePlayList() = 0;
    virtual void addRandomPlayList(int size, const Library& lib) = 0;
    virtual Playlist& getPlaylist(std::string name)=0;
    virtual LinkedList<PlaylistQueue>* getCollection() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const PlaylistCollection& a);
};

#endif //AUTODJ_PLAYLISTCOLLECTION_H
