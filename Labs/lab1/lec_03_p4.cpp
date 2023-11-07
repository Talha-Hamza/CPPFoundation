#include <iostream>
using namespace std;
int main() {
    cout << "Enter a 24-hour time in the format HH:MM" << endl;
    int hour, min;
    char trash; // collect single-character garbage
    double cost = 0.0;
    cin >> hour >> trash >> min;

if (min >= 0 && min <= 59 && hour >= 0 && hour <= 23) {
cout << "Valid time" << endl;
    if (hour == 17) {
        cost = 10000;
    }
    else if (hour == 18) {
        cost = 15000;
    }
    else if (hour == 19) {
        cost =190000;
    }
    else {
        cost = 4999;
    }
}
else {
    cout << "Invalid time" << endl;
    return 0;
}
    cout << "The cost of a 30 second commercial break starting at ";
    cout << hour << ":" << min;
    cout << " is $" << cost << endl;
    return 0;
}
