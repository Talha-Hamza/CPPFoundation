// EE 1301 
// HW 2B
// Talha Hamza
// hamza050
#include <iostream>
#include <string>

using namespace std;

// Function to toggle between 'A' (AM) and 'P' (PM).
char toggleMidday(char midday) {
    if (midday == 'A') {
        return 'P';
    } else if (midday == 'P') {
        return 'A';
    } else {
        cout << "Invalid midday value. Keeping it unchanged." << endl;
        return midday;
    }
}

int main() {
    // Declare variables for input and calculations.
    string input1;
    string input2;
    int hour = 0;
    char midday;
    string outputMidday;

    // Prompt the user to enter the current time (A for AM, P for PM).
    cout << "Enter the current time (A for AM, P for PM): ";
    
    // Read input and handle leading white spaces.
    cin >> std::ws;
    getline(cin, input1);
    
    // Extract the hour and midday part from the input.
    hour = stoi(input1);
    midday = input1[2];

    // Check if the hour is within the valid range (1-12) and if midday is 'A' or 'P'.
    if (hour > 0 && hour <= 12) {
        if (midday == 'A' || midday == 'P') {
            // Prompt the user to enter how many hours to move the clock forward or backward.
            cout << "How many hours forward or backward do you want to move the clock (F for forward, B for backward): ";
            
            // Read input and handle leading white spaces.
            cin >> std::ws;
            getline(cin, input2);
            
            // Extract the direction and number of hours from the input.
            char direction = input2[0];
            string input3 = input2.substr(1);
            int hour2 = stoi(input3);

            if (hour2 < 0) {
                cout << "Invalid input " << hour2 << endl;
                return 0;
            }
            // Calculate the new hour.
            int newHour = hour + hour2;

            // Ensure that newHour is within the valid range (1-12) and update midday accordingly.
            while (newHour > 12) {
                newHour = newHour - 12;
                midday = toggleMidday(midday);
            }

            // Determine whether the new time is AM or PM.
            if (midday == 'A'){
                outputMidday = "AM";
            } else if (midday == 'P') {
                outputMidday = "PM";
            }
            else{
                cout << "Invalid midday value. Keeping time unchanged." << endl;
                return 0;
            }

            // Display the new time.
            cout << "The new time is: " << newHour << " " << outputMidday << endl;

        } else {
            // Handle invalid midday input.
            cout << "Invalid input " << midday << endl;
        }
    } else {
        // Handle invalid hour input.
        cout << "Invalid input " << hour << endl;
    }

    return 0;
}
