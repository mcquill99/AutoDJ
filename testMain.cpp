//
// Created by mcqui on 12/3/2018.
//
#include <iostream>
#include "TestLib.h"
#include "LinkedPlayListsCollection.h"
#include "PlayList.h"
#include "Song.h"

int main(){
    std::cout << "-----Song-----" << std::endl;

    Song* songa = new Song("artist a", "title a", 120, 0);
    Song* songb = new Song("artist b", "artist b", 32, 3);
    Song* songc = new Song(*songa);

    std::cout << *songa << "\n" << *songb << "\n" << *songc << "\n" << std::endl;

    songa->incrementPlayCount();

    std::cout << *songa << "\n" << *songb << "\n" << *songc << std::endl;

    delete songa;
    delete songb;
    delete songc;
    std::cout << "-----PlayList-----" << std::endl;
    PlayList* testList = new PlayList("Playlist Test");
    PlayList* testList2 = new PlayList("Playlist Test2");
    PlayList* testList3 = new PlayList("Empty List");
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

    std::cout << "-----LinkedPlayListsCollection-----" << std::endl;
    LinkedPlayListsCollection *collection1 = new LinkedPlayListsCollection();
    PlayList myList = PlayList("Rock");
    PlayList myList2 = PlayList("Pop");
    PlayList myList3 = PlayList("Metal");

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
