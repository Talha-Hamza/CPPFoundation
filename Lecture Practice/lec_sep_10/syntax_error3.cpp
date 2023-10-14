// C++ program to illustrate
// syntax error

#include <iostream>
using namespace std;

int main()
{
	int x = 10;
	int y = 15;
	
	cout << " "<< (x, y); // semicolon missed
	return 0;
}

// This code is contributed by shivanisinghss2110 on https://www.geeksforgeeks.org/errors-in-cc/
// This exaxmple has been modified.
