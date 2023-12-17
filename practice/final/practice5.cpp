# include <iostream>
using namespace std;


int sum(int number);


int main(){

    int number = sum(5);
    cout << "cumulative sum: " << number;

    return 0;
}

int sum(int number){
    int total = 0;
    if (number == 1){
        total += 1;
        return total;
    }
    else if (number == 0){
        return total;
    }
    else{
        total = number + sum(number-1);
        return total;
    }

}