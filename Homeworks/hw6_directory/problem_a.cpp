#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


class Dice{ 
    private:
    int min ;
    int max;

    public:
    Dice(int input_min = 1, int input_max = 6);

    int roll(int input_min, int input_max);

};

Dice::Dice(int input_min, int input_max){
    min = input_min;
    max = input_max;
    srand(time(NULL));
}

int Dice::roll(int input_min, int input_max){
int num = (rand() % (input_max-input_min+1)) + input_min;
return num;
}


int main(){


int user_min;
int user_max;
Dice Dice;

cout << "Let's set up a die to roll. What are the minimum and maximum values for this die?"<<endl;
cout << "Minimum Value: ";
cin >> user_min;
cout << "Maximum Value: ";
cin >> user_max;

cout << endl;
cout << "The die is rolled 10 times. The results of those rolls are:" << endl;

for (int i = 1; i<11; ++i){

cout << "Roll #"<< i << " was: " << Dice.roll(user_min, user_max) << endl;

}


    return 0;
}