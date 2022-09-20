#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"
#include "Song.h"
#include "Playlist.h"

using namespace std;

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(vector<Song*>& allSongs);

void ListSongsMenuOption(vector<Song*>& allSongs);

void AddPlaylistMenuOption(vector<Playlist>& userPlaylists);

void AddSongToPlaylistMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs);

void ListPlaylistsMenuOption(vector<Playlist>& userPlaylists);

void PlayPlaylistMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs);

void RemovePlaylistMenuOption(vector<Playlist>& userPlaylists);

void RemoveSongFromPlaylistMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs);

void RemoveSongFromLibraryMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs);

void OptionsMenuOption(/*TODO: list any parameters here*/);

void QuitMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs);

int main() {
    std::cout << "Welcome to the Firstline PLayer! Enter options to see menu options. " << std::endl << std::endl;

    vector <Song* > allSongs;
    vector <Playlist> userPlaylists;

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");
        if (userMenuChoice == "add") {
            AddSongsMenuOption(allSongs);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(allSongs);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(userPlaylists);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(userPlaylists, allSongs);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(userPlaylists);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(userPlaylists, allSongs);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(userPlaylists);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(userPlaylists, allSongs);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(userPlaylists, allSongs);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption(userPlaylists, allSongs);
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption(/*TODO: list any arguments here*/);
        }
    }


    return 0;
}

std::string GetUserString(const::string& prompt) {
    std::string userAnswer = "none";
    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;

}

int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(vector<Song*>& allSongs) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter song's names and first line"
        << " (type \"" << DONE_KEYWORD << "\" when done);" << std::endl;
    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        //Create a Song using `songName` and `firstLine` and add it to the list of songs,
       // This should be just 1-2 lines of code to create the song and add it to the list

        Song* currSong = new Song(0);
        //calls the construto which makes times played = 0
        currSong->SetSongName(songName);
        currSong->SetSongLyrics(firstLine);
        allSongs.push_back(currSong); //this might be a problem in the future
        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(vector<Song*>& allSongs) { //lists the info about every song in the libary

    Song currSong;
    for (int i = 0; i < allSongs.size(); ++i) {
        string currName = allSongs.at(i)->GetSongName();
        string currLyrics = allSongs.at(i)->GetSongLyrics();
        int currTimesPlayed = allSongs.at(i)->GetTimesPlayed();

        cout << currName << ": \"" << currLyrics << "\", " << currTimesPlayed << " play(s)." << endl;
    }
}

void AddPlaylistMenuOption(vector<Playlist>& userPlaylists) { //adds a playlist to the libary
    string userPlaylistName = GetUserString("Playlist name: ");
    Playlist currPlaylist(userPlaylistName);

    userPlaylists.push_back(currPlaylist);
}

void AddSongToPlaylistMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs) {
    int userPlaylistChosen;
    int userSongChosen;
    for (int i = 0; i < userPlaylists.size(); ++i) {
        string currName = userPlaylists.at(i).GetPlaylistName();
        cout << i << ": " << currName << endl;
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> userPlaylistChosen;
    for (int i = 0; i < allSongs.size(); ++i) {
        cout << i << ": " << allSongs.at(i)->GetSongName() << endl;
    }
    cout << "Pick a song index number: " << endl;
    cin >> userSongChosen;
    cin.ignore();
    cout << endl;
    (userPlaylists.at(userPlaylistChosen)).AddSongToPlaylist(allSongs.at(userSongChosen));
}

void ListPlaylistsMenuOption(vector<Playlist>& userPlaylists) {
    for (int i = 0; i < userPlaylists.size(); ++i) {
        string currName = userPlaylists.at(i).GetPlaylistName();
        cout << i << ": " << currName << endl;
    }
}

void PlayPlaylistMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs) {
    int userPlaylistChosen;
    for (int i = 0; i < userPlaylists.size(); ++i) {
        string currName = userPlaylists.at(i).GetPlaylistName();
        cout << i << ": " << currName << endl;
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> userPlaylistChosen;
    cin.ignore();
    cout << "Playing songs from playlist: " << userPlaylists.at(userPlaylistChosen).GetPlaylistName()
        << endl;
    userPlaylists.at(userPlaylistChosen).PrintPlaylist();
}


void RemovePlaylistMenuOption(vector<Playlist>& userPlaylists) {
    int userPlaylistChosen;
    for (int i = 0; i < userPlaylists.size(); ++i) {
        string currName = userPlaylists.at(i).GetPlaylistName();
        cout << i << ": " << currName << endl;
    }
    cout << "Pick a playlist index number to remove: " << endl;
    cin >> userPlaylistChosen;
    cin.ignore();
    userPlaylists.erase(userPlaylists.begin() + userPlaylistChosen);
}


void RemoveSongFromPlaylistMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs) {
    int userPlaylistChosen;
    int userSongChosen;
    for (int i = 0; i < userPlaylists.size(); ++i) {
        string currName = userPlaylists.at(i).GetPlaylistName();
        cout << i << ": " << currName << endl;
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> userPlaylistChosen;
    userPlaylists.at(userPlaylistChosen).ListSongsInPlaylist();
    cout << "Pick a song index number to remove: " << endl;
    cin >> userSongChosen;
    cin.ignore();
    cout << endl;
    (userPlaylists.at(userPlaylistChosen)).RemoveSongFromPlaylist(userSongChosen);

}

void RemoveSongFromLibraryMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs) {
    int userSongChosen;
    for (int i = 0; i < allSongs.size(); ++i) {
        cout << i << ": " << allSongs.at(i)->GetSongName() << endl;
    }
    cout << "Pick a song index number to remove: " << endl;
    cin >> userSongChosen;
    cin.ignore();
    for (int i = 0; i < userPlaylists.size(); ++i) {
        userPlaylists.at(i).RemoveSongFromPlaylist(allSongs.at(userSongChosen));
    }
    delete allSongs.at(userSongChosen);
    allSongs.erase(allSongs.begin() + userSongChosen);
    cout << endl;

    //deleting and freeing some things here!! :)
}

void OptionsMenuOption(/*TODO: list any parameters here*/) {
    std::cout << "add      Adds a list of songs to the library" << std::endl
        << "list     Lists all the songs in the library" << std::endl
        << "addp     Adds a new playlist" << std::endl
        << "addsp    Adds a song to a playlist" << std::endl
        << "listp    Lists all the playlists" << std::endl
        << "play     Plays a playlist" << std::endl
        << "remp     Removes a playlist" << std::endl
        << "remsp    Removes a song from a playlist" << std::endl
        << "remsl    Removes a song from the library (and all playlists)" << std::endl
        << "options  Prints this options menu" << std::endl
        << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption(vector<Playlist>& userPlaylists, vector<Song*>& allSongs) {
    std::cout << "Goodbye!" << std::endl;
    for (int i = 0; i < allSongs.size(); ++i) {
        delete allSongs.at(i);
    }
    //frees up some memory here!! :)
}
