#include "FileIO.h"
#include <fstream>
#include "ArrayListLibrary.h"
/*
 * This function reads a list of songs from a previously saved library written to some file libReadFile
 */
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
        libToAdd.addSong(*(new Song(artist,name,std::stoi(duration),std::stoi(playcount))));
    }
}
/*
 * Reads a list of playlists with songs already in the library and saves them as playlists into playlist collection
 */
void readToPlaylistsCollection(std::string collectionReadFile, PlaylistCollection& collectionToAdd){
    std::ifstream readToCollection;
    readToCollection.open(collectionReadFile);
    std::string word = "";
    while(getline(readToCollection,word)){
        std::stringstream ss(word);
        std::string playlistName;
        //collectionToAdd.addSong();
    }
    //TODO: Figure how to format playlists
}
/*
 * write the current library into a file to read later
 */
void writeFromLibrary(std::string libWriteFile, ArrayListLibrary& libToWrite){
    std::ofstream WriteFromLib;
    WriteFromLib.open(libWriteFile);
    for(Song* temp : libToWrite.libOfSongs){
        WriteFromLib<<temp->getArtist()<<","<<temp->getTitle()<<","<<temp->getDuration()<<","<<temp->getPlayCount()<<"\n";
    }
}
/*
 * write all playlists into a file to read later
 */
void writeFromPlaylistsCollection(std::string collectionWriteFile, PlaylistCollection& collectionToWrite){
    std::ofstream WriteFromCollection;
    WriteFromCollection.open(collectionWriteFile);
}
/*
 * list of new songs to add to library
 */
void addSongs(std::string songsAddFile, Library& libToAdd){
    std::ifstream songsToAdd;
    songsToAdd.open(songsAddFile);
    std::string word = "";
    while(getline(songsToAdd,word)){
        std::stringstream ss(word);
        std::string artist,name,duration,playcount;
        getline(ss,artist,',');
        getline(ss,name,',');
        getline(ss,duration,',');
        getline(ss,playcount,',');
        libToAdd.addSong(*(new Song(artist,name,std::stoi(duration),std::stoi(playcount))));
    }
}
/*
 * list of songs to remove from library and ALL playlists
 */
void removeSongs(std::string songsRemoveFile, Library& libToRemove){
    std::ifstream songsToRemove;
    songsToRemove.open(songsRemoveFile);

}