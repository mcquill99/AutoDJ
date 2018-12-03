//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLIST_H
#define AUTODJ_PLAYLIST_H

#include "Song.h"
#include "LinkedQueue.h"

class PlayList {
private:
    std::string name;
    LinkedQueue<Song*>* songlist;
public:
    PlayList(std::string newName);
    PlayList(const PlayList& playlistToCopy);
    PlayList& operator=(const PlayList& playlistToCopy);
    ~PlayList();
    void addSong(Song songToAdd);
    void removeSong();
    std::string toString();
    double getDuration();
    Song playNext();
    bool isEmpty();
};


#endif //AUTODJ_PLAYLIST_H
