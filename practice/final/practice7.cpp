#include <iostream>
using namespace std;

int recFunc(int number){
    if (number <= 2){
        return 2;
    }
    else{
        return (recFunc(number-1)+recFunc(number-2)-1);
    }
}

int main() {
cout << "Recursive test, x = 12 I get : " << recFunc(12) <<endl;
return 0;
}
