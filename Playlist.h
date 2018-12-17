//
// Created by Ligeti on 12/9/2018.
//

#ifndef AUTODJ_PLAYLIST_H
#define AUTODJ_PLAYLIST_H

#include <iostream>
#include "Song.h"

class Playlist{
private:
    Playlist(const Playlist& playlistToCopy);
    Playlist& operator=(const Playlist& playlistToCopy);
public:
    Playlist() {}
    virtual ~Playlist() {}
    virtual void addSong(const Song& songToAdd)=0;
    virtual void removeSong(Song& songToRemove)=0;
    virtual int getDuration()=0;
    virtual Song playNext()=0;
    virtual bool isEmpty()=0;
    virtual std::string getName()=0;
};

#endif //AUTODJ_PLAYLIST_H