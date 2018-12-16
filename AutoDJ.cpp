//
// Created by eostendarp on 12/1/18.
//

#include <iostream>
#include "ArrayListLibrary.h"

int main(){
    bool loop = true;
    Library *currLib = new ArrayListLibrary();
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

        }
        else if(toDo == "playlists"){

        }
        else if(toDo == "playlist"){

        }
        else if(toDo == "new"){

        }
        else if(toDo == "add"){

        }
        else if(toDo == "remove"){

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