// EE 1301
// HW 6A
// Talha Hamza
// HAMZA050

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Class representing a six-sided die with a specified range
class Dice {
private:
    int min; // Minimum value on the die
    int max; // Maximum value on the die

public:
    // Constructor with default values for min and max
    Dice(int input_min = 1, int input_max = 6);

    // Method to simulate rolling the die within the specified range
    int roll(int input_min, int input_max);
};

// Implementation of the Dice class
Dice::Dice(int input_min, int input_max) {
    min = input_min;
    max = input_max;
    srand(time(NULL)); // Seed the random number generator with the current time
}

// Method to simulate rolling the die within the specified range
int Dice::roll(int input_min, int input_max) {
    // Generate a random number within the specified range and return it
    int num = (rand() % (input_max - input_min + 1)) + input_min;
    return num;
}

// Main function
int main() {
    int user_min; // User-defined minimum value for the die
    int user_max; // User-defined maximum value for the die
    Dice Dice;    // Create an instance of the Dice class

    // Prompt the user to set up the die by providing minimum and maximum values
    cout << "Let's set up a die to roll. What are the minimum and maximum values for this die?" << endl;
    cout << "Minimum Value: ";
    cin >> user_min;
    cout << "Maximum Value: ";
    cin >> user_max;

    cout << endl;
    cout << "The die is rolled 10 times. The results of those rolls are:" << endl;

    // Roll the die 10 times and display the results
    for (int i = 1; i <= 10; ++i) {
        cout << "Roll #" << i << " was: " << Dice.roll(user_min, user_max) << endl;
    }

    return 0;
}
