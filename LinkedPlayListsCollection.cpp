//
// Created by eostendarp on 11/27/18.
//

#include "LinkedPlayListsCollection.h"

LinkedPlayListsCollection::LinkedPlayListsCollection(){
    collection = new LinkedList<PlaylistQueue>();
}

LinkedPlayListsCollection::LinkedPlayListsCollection(const LinkedPlayListsCollection & CollectionToCopy){

    LinkedList<PlaylistQueue> *toCopy = CollectionToCopy.getCollection();
    collection = new LinkedList<PlaylistQueue>(*toCopy);

}
LinkedPlayListsCollection::~LinkedPlayListsCollection(){
    delete collection;

}

LinkedPlayListsCollection& LinkedPlayListsCollection::operator=(const LinkedPlayListsCollection &collectionToCopy){
    if(&collectionToCopy != this){
        delete collection;

        LinkedList<PlaylistQueue> *toCopy = collectionToCopy.getCollection();
        collection = new LinkedList<PlaylistQueue>(*toCopy);
    }

}


std::string LinkedPlayListsCollection::printPlayList(std::string listName){
        int length = collection->getItemCount();
        std::string playListString = "";

        for(int i = 0; i < length; i++){
            if(collection->getValueAt(i).getName() == listName){
                PlaylistQueue playList = PlaylistQueue(collection->getValueAt(i));
                playListString = playListString + playList.getName() + ": ";
                while (!playList.isEmpty()) {
                    Song song = playList.playNext();
                    playListString += song.getArtist() + "-" + song.getTitle() + ", ";
                }
            }
        }

        return playListString;




}

void LinkedPlayListsCollection::addPlayList(const PlaylistQueue &playListToAdd){

    collection->insertAtEnd(playListToAdd);

}

void LinkedPlayListsCollection::removePlayList(){
    if(!collection->isEmpty()){
        collection->removeValueAtFront();
    }
}

void LinkedPlayListsCollection::addRandomPlayList(int size, const Library& lib){
    PlaylistQueue* randomPlaylist = new PlaylistQueue("Random");
    for (int i = 0; i < size; i++) {
        randomPlaylist->addSong(lib.getSong(rand() % lib.getSize()));
    }
    addPlayList(*randomPlaylist);
}

LinkedList<PlaylistQueue>* LinkedPlayListsCollection::getCollection() const {
    return collection;
}

Playlist& LinkedPlayListsCollection::getPlaylist(std::string name){
    for(int i = 0; i < collection->getItemCount(); i++){
        if(collection->getValueAt(i).getName() == name){
            return collection->getValueAt(i);
        }
    }

}

std::ostream& operator<<(std::ostream& os, const PlaylistCollection& a) {
    int itemCount = a.getCollection()->getItemCount();
    for(int i = 0; i < itemCount; i++){
        os << a.getCollection()->getValueAt(i).getName() << " " << std::to_string(a.getCollection()->getValueAt(i).getDuration()) << "\n";
    }

    return os;
}
