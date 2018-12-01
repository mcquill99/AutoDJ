//
// Created by eostendarp on 11/27/18.
//

#ifndef AUTODJ_PLAYLIST_H
#define AUTODJ_PLAYLIST_H

#include <string>
class PlayList {
private:

public:
    PlayList(std::string nameIn);
    void remove(std::string artist, std::string songTitle);
    void add(std::string artist, std::string songTitle);

};


#endif //AUTODJ_PLAYLIST_H
