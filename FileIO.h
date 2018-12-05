#include <string>
#include <iostream>
#include <fstream>
#include "Library.h"
#include "PlayListsCollection.h"

void readToLibrary(std::string libReadFile, Library& libToAdd);
void readToPlaylistsCollection(std::string collectionReadFile, PlayListsCollection& collectionToAdd);
void writeFromLibrary(std::string libWriteFile, Library& libToWrite);
void writeFromPlaylistsCollection(std::string collectionWriteFile, PlayListsCollection& collectionToWrite);
void addSongs(std::string songsAddFile, Library& libToAdd);
void removeSongs(std::string songsRemoveFile, Library& libToRemove);
