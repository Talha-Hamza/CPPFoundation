# include <iostream>
using namespace std;
int main(){

string FullNameOne;
string FullNameTwo;
float heightOne;
float heightTwo;

cout << "Enter the first person's full name: ";
getline(cin, FullNameOne);
cout << "Enter the first person's height in inches: ";
cin >> std::ws;
cin >> heightOne;
cout << "Enter the second person's full name: ";
cin >> std::ws;
getline(cin, FullNameTwo);
cout << "Enter the second person's height in inches: ";
cin >> std::ws;
cin >> heightTwo;

cout << FullNameOne << " and "" " << FullNameTwo << " standing on top of each other are " << heightOne+heightTwo << " feet tall." << endl;

    return 0;
}