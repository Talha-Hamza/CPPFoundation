# include <iostream>
using namespace std;

#ifndef BUGLIB_HPP
#define BUGLIB_HPP
class Bug {
public:
    int position;
    int dir;
    void move();
    void turn();
    void display();

    Bug();  // Default constructor
    Bug(int entered_position);  // Parameterized constructor
};

Bug::Bug(){
    position = 0;
    dir = 1;

}

Bug::Bug(int entered_position){
    position = entered_position;
    dir = 1;
}

void Bug::move(){
    if (dir == 1){
        position++;
    }
    else{
        position--;
    }
}

void Bug::turn(){
    if (dir == 1){
        dir = -1;
    }
    else{
        dir = 1;
    }
}

void Bug::display(){
    cout << "Position: " << position;
    cout << "  Direction: " << dir <<endl;
}
#endif
