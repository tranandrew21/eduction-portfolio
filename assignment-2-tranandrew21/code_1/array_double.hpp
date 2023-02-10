#ifndef READFILE_H__
#define READFILE_H__

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct movieRecord 
{
	string movieName;
	int movieCount;
	float avgUserRating;
};

bool checkMovieToBeIncluded(string movieMpaRating, string mpaRatingToBeExcluded);
void doubleArray(movieRecord *&movieArray, int &arrCapacity);
int getTotalMoviesCount(movieRecord movieRecords[], int length);
void sortArray(movieRecord movieRecords[], int length);
void printTopNMovies(movieRecord* movieArray, int numberOfMovies);

#endif // READFILE_H__