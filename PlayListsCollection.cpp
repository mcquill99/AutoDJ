//
// Created by eostendarp on 11/27/18.
//

#include "PlayListsCollection.h"

PlayListsCollection::PlayListsCollection(){
    collection = new LinkedQueue<PlayList*>();
}

PlayListsCollection::PlayListsCollection(const PlayListsCollection & CollectionToCopy){
    LinkedQueue<PlayList*> copyCollection = CollectionToCopy->getCollection()
    collection = new LinkedQueue<PlayList*>(const LinkedQueue<PlayList*> copyCollection);

}
PlayListsCollection::~PlayListsCollection(){
    delete collection;

}

PlayListsCollection& PlayListsCollection::operator=(const PlayListsCollection &collectionToCopy){

}

std::string PlayListsCollection::allToString(){
    std::string toString = "";
    LinkedQueue<PlayList*> collection2 = new LinkedQueue( const)

    while(!collection->isEmpty()){

    }

}

std::string PlayListsCollection::toString(std::string listName){

}

void PlayListsCollection::addPlayList(PlayList *playListToAdd){
    collection->enqueue(playListToAdd);

}

void PlayListsCollection::removePlayList(){
    collection->dequeue();

}

void PlayListsCollection::addRandomPlayList(){

}

LinkedQueue<PlayList*> PlayListsCollection::getCollection(){
    return *collection;
}
