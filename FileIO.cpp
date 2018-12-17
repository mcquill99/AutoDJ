#include "FileIO.h"
#include <fstream>
#include "ArrayListLibrary.h"
#include "LinkedPlayListsCollection.h"

/*
* This function reads a list of songs from a previously saved library written to some file libReadFile
*/
std::string readToLibrary(std::string libReadFile, Library& libToAdd){
    std::ifstream readToLib;
    readToLib.open(libReadFile);
    std::string word = "";
    std::string toReturn = "";
    while(getline(readToLib,word)){
        std::stringstream ss(word);
        std::string artist,name,duration,playcount;
        getline(ss,artist,',');
        getline(ss,name,',');
        getline(ss,duration,',');
        getline(ss,playcount,',');
        if(libToAdd.findSongIndex(artist,name) == -1){
            libToAdd.addSong(*(new Song(artist,name,std::stoi(duration),std::stoi(playcount))));
        }
        else{
            toReturn = toReturn + artist + " - " + name + ", ";
        }
    }
    return toReturn;
}
/*
 * Reads a list of playlists with songs already in the library and saves them as playlists into playlist collection
 */
void readToPlaylistsCollection(std::string collectionReadFile, PlaylistCollection& collectionToAdd){
    std::ifstream readToCollection;
    readToCollection.open(collectionReadFile);
    std::string word = "";
    std::string playlistName;
    PlaylistQueue* playlistToAdd;
    while(getline(readToCollection,word)){
        std::stringstream ss(word);
        std::string temp;
        if(getline(ss,temp,','), temp == "playlist"){
            playlistToAdd = nullptr;
            getline(ss,playlistName,':');
            PlaylistQueue* playlistToAdd = new PlaylistQueue(playlistName);
            collectionToAdd.addPlayList(*playlistToAdd);
        }
        else{
            std::string artist,name,duration,playcount;
            getline(ss,artist,',');
            getline(ss,name,',');
            getline(ss,duration,',');
            getline(ss,playcount,',');
            collectionToAdd.getCollection()->getValueAt(collectionToAdd.getCollection()->getItemCount()-1).addSong(*(new Song(artist, name, std::stoi(duration), std::stoi(playcount))));
        }
    }
}
/*
 * write the current library into a file to read later
 */
void writeFromLibrary(std::string libWriteFile, Library& libToWrite){
    std::ofstream ofs;
    ofs.open(libWriteFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    std::ofstream WriteFromLib;
    WriteFromLib.open(libWriteFile);
    for(int i = 0; i < libToWrite.libOfSongs->getItemCount(); i++){
        WriteFromLib<<libToWrite.libOfSongs->getValueAt(i).getArtist()<<","<<libToWrite.libOfSongs->getValueAt(i).getTitle()<<","<<libToWrite.libOfSongs->getValueAt(i).getDuration()<<","<<libToWrite.libOfSongs->getValueAt(i).getPlayCount()<<"\n";
    }
}
/*
 * write all playlists into a file to read later
 */
void writeFromPlaylistsCollection(std::string collectionWriteFile, PlaylistCollection& collectionToWrite){
    std::ofstream ofs;
    ofs.open(collectionWriteFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    std::ofstream WriteFromCollection;
    WriteFromCollection.open(collectionWriteFile);
    for(int i = 0; i < collectionToWrite.getCollection()->getItemCount(); i++){
        WriteFromCollection<<"playlist:"<<collectionToWrite.getCollection()->getValueAt(i).getName()<<"\n";
        PlaylistQueue* tempCounter = new PlaylistQueue(collectionToWrite.getCollection()->getValueAt(i));
        while(!tempCounter->isEmpty()){
            Song tempSong = tempCounter->playNext();
            WriteFromCollection<<"song,"<<tempSong.getArtist()<<","<<tempSong.getTitle()<<","<<tempSong.getDuration()<<","<<tempSong.getPlayCount()<<std::endl;
        }
        delete tempCounter;
    }
}
/*
 * list of new songs to add to library
 */
void addSongs(std::string songsAddFile, ArrayListLibrary& libToAdd){
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
void removeSongs(std::string songsRemoveFile, ArrayListLibrary& libToRemove, LinkedPlayListsCollection& playlists){
    std::ifstream songsToRemove;
    songsToRemove.open(songsRemoveFile);
    std::string word = "";
    while(getline(songsToRemove,word)){
        std::stringstream ss(word);
        std::string artist,name,duration,playcount;
        getline(ss,artist,',');
        getline(ss,name,',');
        getline(ss,duration,',');
        getline(ss,playcount,',');
        Song* tempSongPointer;
        for(int i = 0; i < libToRemove.libOfSongs->getItemCount(); i++){
            if(libToRemove.libOfSongs->getValueAt(i).getArtist() == artist && libToRemove.libOfSongs->getValueAt(i).getTitle() == name ){
                tempSongPointer = &libToRemove.libOfSongs->getValueAt(i);
                break;
            }
        }
        for(int i =0; i < playlists.getCollection()->getItemCount(); i++){
            playlists.getCollection()->getValueAt(i).removeSong(*tempSongPointer);
        }
        for(int i = 0; i < libToRemove.libOfSongs->getItemCount(); i++){
            if(libToRemove.libOfSongs->getValueAt(i).getArtist() == artist && libToRemove.libOfSongs->getValueAt(i).getTitle() == name ){
                libToRemove.removeSong(libToRemove.libOfSongs->getValueAt(i));
                break;
            }
        }
    }

}