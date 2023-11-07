# include <iostream>
#include <iomanip>

using namespace std;

void minutesToTime(int minute_value, int& hours, int& mins){
int temp_hours = 0;

while (minute_value >= 60){
    minute_value -= 60;
    temp_hours++;}

hours = temp_hours;
mins = minute_value;

cout << "Hours:minutes is " << hours << ":" << setfill('0') << setw(2) << mins << endl;;
}


int main(){

bool flag = true;
int minute_value = 0;
int hours = 0;
int mins = 0;

while (flag == true){
cout << "Enter a number of minutes: ";
cin >> minute_value;

minutesToTime(minute_value, hours, mins);

cout << "Continue? (y/n): ";
char answer;
std::ws(cin);
cin >> answer;

if (answer == 'n'){
    flag = false;
}
else if (answer == 'y'){
    flag = true;
}
else{
    cout << "Invalid input" << endl;
    flag = false;
}
}
return 0;
}