# include <iostream>
# include <string>
# include <cmath>


using namespace std;

void find_factors(int num){

for (int i = 2; i <= num;){

int remainder = num % i; 

if (remainder == 0){
    num = num / i;
    if (num != 1){cout << i << " * "; }
    else {
        cout << i;
    }    
    }
else if (remainder != 0){
    i = i + 1;}
}

}


int main()
{
int num;
int factor;

cout << "Enter a number: ";
cin >> num;

find_factors(num);
return 0;
}