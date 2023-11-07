#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int numa;
    int numb;
    int result;
    char op;
    
    cout << "Enter an equation: ";
    cin >> std::ws;
    cin >> numa >> op >> numb;
    
    if (op == '+'){
        result= numa + numb;
    } else if (op == '-'){
        result = numa - numb;
    } else if (op == '*'){
        result =  numa * numb;
    } else if (op == '/'){
        result = numa / numb;
    } else {
        cout << "Invalid operator" << endl;
        return 0;
    }
    cout << numa <<  op  << numb << " = " << result << endl;
    return 0;
}
