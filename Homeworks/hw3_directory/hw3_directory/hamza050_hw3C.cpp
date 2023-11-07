// EE 1301 
// HW 3C
// Talha Hamza
// HAMZA050

#include <iostream>     // cout, etc.
#include <stdlib.h>     // srand, rand
#include <cmath>        // pow
#include <iomanip>      // setprecision
#include <ctime>        // time

using namespace std;

int spin_the_wheels(int d, int w) {
// initialize an empty array of size w
int wheels[w];
    for (int i = 0; i < w; i++) {
        int random = ((rand() % d) + 1);
        // cout << random << " ";
        wheels[i] = random;
    }
// compare each element of the array to the first element
    for (int i = 0; i < w; i++) {
        if (wheels[i] != wheels[0]) {
            // cout << "You lose." << endl;
            return 0;
        }
    }
    // cout << "Eureka!---------------------------" << endl;  
    // print the array
    // for (int i = 0; i < w; i++) {
    //     cout << wheels[i] << " ";
    // }

   return 1;
}

int main() {
int wheels;
int range;
int initial_wheel = 3;
int initial_range = 9;
int n = 1000000;
srand(time(NULL));
for (int i = initial_wheel; i<= 6; i++){

    for (int j = initial_range; j<=27; j = j+3) {

    cout << "w=" << i << ", d=" << j << ": ";

    wheels = i;
    range = j;
    int win_count = 0;
    double theoretical = (range/(pow(range, wheels)))*100;


    int value = spin_the_wheels(range, wheels);
    // cout <<"Value returned " <<value << endl;

    for (int i = 0; i <= n; i++) {
        value = spin_the_wheels(range, wheels);
        if (value == 1) {
            win_count++;
        }
        // cout <<"Value returned " <<value << endl;
        // count++;
    }
    std::cout << std::fixed << std::setprecision(4);
    cout << "Simulated probability = m/n = " << (win_count/1000000.0)*100.0 << "%. ";
    std::cout.unsetf(std::ios::fixed);
    cout << setprecision(6);
    cout << "Theoretical Probability = " << theoretical << "%" << endl;
    // cout << "You won after " << count << " tries." << endl;
    
    }
}
    return 0;
}
