//
// Created by jakea on 6/11/2021.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Playlist.h"

using namespace std;


Playlist::Playlist() {
    name = "no playlist name";

}

Playlist::Playlist(string userPlaylistName) {
    name = userPlaylistName;

}

string Playlist::GetPlaylistName() {
    return name;
}

void Playlist::AddSongToPlaylist(Song* songPointer) {
    allSongs.push_back(songPointer);
}

void Playlist::PrintPlaylist() {
    for (int i = 0; i < allSongs.size(); ++i) {
        allSongs.at(i)->IncreaseTimesPlayed();
        cout << allSongs.at(i)->GetSongLyrics() << endl;
    }
}

void Playlist::ListSongsInPlaylist() {
    for (int i = 0; i < allSongs.size(); ++i) {
        cout << i << ": " << allSongs.at(i)->GetSongName() << endl;
    }
}

void Playlist::RemoveSongFromPlaylist(int index) {
    allSongs.erase(allSongs.begin() + index);
}

void Playlist::RemoveSongFromPlaylist(Song* removeSong) {
    for (int i = 0; i < allSongs.size(); ++i) {
        if (removeSong == allSongs.at(i)) {
            allSongs.erase(allSongs.begin() + i);
            --i; //this avoids erasing every other element
        }
    }

}

