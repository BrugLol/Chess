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

pair<int, int> FindKing(vector<vector<char>>& board, char king) {
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            if (board[row][col] == king) {
                return {row, col};
            }
        }
    }

    return {-1, -1};
}

pair<int, int> LocalizePiece(vector<vector<char>>& board, string position) {
    int col = position[0] - 'a';
    int row = 8 - (position[1] - '0');

    return {row, col};
}

bool InCheck(vector<vector<char>>& board, char king) {
    pair<int, int> KingPos = FindKing(board, king);
    int knightMoves[8][2] = {
    {-2, -1},
    {-2,  1},
    {-1, -2},
    {-1,  2},
    { 1, -2},
    { 1,  2},
    { 2, -1},
    { 2,  1}
    };

    if (KingPos.first == -1) {
        cout << RED << "ERROR KING CANNOT BE FOUND!\n" << RESET;
        return true;
    }

    int kx = KingPos.first; //Returns the row of the king
    int ky = KingPos.second; //Returns the col of the king
    if (king == 'k') {
        // Down
        for (int row = kx + 1; row < 8; row++) {
            if (board[row][ky] != '*') {
                if (board[row][ky] == 'Q' || board[row][ky] == 'R') {
                    return true;
                }

                break;
            }
        }
        
        // Up
        for (int row = kx - 1; row >= 0; row--) {
            if (board[row][ky] != '*') {
                if (board[row][ky] == 'Q' || board[row][ky] == 'R')
                    return true;
                break;
            }
        }

        // Right
        for (int col = ky + 1; col < 8; col++) {
            if (board[kx][col] != '*') {
                if (board[kx][col] == 'Q' || board[kx][col] == 'R')
                    return true;
                break;
            }
        }

        // Left
        for (int col = ky - 1; col >= 0; col--) {
            if (board[kx][col] != '*') {
                if (board[kx][col] == 'Q' || board[kx][col] == 'R')
                    return true;
                break;
            }
        }

        // Up Right
        for (int row = kx - 1, col = ky + 1; row >= 0 && col < 8; row--, col++) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'Q' || board[row][col] == 'B')
                    return true;
                break;
            }
        }

        //Down Right
        for (int row = kx + 1, col = ky + 1; row < 8 && col < 8; row++, col++) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'Q' || board[row][col] == 'B')
                    return true;
                break;
            }
        }

        //Up Left
        for (int row = kx - 1, col = ky - 1; row >= 0 && col >= 0; row--, col--) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'Q' || board[row][col] == 'B')
                    return true;
                break;
            }
        }

        //Down Left
        for (int row = kx + 1, col = ky - 1; row < 8 && col >= 0; row++, col--) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'Q' || board[row][col] == 'B')
                    return true;
                break;
            }
        }


        //Knight
        for (auto& move : knightMoves) {
            int row = kx + move[0];
            int col = ky + move[1];

            if (row >= 0 && row < 8 && col >= 0 && col < 8) {
                if (board[row][col] == 'N') {
                    return true;
                }
            }
        }

        //Pawn
        if (kx - 1 >= 0) {
            if (ky - 1 >= 0 && board[kx - 1][ky - 1] == 'P') {
                return true;
            }
            if (ky + 1 < 8 && board[kx - 1][ky + 1] == 'P') {
                return true;
            }
        }
    }

    if (king == 'K') {
        // Down
        for (int row = kx + 1; row < 8; row++) {
            if (board[row][ky] != '*') {
                if (board[row][ky] == 'q' || board[row][ky] == 'r') {
                    return true;
                }

                break;
            }
        }
        
        // Up
        for (int row = kx - 1; row >= 0; row--) {
            if (board[row][ky] != '*') {
                if (board[row][ky] == 'q' || board[row][ky] == 'r')
                    return true;
                break;
            }
        }

        // Right
        for (int col = ky + 1; col < 8; col++) {
            if (board[kx][col] != '*') {
                if (board[kx][col] == 'q' || board[kx][col] == 'r')
                    return true;
                break;
            }
        }

        // Left
        for (int col = ky - 1; col >= 0; col--) {
            if (board[kx][col] != '*') {
                if (board[kx][col] == 'q' || board[kx][col] == 'r')
                    return true;
                break;
            }
        }

        // Up Right
        for (int row = kx - 1, col = ky + 1; row >= 0 && col < 8; row--, col++) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'q' || board[row][col] == 'b')
                    return true;
                break;
            }
        }

        //Down Right
        for (int row = kx + 1, col = ky + 1; row < 8 && col < 8; row++, col++) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'q' || board[row][col] == 'b')
                    return true;
                break;
            }
        }

        //Up Left
        for (int row = kx - 1, col = ky - 1; row >= 0 && col >= 0; row--, col--) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'q' || board[row][col] == 'b')
                    return true;
                break;
            }
        }

        //Down Left
        for (int row = kx + 1, col = ky - 1; row < 8 && col >= 0; row++, col--) {
            if (board[row][col] != '*') {
                if (board[row][col] == 'q' || board[row][col] == 'b')
                    return true;
                break;
            }
        }


        //Knight
        for (auto& move : knightMoves) {
            int row = kx + move[0];
            int col = ky + move[1];

            if (row >= 0 && row < 8 && col >= 0 && col < 8) {
                if (board[row][col] == 'n') {
                    return true;
                }
            }
        }

        //Pawn
        if (kx + 1 < 8) {
            if (ky + 1 < 8 && board[kx + 1][ky + 1] == 'p') {
                return true;
            }
            if (ky - 1 >= 0 && board[kx + 1][ky - 1] == 'p') {
                return true;
            }
        }
    }


    return false;
}

bool IsValidPos(vector<vector<char>>& board, pair<int, int> from, pair<int, int> to, char p, bool& wCheck, bool& bCheck) {
    if ((isupper(board[to.first][to.second]) && isupper(p)) || (islower(board[to.first][to.second]) && islower(p))) {
        cout << "Pieces have not unlocked phantasmal abilities yet.\n";
        return false;
    } //Tried to move piece to a position occupied by the same team piece.

    char CapturedPiece = board[to.first][to.second]; //Saves captured piece.

    


    int direction;
    int rowDir;
    int colDir;

    if (p == 'P') {
        direction = -1;
        


        if (from.second == to.second) {

            if (from.first - 1 == to.first &&
                board[to.first][to.second] == '*') {
            }
            else if (from.first - 2 == to.first && from.first == 6) {

                for (int i = from.first + direction; i >= to.first; i--) {
                    if (board[i][to.second] != '*') {
                        return false;
                    }
                }

            }
            else {
                return false;
            }

        }
        else if (
            from.first - 1 == to.first &&
            (from.second - 1 == to.second || from.second + 1 == to.second) &&
            islower(board[to.first][to.second])
        ) {
        }
        else {
            cout << "Tried to move piece sideways! Or you moved more spaces \n";
            return false;
        }

        board[to.first][to.second] = board[from.first][from.second];
        board[from.first][from.second] = '*'; // Temp Move
        if (InCheck(board, 'K')) {
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do

            cout << "The WHITE king is in check!\n";
            return false;
        }
        board[from.first][from.second] = p;
        board[to.first][to.second] = CapturedPiece;
        //Re-do

    return true;
    } else if (p == 'p') {
         direction = 1;
        


        if (from.second == to.second) {

            if (from.first + 1 == to.first &&
                board[to.first][to.second] == '*') {
            }
            else if (from.first + 2 == to.first && from.first == 1) {

                for (int i = from.first + direction; i <= to.first; i++) {
                    if (board[i][to.second] != '*') {
                        return false;
                    }
                }

            } else {
                return false;
            }

        }
        else if (
            from.first + 1 == to.first &&
            (from.second + 1 == to.second || from.second - 1 == to.second) &&
            isupper(board[to.first][to.second])
        ) {
        }
        else {
            cout << "Tried to move piece sideways! Or you moved more spaces \n";
            return false;
        }

        board[to.first][to.second] = board[from.first][from.second];
        board[from.first][from.second] = '*';
        if (InCheck(board, 'k')) {
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do

            cout << "The BLACK king is in check!\n";
            return false;
        }
        board[from.first][from.second] = p;
        board[to.first][to.second] = CapturedPiece;
        //Re-do

    return true;
    }

    if (p == 'R' || p == 'r') {
        if (from.second == to.second || from.first == to.first) {
            if (from.first > to.first) {
                direction = -1;
                for (int i = from.first + direction; i != to.first; i += direction) {
                    if (board[i][to.second] != '*') {
                        return false;
                    }
                }
            } else if (from.first < to.first)  {
                direction = 1;
                for (int i = from.first + direction; i != to.first; i += direction) {
                    if (board[i][to.second] != '*') {
                        return false;
                    }
                }
            }
            
            else if (from.second > to.second) {
                direction = -1;
                for (int i = from.second + direction; i != to.second; i += direction) {
                    if (board[to.first][i] != '*') {
                        return false;
                    }
                }
            } else {
                direction = 1;
                for (int i = from.second + direction; i != to.second; i += direction) {
                    if (board[to.first][i] != '*') {
                        return false;
                    }
                }
            }   
        } else {
            return false;
        }

        if (isupper(p)) {
            board[to.first][to.second] = board[from.first][from.second];
            board[from.first][from.second] = '*'; // Temp Move
            if (InCheck(board, 'K')) {
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do

                cout << "The WHITE king is in check!\n";
                return false;
            }
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do
        }

        if (islower(p)) {
            board[to.first][to.second] = board[from.first][from.second];
            board[from.first][from.second] = '*';
            if (InCheck(board, 'k')) {
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do

                cout << "The BLACK king is in check!\n";
                return false;
            }
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do
        }
    }

    if (p == 'B' || p == 'b') {
        if (abs(from.first - to.first) == abs(from.second - to.second)) {
            int row = abs(from.second - to.second);
            int col = abs(from.first - to.first);

            if (from.first > to.first && from.second < to.second) { //Upwards and Right
                rowDir = -1;
                colDir = 1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } else if (from.first > to.first && from.second > to.second) { //Upwards and Left
                rowDir = -1;
                colDir = -1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } else if (from.first < to.first && from.second < to.second){ //Downards and Right
                rowDir = 1;
                colDir = 1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } else if (from.first < to.first && from.second > to.second) { //Downards and Left
                rowDir = 1;
                colDir = -1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } 

            if (isupper(p)) {
                board[to.first][to.second] = board[from.first][from.second];
                board[from.first][from.second] = '*'; // Temp Move
                if (InCheck(board, 'K')) {
                    board[from.first][from.second] = p;
                    board[to.first][to.second] = CapturedPiece;
                    //Re-do

                    cout << "The WHITE king is in check!\n";
                    return false;
                }
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do
            }

            if (islower(p)) {
                board[to.first][to.second] = board[from.first][from.second];
                board[from.first][from.second] = '*';
                if (InCheck(board, 'k')) {
                    board[from.first][from.second] = p;
                    board[to.first][to.second] = CapturedPiece;
                    //Re-do

                    cout << "The BLACK king is in check!\n";
                    return false;
                }
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do
            }
        } else {
            return false;
        }
    }

    if (p == 'N' || p == 'n') {
        if ((abs(to.first - from.first) == 2 && abs(to.second - from.second) == 1) || (abs(to.first - from.first) == 1 && abs(to.second - from.second) == 2)) {
            if (isupper(p)) {
                board[to.first][to.second] = board[from.first][from.second];
                board[from.first][from.second] = '*'; // Temp Move
                if (InCheck(board, 'K')) {
                    board[from.first][from.second] = p;
                    board[to.first][to.second] = CapturedPiece;
                    //Re-do

                    cout << "The WHITE king is in check!\n";
                    return false;
                }
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do
            }

            if (islower(p)) {
                board[to.first][to.second] = board[from.first][from.second];
                board[from.first][from.second] = '*';
                if (InCheck(board, 'k')) {
                    board[from.first][from.second] = p;
                    board[to.first][to.second] = CapturedPiece;
                    //Re-do

                    cout << "The BLACK king is in check!\n";
                    return false;
                }
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do
            }
            return true;

        } else {
            return false;
        }

        
    }

    if (p == 'K' || p == 'k') {
        if (!(abs(to.first - from.first) <= 1 && abs(to.second - from.second) <= 1 && from != to)) {
            return false;
        }

        if (isupper(p)) {
            board[to.first][to.second] = board[from.first][from.second];
            board[from.first][from.second] = '*'; // Temp Move
            if (InCheck(board, 'K')) {
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do

                cout << "The WHITE king is in check!\n";
                return false;
            }
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do
        }

        if (islower(p)) {
            board[to.first][to.second] = board[from.first][from.second];
            board[from.first][from.second] = '*';
            if (InCheck(board, 'k')) {
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do

                cout << "The BLACK king is in check!\n";
                return false;
            }
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do
        }
        return true;
    }

    if (p == 'Q' || p == 'q') {
        if (from.second == to.second || from.first == to.first) {
            if (from.first > to.first) {
                direction = -1;
                for (int i = from.first + direction; i != to.first; i += direction) {
                    if (board[i][to.second] != '*') {
                        return false;
                    }
                }
            } else if (from.first < to.first)  {
                direction = 1;
                for (int i = from.first + direction; i != to.first; i += direction) {
                    if (board[i][to.second] != '*') {
                        return false;
                    }
                }
            }
            
            else if (from.second > to.second) {
                direction = -1;
                for (int i = from.second + direction; i != to.second; i += direction) {
                    if (board[to.first][i] != '*') {
                        return false;
                    }
                }
            } else {
                direction = 1;
                for (int i = from.second + direction; i != to.second; i += direction) {
                    if (board[to.first][i] != '*') {
                        return false;
                    }
                }
            }   
        } else if (abs(from.first - to.first) == abs(from.second - to.second)) {
            int row = abs(from.second - to.second);
            int col = abs(from.first - to.first);

            if (from.first > to.first && from.second < to.second) { //Upwards and Right
                rowDir = -1;
                colDir = 1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } else if (from.first > to.first && from.second > to.second) { //Upwards and Left
                rowDir = -1;
                colDir = -1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } else if (from.first < to.first && from.second < to.second){ //Downards and Right
                rowDir = 1;
                colDir = 1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            } else if (from.first < to.first && from.second > to.second) { //Downards and Left
                rowDir = 1;
                colDir = -1;

                for (int i = 1; i < row; i++) {
                    if (board[from.first + i * rowDir][from.second + i * colDir] != '*') {
                        return false;
                    }
                }
            }
        }
        else {
            return false;
        }

        if (isupper(p)) {
            board[to.first][to.second] = board[from.first][from.second];
            board[from.first][from.second] = '*'; // Temp Move
            if (InCheck(board, 'K')) {
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do

                cout << "The WHITE king is in check!\n";
                return false;
            }
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do
        }

        if (islower(p)) {
            board[to.first][to.second] = board[from.first][from.second];
            board[from.first][from.second] = '*';
            if (InCheck(board, 'k')) {
                board[from.first][from.second] = p;
                board[to.first][to.second] = CapturedPiece;
                //Re-do

                cout << "The BLACK king is in check!\n";
                return false;
            }
            board[from.first][from.second] = p;
            board[to.first][to.second] = CapturedPiece;
            //Re-do
        }
    }

    return true;
}

bool IsCheckmate(vector<vector<char>>& board, char king,
                 bool& wCheck, bool& bCheck) {

    if (!InCheck(board, king))
        return false;

    bool white = (king == 'K');

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {

            char piece = board[row][col];

            if (piece == '*')
                continue;

            if (white && !isupper(piece))
                continue;

            if (!white && !islower(piece))
                continue;

            pair<int, int> from = {row, col};

            for (int toRow = 0; toRow < 8; toRow++) {
                for (int toCol = 0; toCol < 8; toCol++) {

                    pair<int, int> to = {toRow, toCol};

                    if (IsValidPos(board, from, to, piece, wCheck, bCheck)) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void MovePiece(vector<vector<char>>& board, pair<int, int> from, pair<int, int> to, char& p, bool& wCheck, bool& bCheck) {
    board[to.first][to.second] = board[from.first][from.second];
    board[from.first][from.second] = '*';

    if (p == 'P' && to.first == 0) {
        board[to.first][to.second] = 'Q';
    } else if (p == 'p' && to.first == 7) {
        board[to.first][to.second] = 'q';
    }

    wCheck = InCheck(board, 'K');
    bCheck = InCheck(board, 'k');

    
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

    bool whiteCheck = false;
    bool blackCheck = false;
    pair<int, int> selectPos;
    pair<int, int> lastPos;
    char piece;
    string position;

    int turnOrder = 0;
    vector<vector<char>> board = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', ' ', '8'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', ' ', '7'},
    {'*', '*', '*', '*', '*', '*', '*', '*', ' ', '6'},
    {'*', '*', '*', '*', '*', '*', '*', '*', ' ', '5'},
    {'*', '*', '*', '*', '*', '*', '*', '*', ' ', '4'},
    {'*', '*', '*', '*', '*', '*', '*', '*', ' ', '3'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', ' ', '2'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', ' ', '1'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}
    };
    

    




    while (true) {
        system("cls");
        DrawBoard(board);

        if (turnOrder == 0) {
            cout << "WHITE TURN! Please type a position, no need to refer to any pieces: ";
            cin >> position;
        } else {
            cout << "BLACK TURN! Please type a position, no need to refer to any pieces: ";
            cin >> position;
        }
        

            

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

                    if (IsValidPos(board, selectPos, lastPos, piece, whiteCheck, blackCheck)) {
                        MovePiece(board, selectPos, lastPos, piece, whiteCheck, blackCheck);

                        if (IsCheckmate(board, 'k', whiteCheck, blackCheck)) {
                            cout << "CHECKMATE! WHITE WINS!\n";
                            return 0;
                        }

                        turnOrder = 1;
                    } else {
                        cout << "Invalid move!" << endl;
                        Sleep(1000);
                    }
                }
            } else if (isupper(piece) && turnOrder != 0) {
                cout << "You selected an empty space, or the enemies pieces.";
                Sleep(500);
            } 
            
            if (islower(piece) && turnOrder == 1) {
                cout << "Please type where you want to move " << board[selectPos.first][selectPos.second] << " at: ";
                cin >> position;

                if (position.length() != 2 ||
                position[0] < 'a' || position[0] > 'h' ||
                position[1] < '1' || position[1] > '8') {
                    cout << "Please type a position that is allowed. You don't need to refer to any pieces only the position. \n";
                    continue;
                } else {
                    lastPos = LocalizePiece(board, position);

                    if (IsValidPos(board, selectPos, lastPos, piece, whiteCheck, blackCheck)) {
                        MovePiece(board, selectPos, lastPos, piece, whiteCheck, blackCheck);

                        if (IsCheckmate(board, 'K', whiteCheck, blackCheck)) {
                            cout << "CHECKMATE! BLACK WINS!\n";
                            return 0;
                        }

                        turnOrder = 0;
                    } else {
                        cout << "Invalid move!" << endl;
                        Sleep(1000);
                            
                    }
                }
            } else if (islower(piece) && turnOrder != 1) {
                cout << "You selected an empty space, or the enemies pieces.";
                Sleep(500);

            }
        }
    }
}