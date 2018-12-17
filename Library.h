//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_LIBRARY_H
#define AUTODJ_LIBRARY_H

#include <string>
#include "Song.h"

class Library {
private:
    Library(const Library& listToCopy);
    Library& operator=(const Library& listToCopy);
public:
    Library(){}
    virtual ~Library(){}
    virtual void addSong(Song &songToAdd)=0;
    virtual void removeSong(Song &songToRemove)=0;
    virtual Song& getSong(int index) const =0;
    virtual int getSize() const =0;
    virtual std::string toString()=0;
    virtual std::string printArtistSongs(std::string artist)=0;
    virtual std::string returnSong(std::string artistName, std::string songName)=0;
    virtual int findSongIndex(std::string artistName, std::string songName)=0;
//    virtual void saveLibrary(std::string fileName)=0;
//    virtual void loadLibrary(std::string fileName)=0;


};


#endif //AUTODJ_LIBRARY_H
