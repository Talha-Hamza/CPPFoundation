#include <iostream>
#include <string>

using namespace std;

int main() {
    string full_name;
    
    cout << "Enter your full name: ";
    getline(cin, full_name);
    
    // Name is in the format: First Middle Last, split it into three parts
    string first_name = full_name.substr(0, full_name.find(" "));
    full_name.erase(0, full_name.find(" ") + 1);

    string middle_name = full_name.substr(0, full_name.find(" "));
    full_name.erase(0, full_name.find(" ") + 1);

    string last_name = full_name.substr(0, full_name.find(" "));
    full_name.erase(0, full_name.find(" ") + 1);

    // Print the name in the format: Last, First Middle
    cout << last_name << ", " << first_name << " " << middle_name << endl;


    return 0;
}
