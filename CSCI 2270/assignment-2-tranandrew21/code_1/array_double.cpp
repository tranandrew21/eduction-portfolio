#include "array_double.hpp"

bool checkMovieToBeIncluded(string movieMpaRating, string mpaRatingToBeExcluded){
    // TODO
    if (movieMpaRating == mpaRatingToBeExcluded) {
        return false;
    }
    else {
        return true;
    }
    //return false;
}

void doubleArray(movieRecord *&movieArray, int &arrCapacity)
{
    // TODO
    int newCapacity = arrCapacity * 2;
    movieRecord* newArr = new movieRecord[newCapacity];

    for (int i = 0; i < arrCapacity; i++) {
        newArr[i] = movieArray[i];
    }

    arrCapacity = newCapacity;
    delete[] movieArray;
    movieArray = nullptr;
    movieArray = newArr;
}

int getTotalMoviesCount(movieRecord* distinctMovies, int length) {
    // TODO
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += distinctMovies[i].movieCount;
    }
    return sum;
}

void sortArray(movieRecord* distinctMovies, int length) {
    // TODO
    for(int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (distinctMovies[j].avgUserRating == distinctMovies[j + 1].avgUserRating) {
                if (distinctMovies[j].movieName[0] > distinctMovies[j + 1].movieName[0]) {
                    movieRecord temp = distinctMovies[j + 1];
                    distinctMovies[j + 1] = distinctMovies[j];
                    distinctMovies[j] = temp;
                }
            }
            if (distinctMovies[j].avgUserRating < distinctMovies[j+1].avgUserRating) {
                movieRecord temp = distinctMovies[j + 1];
                distinctMovies[j + 1] = distinctMovies[j];
                distinctMovies[j] = temp;
            }
        }
    }
}

void printTopNMovies(movieRecord* movieArray,int numberOfMovies)
{
    // TODO
    cout << fixed << setprecision(3);
    cout << "Movie Ratings" << "\n";
    cout << "---------------------------------------" << "\n";
    for(int i = 0; i < numberOfMovies; i++) {
        cout << movieArray[i].avgUserRating << " " << movieArray[i].movieName << endl;
    }
}
