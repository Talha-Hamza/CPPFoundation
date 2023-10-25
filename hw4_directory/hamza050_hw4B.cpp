// EE 1301 
// HW 4B
// Talha Hamza
// HAMZA050

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // open a file stream for reading from "statistics.csv"
    ifstream inFS("statistics.csv");
    string grade;
    int frequency;
    int max = 0;
    // open a file stream for writing to "histogram.txt"
    ofstream outFS("histogram.txt");
    if (!outFS.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    
    // check if input file stream opened successfully
    if (!inFS.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }

    string line;
    // read from whole lines from statistics.csv
    while (getline(inFS, line)) {
        stringstream ss(line);
        getline(ss, grade, ','); // read from the stringstream until a comma is reached
        ss >> frequency; // read from the stringstream until the end of the stringstream is reached

        // comment out the following lines to see the output of the program
        // cout << "Grade: " << grade << endl;
        // cout << "Frequency: " << frequency << endl;
        // cout << endl;

    // calculate the maximum frequency by using an if statement and measuring each frequency against the current maximum frequency
        if (frequency > max) {
            max = frequency;
        }
     // print the histogram to histogram.txt
        outFS << grade ;
        for (int i = 0; i < frequency; ++i) {
            outFS << " X"; // print X the same numver of times as each frequency
        }
        outFS << endl;
    }

    if (!inFS.eof()) {
        cout << "Input failure before reaching the end of the file." << endl;
    }

    inFS.close();
    
    int numEqualSigns = (1+max)*2; // calculate the number of equal signs needed for the histogram. This formalae was derived by observing the samples outputs. 
    for (int i = 0; i < numEqualSigns; ++i) {
        outFS << "=";
    }
    outFS << endl;

    //print the frequency numbers to histogram.txt
    outFS << "  ";
    for (int i = 1; i <= max; ++i) {
        outFS << i << " ";
    }

    outFS.close();

    return 0;
}
