//
// Created by Ligeti on 12/9/2018.
//

#ifndef AUTODJ_PLAYLIST_H
#define AUTODJ_PLAYLIST_H

class Playlist{
private:
    Playlist(const Playlist& playlistToCopy);
    Playlist& operator=(const Playlist& playlistToCopy);
public:
    Playlist() {}
    virtual ~Playlist() {}

};

#endif //AUTODJ_PLAYLIST_H
