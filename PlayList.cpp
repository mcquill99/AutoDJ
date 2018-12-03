//
// Created by eostendarp on 11/27/18.
//

#include "PlayList.h"

PlayList::PlayList(std::string newName) {
    songlist = new LinkedQueue<Song*>();
    this->name = newName;
}

PlayList::PlayList(const PlayList &playlistToCopy) {
    songlist = playlistToCopy.songlist;
}

PlayList &PlayList::operator=(const PlayList &playlistToCopy) {
    delete songlist;
    songlist = playlistToCopy.songlist;
}

PlayList::~PlayList() {
    delete songlist;
}

void PlayList::addSong(Song songToAdd) {
    songlist->enqueue(&songToAdd);
}

void PlayList::removeSong() {
    songlist->dequeue();
}

std::string PlayList::toString() {
    std::string returnString;
    returnString = songlist->toString();
    return returnString;
}

double PlayList::getDuration() {
    return songlist->sumItems();
}

Song PlayList::playNext() {
    return *songlist->dequeue();
}

bool PlayList::isEmpty() {
    return songlist->isEmpty();
}
std::string PlayList::getName(){
    return name;
}