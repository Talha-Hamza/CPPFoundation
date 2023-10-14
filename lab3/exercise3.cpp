#include <iostream>
#include <string>
#include <iomanip>
# include <cmath>

using namespace std;

int main(){
int num;

double old_guess = 1.0;
double new_guess = 0.1;

cout << "Enter the Number to find square root: ";
cin >> num;

if (num < 0){
    cout << "Please enter a valid input(Positive Integer)." << endl;
    return 0;
}

cout << "Guessing..." << endl;
while (abs(old_guess - new_guess) > 0.0001){
    old_guess = new_guess;
    new_guess = (old_guess + num/old_guess)/2;
    cout << setprecision(5) << fixed;
    cout << "Guess: " << new_guess << endl;
}
cout << "Final Guess: " << new_guess << endl;

cout << "Actual Value: " << sqrt(num) << endl;



    return 0;
}