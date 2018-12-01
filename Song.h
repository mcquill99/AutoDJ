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
    Song(std::string artist, std::string title, double duration, int playCount=0);

};


#endif //AUTODJ_SONG_H
