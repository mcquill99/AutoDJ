//
// Created by eostendarp on 12/3/18.
//

#ifndef AUTODJ_SONG_H
#define AUTODJ_SONG_H


#include <string>


class Song {
private:
    std::string artist, title;
    int duration, playCount;
public:
    Song(std::string artist, std::string title, int duration, int playCount);
    Song(const Song& songToCopy);
    Song& operator=(const Song& songToCopy);
    std::string getArtist();
    std::string getTitle();
    int getDuration();
    int getPlayCount();
    void incrementPlayCount();
    template <class T>
    friend int operator+(const T& a, const Song& b);
    friend bool operator==(const Song& a, const Song& b);
    friend std::ostream& operator<<(std::ostream& os, const Song& a);
    };


#endif //AUTODJ_SONG_H
