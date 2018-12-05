#include "PlayList.h"

PlayList::PlayList(std::string newName) {
    songlist = new LinkedQueue<Song>();
    this->name = newName;
}

PlayList::PlayList(const PlayList &playlistToCopy) {
    songlist = playlistToCopy.songlist;
    this->name = playlistToCopy.name;
}

PlayList &PlayList::operator=(const PlayList &playlistToCopy) {
    delete songlist;
    songlist = playlistToCopy.songlist;
}

PlayList::~PlayList() {
    delete songlist;
}

void PlayList::addSong(Song songToAdd) {
    songlist->enqueue(songToAdd);
}

void PlayList::removeSong() {
    //TODO: This is completely incorrect DAMION
    songlist->dequeue();
}

int PlayList::getDuration() {
    if(songlist->isEmpty()){
        return 0;
    }
    else{
        return songlist->getSum();
    }
}

Song PlayList::playNext() {
    return songlist->dequeue();
}

bool PlayList::isEmpty() {
    return songlist->isEmpty();
}

std::string PlayList::getName(){
    return this->name;
}

std::ostream& operator<<(std::ostream& os, const PlayList& a){
    return os << *a.songlist;
}
