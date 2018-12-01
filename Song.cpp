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

