// EE 1301 
// HW 1B
// Talha Hamza
// HAMZA050


#include <iostream>     // cout, etc.
#include <iomanip>      // setprecision, fixed
#include <cmath>        // round

using namespace std;

int main()
{
// declare a variable for users choice
char choice;
int i_r;
int i_g;
int i_b;

double f_r;
double f_g;
double f_b;

// ask if input is going to be integers or doubles
cout << "Are input components int or float (i/f)? ";
cin >> choice;


// if the user chooses integers
if (choice == 'i')
{
    cout << "Input r, g, b: ";
    cin >> i_r >> i_g >> i_b;

    f_r = i_r / 255.0;
    f_g = i_g / 255.0;
    f_b = i_b / 255.0;

    cout << fixed << setprecision(2); // Use fixed for fixed-point notation
    cout << "Float representation: " << f_r << " " << f_g << " " << f_b << endl;
}

else if (choice == 'f')
{
    cout << "Input r, g, b: ";
    cin >> f_r >> f_g >> f_b;

    i_r = f_r * 255.0;
    i_g = f_g * 255.0;
    i_b = f_b * 255.0;
    cout << "Integer representation: " << static_cast<int>(i_r) << " " << static_cast<int>(i_g) << " " << static_cast<int>(i_b) << endl;
}

else
{
cout << "Invalid option." << endl;
}

    return 0;
}