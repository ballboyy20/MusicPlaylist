//
// Created by jakea on 6/11/2021.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Song.h"

#ifndef MAIN_LAB_8_PLAYLIST_H
#define MAIN_LAB_8_PLAYLIST_H
using namespace std;

class Playlist {
public:
	Playlist();

	Playlist(string userPlaylistName);

	string GetPlaylistName();

	void AddSongToPlaylist(Song* songPointer);

	void PrintPlaylist(); //prints songs for playing a playlist
	void ListSongsInPlaylist(); //prints songs for selecting which one to remove from playlist
	void RemoveSongFromPlaylist(int index);
	void RemoveSongFromPlaylist(Song* removeSong);

private:
	string name;
	vector<Song*> allSongs;

};


#endif //MAIN_LAB_8_PLAYLIST_H

