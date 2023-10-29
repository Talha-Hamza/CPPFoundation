// EE 1301 
// HW 3A
// Talha Hamza
// HAMZA050

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time
#include <string>       // string

using namespace std;
int main(){
bool flag = true;

while (flag){
int integer;
cout << "Enter an integer from -50 to 50: ";
cin >> integer;

while (integer < -50 || integer > 50){
    cout << "Sorry, you have entered an out of bounds input! Please enter a valid value." << endl;
    cout << "Enter an integer from -50 to 50: ";
    cin >> integer;
}

if (integer == 0){
    cout << "Goodbye." << endl;
    flag = false;
    return 0;
}

if (integer < 0) {

    for (int i = integer; i < 0; i++) {
        for (int j = 0; j < -i; j++) {
            cout << -i;
        }
        cout << endl;
    }
}
else {

for (int i = 1; i <= integer; i++){
    for (int j = 0; j < i; j++){
        cout << i;
    }
    cout << endl;
}
}
}
return 0;
}