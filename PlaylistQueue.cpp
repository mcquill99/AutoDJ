#include "PlaylistQueue.h"

PlaylistQueue::PlaylistQueue(std::string newName) {
    songlist = new LinkedQueue<Song>();
    this->name = newName;
}

PlaylistQueue::PlaylistQueue(const PlaylistQueue &playlistToCopy) {
    songlist = new LinkedQueue<Song>(*playlistToCopy.songlist);
    this->name = playlistToCopy.name;
}

PlaylistQueue &PlaylistQueue::operator=(const PlaylistQueue &playlistToCopy) {
    delete songlist;
    songlist = playlistToCopy.songlist;
}

PlaylistQueue::~PlaylistQueue() {
    delete songlist;
}

void PlaylistQueue::addSong(const Song& songToAdd) {
    songlist->enqueue(songToAdd);
}

void PlaylistQueue::removeSong(std::string songToRemove) {
    //TODO: This is completely incorrect DAMION
    songlist->dequeue();
}

int PlaylistQueue::getDuration() {
    if(songlist->isEmpty()){
        return 0;
    }
    else{
        return songlist->getSum();
    }
}

Song PlaylistQueue::playNext() {
    return songlist->dequeue();
}

bool PlaylistQueue::isEmpty() {
    return songlist->isEmpty();
}

std::string PlaylistQueue::getName(){
    return this->name;
}

std::ostream& operator<<(std::ostream& os, const PlaylistQueue& a){
    return os << *a.songlist;
}
