#include <string>
#include "Library.h"
#include "PlaylistCollection.h"
#include "ArrayListLibrary.h"
#include "LinkedPlayListsCollection.h"

std::string readToLibrary(std::string libReadFile, ArrayListLibrary& libToAdd);
void readToPlaylistsCollection(std::string collectionReadFile, PlaylistCollection& collectionToAdd);
void writeFromLibrary(std::string libWriteFile, ArrayListLibrary& libToWrite);
void writeFromPlaylistsCollection(std::string collectionWriteFile, PlaylistCollection& collectionToWrite);
void addSongs(std::string songsAddFile, ArrayListLibrary& libToAdd);
void removeSongs(std::string songsRemoveFile, ArrayListLibrary& libToRemove, LinkedPlayListsCollection& playlists);
