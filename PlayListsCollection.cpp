//
// Created by eostendarp on 11/27/18.
//

#include "PlayListsCollection.h"

PlayListsCollection::PlayListsCollection(){
    collection = new LinkedList<PlayList>();
}

PlayListsCollection::PlayListsCollection(const PlayListsCollection & CollectionToCopy){

    LinkedList<PlayList> *toCopy = CollectionToCopy.getCollection();
    //collection = new LinkedList<PlayList>(*toCopy);

}
PlayListsCollection::~PlayListsCollection(){
    delete collection;

}

PlayListsCollection& PlayListsCollection::operator=(const PlayListsCollection &collectionToCopy){
    if(&collectionToCopy != this){
        delete collection;

        LinkedList<PlayList> *toCopy = collectionToCopy.getCollection();
        //collection = new LinkedList<PlayList>(*toCopy);
    }

}


std::string PlayListsCollection::printPlayList(std::string listName){
        int length = collection->getItemCount();
        std::string playListString;

        for(int i = 0; i < length; i++){
            if(collection->getValueAt(i).getName() == listName){
                PlayList* playList = new PlayList(collection->getValueAt(i));
                while (!playList->isEmpty()) {
                    Song song = playList->playNext();
                    playListString += song.getArtist() + "-" + song.getTitle() + ", ";
                }
            }
        }

        return playListString;




}

void PlayListsCollection::addPlayList(const PlayList &playListToAdd){

    collection->insertAtEnd(playListToAdd);

}

void PlayListsCollection::removePlayList(){
    if(!collection->isEmpty()){
        collection->removeValueAtFront();
    }

}

void PlayListsCollection::addRandomPlayList(){
    //TODO
}

LinkedList<PlayList>* PlayListsCollection::getCollection() const {
    return collection;
}

std::ostream& operator<<(std::ostream& os, const PlayListsCollection& a) {
    int itemCount = a.getCollection()->getItemCount();
    for(int i = 0; i < itemCount; i++){
        os << a.getCollection()->getValueAt(i).getName() << " " << std::to_string(a.getCollection()->getValueAt(i).getDuration()) << "\n";
    }

    return os;
}
