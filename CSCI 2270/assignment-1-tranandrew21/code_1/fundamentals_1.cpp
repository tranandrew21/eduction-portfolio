#include "fundamentals_1.hpp"

int addToArrayAsc(float sortedArray[], int numElements, float newValue) {
    // TODO
    // Creating a loop to iterate through the number of elements
    for(int i = 0; i < numElements; i++) {
        if(newValue < sortedArray[i]) { // Here if the value of the new value is less then the current value of the sorted array, we shift the value right.
            for(int j = numElements; j > i; j--) {
                sortedArray[j] = sortedArray[j-1];
            }
            sortedArray[i] = newValue;
            return numElements + 1;
        }
    }
    sortedArray[numElements] = newValue;
    return numElements + 1; // returns the current count of the elements inserted
}

