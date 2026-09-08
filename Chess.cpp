#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;



int main() {
    #define RED   "\033[31m"
    #define GREEN "\033[32m"
    #define RESET "\033[0m"


    //Game-Variables.
    const int sizex = 8; 
    const int sizey = 8;

    int turnOrder = 0;
    vector<vector<char>> board;

    // Generate Board
    for (int col = 0; col < sizey; col++) {
        board.push_back({});

        for (int row = 0; row < sizex; row++) {
            board[col].push_back({'*'});
        }
    }

    //Draw Board

    for (int col = 0; col < board.size(); col++) {
        
        for (int v = 0; v < board[col].size(); v++) {

            if (board[col][v] == '*' && (v + col) % 2 == 0) {
                cout << GREEN << board[col][v] << RESET; 
            } else {
                cout << board[col][v];
            }
        }

        cout << endl;
    }
}