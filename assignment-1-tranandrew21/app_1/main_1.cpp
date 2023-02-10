#include <iostream>
#include <fstream>
#include "../code_1/fundamentals_1.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream fin;
    fin.open(argv[1]);

    if(!fin) {
        cout << "Failed to open the file" << endl;
        return 0;
    }
    float sortedArray[100];
    string newValue;
    int numElements = 0;
    while(getline(fin, newValue)) {
        numElements = addToArrayAsc(sortedArray, numElements, stof(newValue));
        for (int i = 0; i < numElements; i++) {
            cout << sortedArray[i];
            if (i == numElements - 1) {
                cout << "\n";
            }
            else {
                cout << ",";
            }
        }
    }
    return 0;
}

