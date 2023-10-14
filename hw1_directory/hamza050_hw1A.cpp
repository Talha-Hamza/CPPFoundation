// EE 1301 
// HW 1A
// Talha Hamza
// HAMZA050

#include <iostream>     // cout, etc.
#include <iomanip>      // setprecision, fixed
#include <cmath>        // round

using namespace std;

int main()
{
    double h;
    double r;
    double volume_tank;
    double surface_area;
    double volume_fluid;
    double surface_area_fluid;

    cout << "Input the radius of the sphere: ";
    cin >> r;
    cout << "Input the height of the fluid: ";
    cin >> h;

    volume_tank = (4.0 / 3) * M_PI * pow(r, 3);
    surface_area = 4 * M_PI * pow(r, 2);
    volume_fluid = M_PI * pow(h, 2) * (3 * r - h) / 3.0;
    surface_area_fluid = 2.0 * M_PI * r * h;

    // Print the results accurate to 2 decimal places
    cout << fixed << setprecision(2); // Use fixed for fixed-point notation

    cout << "Volume of the entire tank: " << volume_tank << endl;
    cout << "Surface area of the entire tank: " << surface_area << endl;
    cout << "Volume of the fluid: " << volume_fluid << endl;
    cout << "Surface area covered by the fluid: " << surface_area_fluid << endl;

    return 0;
}
