//
// Created by mcqui on 12/3/2018.
//
#include <iostream>
#include "PlayList.h"

int main(){
    std::cout << "-----Song-----" << std::endl;




    std::cout << "-----PlayList-----" << std::endl;
    PlayList* testList = new PlayList("PlayList 1");
    Song* testSong = new Song("Bob Dylan", "The Times They Are A-Changin'", 192, 0);
    testList->addSong(*testSong);
    std::cout<<testList->toString()<<std::endl;


    std::cout << "-----PlayListsCollection-----" << std::endl;


    return 0;
}