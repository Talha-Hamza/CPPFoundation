// EE 1301 
// HW 5C
// Talha Hamza
// HAMZA050

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
 
using namespace std;

ifstream testArray;

int main(int argc, char* argv[]) {

// check if the user has entered the correct number of arguments. If not, print the correct usage and exit the program.
    if (argc != 2) {
        // cout << "Usage: program.exe fileName.txt" << endl;
        return 1;
    }
// get the filename from the command line argument. This is the name of the text file that contains the array to be transformed.
    string testArrayName = argv[1];

// open the text file. If the file cannot be opened, print an error message and exit the program.
    testArray.open(testArrayName);
    if (testArray.fail()) {
        cout << "Cannot find specified text file." << endl;
        return 1;
    }

// determine number of rows and columns in testArray
    int rows = 0;
    int columns = 0;
    string line;
    int sum = 0;
    while (getline(testArray, line)) {
        // each line represents a row hence rows are counted as each line is read
        rows++;
        // count the number of items in each line by counting the number of spaces. 
        int numbers = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                numbers++;
            }
        }
        columns = numbers; // since there is an extra space at the end of each item, the number of spaces is equal to the number of items
    }

// for testing purposes, print the number of rows and columns
// cout << "rows: " << rows << endl;
// cout << "columns: " << columns << endl;

// initialize a 2d array with the number of rows and columns determined above
int** array = new int*[rows];
for (int i = 0; i < rows; i++) {
    array[i] = new int[columns];
}


testArray.clear(); // Clear any error flags or state flags in the input stream.This allows me to read from the beginning 
testArray.seekg(0, ios::beg); // set the position of the next character to be extracted from the input stream to the beginning of the file
int row = 0;
int column = 0;
// read the values from the text file and store into the 2d array
while (testArray >> array[row][column]) {
    column++;
    if (column == columns) {
        row++;
        column = 0;
    }
}

// close the txt file after reading
testArray.close();


// print the 2d array. This is just for testing purposes and has been commented out.
// for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < columns; j++) {
//         cout << setw(3) << array[i][j] << " ";
//     }
//     cout << endl;
// }

// create a new 2d array to store the transformed values
int** transformedArray = new int*[rows];
for (int i = 0; i < rows; i++) {
    transformedArray[i] = new int[columns];
}


// Calculate the average of each pixel and its neighbors, the neighbours being the pixels above, below, to the left and to the right and diagonal to the pixel

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        sum = array[i][j]; // sum starts out as the calue of the pixel itself. The steps below add the values of the neighbour pixels around it
        int count = 1; // count starts out as 1 because the pixel itself is counted. it will be used to calculate the average. 
;
/* the below 3 if statements add the top & top diagnol pixels if they exist */

        if (i > 0) { // ensure pixel above exists. 
            sum += array[i - 1][j]; // add pixel one row above;

            count++; // increment count because the pixel above exists and is added to sum. I will not repeat this comment for the other if statements below.

            if (j > 0) { // ensure pixel to the top left exists.
                sum += array[i - 1][j - 1]; // add pixel that is one row above and one column to the left
                count++;
            } 
            if (j < columns - 1) { // ensure pixel to the top right exists.
                                    // columns - 1 because the index of the rightmost column is columns - 1 (since the index starts at 0)
                sum += array[i - 1][j + 1]; // add pixel that is one row above and one column to the right
                count++;
            }
        }
        if (i < rows - 1) {  // ensure pixel below exists.
            sum += array[i + 1][j]; // add pixel one row below
            count++;

            if (j > 0) { // ensure pixel to the bottom left exists.
                sum += array[i + 1][j - 1]; // add pixel that is one row below and one column to the left
                count++;
            }
            if (j < columns - 1) { // ensure pixel to the bottom right exists.
                sum += array[i + 1][j + 1]; // add pixel that is one row below and one column to the right
                count++;;
            }
        }
        if (j > 0) { // ensure pixel to the left exists.   
            sum += array[i][j - 1]; // add pixel one column to the left
            count++;
        }
        if (j < columns - 1) { // ensure pixel to the right exists.
            sum += array[i][j + 1]; // add pixel one column to the right
            count++;
        }

        // store the average of the pixel and its neighbours in the transformed array in the same position as the original pixel
        transformedArray[i][j] = sum / count;
    }
}

// print the transformed array
// cout << "Transformed" << endl;
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        cout << transformedArray[i][j] << " ";
    }
    cout << endl;
}

    return 0;
}

