// EE 1301 
// HW 5B
// Talha Hamza
// HAMZA050

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

int main(int agrc, char* argv[]){

    // check if the user entered the correct number of arguments
    if (agrc != 4){
        cout << "Usage: program.exe rows columns arrayMax" << endl;
        return 1;
    }

    // create and open a text file named randArray.txt
    ofstream randArray;
    randArray.open("randArray.txt");
    
    // get the number of columns and rows and the max value from the user
    int c = atoi(argv[1]);
    int r = atoi(argv[2]);
    int max = atoi(argv[3]);

// seed the random number generator
    srand(time(0));

    // write the number of rows and columns to the file
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            // cout << setw(3) << rand() % (max * 2 + 1) - max;
            randArray << rand() % (max * 2 + 1) - max << " "; // write a random number between -max and max to the file
        }
        if (i != r-1){
            randArray << endl;
        }
    }

    // close the file 
    randArray.close();

    return 0;
}