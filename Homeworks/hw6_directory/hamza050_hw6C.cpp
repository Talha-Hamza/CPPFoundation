// EE 1301
// HW 6C
// Talha Hamza
// HAMZA050

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function prototype for binary search
int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound);

int main() {
    // File stream for reading
    ifstream fin;

    // Array to store sorted values
    int sortedArray[1000] = {0};
    
    // Counter to keep track of the number of elements read from the file
    int counter = 0;
    
    // Number to search for in the array
    int numVal = 0;
    
    // File name
    string filename;

    // Prompt user for the file with the array
    cout << "What is the file with the array you want to search? ";
    cin >> filename;

    // Prompt user for the number to find
    cout << "What is the number you want to find? Please provide an integer: ";
    cin >> numVal;

    // Open the file
    fin.open(filename);

    // Check if the file is opened successfully
    if (!fin.is_open()) {
        cout << "Error in opening file";
        return 1;
    }

    // Read values from the file into the array
    while (counter < 1000 && fin >> sortedArray[counter]) {
        counter = counter + 1;
    }

    // Close the file
    fin.close();

    // Length of the array
    int arrayLength = counter;

    // Display the elements in the array (commented out)
    // for (int i = 0; i < arrayLength; ++i) {
    //     cout << sortedArray[i] << " ";
    // }

    // Uncomment the line below to display the counter
    // cout << "Counter: " << counter << endl;

    // Perform binary search
    binarySearch(sortedArray, numVal, 0, counter - 1);

    return 0;
}

// Binary search function
int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound) {
    // Check if the search interval is valid
    if (leftBound > rightBound) {
        cout << numVal << " is not in sortedArray" << endl;
        return -1;
    }

    // Calculate the middle index
    int midVal = (leftBound + rightBound) / 2;
    
    // Get the element at the middle index
    int foundElement = sortedArray[midVal];
    // Uncomment the line below to display the current index being examined
    // cout << "Looking at index: " << midVal << endl;

    // Check if the found element is equal to the desired value
    if (foundElement == numVal) {
        cout << numVal << " can be found at sortedArray[" << midVal << "]" << endl;
        return midVal;
    } else if (foundElement < numVal) {
        // If the found element is less than the desired value, search the upper half
        return binarySearch(sortedArray, numVal, midVal + 1, rightBound);
    } else {
        // If the found element is greater than the desired value, search the lower half
        return binarySearch(sortedArray, numVal, leftBound, midVal - 1);
    }
}
