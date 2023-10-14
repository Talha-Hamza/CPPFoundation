# include <iostream>
using namespace std;

int main(){

char answer1;
char answer2;
char answer3;
int randNum;

// choose a random number between 1, 2 or 3
srand(time(0));
randNum = rand() % 3 + 1;

if (randNum == 1 ){
    cout << "Do you wish to cross the bridge? (y/n) ";
    cin >> answer1;
}
else if (randNum == 2 ){
cout << "Do you have a sword? (y/n) ";
cin >> answer1;
}

else {
cout << "Are you strong? (y/n) ";
cin >> answer1;
}

// choose a random number between 4, 5 or 6
srand(time(0));
randNum = rand() % 3 + 4;

if (randNum == 4 ){
    cout << "Do you brush your teeth? (y/n) ";
    cin >> answer2;
}
else if (randNum == 5 ){
cout << "Do you have a shield? (y/n) ";
cin >> answer2;
}

else {
cout << "Are you fast? (y/n) ";
cin >> answer2;
}

// choose a random number between 7, 8 or 9
srand(time(0));
randNum = rand() % 3 + 7;
if (randNum == 7 ){
    cout << "Do you have a horse? (y/n) ";
    cin >> answer3;
}
else if (randNum == 8 ){
cout << "Do you have a helmet? (y/n) "; 
cin >> answer3;
}

else {
cout << "Are you brave? (y/n) ";
cin >> answer3;
}


if (answer1 == 'y' && answer2 == 'y' && answer3 == 'y'){
    cout << "You cross the bridge and live happily ever after." << endl;
}
else{
    cout << "You may not cross the bridge." << endl;
}  
    return 0;
}
