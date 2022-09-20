//
// Created by jakea on 6/11/2021.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Song.h"

using namespace std;

Song::Song() {
	name = "none";
	lyrics = "none";


}

void Song::SetSongName(string songName) {
	name = songName;

}

void Song::SetSongLyrics(string firstLine) {
	lyrics = firstLine;

}

Song::Song(int timesPlayed) {
	played = timesPlayed;
}

string Song::GetSongName() {
	return name;
}

string Song::GetSongLyrics() {
	return lyrics;
}

int Song::GetTimesPlayed() {
	return played;
}

void Song::IncreaseTimesPlayed() {
	++played;

}
