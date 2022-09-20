//
// Created by jakea on 6/11/2021.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#ifndef MAIN_LAB_8_SONG_H
#define MAIN_LAB_8_SONG_H
using namespace std;

class Song {
public:
	Song();

	Song(int timesPlayed);
	void SetSongName(string songName);

	void SetSongLyrics(string firstLine);

	string GetSongName();

	string GetSongLyrics();

	int GetTimesPlayed();

	void IncreaseTimesPlayed();


private:
	string name;
	string lyrics;
	int played = 0;


};


#endif //MAIN_LAB_8_SONG_H

