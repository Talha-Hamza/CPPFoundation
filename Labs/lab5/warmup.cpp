#include <iostream>

using namespace std;

class Point
{ 
   public:
void showPoint( );
Point( );
Point(int newX, int newY) {
	xlocation = newX;
	ylocation = newY;
}
int xlocation;
int ylocation; 
} ;

int main(){

int a = 1;
int b = 2;
int* myIntPointer;
myIntPointer = &a;

Point* myPointPointer = new Point(*myIntPointer, b);
*myIntPointer = myPointPointer->ylocation;
myPointPointer->xlocation = 10;

cout << myPointPointer->xlocation << ' ' << *myIntPointer;
cout << ' ' << b << ' ' << a << endl;

return 0;
}