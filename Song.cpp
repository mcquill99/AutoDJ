//
// Created by eostendarp on 12/3/18.
//

#include "Song.h"
#include <sstream>
#include <iomanip>


Song::Song(std::string artist, std::string title, int duration, int playCount) {
    this->artist = artist;
    this->title = title;
    this->duration = duration;
    this->playCount = playCount;
}

Song::Song(const Song& songToCopy) {
    artist = songToCopy.artist;
    title = songToCopy.title;
    duration = songToCopy.duration;
    playCount = songToCopy.playCount;
}

Song& Song::operator=(const Song& songToCopy) {
    if (&songToCopy != this) {
        artist = songToCopy.artist;
        title = songToCopy.title;
        duration = songToCopy.duration;
        playCount = songToCopy.playCount;
    }
    return *this;
}

std::string Song::getArtist() {
    return artist;
}

std::string Song::getTitle() {
    return title;
}

int Song::getDuration() {
    return duration;
}

int Song::getPlayCount() {
    return playCount;
}

void Song::incrementPlayCount() {
    playCount++;
}

int operator+(int a, const Song& b) {
    return a + b.duration;
}

bool operator==(const Song& a, const Song& b) {
    return a.artist == b.artist && a.title == b.title && a.duration == b.duration && a.playCount == b.playCount;
}

std::ostream& operator<<(std::ostream& os, const Song& a) {
    return os << "<" << a.artist << " - " << a.title << ", " << a.duration / 60 << ":" << std::setfill('0') << std::setw(2) << a.duration % 60 << ", plays: " << a.playCount << ">";
}
