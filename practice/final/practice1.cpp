#include <iomanip>
#include <iostream>
using namespace std;

class Rectangle{

    public:
    void set_length(int input_length);
    void set_width(int input_width);
    void print_area();
    Rectangle();
    Rectangle(int input_length, int input_width);

    private:
    int length;
    int width;
};

Rectangle::Rectangle(){
    width = 0;
    length = 0;
}
Rectangle::Rectangle(int input_length, int input_width){
    width = input_width;
    length = input_length;
}
void Rectangle::set_length(int input_length){
    length = input_length;
}
void Rectangle::set_width(int input_width){
    width = input_width;
}
void Rectangle::print_area(){
    cout << "Area: " << width*length << endl;
}

int main(){

    Rectangle firstRectangle;
    Rectangle secondRectangle(9,10);

    firstRectangle.set_length(5);
    firstRectangle.set_width(6);

    firstRectangle.print_area();
    secondRectangle.print_area();
 
    return 0;
}