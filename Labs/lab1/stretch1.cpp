#include <iostream>
using namespace std;

int main() {

int x = 20;
double h = 1e-9;
double derivative = 0.0;

// function f is x^3


double v = x + h;

double fv = v*v*v;
double fx = x*x*x;

double df = fv - fx;
derivative = df/h;

cout << "derivative = " << derivative << endl;

    return 0;
}

