#include <string>
#include <iostream>
#include <fstream>
#include "Library.h"
#include "LinkedPlayListsCollection.h"
private:

void readToLibrary(std::string libReadFile, Library& libToAdd);
void readToPlaylistsCollection(std::string collectionReadFile, PlaylistCollection& collectionToAdd);
void writeFromLibrary(std::string libWriteFile, Library& libToWrite);
void writeFromPlaylistsCollection(std::string collectionWriteFile, PlaylistCollection& collectionToWrite);
void addSongs(std::string songsAddFile, Library& libToAdd);
void removeSongs(std::string songsRemoveFile, Library& libToRemove);
