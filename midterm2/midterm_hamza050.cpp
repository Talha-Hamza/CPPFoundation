#include <iostream>
#include <cstdlib>

using namespace std;    
// declare functions
int rollDie();
bool isKindaPrime(int num);

int main()
{
// seed the random number generator with current time
srand(time(0));

// initiate loop to run 10 times
for (int i = 0; i<10; i++)
{   
    // call rollDie function and store the value in randomNum
    int randomNum = rollDie();
    cout << "Roll: "<< randomNum << " is ";

    // if result is true, print KindaPrime, else print not KindaPrime
    if (isKindaPrime(randomNum))
    {
        cout << "KindaPrime" << endl;
    }
    else
    {
        cout << "not KindaPrime" << endl;
    }
}


}


bool isKindaPrime(int num)
{
    // iterate through the provided range of 3 to 13. Divide the num by each number in the range.
    for (int i = 3; i <= 13; i++)
    {
        // to prevent division of the same number by it self, (i.e 3/3 remainder is 0) check if the number is greater than i
        if (num > i ){
        // if the remainder is 0, return false
        if (num % i == 0)
        {
            return false;
        }
        }
    }
    return true;
}


// the range I have chosen is 1-33. The reason is because 0 neither a prime nor a composite. 
// the upper range is 33 because 33 is the largest number that is not divisible by 2,3,5,7,11,13
int rollDie()
{
    int randomNum = (rand() % 33)+1;
    return randomNum;
}