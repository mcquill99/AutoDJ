//
// Created by eostendarp on 12/1/18.
//

#include <iostream>
#include "ArrayListLibrary.h"
#include "LinkedPlayListsCollection.h"

int main(){
    bool loop = true;
    Library *currLib = new ArrayListLibrary();
    PlaylistCollection *currCollection = new LinkedPlayListsCollection();
    std::cout << "Welcome to our Auto DJ!" << std::endl;
    while(loop){
        std::cout << "What would you like to do?: " << std::endl;
        std::string toDo = "";
        std::cin >> toDo;

        if(toDo == "help"){
            std::cout << "help - list commands \n "
                         "library - Displays current library \n "
                         "artist - displays all songs from that artist \n "
                         "song -displays all information of that song \n "
                         "import - adds all songs from the file to the current library \n "
                         "discontinue - removes all songs from the given file from the library \n "
                         "playlists - displays all names and durations of existing playlists \n "
                         "playlist - displays info from a certain playlist \n "
                         "new - Make a new empty playlist with a given name \n "
                         "add - adds the song to the end of the playlist \n "
                         "remove - removes a given song from a playlist \n "
                         "playnext - print all information of the next song to be played from a given playlist, and removes that song from the playlist \n "
                         "newrandom - makes a new playlist with a given name and puts random songs in the playlist to fill it as close to the given duration as possible" << std::endl;
        }
        else if(toDo == "library"){
            std::cout << currLib->toString() << std::endl;

        }
        else if(toDo == "artist"){
            std::cout << "What artist would you like to see?: " << std::endl;
            std::string artist;
            std::cin >> artist;
            //std::cout <<
        }
        else if(toDo == "song"){
            std::cout << "What song would you like to see information for: " << std::endl;
            std::string song;
            std::cin >> song;
            //std::cout

        }
        else if(toDo == "import"){
            std::cout << "Whats the name of the file you want to import?: " << std::endl;
            std::string fileName;
            std::cin >> fileName;


        }
        else if(toDo == "discontinue"){
            std::cout << "Whats the name of the file you want to discontinue?: " << std::endl;
            std::string fileName;
            std::cin >> fileName;

        }
        else if(toDo == "playlists"){
            std::cout << currCollection << std::endl;

        }
        else if(toDo == "playlist"){
            std::cout << "What is the name of the playlist you want to see? :" << std::endl;
            std::string name;
            std::cin >> name;

            std::string toPrint = currCollection->printPlayList(name);
            if(toPrint == ""){
                std::cout << "that playlist doesnt exist!" << std::endl;
            }
            else{
                std::cout << toPrint << std::endl;
            }

        }
        else if(toDo == "new"){
            std::cout << "What do you want to name your playlist?" << std::endl;
            std::string name;
            std::cin >> name;
            currCollection->addPlayList(*new PlaylistQueue(name));
            std::cout << "Playlist added successfully" << std::endl;


        }
        else if(toDo == "add"){
            std::cout << "Whats the name of the playlist you want to add a song to? " << std::endl;
            std::string playListName;
            std::cin >> playListName;

            std::string check = currCollection->printPlayList(playListName);
            if(check == ""){
                std::cout << "Please enter a valid playlist name";
            }
            else{
                std::cout << "Whats the name";
            }

        }
        else if(toDo == "remove"){
            std::cout << "Whats the name of the playlist you want to remove a song from? " << std::endl;
            std::string playListName;
            std::cin >> playListName;

            std::string check = currCollection->printPlayList(playListName);
            if(check == ""){
                std::cout << "Please enter a valid playlist name";
            }
            else{
                std::cout << "Whats the name";
            }

        }
        else if(toDo == "playnext"){

        }
        else if(toDo == "newrandom"){

        }
        else if(toDo == "quit"){

        }
        else{
            std::cout << "Thanks not a valid function! type 'help' to see a list of commands" << std::endl;
        }
    }

    return -1;
}