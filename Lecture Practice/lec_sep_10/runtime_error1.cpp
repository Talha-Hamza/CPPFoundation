// C++ program to illustrate
// run-time error
#include <iostream>
using namespace std;

int main()
{
	int n = 9, div = 0;
	int i;
	// enter the number to be divided by
	cout << "Enter the number to be divided by: ";
	cin >> i;
	// wrong logic
	// number is divided by 0,
	// so this program abnormally terminates
	div = n/i;
	
    cout << "result of division by "<< i << " is = " << div;
    return 0;
}

// This code is contributed by shivanisinghss2110 on https://www.geeksforgeeks.org/errors-in-cc/
