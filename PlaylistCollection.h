//
// Created by mcqui on 12/9/2018.
//

#ifndef AUTODJ_PLAYLISTCOLLECTION_H
#define AUTODJ_PLAYLISTCOLLECTION_H

#include <iostream>
#include "PlayList.h"
#include "LinkedList.h"

class PlaylistCollection {

private:
    PlaylistCollection(const PlaylistCollection& collectionToCopy);
    PlaylistCollection& operator=(const PlaylistCollection& collectionToCopy);
public:
    PlaylistCollection() {}
    virtual ~PlaylistCollection() {}
    virtual std::string printPlayList(std::string listName) = 0;
    virtual void addPlayList(const PlayList &playListToAdd) = 0;
    virtual void removePlayList() = 0;
    virtual void addRandomPlayList() = 0;
    virtual LinkedList<PlayList>* getCollection() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const PlaylistCollection& a);
};

#endif //AUTODJ_PLAYLISTCOLLECTION_H
