#include <iostream>

using namespace std;

int main()
{

int array[10] = {1,2,3,4,5,6,7,8,9,10};


int* joseph = nullptr;
int* talha = nullptr;
int* mike = nullptr;
int* andrew = nullptr;


for (int i = 0; i < 10; i++)
{
    cout << array[i];
}


joseph = &array[0];
talha = &array[9];
mike = &array[5];
andrew = &array[2];

cout <<endl << "joseph's favourite number: " << *joseph << endl ;
cout << "talha's favourite number: : " << *talha << endl << "mike's favourite number: ";
cout << *mike <<endl<< "andrew's favourite number: " << *andrew<< endl << endl;

joseph = talha;

cout <<endl << endl << "joseph's favourite number: " << *joseph << endl ;
cout << "talha's favourite number: : " << *talha << endl << "mike's favourite number: ";
cout << *mike <<endl<< "andrew's favourite number: " << *andrew<< endl << endl;

// array remains unharmed
for (int i = 0; i < 10; i++)
{
    cout << array[i];
}

    return 0;
}
