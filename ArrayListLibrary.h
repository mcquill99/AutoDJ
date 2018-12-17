//
// Created by mcqui on 12/15/2018.
//

#ifndef AUTODJ_ARRAYLISTLIBRARY_H
#define AUTODJ_ARRAYLISTLIBRARY_H


#include "Library.h"
#include "Song.h"
#include "ArrayList.h"

class ArrayListLibrary : public Library {
private:
public:
    ArrayList<Song>* libOfSongs;

    ArrayListLibrary();
    ~ArrayListLibrary();
    ArrayListLibrary& operator=(const ArrayListLibrary& playlistToCopy);
    void addSong(Song &songToAdd);
    void removeSong(Song &songToRemove);
    Song& getSong(int index) const ;
    int getSize() const;
    std::string toString();
    std::string printArtistSongs(std::string artistName);
    std::string returnSong(std::string artistName, std::string songName);
    int findSongIndex(std::string artistName, std::string songName);
//    void saveLibrary(std::string fileName);
//    void loadLibrary(std::string fileName);
    ArrayList<Song> getLibrary() const;



};


#endif //AUTODJ_ARRAYLISTLIBRARY_H
