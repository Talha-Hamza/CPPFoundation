#include <iostream>

using namespace std;

double* momentum (double velocity_array[], double mass ){

    double* momentum = new double [3];
    for (int i = 0; i < 3; i++){
        momentum[i] = velocity_array[i] * mass;
    }
    return momentum;
}



int main(){


    double velocity_array[3] = {1,2,3};
    double mass = 2;

    double* momentum_array = momentum(velocity_array, mass);

    for (int i = 0; i < 3; i++){
        cout << momentum_array[i] << endl;
    }

    return 0;
}