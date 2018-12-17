#include <string>
#include "Library.h"
#include "PlaylistCollection.h"
#include "ArrayListLibrary.h"

void readToLibrary(std::string libReadFile, ArrayListLibrary& libToAdd);
void readToPlaylistsCollection(std::string collectionReadFile, PlaylistCollection& collectionToAdd);
void writeFromLibrary(std::string libWriteFile, Library& libToWrite);
void writeFromPlaylistsCollection(std::string collectionWriteFile, PlaylistCollection& collectionToWrite);
void addSongs(std::string songsAddFile, Library& libToAdd);
void removeSongs(std::string songsRemoveFile, Library& libToRemove);
