//
// Created by eostendarp on 11/27/18.
//

#include "PlayList.h"

PlayList::PlayList(std::string newName) {
    playlist = new LinkedQueue<Song>();
    this->name = newName;
}

PlayList::PlayList(const PlayList &playlistToCopy) {

}

PlayList &PlayList::operator=(const PlayList &playlistToCopy) {

}

PlayList::~PlayList() {

}

void PlayList::addSong(Song songToAdd) {
    playlist->enqueue(songToAdd);
}

void PlayList::removeSong() {
    playlist->dequeue();
}

std::string PlayList::toString() {
    std::string returnString;
    returnString = playlist->toString();
    return returnString;
}

double PlayList::getDuration() {

}

Song PlayList::playNext() {

}

bool PlayList::isEmpty() {

}


