#include <iostream>
using namespace std;

int main(int argc, char* argv[])  {
        if (argc != 2){
        cout << "Incorrect number of arguments! USAGE:" << endl;
        cout << "swappy <string>";}

        string str = argv[1];
        int n = str.length();

        char first = str[0];
        char last = str[n-1];

        str[0] = last;
        str[n-1] = first;
        
        cout << str << endl;
        
}


