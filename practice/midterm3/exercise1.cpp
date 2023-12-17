#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){

int holder; 
int input_array[10][10];

ofstream onFs;
int array[10][10];


for (int i = 1; i<11; ++i){
    for (int j = 1; j<11; ++j){

    array[j-1][i-1] = j + ((i-1)*10);
    cout << "Adding" << array[j][i];

    }
    cout << endl;
}

// printing the array 
for (int i = 0; i<10; ++i){
    for (int j = 0; j<10; ++j){
    cout << array[j][i];
    }
    cout <<endl;
}

onFs.open("data.txt");

if (onFs.is_open()){

    cout <<"Initiating write to file."<< endl;
    for (int i = 0; i<10; ++i){
    for (int j = 0; j<10; ++j){
    onFs << array[j][i];
    if (j<9){onFs << ",";}
    }
    if(i<9){onFs << endl;}
}
onFs.close();

ifstream inFs;
char comma;
inFs.open("data.txt"); // Use the correct file name
if (inFs.is_open()) {
    cout << "Initiating read from file." << endl;
    while (!inFs.eof()){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j<9) {inFs >> input_array[j][i] >> comma;}
            else{
            inFs >> input_array[j][i];}  
        }
    }
    }
    inFs.close();
}

// printing the array 
for (int i = 0; i<10; ++i){
    for (int j = 0; j<10; ++j){
    cout << input_array[j][i];
    }
    cout <<endl;
}

}

    return 0;
}


