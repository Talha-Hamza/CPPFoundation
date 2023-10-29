// EE 1301 
// HW 3B
// Talha Hamza
// HAMZA050

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time


using namespace std;


int randWalk(int oldValue, int updateSize){

    int random = rand() % ((2*updateSize)+1) - updateSize;
    
    int newValue = oldValue + random;

    if (newValue < 0){
        newValue = 0;
    }
    else if (newValue > 255){
        newValue = 255;
    }

else{
    newValue = newValue;
}

return newValue;

}


using namespace std;
int main(){

int initial_integer;
int updateSize;
int iterations;

cout << "Please enter an initial integer value in the range [0,255]: ";
cin >> initial_integer;

while (initial_integer < 0 || initial_integer > 255){
    cout << "Value must be between 0 and 255. Please enter an initial value in the range [0,255]: ";
    cin >> initial_integer;
}

cout << "Please enter the desired number of iterations: ";
cin >> iterations;

while (iterations < 0){
    cout << "Number of iterations must be greater than 0. Please enter the desired number of iterations: ";
    cin >> iterations;
}

cout << "Please enter the size of each possible update for each iteration: ";
cin >> updateSize;

srand(time(NULL));
for (int i = 1; i <= iterations; i++){

    cout << "Value at iteration #  " << i << " is: ";
    initial_integer = randWalk(initial_integer, updateSize);
    cout << initial_integer << endl;
}


return 0;
}