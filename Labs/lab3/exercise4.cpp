#include <iostream>
#include <string>
#include <iomanip>
# include <cmath>

using namespace std;

double babylonianRoot(double n){

double old_guess = 1.0;
double new_guess = 0.1;

while (abs(old_guess - new_guess) > 0.0001){
    old_guess = new_guess;
    new_guess = (old_guess + n/old_guess)/2;
    cout << setprecision(5) << fixed;
}

return new_guess;
}


int main(){
int num;
bool flag = true;
char choice;

while (flag){
cout << "enter a value: ";
cin >> num;

if (num < 0){
    cout << "Please enter a valid input(Positive Integer)." << endl;
    return 0;
}

cout << "square root of " << num << " is " << babylonianRoot(num) << endl;

cout << "continue? (y/n): ";
cin >> std::ws;
cin >> choice;

if (choice == 'n'){
    flag = false;
}
}
    return 0;
}