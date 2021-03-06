//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLISTQUEUE_H
#define AUTODJ_PLAYLISTQUEUE_H

#include "Song.h"
#include "LinkedQueue.h"
#include "Playlist.h"

class PlaylistQueue : public Playlist{
private:
    std::string name;
public:
    LinkedQueue<Song>* songlist;

    PlaylistQueue(std::string newName);
    PlaylistQueue(const PlaylistQueue& playlistToCopy);
    PlaylistQueue& operator=(const PlaylistQueue& playlistToCopy);
    ~PlaylistQueue();
    void addSong(const Song& songToAdd);
    void removeSong(Song& songToRemove);
    int getDuration();
    Song playNext();
    bool isEmpty();
    std::string getName();
    friend std::ostream& operator<<(std::ostream& os, const PlaylistQueue& a);

};


#endif //AUTODJ_PLAYLISTQUEUE_H
