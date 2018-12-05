#include "FileIO.h"

void readToLibrary(std::string libReadFile, Library& libToAdd){
    std::ifstream readToLib;
    readToLib.open(libReadFile);
    std::string songConstructor = "";
    //TODO: Finish once library is complete DAMION
}

void readToPlaylistsCollection(std::string collectionReadFile, PlayListsCollection& collectionToAdd){
    std::ifstream readToCollection;
    readToCollection.open(collectionReadFile);
}

void writeFromLibrary(std::string libWriteFile, Library& libToWrite){
    std::ofstream WriteFromLib;
    WriteFromLib.open(libWriteFile);
}

void writeFromPlaylistsCollection(std::string collectionWriteFile, PlayListsCollection& collectionToWrite){
    std::ofstream WriteFromCollection;
    WriteFromCollection.open(collectionWriteFile);
}

void addSongs(std::string songsAddFile, Library& libToAdd){
    std::ifstream songsToAdd;
    songsToAdd.open(songsAddFile);

}

void removeSongs(std::string songsRemoveFile, Library& libToRemove){

}