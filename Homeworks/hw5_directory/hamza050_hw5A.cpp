// EE 1301 
// HW 5A
// Talha Hamza
// HAMZA050

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Board is described by the following coordinate system:
// 0 --> +X
// |
// |
// V
// +Y
// W for wall
//check if maze.txt is in directory and can be opened

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';
const char WALL = 'W'; // added new symbol for wall
const int screen_num_lines = 25;
const int lengthX = 10;       // for now we only support square boards
const int lengthY = 10;       // it "should" work with non-square, YMMV

 // added new array for wall coordinates. I added them such that every other point is a wall
const int Wr[] = {0, 2, 4, 6, 8};
const int Wc[] = {1, 3, 5, 7, 9};

ifstream mazeFile; // global variable for maze.txt

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos); 
void clearScreen();
void showGrid(char board[lengthX][lengthY]);
bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action); 

int main()
{
    char board[lengthX][lengthY] = {0};
    int xPos = 0, yPos = 0;

    // check if maze.txt is in directory and can be opened. if not, play default mode using initBoard
    mazeFile.open("maze.txt");
    if (mazeFile.fail()) {
        // cout << "Playing default mode" << endl;
        initBoard(board, xPos, yPos);}
    else {
        // cout << "Playing custom mode" << endl;

        // start a loop to read in the maze.txt file and store each item of the text file into the board array according to the coordinates
        // determined in the maze.txt
        for(int curRow=0; curRow < lengthY; curRow++) { 
            for(int curCol=0; curCol < lengthX; curCol++) { 
                mazeFile >> board[curCol][curRow]; 
                if (board[curCol][curRow] == ROBOT) {  // set the cursor coordinates so we know where to start from
                    xPos = curCol;
                    yPos = curRow;
                }
            }
        }
    }

    while(hasChar(board, GOAL))
    {
        char action;
        clearScreen();
        showGrid(board);
        cout << "Where would you like to go? (l, r, u, d) " << endl;
        cin >> action;
        updateGrid(board, xPos, yPos, action);
    }

    clearScreen();
    showGrid(board);
    cout << "You found the cookie!  Congratulations!\n";

    return 0;
}

/*
Description: Initializes game board. Sets all characters in board as blanks,
then sets position of goal, and then sets position of robot.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
Outputs: NA
*/
void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos) {
// set all the characters in the board to be blank
        for(int curRow=0; curRow < lengthY; curRow++) {
            for(int curCol=0; curCol < lengthX; curCol++) {
                board[curCol][curRow] = BLANK;
            }
        }
// set the walls in the board according to the coordinates in the Wr and Wc arrays
// note that walls overwrite the blank spaces
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++){
                board[Wr[j]][Wc[i]] = WALL;
            }
        }
// set the goal and robot positions. This is done after the walls are set so that the walls do not overwrite the goal and robot positions
// coordinates are changed from the example 
        board[8][0] = GOAL;
        board[3][8] = ROBOT;

// starting position corresponding to robot position
        xPos = 3;
        yPos = 8;
}

/*
Description: Loops through given game board to determine if it contains given char findMe.
Inputs:
    char board[][] - 2D array used to represent game board
    char findMe - character to look for in game board
Outputs:
    bool - returns true if board contains findMe, else returns false 
*/
bool hasChar(char board[lengthX][lengthY], char findMe) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            if(board[curCol][curRow] == findMe) {
                return true;
            }
        } //end curCol loop
    } // end curRow loop

    return false;
}

/*
Description: Prints out screen_num_lines amount of end lines to terminal so 
that old board is no longer visible.
Inputs: NA
Outputs: NA
*/
void clearScreen() {
    for(int i = 0;i<screen_num_lines;i++) {
        cout << endl;
    }
}

/*
Description: Prints out input game board to the terminal.
Inputs: 
    char board[][] - 2D array used to represent game board
Outputs: NA
*/
void showGrid(char board[lengthX][lengthY]) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            cout << board[curCol][curRow];
        } // end curCol loop
        cout << endl;
    } // end curRow loop
}


void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action) {
    int newXPos = xPos;
    int newYPos = yPos;

    if (action == 'l' && xPos > 0) {
        newXPos--;
    } else if (action == 'r' && xPos < lengthX - 1) {
        newXPos++;
    } else if (action == 'u' && yPos > 0) {
        newYPos--;
    } else if (action == 'd' && yPos < lengthY - 1) {
        newYPos++;
    }
// check if the new position is not a wall
// if it is a wall do not update the coordinates 
// if it is not a wall update the coordinates
if (!(board[newXPos][newYPos] == WALL)) {
board[xPos][yPos] = BLANK;
xPos = newXPos;
yPos = newYPos;
board[xPos][yPos] = ROBOT;
}
}
