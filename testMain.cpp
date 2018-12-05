//
// Created by mcqui on 12/3/2018.
//
#include <iostream>
#include "TestLib.h"
#include "PlayListsCollection.h"
#include "PlayList.h"
#include "Song.h"

int main(){
    std::cout << "-----Song-----" << std::endl;




    std::cout << "-----PlayList-----" << std::endl;




    std::cout << "-----PlayListsCollection-----" << std::endl;
    PlayListsCollection collection1 = PlayListsCollection();
    PlayList myList = PlayList("Rock");
    PlayList myList2 = PlayList("Pop");
    PlayList myList3 = PlayList("Metal");

    Song song1 = Song("Darude","SandStorm",89, 0);
    Song song2 = Song("Tenacious D", "The Metal", 120, 0);
    Song song3 = Song("Megadeth", "Holy Wars", 500, 0);
    Song song4 = Song("Justin Timberlake", "Cry Me A River", 300, 0);

    collection1.addPlayList(myList);

    std::cout << collection1 << std::endl;

    myList.addSong(song1);
    myList.addSong(song2);

    std::cout << collection1 << std::endl;
    printAssertEquals("Darude-SandStorm, Tenacious D-The Metal, " , collection1.printPlayList("rock"));

    collection1.addPlayList(myList2);

    myList2.addSong(song3);
    myList2.addSong(song1);
    myList2.addSong(song2);

    std::cout << collection1 << std::endl;

    collection1.removePlayList();
    std::cout << collection1 << std::endl;

    collection1.addPlayList(myList3);

    std::cout << collection1 << std::endl;

    myList3.addSong(song1);
    printAssertEquals("Megadeth-Holy Wars, " , collection1.printPlayList("Metal"));

    collection1.removePlayList();
    collection1.removePlayList();
    collection1.removePlayList();

    std::cout << collection1 << std::endl;





    return 0;
}