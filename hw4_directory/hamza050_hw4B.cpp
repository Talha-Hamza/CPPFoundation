#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    ifstream inFS("statistics.csv");
    string grade;
    int frequency;
    int max = 0;

    ofstream outFS("histogram.txt");
    if (!outFS.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    

    if (!inFS.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }

    string line;

    while (getline(inFS, line)) {
        stringstream ss(line);
        getline(ss, grade, ',');
        ss >> frequency;
        // cout << "Grade: " << grade << endl;
        // cout << "Frequency: " << frequency << endl;
        // cout << endl;

        if (frequency > max) {
            max = frequency;
        }

        outFS << grade ;
        for (int i = 0; i < frequency; ++i) {
            outFS << " X";
        }
        outFS << endl;
    }

    if (!inFS.eof()) {
        cout << "Input failure before reaching the end of the file." << endl;
    }

    inFS.close();
    
    int numEqualSigns = (1+max)*2;
    for (int i = 0; i < numEqualSigns; ++i) {
        outFS << "=";
    }
    outFS << endl;

    outFS << "  ";
    for (int i = 1; i <= max; ++i) {
        outFS << i << " ";
    }

    outFS.close();

    return 0;
}
