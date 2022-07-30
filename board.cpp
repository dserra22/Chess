#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <unistd.h>


void printBoard(vector<vector<Piece*>>& board) {
    unsigned int microsecond = 50;
    usleep(3 * microsecond);
    cout << "\033[2J" << endl;
    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "8" << endl;
    cout << " | "; board.at(0).at(0)->printPiece();  cout << " | "; board.at(0).at(1)->printPiece();
    cout << " | "; board.at(0).at(2)->printPiece();  cout << " | "; board.at(0).at(3)->printPiece();
    cout << " | "; board.at(0).at(4)->printPiece();  cout << " | "; board.at(0).at(5)->printPiece();
    cout << " | "; board.at(0).at(6)->printPiece();  cout << " | "; board.at(0).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "7" << endl;
    cout << " | "; board.at(1).at(0)->printPiece();  cout << " | "; board.at(1).at(1)->printPiece();
    cout << " | "; board.at(1).at(2)->printPiece();  cout << " | "; board.at(1).at(3)->printPiece();
    cout << " | "; board.at(1).at(4)->printPiece();  cout << " | "; board.at(1).at(5)->printPiece();
    cout << " | "; board.at(1).at(6)->printPiece();  cout << " | "; board.at(1).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "6" <<  endl;
    cout << " | "; board.at(2).at(0)->printPiece();  cout << " | "; board.at(2).at(1)->printPiece();
    cout << " | "; board.at(2).at(2)->printPiece();  cout << " | "; board.at(2).at(3)->printPiece();
    cout << " | "; board.at(2).at(4)->printPiece();  cout << " | "; board.at(2).at(5)->printPiece();
    cout << " | "; board.at(2).at(6)->printPiece();  cout << " | "; board.at(2).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "5" << endl;
    cout << " | "; board.at(3).at(0)->printPiece();  cout << " | "; board.at(3).at(1)->printPiece();
    cout << " | "; board.at(3).at(2)->printPiece();  cout << " | "; board.at(3).at(3)->printPiece();
    cout << " | "; board.at(3).at(4)->printPiece();  cout << " | "; board.at(3).at(5)->printPiece();
    cout << " | "; board.at(3).at(6)->printPiece();  cout << " | "; board.at(3).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "4" << endl;
    cout << " | "; board.at(4).at(0)->printPiece();  cout << " | "; board.at(4).at(1)->printPiece();
    cout << " | "; board.at(4).at(2)->printPiece();  cout << " | "; board.at(4).at(3)->printPiece();
    cout << " | "; board.at(4).at(4)->printPiece();  cout << " | "; board.at(4).at(5)->printPiece();
    cout << " | "; board.at(4).at(6)->printPiece();  cout << " | "; board.at(4).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "3" << endl;
    cout << " | "; board.at(5).at(0)->printPiece();  cout << " | "; board.at(5).at(1)->printPiece();
    cout << " | "; board.at(5).at(2)->printPiece();  cout << " | "; board.at(5).at(3)->printPiece();
    cout << " | "; board.at(5).at(4)->printPiece();  cout << " | "; board.at(5).at(5)->printPiece();
    cout << " | "; board.at(5).at(6)->printPiece();  cout << " | "; board.at(5).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "2" << endl;
    cout << " | "; board.at(6).at(0)->printPiece();  cout << " | "; board.at(6).at(1)->printPiece();
    cout << " | "; board.at(6).at(2)->printPiece();  cout << " | "; board.at(6).at(3)->printPiece();
    cout << " | "; board.at(6).at(4)->printPiece();  cout << " | "; board.at(6).at(5)->printPiece();
    cout << " | "; board.at(6).at(6)->printPiece();  cout << " | "; board.at(6).at(7)->printPiece(); cout << endl;

    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << " |      |      |      |      |      |      |      |      | " << "1" << endl;
    cout << " | "; board.at(7).at(0)->printPiece();  cout << " | "; board.at(7).at(1)->printPiece();
    cout << " | "; board.at(7).at(2)->printPiece();  cout << " | "; board.at(7).at(3)->printPiece();
    cout << " | "; board.at(7).at(4)->printPiece();  cout << " | "; board.at(7).at(5)->printPiece();
    cout << " | "; board.at(7).at(6)->printPiece();  cout << " | "; board.at(7).at(7)->printPiece(); cout << endl;
    cout << "   ____   ____   ____   ____   ____   ____   ____   ____   " << endl;
    cout << "    A      B     C       D      E      F     G       H" << endl;

}

void populateBoard(vector<vector<Piece*>>& board) {

    for (int i = 0; i < 8; ++i) {
        vector<Piece*> row;
        for (int j = 0; j < 8; ++j) {
            Piece *piece;
            if (i == 6 || i == 1) {
                if (i == 1) // lower number = blue team
                    piece = new Pawn(i, j, false);
                else {
                    piece = new Pawn(i, j, true); 
                }                  
            } else if (i == 0) {
                if (j == 0 || j == 7) {
                    piece = new Rook(i, j, false);
                }
                if (j == 1 || j == 6) {
                    piece = new Knight(i, j, false);
                }
                if (j == 2 || j == 5) {
                    piece = new Bishop(i, j, false);
                }
                if (j == 3) {
                    piece = new Queen(i, j, false);
                }
                if (j == 4) {
                    piece = new King(i, j, false);
                }          
            } else if (i == 7) {
                if (j == 0 || j == 7) {
                    piece = new Rook(i, j, true);
                }
                if (j == 1 || j == 6) {
                    piece = new Knight(i, j, true);
                }
                if (j == 2 || j == 5) {
                    piece = new Bishop(i, j, true);
                }
                if (j == 3) {
                    piece = new Queen(i, j, true);
                }
                if (j == 4) {
                    piece = new King(i, j, true);
                }
            }
            else {
                piece = new Piece(i,j);          
            }
            row.push_back(piece);
        }
        board.push_back(row);
    }
}

void deleteBoard(vector<vector<Piece*>> &board) {
    for (int i  = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(i).size(); ++j) {
            delete board.at(i).at(j);
        }
    }
}

bool translateInput(bool redTurn, Points &points) {
    string input;
    if (redTurn) {
        cout << "Red's";
    } else {
    cout << "Blue's";
    }
    cout << " turn ";
    cin >> input;

    int count = 0;
    while (input.size() != 0) {
        // j == A-H,              i = 1-7
        if (input.at(0) == '1' || input.at(0) == 'H') {
            if (count == 1)
                points.i = 7;
            else if (count == 0)
                points.j = 7;
            else if (count == 4)
                points.i2 = 7;
            else if (count == 3)
                points.j2 = 7;
        } else  if (input.at(0) == 'G' || input.at(0) == '2') {
            if (count == 1)
                points.i = 6;
            else if (count == 0)
                points.j = 6;
            else if (count == 4)
                points.i2 = 6;
            else if (count == 3)
                points.j2 = 6;
        } else  if (input.at(0) == 'F' || input.at(0) == '3') {
            if (count == 1)
                points.i = 5;
            else if (count == 0)
                points.j = 5;
            else if (count == 4)
                points.i2 = 5;
            else if (count == 3)
                points.j2 = 5;
        } else if (input.at(0) == 'E' || input.at(0) == '4') {
            if (count == 1)
                points.i = 4;
            else if (count == 0)
                points.j = 4;
            else if (count == 4)
                points.i2 = 4;
            else if (count == 3)
                points.j2 = 4;
        } else if (input.at(0) == 'D' || input.at(0) == '5') {
            if (count == 1)
                points.i = 3;
            else if (count == 0)
                points.j = 3;
            else if (count == 4)
                points.i2 = 3;
            else if (count == 3)
                points.j2 = 3;
        } else if (input.at(0) == 'C' || input.at(0) == '6') {
            if (count == 1)
                points.i = 2;
            else if (count == 0)
                points.j = 2;
            else if (count == 4)
                points.i2 = 2;
            else if (count == 3)
                points.j2 = 2;
        } else if (input.at(0) == 'B' || input.at(0) == '7') {
            if (count == 1)
                points.i = 1;
            else if (count == 0)
                points.j = 1;
            else if (count == 4)
                points.i2 = 1;
            else if (count == 3)
                points.j2 = 1;
        } else if (input.at(0) == 'A' || input.at(0) == '8') {
            if (count == 1)
                points.i = 0;
            else if (count == 0)
                points.j = 0;
            else if (count == 4)
                points.i2 = 0;
            else if (count == 3)
                points.j2 = 0;
        } else if (input.at(0) == ':'){
            ;
        }
        else {
            return false;
        }
        count++;
        input = input.substr(1);
    }
    return true;
}