#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n;        // Variable to store the number of sides on the die.
    int random;   // Variable to store the result of rolling the die.
    bool run = true;  // A boolean flag to control the game loop.
    char decision;    // Variable to store the user's decision (y/n).

    // Prompt the user to enter the number of sides on the die (n).
    cout << "Enter the number of sides on the die: ";
    cin >> n;

    // Seed the random number generator with the current time.
    srand(time(0));

    // Generate an initial random number within the range of 1 to n.
    random = (rand() % n + 1);

    // Start an infinite loop to simulate rolling the die.
    while (run == true) {
        // Display the result of the die roll.
        cout << "You rolled a " << random << endl;
        cout << "Would you like to roll again? (y/n): ";
        
        // Read the user's decision (y/n).
        cin >> decision;

        // Check if the user input is valid.
        while (decision != 'y' && decision != 'n') {
            cout << "Invalid input. Please enter only 'y' or 'n': ";
            cin >> decision;
        }

        if (decision == 'y') {
            // Generate a new random number if the user wants to roll again.
            random = (rand() % n + 1);
        } else if (decision == 'n') {
            run = false; // Set run to false to exit the loop if the user chooses not to roll again.
        }
    }

    return 0;
}
