//
// Created by mcqui on 12/15/2018.
//

#include "ArrayListLibrary.h"
#include "FileIO.h"

ArrayListLibrary::ArrayListLibrary() {
    libOfSongs = new ArrayList<Song>(20);
}
ArrayListLibrary::~ArrayListLibrary() {
    delete libOfSongs;
}
ArrayListLibrary& ArrayListLibrary::operator=(const ArrayListLibrary &libraryToCopy) {
    if (&libraryToCopy != this) {
        delete libOfSongs;

        ArrayList<Song> toCopy = libraryToCopy.getLibrary();
        libOfSongs = new ArrayList<Song>(toCopy);
    }
}

void ArrayListLibrary::addSong(Song &songToAdd){
    if(libOfSongs->isEmpty()){
        libOfSongs->insertAtFront(songToAdd);
    }
    else{
        int itemCount = libOfSongs->getItemCount();
        for(int i = 0; i < itemCount; i++){
            if(songToAdd < libOfSongs->getValueAt(i)){
                libOfSongs->insertAt(songToAdd, i);
                break;
            }
            else if(i == itemCount - 1){
                libOfSongs->insertAt(songToAdd, i);
                break;
            }
        }
    }
}

void ArrayListLibrary::removeSong(Song &songToRemove) {
    int itemCount = libOfSongs->getItemCount();
    for(int i = 0; i < itemCount; i++){
        if(songToRemove == libOfSongs->getValueAt(i)){
            libOfSongs->removeValueAt(i);
        }
    }
}

Song& ArrayListLibrary::getSong(int index) const {
    return libOfSongs->getValueAt(index);
}

int ArrayListLibrary::getSize() const {
    return libOfSongs->getItemCount();
}

std::string ArrayListLibrary::toString(){
    if (libOfSongs->getItemCount() <= 0)
        return "[]";

    std::ostringstream out;
    out << "[";
    int length = libOfSongs->getItemCount();
    for (int i = 0; i < length - 1; i++)
        out << libOfSongs->getValueAt(i) << ", ";
    out << libOfSongs->getValueAt(length - 1) << "]";
    return out.str();
}

//void ArrayListLibrary::saveLibrary(std::string fileName) {
//    writeFromLibrary(fileName, this);
//
//}
//
//void ArrayListLibrary::loadLibrary(std::string fileName) {
//    readToLibrary(fileName, this);
//}

std::string ArrayListLibrary::printArtistSongs(std::string artistName){
    int itemCount = libOfSongs->getItemCount();
    std::string songNames = "";
    for(int i = 0; i < itemCount; i++){
        if(artistName == libOfSongs->getValueAt(i).getArtist()){
            songNames = songNames + libOfSongs->getValueAt(i).getTitle() + ", ";
        }
    }
    return songNames;

}

std::string ArrayListLibrary::returnSong(std::string artistName, std::string songName){
    int itemCount = libOfSongs->getItemCount();
    std::ostringstream out;
    out << "";
    for(int i = 0; i < itemCount; i++){
        if(libOfSongs->getValueAt(i).getArtist() == artistName && libOfSongs->getValueAt(i).getTitle() == songName){
            out << libOfSongs->getValueAt(i);
        }
    }
    return out.str();
}
ArrayList<Song> ArrayListLibrary::getLibrary() const{
    return *libOfSongs;
}
