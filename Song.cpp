//
// Created by eostendarp on 11/27/18.
//

#include "Song.h"

Song::Song(std::string artistIn, std::string titleIn, double durationIn, int playCountIn){
    artist = artistIn;
    title = titleIn;
    duration = durationIn;
    playCount = playCountIn;
}
Song::Song(const Song& songToCopy){
    artist = songToCopy.artist;
    title = songToCopy.title;
    duration = songToCopy.duration;
    playCount = songToCopy.playCount;
}

Song& Song::operator=(const Song& songToCopy){
    if(this != &songToCopy){
        artist = songToCopy.artist;
        title = songToCopy.title;
        duration = songToCopy.duration;
        playCount = songToCopy.playCount;
    }

    return *this;

}
std::string Song::getArtist(){
    return artist;
}

std::string Song::getTitle(){
    return title;
}

double Song::getDuration(){
    return duration;
}

int Song::getPlayCount(){
    return playCount;
}

void Song::updatePlayCount(){
    playCount++;
}

std::string Song::toString(){
    return title + " By " + artist;
}

