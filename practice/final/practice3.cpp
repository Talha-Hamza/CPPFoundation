#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(){

    int size = 0;
    int count = 0;
    int value_holder;
    ifstream inFs;
    char garbage;

    inFs.open("text.txt");

    if (!inFs.is_open()){
        cout << "Could not open file";
        return 1;
    }

    cout << "Starting to read number"<< endl;

    // get the very first element
    inFs >> size;
    cout << "Size is: " << size << endl;
    // based on the size, we can create an array
    int *arr = new int[size];

    // garbage the comma
    inFs >> garbage;

    // get value rught after comma
    inFs >> value_holder;
    cout << value_holder << " ";

    // store it in the array
    arr[count] = value_holder;
    count++;


    while(!inFs.eof()){
    // get the very first element
    inFs >> value_holder;
    cout << value_holder << " ";
    // store it in the array
    arr[count] = value_holder;
    count++;

    // garbage the comma
    inFs >> garbage;

    // get value rught after comma
    inFs >> value_holder;
    cout << value_holder << " ";

    // store it in the array
    arr[count] = value_holder;
    count++;

    }

    // print the array
    cout << endl << "Printing array" << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    // output the reverse of this array in a new text file called new.txt
    cout << endl <<"Done reading. Now closing file" << endl;
    inFs.close();   

    ofstream fout;

    fout.open("new.txt");

    
    cout << endl << "outputing array" << endl;
        for (int i = (size-1); i >= 0; --i){
            fout << arr[i] << " ";
        }
    
    fout.close();


    return 0;
}