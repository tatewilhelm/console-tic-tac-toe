/*
 Text based Tic Tac Toe
 A capItal I Project
 https://www.fiverr.com/capitali
 */


// Librarys and universal vars
#include <iostream>
#include <vector>

using namespace std;

bool p1Turn = true;
bool onOff = false;
int x;
int y;
int marks = 0;
string input;
/* 
okay so heres where i need to explain the boards. board arr is the board that is printed to the console.
vboard is the board that is used to calculate wins, tooken spaces, etc. Use refreshBoard() to update vboard to board arr.
in vboard, 0 = to a empty space, 1 = a X, 2 = to a O
   */

string board[4][4] = {  { "#", "1", "2", "3"},
                        { "4", "#", "#", "#"},
                        { "5", "#", "#", "#"},
                        { "6", "#", "#", "#"} };

int vboard[3][3] = {  { 0, 0, 0},
                      { 0, 0, 0},
                      { 0, 0, 0}  };

void printBoard() {
  for (int i = 0; i < 4; i++) {
    std::cout << " ";
    for (int ii = 0; ii < 4; ii++) {
      std::cout << board[i][ii] << " ";
    }
    std::cout << "\n";

  }
}                    
void refreshBoard() {
 
    for (int i = 0; i < 3; i++) {
     for (int ii = 0; ii < 3; ii++) {
       if (vboard[i][ii] == 0) {
        board[i + 1][ii + 1] = "#";
     } else if (vboard[i][ii] == 1) {
        board[i + 1][ii + 1] = "X";
        
     } else if (vboard[i][ii] == 2) {
        board[i + 1][ii + 1] = "O";
        
     } else {
       cout << "Error, A proggramming error has occured\n";
     }
       
      }
    
    }
   
 
}
 // checkforWin() returns 0 1 or 2.
 // 0 means no win. 1 means p1 won. 2 means p2 won.
 // this is the brute force method, there are more optimized ways to do it, but its too much work for this small of a project.
int checkForWin() {
  //left side
  if (vboard[0][0] == 1 && vboard[1][0] == 1 && vboard[2][0] == 1) {
    return 1;
  } else if (vboard[0][0] == 2 && vboard[1][0] == 2 && vboard[2][0] == 2) {
    return 2;
    // right side
  } else if (vboard[0][2] == 1 && vboard[1][2] == 1 && vboard[2][2] == 1) {
   return 1;
  } else if (vboard[0][2] == 2 && vboard[1][2] == 2 && vboard[2][2] == 2) {
   return 2;
   // top
  } else if (vboard[0][0] == 1 && vboard[0][1] == 1 && vboard[0][2] == 1) {
   return 1;
  } else if (vboard[0][0] == 2 && vboard[0][1] == 2 && vboard[0][2] == 2) {
   return 2;
   // bottom
  } else if (vboard[2][0] == 1 && vboard[2][1] == 1 && vboard[2][2] == 1) {
   return 1;
  } else if (vboard[2][0] == 2 && vboard[2][1] == 2 && vboard[2][2] == 2) {
   return 2;
   // postive slope diagonal
  } else if (vboard[0][2] == 1 && vboard[1][1] == 1 && vboard[2][0] == 1) {
   return 1;
  } else if (vboard[0][2] == 2 && vboard[1][1] == 2 && vboard[2][0] == 2) {
   return 2;
   // negative slope diagonal
  } else if (vboard[0][0] == 1 && vboard[1][1] == 1 && vboard[2][2] == 1) {
   return 1;
  } else if (vboard[0][0] == 2 && vboard[1][1] == 2 && vboard[2][2] == 2) {
   return 2;
    // vertical
  } else if (vboard[0][1] == 1 && vboard[1][1] == 1 && vboard[2][1] == 1) {
   return 1;
  } else if (vboard[0][1] == 2 && vboard[1][1] == 2 && vboard[2][1] == 2) {
   return 2;
    // horizontal
  } else if (vboard[1][0] == 1 && vboard[1][1] == 1 && vboard[2][2] == 1) {
   return 1;
  } else if (vboard[1][0] == 2 && vboard[1][1] == 2 && vboard[2][2] == 2) {
   return 2;
  } else {
    return 0;
  }
}


int main() {
  
      while (onOff == false) { 
     doover:if (p1Turn == true) {
    printBoard();
    cout << "\nPlayer 1's Turn (X's)\n\nEnter Coordinates by typing the the 2 numbers coorelating to the location \nof where you would like to place your marker with a colon between the 2\n\nFor Example: Coordinates (1, 5) should be typed in like \"1:5\"\n\n";
    getline(cin, input);
    cout << "\n\n\n\n";
    if (input.length() == 3) {
     x = stoi(input.substr(0, 1));
     y = stoi(input.substr(2, 1));

     if (vboard[y - 4][x - 1] == 0) {
       if (x <= 3 &&  x > 0 && y <= 6 &&  y > 3) {

       vboard[y - 4][x - 1] = 1;
       refreshBoard();
       marks++;
       p1Turn = false;
       if (checkForWin() == 1) {
         printBoard();
         cout << "\n\n\nPlayer 1 Wins!\n";
         onOff = true;
        } else if (checkForWin() == 2) {
          printBoard();
           cout << "\n\n\nPlayer 2 Wins!\n";
            onOff = true;
        } else if (marks == 9) {
          printBoard();
           cout << "\n\n\nTie!\n";
            onOff = true;
        }
       } else {
       cout << "Error, Your coordinates are out of bounds\n\n";
       goto doover;
       }
     } else {
       cout << "\nError, That space is taken\n\n";
       goto doover;
     }
    } else {
      cout << "\nError, You didnt type in a correct coordinate\n\n";
      goto doover;
    }

   } else {
    printBoard();
    cout << "Player 2's Turn (O's)\n\nEnter Coordinates by typing the the 2 numbers coorelating to the location \nof where you would like to place your marker with a colon between the 2\n\nFor Example: Coordinates (1, 5) should be typed in like \"1:5\"\n\n";
    getline(cin, input);
    cout << "\n\n\n\n";
    if (input.length() == 3) {
     x = stoi(input.substr(0, 1));
     y = stoi(input.substr(2, 1));

     if (vboard[y - 4][x - 1] == 0) {
       if (x <= 3 &&  x > 0 && y <= 6 &&  y > 3) {

       vboard[y - 4][x - 1] = 2;
       refreshBoard();
       marks++;
       p1Turn = true;
        if (checkForWin() == 1) {
          printBoard();
         cout << "\n\n\nPlayer 1 Wins!\n";
         onOff = true;
        } else if (checkForWin() == 2) {
          printBoard();
           cout << "\n\n\nPlayer 2 Wins!\n";
            onOff = true;
        } else if (marks == 9) {
           printBoard();
           cout << "\n\n\nTie!\n";
            onOff = true;
        }

       } else {
       cout << "Error, Your coordinates are out of bounds\n\n";
       goto doover;
       }
     } else {
       cout << "\nError, That space is taken\n\n";
       goto doover;
     }
    } else {
      cout << "\nError, You didnt type in a correct coordinate\n\n";
      goto doover;
    }
   }
  }
  cout << "Press Enter To Exit\n\n";
 
 cin.ignore();
}