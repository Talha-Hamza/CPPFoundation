// EE 1301
// HW 2C
// Talha Hamza
// hamza050

// Include necessary C++ libraries for input/output and random number generation.
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int choice; // Variable to store the user's choice.
    bool play = true; // A boolean flag to control the game loop.

    while (play == true) {
        // Prompt the user to enter the number of values on each wheel.
        cout << "How many values do you want on each wheel? ";
        cin >> std::ws; // Read and discard any leading whitespace.
        cin >> choice;

        while (choice < -1 || choice == 0) {
            // Validate user input to ensure it's positive or -1 to stop playing.
            cout << "Please enter only positive numbers to continue playing, or -1 to stop playing. ";
            cin.clear(); // Clear any error flags.
            cin.ignore(1000, '\n'); // Ignore characters in the input buffer.
            cin >> std::ws; // Read and discard any leading whitespace.
            cin >> choice;
        }

        if (choice == -1) {
            play = false; // Set play to false to exit the loop.
            cout << "OK, goodbye." << endl;
            break; // Exit the loop.
        }

        // Generate random numbers for each wheel.
        srand(time(0));
        int random1 = (rand() % choice) + 1;
        int random2 = (rand() % choice) + 1;
        int random3 = (rand() % choice) + 1;
        int random4 = (rand() % choice) + 1;

        // Display the results of the wheel spin.
        cout << "The wheels spin to give: " << random1 << " " << random2 << " " << random3 << " " << random4;

        if (random1 == random2 && random2 == random3 && random3 == random4) {
            cout << ". Eureka!" << endl; // Output a message if all values are equal.
        } else {
            cout << ". You lose." << endl; // Output a message if not all values are equal.
        }
    }

    return 0;
}