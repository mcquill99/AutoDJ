#include "FileIO.h"
#include <iostream>

void readToLibrary(std::string libReadFile, Library& libToAdd){
    std::ifstream readToLib;
    readToLib.open(libReadFile);
    std::string word = "";
    while(getline(readToLib,word)){
        std::stringstream ss(word);
        std::string artist,name,duration,playcount;
        getline(ss,artist,',');
        getline(ss,name,',');
        getline(ss,duration,',');
        getline(ss,playcount,',');
        libToAdd.addSong(new Song(artist,name,std::stoi(duration),std::stoi(playcount)));
    }
}

void readToPlaylistsCollection(std::string collectionReadFile, PlaylistCollection& collectionToAdd){
    std::ifstream readToCollection;
    readToCollection.open(collectionReadFile);
    std::string word = "";
    while(getline(readToCollection,word)){
        std::stringstream ss(word);
        std::string playlistName;
        collectionToAdd.addSong();
    }
}

void writeFromLibrary(std::string libWriteFile, Library& libToWrite){
    std::ofstream WriteFromLib;
    WriteFromLib.open(libWriteFile);
}

void writeFromPlaylistsCollection(std::string collectionWriteFile, PlaylistCollection& collectionToWrite){
    std::ofstream WriteFromCollection;
    WriteFromCollection.open(collectionWriteFile);
}

void addSongs(std::string songsAddFile, Library& libToAdd){
    std::ifstream songsToAdd;
    songsToAdd.open(songsAddFile);

}

void removeSongs(std::string songsRemoveFile, Library& libToRemove){

}