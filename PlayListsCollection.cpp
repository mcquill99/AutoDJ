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
    LinkedQueue<PlayList*> collectionCopy = LinkedQueue<PlayList*>(*collection);

    while(!collectionCopy.isEmpty()){
        PlayList *listToString = collectionCopy.dequeue();
        toString = toString + listToString->getName(); + " " + std::to_string(listToString->getDuration()) + "\n";
    }

    return toString;

}

std::string PlayListsCollection::toString(std::string listName){
        LinkedQueue <PlayList*> collectionCopy = LinkedQueue<PlayList*>(*collection);
        PlayList *listToPrint = nullptr;

        while(!collectionCopy.isEmpty()){
            PlayList *tempList = collectionCopy.dequeue();
            if(tempList->getName() == listName){
                listToPrint = tempList;
            }
        }

        return listToPrint->toString();



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
