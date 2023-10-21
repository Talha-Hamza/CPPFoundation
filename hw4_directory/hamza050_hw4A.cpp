#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFS("grades.txt");
    string name1;
    string name2;
    double grade;

    int count_A = 0;
    int count_B = 0;
    int count_C = 0;
    int count_D = 0;
    int count_F = 0;
   

    if (!inFS.is_open()) {
        // cout << "Could not open file grades.txt." << endl;
        return 1;
    }

    // cout << "Reading names and ages:" << endl;

       int count = 0;
    while (inFS >> name1 >> name2 >> grade) { // Check after reading
        count++;
        // cout << "Student " << count << endl;
        // cout << "First name: " << name1 << endl;
        // cout << "Last name: " << name2 << endl;
        // cout << "Grade: " << grade << endl;
        // cout << endl;

        if (grade >= 90) {
            count_A++;
        }
        else if (grade >= 80) {
            count_B++;
        }
        else if (grade >= 70) {
            count_C++;
        }
        else if (grade >= 60) {
            count_D++;
        }
        else {
            count_F++;
        }
    }

    if (!inFS.eof()) {
        // cout << "Input failure before reaching the end of the file." << endl;
    }

    inFS.close();

    cout << count_A << " A" << endl;
    cout << count_B << " B" << endl;
    cout << count_C << " C" << endl;
    cout << count_D << " D" << endl;
    cout << count_F << " F" << endl;

    // create a file statistics.csv if it does not exist
    ofstream outFS("statistics.csv", ios::app);

    // write the statistics to the file

    outFS << "A," << count_A << endl;
    outFS << "B," << count_B << endl;
    outFS << "C," << count_C << endl;
    outFS << "D," << count_D << endl;
    outFS << "F," << count_F << endl;

    return 0;
}
