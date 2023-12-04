// EE 1301 
// HW 6B
// Talha Hamza
// HAMZA050

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector> 
using namespace std;

// Dice class declaration
class Dice{ 
    private: 
    int min ; // minimum value of the dice
    int max; // maximum value of the dice

    public:
    Dice(int input_min = 1, int input_max = 6); // constructor
    int roll(int input_min, int input_max); // roll function

};

// Dice class definition
Dice::Dice(int input_min, int input_max){
    min = input_min;
    max = input_max;
    // srand(time(NULL));
}
// roll function definition
int Dice::roll(int input_min, int input_max){
int num = (rand() % (input_max-input_min+1)) + input_min; // random number generator
return num;
}

const int MAX_NUM_DICE=50;
// pre written code. Parse the user input and store the results in the pairs array
void userInputParser(string s, int dice[], int maxNumDie) ;

int main() {
    // pre written code. Parse the user input and store the results in the pairs array
    int pairs[2 * MAX_NUM_DICE + 1] = {0};
    srand(time(0)); // DO NOT WRITE THIS LINE AGAIN OR ANYWHERE ELSE
    cout << "What die do you want to roll? (e.g. 4d3+2) ";
    string s;
    getline(cin, s);
    userInputParser(s, pairs, MAX_NUM_DICE);

    // for troubleshooting purposes uncomment the following lines:

    // print out the pairs array
    // for(int j=0; j < pairs[0]; j++)
    // {
    //     cout << pairs[j] << " ";
    // }
    // cout << endl;
     
    // ask the user how many rounds they want to roll 
    cout << "How many rounds do you want to roll? " ;
    int rounds;
    cin >> rounds;

    int size_array = pairs[0]; // find the size of the array made by the parser function
    int num_dice = (size_array-1)/2; // use the above to find the number of dice
    int randum_sum = 0; // initialize the sum of the random numbers
    int randum_temp[num_dice] = {0}; // initialize the array to store the random numbers
    Dice diceArray[num_dice]; // initialize the array of dice objects

// create an array of dice objects using the Dice class and a for loop
    for(int i=0; i < num_dice; i++)
    {
        diceArray[i] = Dice(pairs[2*i+1], pairs[2*i+2]);
    }

// to present the sample roll, call the roll function for each die and store the results in an array
// then sum the array and print the result naming it sample roll
    for(int j=0; j < num_dice; j++){
        randum_temp[j] = diceArray[j].roll(pairs[2*j+1], pairs[2*j+2]);
        }
        for(int j=0; j < num_dice; j++){
            randum_sum += randum_temp[j];
            }
    cout << "Sample roll: " << randum_sum << endl;


// create a dynamic array to store all the results of the rolls
    int* holder = new int[rounds]; 
    int temp[num_dice] = {0};

// create a for loop to roll the number of times requested by user the dice and store the results in the dynamic array
    for (int i = 0; i < rounds; i++) {
        int sum = 0;
        // this for loop rolls the all sets of dice and stores the results in the temp array
        for(int j=0; j < num_dice; j++){
        temp[j] = diceArray[j].roll(pairs[2*j+1], pairs[2*j+2]);
        }
        sum = 0;
        // this for loop sums the results of the temp array and stores as one entry in the results in the holder array
        // each entry in the holder array is regarded as one roll of all the dice
        for(int j=0; j < num_dice; j++){
            sum += temp[j];
        }
        holder[i] = sum;
    }

    // for troubleshooting purposes uncomment the following lines:
    // print out the holder array
    // for(int j=0; j < rounds; j++)
    // {
    //     cout << holder[j] << " ";
    // }
    // cout << endl;

// to find the average of the rolls, sum the holder array and divide by the number of rolls
// for loop to sum the holder array
    int sum = 0;
    for (int i = 0; i < rounds; i++){
        sum += holder[i];
    }

    // finding the minimum in the array, by setting the first entry as the minimum and comparing it to the rest of the array
    int array_min = holder[0];
    for (int i = 0; i < rounds; ++i ){
        if (holder[i]<array_min){
            array_min = holder[i];
        }
    }

    // finding the minimum in the array, by setting the first entry as the minimum and comparing it to the rest of the array
    int array_max = holder[0];
    for (int i = 0; i < rounds; ++i ){
        if (holder[i]>array_max){
            array_max = holder[i];
        }
    }

    double average = 1.0*sum/rounds; // find the average of the rolls, double is used to avoid integer division

    // cout << "Sum " <<sum << endl;
    // cout << "Number of rolls: " << total_size << endl;
    cout << "Minimum roll: " << array_min << endl;
    cout << "Maximum roll: " << array_max << endl;
    cout << "Average roll: " << average << endl;
    
}

// pre written code. Parse the user input and store the results in the pairs array

void userInputParser(string s, int dice[], int maxNumDie) {
    string data[4*maxNumDie];  // Intermediate storage for parsing input string

    // count how many '+'s or 'd's there are...
    int parts = 0;
    for(int i=0; i < s.length(); i++)
    {
        if(s[i] == 'd' || s[i] == '+')
        {
            parts++;
        }
    }
    // ... so we know the number of times to decode values

    int index=0;
    unsigned d = s.find('d');
    unsigned p = s.find('+');
    while(d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1))
    {
        bool dFirst = d < p;
        if(dFirst)
        {
            string before = s.substr(0,d); // part before the 'd' (should be just one number)
            // figure out what number is after 'd'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-d-1); i++)
            {
                if(isdigit(s[count+d+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+d+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(d+1,count); //should be just the number after 'd'

            // store these two parts
            data[index] = before;
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(d+count+1); // discard these two parts
        }
        else // same idea for the '+'
        {
            // figure out what number is after '+'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-p-1); i++)
            {
                if(isdigit(s[count+p+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+p+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(p+1,count); //should be just the number after '+'

            // store this part
            data[index] = "+";
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(p+count+1); // discard these two parts
        }

        // update d and p for next loop interation
        d = s.find('d');
        p = s.find('+');

    }

    // now we need to figure out how many dice there are (as 2d4 is 2 dice)
    // we will treat "+2" as a die that rolls [2,2]
    int diceCount = 0;
    for(int i=0; i < parts*2; i+=2)
    {
        if(data[i][0] == '+')
        {
            diceCount++;
        }
        else
        {
            diceCount+=atoi(data[i].c_str());
        }
    }

    dice[0] = diceCount*2+1; // put size in first index

    int ind=1; // index for the "dice" array (as not same as data array)
    for(int i=0; i < parts*2; i+=2)
    {
        // if we have a +, add a "Dice" that has a range of 0
        if(data[i][0] == '+')
        {
            dice[ind] = atoi(data[i+1].c_str());
            dice[ind+1] = atoi(data[i+1].c_str());

            ind+=2;
        }
        else // otherwise add however many of the dice requested
        {
            for(int j=0; j < atoi(data[i].c_str()); j++)
            {
                dice[ind] = 1;
                dice[ind+1] = atoi(data[i+1].c_str());

                ind += 2;
            }
        }
    }

}
