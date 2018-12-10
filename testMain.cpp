//
// Created by mcqui on 12/3/2018.
//
#include <iostream>
#include "TestLib.h"
#include "PlayListsCollection.h"
#include "PlaylistQueue.h"
#include "Song.h"

int main(){
    std::cout << "-----Song-----" << std::endl;




    std::cout << "-----PlaylistQueue-----" << std::endl;
    PlaylistQueue* testList = new PlaylistQueue("Playlist Test");
    PlaylistQueue* testList2 = new PlaylistQueue("Playlist Test2");
    PlaylistQueue* testList3 = new PlaylistQueue("Empty List");
    Song newSong1 = Song("New Patek","Lil Uzi Vert",340,0);
    Song newSong2 = Song("151 Rum","JID",126,0);
    Song newSong3 = Song("Holy Wars... The Punishment Due","Megadeth",392,0);

    testList->addSong(newSong1);
    testList->addSong(newSong2);

    testList2->addSong(newSong3);
    testList2->addSong(newSong1);

    std::cout<<"Print Playlists:"<<std::endl;
    std::cout<<*testList<<std::endl;
    std::cout<<*testList2<<std::endl;
    std::cout<<*testList3<<std::endl;

    std::cout<<"Is empty:"<<std::endl;
    std::cout<<testList->isEmpty()<<std::endl;
    std::cout<<testList2->isEmpty()<<std::endl;
    std::cout<<testList3->isEmpty()<<std::endl;

    std::cout<<"Next Song: "<<std::endl<<testList2->playNext()<<std::endl;


    delete testList, testList2, testList3;

    std::cout << "-----PlayListsCollection-----" << std::endl;
    PlayListsCollection *collection1 = new PlayListsCollection();
    PlaylistQueue myList = PlaylistQueue("Rock");
    PlaylistQueue myList2 = PlaylistQueue("Pop");
    PlaylistQueue myList3 = PlaylistQueue("Metal");

    Song song1 = Song("Darude","SandStorm",89, 0);
    Song song2 = Song("Tenacious D", "The Metal", 120, 0);
    Song song3 = Song("Megadeth", "Holy Wars", 500, 0);
    Song song4 = Song("Justin Timberlake", "Cry Me A River", 300, 0);

    collection1->addPlayList(myList);

    myList.addSong(song1);
    myList.addSong(song2);
    std::cout << "Added playList 'rock'" << std::endl;
    std::cout << *collection1 << std::endl;

    std::cout << "checking against contents of rock playlist" << std::endl;
    printAssertEquals("Darude-SandStorm, Tenacious D-The Metal, " , collection1->printPlayList("Rock"));

   collection1->addPlayList(myList2);
    myList2.addSong(song3);
    myList2.addSong(song2);

    std::cout << "adding playlist 'pop'" << std::endl;
    std::cout << *collection1 << std::endl;

    collection1->removePlayList();
    std::cout << "removed first playlist" << std::endl;
    std::cout << *collection1 << std::endl;

    /*std::cout << *collection1 << std::endl;

    collection1->removePlayList();
    std::cout << *collection1 << std::endl;

    collection1->addPlayList(myList3);

    std::cout << *collection1 << std::endl;

    myList3.addSong(song1);
    printAssertEquals("Megadeth-Holy Wars, " , collection1->printPlayList("Metal"));

    collection1->removePlayList();
    collection1->removePlayList();
    collection1->removePlayList();

    std::cout << *collection1 << std::endl;*/

    delete collection1;





    return 0;
}
