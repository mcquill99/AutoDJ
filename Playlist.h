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
    virtual void addSong(Song songToAdd)=0;
    virtual void removeSong()=0;
    virtual std::string toString()=0;
    virtual int getDuration()=0;
    virtual Song playNext()=0;
    virtual bool isEmpty()=0;
    virtual std::string getName()=0;
    virtual friend std::ostream& operator<<(std::ostream& os, const PlaylistQueue& a)=0;
};

#endif //AUTODJ_PLAYLIST_H
