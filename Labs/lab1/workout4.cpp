#include <iostream>
using namespace std;
int main()
{
  int x=5; //variable declarations (and initializations): 
  int a, b, c, d;
  a =  x-1     ; // represent number 4 : using only x and 1
  b =  a-1     ; // represent number 3 : using only a and 1
  c =  b-1     ; // represent number 2 : ...
  d =  c-1     ; // represent number 1
  cout << "5!=" << x*a*b*c*d        << endl; // represent 5!
  return 0;
}
