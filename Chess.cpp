#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <windows.h>

using namespace std;
// Color variables
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

pair<int, int> LocalizePiece(vector<vector<char>>& board, string position) {
    int col = position[0] - 'a';
    int row = 8 - (position[1] - '0');

    return {row, col};
}

bool IsValidPos(vector<vector<char>>& board, pair<int, int> from, pair<int, int> to, char p) {
    if (isupper(board[to.first][to.second]) && isupper(p) || islower(board[to.first][to.second]) && islower(p)) {
        cout << "Pieces have not unlocked phantasmal abilities yet.\n";
        return false;
    }

    return true;
}

void MovePiece(vector<vector<char>>& board, pair<int, int> from, pair<int, int> to) {
    board[to.first][to.second] = board[from.first][from.second];
    board[from.first][from.second] = '*';
}

void DrawBoard(vector<vector<char>>& board) {
    for (int col = 0; col < board.size(); col++) {
        
        for (int v = 0; v < board[col].size(); v++) {

            if (isupper(board[col][v])) {
                cout << GREEN << board[col][v] << RESET;
            }
            else if (board[col][v] == '*' && (v + col) % 2 == 0) {
                cout << GREEN << board[col][v] << RESET;
            }
            else {
                cout << board[col][v];
            }           
        }

        cout << endl;
    }
}


int main() {
   


    //Game-Variables.
    const int sizex = 8; 
    const int sizey = 8;

    pair<int, int> selectPos;
    pair<int, int> lastPos;
    char piece;
    string position;

    int turnOrder = 0;
    vector<vector<char>> board = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    

    




    while (true) {
        system("cls");
        DrawBoard(board);


        cout << "Please type a position, no need to refer to any pieces: ";
        cin >> position;

            

        if (position.length() != 2 ||
        position[0] < 'a' || position[0] > 'h' ||
        position[1] < '1' || position[1] > '8') {
            cout << "Please type a position that is allowed. You don't need to refer to any pieces only the position. \n";
            continue;
        } else {

            selectPos = LocalizePiece(board, position);
            piece = board[selectPos.first][selectPos.second];

            if (isupper(piece) && turnOrder == 0) {
                cout << "Please type where you want to move " << board[selectPos.first][selectPos.second] << " at: ";
                cin >> position;

                if (position.length() != 2 ||
                position[0] < 'a' || position[0] > 'h' ||
                position[1] < '1' || position[1] > '8') {
                    cout << "Please type a position that is allowed. You don't need to refer to any pieces only the position. \n";
                    continue;
                } else {
                    lastPos = LocalizePiece(board, position);

                    if (IsValidPos(board, selectPos, lastPos, piece)) {
                        MovePiece(board, selectPos, lastPos);
                    } else {
                        cout << "Invalid move!" << endl;
                        Sleep(1000);
                            
                    }
                }
            } else {
                cout << "You seleceted an empty space, or the enemies pieces.";

            }

                

                
        }



    }

}