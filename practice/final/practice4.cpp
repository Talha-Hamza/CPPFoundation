#include <iostream>
#include <cstdlib>

using namespace std;


double* momentum(double array[], double mass){
    
    double* newArray =  new double[3];

    for (int i=0; i < 3; ++i){
       newArray[i] = mass*array[i];
    }

return newArray;
}

double* randVec (){
    
    double* randomArray = new double[3];

    for (int i=0; i < 3; ++i){
       randomArray[i] = (rand() % 201)-100;
    }

    // cout << "random array:";
    // for (int i = 0; i < 3; ++i){
    //    cout << randomArray[i] << " ";
    // }

return randomArray;
}

int main(){
    srand(time(NULL));
    double mass = (rand()% 10)+1;
    double* newArray;
    // cout << "random mass: " << mass << endl;

    int sum_first = 0;
    int sum_second = 0;
    int sum_third = 0;
    
    for (int i = 0; i < 1000; ++i){
        
        double* array = randVec();
        newArray = momentum(array, mass);

        for (int i = 0; i < 3; ++i){
        cout << newArray[i] << " ";
        }
        
        cout <<endl;

        sum_first = newArray[0] + sum_first ;
        sum_second = newArray[1] + sum_second;
        sum_third = newArray[2] + sum_third;

        delete[] array;
        delete newArray;
    }
  
    cout << endl;
    cout << "Cumulative first component sum: " << sum_first << endl;
    cout << "Cumulative second component sum: " << sum_second << endl;
    cout << "Cumulative third component sum: " << sum_third << endl;


    cout << "Average vector: [" << (sum_first/1000.0) << ", " << (sum_second/1000.0) << ", " << (sum_third/1000.0) << "]" << endl;
    return 0;
}