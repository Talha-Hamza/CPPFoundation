// EE 1301
// HW 2A
// Talha Hamza
// hamza050

#include <iostream>
#include <string>

// Use the standard namespace to avoid explicit qualification of standard library objects.
using namespace std;

int main() {
    // Initialize a boolean variable 'run' to control the loop.
    bool run = true;
    
    // Initialize a string variable 'input' to store user input.
    string input;

    // Start a loop that runs until run flag is true.
    while (run) {
        // Prompt the user to enter a single digit or an alphabetic character.
        cout << "Enter a single digit or an alphabetic character: ";
        
        // Read the user input as a string and store it in the 'input' variable.
        getline(cin, input);
        
        // Extract the first character from the input and store it in 'ch'.
        char ch = input[0];
        
        // Check if the character is a digit.
        if (ch >= '0' && ch <= '9') {
            cout << "You entered " << ch << ", which is a number." << endl;
        }
        // Check if the character is a lowercase letter.
        else if (ch >= 'a' && ch <= 'z') {
            cout << "You entered " << ch << ", which is a lowercase letter." << endl;
        }
        // Check if the character is an uppercase letter.
        else if (ch >= 'A' && ch <= 'Z') {
            cout << "You entered " << ch << ", which is an uppercase letter." << endl;
        }
        // Check if the character is a space or newline character.
        else if (ch == ' ' || ch == '\n') {
            cout << "You entered " << ch << ", which is not a letter or a number." << endl;
            
            // Set 'run' to false to exit the loop.
            run = false;
        }
        // If the character doesn't match any of the above conditions, treat it as invalid.
        else {
            cout << "You entered " << ch << ", which is not a letter or a number." << endl;
            
            // Set 'run' to false to exit the loop.
            run = false;
        }
    }

    // Exit the program with a return code of 0 to indicate successful execution.
    return 0;
}