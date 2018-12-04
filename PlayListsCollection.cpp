//
// Created by eostendarp on 11/27/18.
//

#include "PlayListsCollection.h"

PlayListsCollection::PlayListsCollection(){
    collection = new LinkedQueue<PlayList*>();
}

PlayListsCollection::PlayListsCollection(const PlayListsCollection & CollectionToCopy){

    LinkedQueue<PlayList*> *toCopy = CollectionToCopy.getCollection();
    collection = new LinkedQueue<PlayList*>(*toCopy);

}
PlayListsCollection::~PlayListsCollection(){
    delete collection;

}

PlayListsCollection& PlayListsCollection::operator=(const PlayListsCollection &collectionToCopy){
    if(&collectionToCopy != this){
        delete collection;
    }

}

std::string PlayListsCollection::allToString(){
    std::string toString = "";
    LinkedQueue<PlayList*> collection2 = LinkedQueue<PlayList*>(*collection);

    while(!collection2.isEmpty()){
        PlayList *listToString = collection2.dequeue();
        toString = toString + listToString->getName(); + " " + std::to_string(listToString->getDuration()) + "\n";
    }

    return toString;

}

std::string PlayListsCollection::toString(std::string listName){
        PlayList *listToReturn = collection->findPlayList(listName);

        return listToReturn->toString();



}

void PlayListsCollection::addPlayList(PlayList *playListToAdd){
    collection->enqueue(playListToAdd);

}

void PlayListsCollection::removePlayList(){
    collection->dequeue();

}

void PlayListsCollection::addRandomPlayList(){

}

LinkedQueue<PlayList*>* PlayListsCollection::getCollection() const {
    return collection;
}
