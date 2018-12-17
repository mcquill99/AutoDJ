//
// Created by eostendarp on 12/1/18.
//

#include <iostream>
#include <fstream>
#include "ArrayListLibrary.h"
#include "LinkedPlayListsCollection.h"
#include "FileIO.h"

int main(){
    bool loop = true;
    Library *currLib = new ArrayListLibrary();
    PlaylistCollection *currCollection = new LinkedPlayListsCollection();
    std::cout << "Welcome to our Auto DJ!" << std::endl;
    while(loop){
        std::cout << "What would you like to do?: " << std::endl;
        std::string toDo;
        std::getline(std::cin ,toDo);

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
            std::cin.ignore();
            std::getline(std::cin ,artist);
            std::cout << currLib->printArtistSongs(artist)<< std::endl;
        }
        else if(toDo == "song"){
            std::cout << "What artist is the song by? " << std::endl;
            std::string artist;
            std::cin.ignore();
            std::getline(std::cin ,artist);
            std::cout << "What is the name of the song?" << std::endl;
            std::string song;
            std::getline(std::cin ,song);

            std::string toPrint = currLib->returnSong(artist, song);
            if(toPrint == ""){
                std::cout << "I don't believe that song is in the library" << std::endl;
            }
            else{
                std::cout << toPrint << std::endl;
            }

        }
        else if(toDo == "import"){
            std::cout << "Whats the name of the file you want to import?: " << std::endl;
            std::string fileName;
            //std::cin.ignore();
            std::getline(std::cin ,fileName);

            std::ifstream ifile(fileName);
            if(!ifile){
                std::cout <<"This file doesn't exist!" << std::endl;
            }
            else{
                std::string notAdded = readToLibrary(fileName, *currLib);
                if(notAdded != ""){
                    std::cout << "These songs could not be added because they already existed: " + notAdded << std::endl;
                }
                else{
                    std::cout << "All songs added successfully" << std::endl;
                }
            }



        }
        else if(toDo == "discontinue"){
            std::cout << "Whats the name of the file you want to discontinue?: " << std::endl;
            std::string fileName;
            std::cin.ignore();
            std::getline(std::cin ,fileName);

        }
        else if(toDo == "playlists"){
            std::cout << *currCollection << std::endl;

        }
        else if(toDo == "playlist"){
            std::cout << "What is the name of the playlist you want to see? :" << std::endl;
            std::string name;
            std::cin.ignore();
            std::getline(std::cin ,name);

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
            //std::cin.ignore();
            std::getline(std::cin ,name);
            currCollection->addPlayList(*new PlaylistQueue(name));
            std::cout << "Playlist added successfully" << std::endl;


        }
        else if(toDo == "add"){
            std::cout << "Whats the name of the playlist you want to add a song to? " << std::endl;
            std::string playListName;
            //std::cin.ignore();
            std::getline(std::cin ,playListName);


            std::string check = currCollection->printPlayList(playListName);
            if(check == ""){
                std::cout << "Please enter a valid playlist name" << std::endl;
            }
            else{
                std::cout << "Whats the name of the artist who made the song" << std::endl;
                std::string artist;
                //std::cin.ignore();
                std::getline(std::cin ,artist);
                std::cout << "Whats the title of the song?" << std::endl;
                std::string title;
                //std::cin.ignore();
                std::getline(std::cin ,title);

                std::cout << "What you entered: " + artist + " " + title<< std::endl;

                if(currLib->findSongIndex(artist, title) == -1){
                    std::cout << "Sorry, I don't seem to have that song in my library" << std::endl;
                }
                else{
                    int index = currLib->findSongIndex(artist, title);
                    currCollection->getPlaylist(playListName).addSong(currLib->getSong(index));
                    std::cout << "Song has been added" << std::endl;
                }
            }

        }
        else if(toDo == "remove"){
            std::cout << "Whats the name of the playlist you want to remove a song from? " << std::endl;
            std::string playListName;
            std::cin.ignore();
            std::getline(std::cin ,playListName);

            std::string check = currCollection->printPlayList(playListName);
            if(check == ""){
                std::cout << "Please enter a valid playlist name";
            }
            else{
                std::cout << "Whats the name of the artist who made the song" << std::endl;
                std::string artist;
                std::cin.ignore();
                std::getline(std::cin, artist);
                std::cout << "Whats the title of the song?" << std::endl;
                std::string title;
                std::cin.ignore();
                std::getline(std::cin ,title);

                if(currLib->findSongIndex(artist, title) == -1){
                    std::cout << "Sorry, I don't seem to have that song in my library" << std::endl;
                }
                else{
                    int index = currLib->findSongIndex(artist, title);
                    currCollection->getPlaylist(playListName).removeSong(currLib->getSong(index));
                    std::cout << "Song has been removed" << std::endl;
                }
            }

        }
        else if(toDo == "playnext"){
            std::cout << "What playlist would you like to play the next song on? " << std::endl;
            std::string name;
            std::cin.ignore();
            std::getline(std::cin ,name);

            if(currCollection->printPlayList(name) == ""){
                std::cout << "Please enter the name of a valid playlist" << std::endl;
            }
            else{
                Song temp = currCollection->getPlaylist(name).playNext();
                temp.incrementPlayCount();
                std::cout << temp << std::endl;
            }

        }
        else if(toDo == "newrandom"){
            std::cout << "What do you want to name the playlist?" << std::endl;
            std::string name;
            std::cin.ignore();
            std::getline(std::cin ,name);

            std::cout << "How long do you want it to be?" << std::endl;
            //TODO



        }
        else if(toDo == "quit"){
            std::cout << "Thank you for using this Auto DJ!" << std::endl;
            loop = false;

        }
        else{
            std::cout << "Thanks not a valid function! type 'help' to see a list of commands" << std::endl;
        }
    }

    return -1;
}