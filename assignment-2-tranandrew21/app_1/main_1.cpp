#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // TODO
    ifstream fin;
    fin.open(argv[1]);

    string line, word, name, rating;
    int length = 0, doubleNum = 0, capacity = 10;
    float avgRating = 0;
    movieRecord *dynaMov = new movieRecord[capacity];
    while(getline(fin, line)) {
        stringstream ss(line);
            for(int i = 0; i < 4; i++) {
                getline(ss, word, '\t');
                if (i == 0) {
                    name = word;
                }
                else if (i == 1) {
                    avgRating = stof(word);
                }
                else if (i == 2) {
                    rating = word;
                }
            }
        if (checkMovieToBeIncluded(rating, argv[2]) == false) {
            continue;
        }
        movieRecord tempArr;
        tempArr.movieName = name;
        tempArr.movieCount = 1;
        tempArr.avgUserRating = avgRating;
        bool dup = false;
        for (int i = 0; i < length; i++) {
            if((dynaMov[i].movieName) == name) {
                dynaMov[i].movieCount += 1;
                dynaMov[i].avgUserRating = ((dynaMov[i].movieCount - 1) * dynaMov[i].avgUserRating + tempArr.avgUserRating) / dynaMov[i].movieCount;
                dup = true;
            }
        }
        if (dup == true) {
            continue;
        }

        dynaMov[length] = tempArr;
        length++;
        if(length == capacity) {
            doubleArray(dynaMov, capacity);
            doubleNum++;
        }
    }

    sortArray(dynaMov, length);
    int totalMovies = getTotalMoviesCount(dynaMov, length);
    cout << "Array doubled: " << doubleNum << endl;
    cout << "Distinct # of movies except " << argv[2] << ": " << length << endl;
    cout << "Total # of movies excluding " << argv[2] << " ratings: " << totalMovies << endl;
    printTopNMovies(dynaMov, stoi(argv[3]));

    delete[] dynaMov;
    dynaMov = nullptr;
    return 0;
}