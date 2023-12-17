#include <iostream>
using namespace std;

class Rectangle {
public:
    int calculateArea() const {
        return length * width;
    }

    ~Rectangle() {
        cout << "Destructor called. Object deleted." << endl;
    }
    int length;
    int width;

};

int main() {
    const int numberOfRectangles = 3;

    // Declare an Array of Object Pointers
    Rectangle* rectanglePtrArray = new Rectangle[numberOfRectangles];


    // Allocate New Memory for Objects
    for (int i = 0; i < 3; ++i) {
        rectanglePtrArray[i].length = i + 1;
        rectanglePtrArray[i].width = i + 2;
    }
    
    // Operate with Object Pointer  
    Rectangle* rectanglePtr = new Rectangle;
    rectanglePtr->length = 5;
    rectanglePtr->width = 10;
    
    cout << "new rectanglePtr: " << rectanglePtr->calculateArea() << endl;
    delete rectanglePtr;

    // Operate with Array of Objects Pointers 
    for (int i = 0; i < numberOfRectangles; ++i) {
        cout << "Area[" << i << "]: " << rectanglePtrArray[i].calculateArea() << endl;
    }


    delete[] rectanglePtrArray;
    // Identify output of given code

    return 0;
}
