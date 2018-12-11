//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLIST_H
#define AUTODJ_PLAYLIST_H

#include "Song.h"
#include "LinkedQueue.h"
#include "Playlist.h"

class PlaylistQueue : public Playlist{
private:
    std::string name;
    LinkedQueue<Song>* songlist;
public:
    PlaylistQueue(std::string newName);
    PlaylistQueue(const PlaylistQueue& playlistToCopy);
    PlaylistQueue& operator=(const PlaylistQueue& playlistToCopy);
    ~PlaylistQueue();
    void addSong(Song songToAdd);
    void removeSong();
    std::string toString();
    int getDuration();
    Song playNext();
    bool isEmpty();
    std::string getName();
    friend std::ostream& operator<<(std::ostream& os, const PlaylistQueue& a);

};


#endif //AUTODJ_PLAYLIST_H
