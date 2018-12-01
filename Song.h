//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_SONG_H
#define AUTODJ_SONG_H


#include <string>

class Song {
private:
    std::string artist, title;
    double duration;
    int playCount;
public:
    Song(std::string artistIn, std::string titleIn, double durationIn, int playCountIn=0);
    Song(const Song& songToCopy);
    Song& operator=(const Song& songToCopy);
    std::string getArtist();
    std::string getTitle();
    double getDuration();
    int getPlayCount();
    void updatePlayCount();
    std::string toString();

};


#endif //AUTODJ_SONG_H
