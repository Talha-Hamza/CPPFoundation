#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double L;    // Variable to store the original length.
    double LR;   // Variable to store the relative length.
    double c = 3e10; // Speed of light in centimeters per second.
    double v;    // Variable to store the velocity.

    // Prompt the user to enter the original length (L) and velocity (v).
    cout << "Enter L: ";
    cin >> L;
    cout << "Enter v: ";
    
    cin >> std::ws; // Read and discard any leading whitespace.
    cin >> v;

    // Calculate the relative length (LR) using the special relativity formula.
    LR = L * sqrt(1 - (v * v) / (c * c));

    // Set the output format to display LR with 5 decimal places.
    cout << setprecision(5) << fixed;

    // Display the result: the relative length (LR).
    cout << "Relative Length = " << LR << endl;

    return 0;
}
