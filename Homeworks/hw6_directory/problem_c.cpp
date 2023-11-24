#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound);

int main() {
    ifstream fin;

    int sortedArray[1000] = {0};
    int counter = 0;
    int numVal = 0;
    string filename;

    cout << "What is the file with the array you want to search? ";
    cin >> filename;

    cout << "What is the number you want to find? Please provide an integer: ";
    cin >> numVal;

    fin.open(filename);

    if (!fin.is_open()) {
        cout << "Error in opening file";
        return 1;
    }

    while (counter < 1000 && fin >> sortedArray[counter]) {
        counter = counter + 1;
    }

    int arrayLength = counter;

    for (int i = 0; i < arrayLength; ++i) {
        cout << sortedArray[i] << " ";
    }

    cout << "Counter: " << counter << endl;

    binarySearch(sortedArray, numVal, 0, counter - 1);

    return 0;
}

int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound) {

    if (leftBound > rightBound) {
        cout << numVal << " not found in the array" << endl;
        return -1;
    }

    int midVal = (leftBound + rightBound) / 2;
    int foundElement = sortedArray[midVal];
    cout << "Looking at index: " << midVal << endl;

    if (foundElement == numVal) {
        cout << numVal << " can be found at index " << midVal << endl;
        return midVal;
    } else if (foundElement < numVal) {
        // lower value found, search upper half
        return binarySearch(sortedArray, numVal, midVal + 1, rightBound);
    } else {
        // higher value found, search lower half
        return binarySearch(sortedArray, numVal, leftBound, midVal - 1);
    }
}
