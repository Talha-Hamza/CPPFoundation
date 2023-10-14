# include <iostream>

using namespace std;

int convert_Roman(int num){

int temp = num;

if (num >= 900 && num <= 999){
    cout  << "CM";
    temp = temp - 900;
    }
    
else if (num >= 500 && num <= 899){
    cout << "D";
    temp = temp - 500;
    }
else if (num >= 400 && num <= 499){
    cout << "CD";
    temp = temp - 400;
    }
else if (num >= 100 && num <= 399){
    cout << "C";
    temp = temp - 100;
    }
else if (num >= 90 && num <= 99){
    cout << "XC";
    temp = temp - 90;
    }
else if (num >= 50 && num <= 89){
    cout << "L";
    temp = temp - 50;
    }
else if (num >= 40 && num <= 49){
    cout << "XL";
    temp = temp - 40;
    }
else if (num >= 10 && num <= 39){
    cout << "X";
    temp = temp - 10;
    }
if (num == 9){
    cout << "IX";
    temp = 0;
    }
else if (num >= 5 && num <= 8){
    cout << "V";
    temp = temp - 5;
    }
else if (num == 4){
    cout << "IV";
    temp = 0;
    }
else if (num >= 1 && num <= 3){
    cout << "I";
    temp = temp - 1;}
return temp;
}

int main(){

int num;
int temp;

cout << "Enter an integer value from 1 to 999: ";
cin >> num;

if (num < 1 || num > 999){
    cout << "Invalid input.	Program terminated." << endl;
    return 0;
}

cout << "The Roman numeral equivalent of " << num << " is ";

temp = convert_Roman(num);
while (temp > 0){
    temp = convert_Roman(temp);
}

    return 0;
}