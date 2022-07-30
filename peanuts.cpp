/*
    Errors: if u have multiple incorrect moves, sometimes same piece
    wont move
    No checks available
    No on pessant
    Pawn can attack forward lol
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "Pieces.h"
#include "board.h"
#include "board.cpp"


using namespace std;
Points::Points() {
    int i = 0;
    int j = 0;
    int i2 = 0;
    int j2 = 0;
}


// printsPoints - testing purposes
void printPoints(Points points) {
    cout << "i : " << points.i << " j : " << points.j << endl;
    cout << "i1 : " << points.i2 << " j1 : " << points.j2 << endl;
}

// promotes pawn
bool pawnPromotion(vector<vector<Piece*>> &board, Points points, bool &redTurn) {
    if (board.at(points.i).at(points.j)->getPiece() != "Pawn") {
        return false;
    }
    if (board.at(points.i).at(points.j)->getTeam() == true &&
            points.i2 == 0 ||
            board.at(points.i).at(points.j)->getTeam() == false &&
            points.i2 == 7) {
                cout << "PAWN PROMOTION" << endl;
                cout << "WHO U WANT LOL" << endl;
                string want;
                cout <<"Q for queen, K for Knight, B for Bishop, R for Rook" << endl;
                cin >> want;

                board[points.i2][points.j2] = board.at(points.i).at(points.j);
                Piece *replacementPiece;
                if (want == "Q") {
                    replacementPiece = new Queen(points.i, points.j, redTurn);
                } else if (want == "K") {
                    replacementPiece = new Knight(points.i, points.j, redTurn);
                } else if (want == "B") {
                    replacementPiece = new Bishop(points.i, points.j, redTurn);   
                } else if (want == "R") {
                    replacementPiece = new Rook(points.i, points.j, redTurn);
                } else if (want == "King") {
                    replacementPiece = new King(points.i, points.j, redTurn);
                }
                board[points.i][points.j] = replacementPiece;
                return true;
        }
    return false;
}


// returns piece's team
bool correctTeam(Piece* piece) {

    return piece->getTeam();
}

// makes sure piece can actually move to piece2
// 1. RULES for movements in individual classes. (on pessan)
// 1a. Piece attacks(Pawn can move (to attack) if enemy is on diagonal)
// include blocked passages with your pieces on here, i <8 j < 8
bool validMove(vector<vector<Piece*>> &board, Points points) {

bool redTeam = board.at(points.i).at(points.j)->getTeam();

// makes sure the rules are valid for moving
if (!board.at(points.i).at(points.j)->move(points, board)) {
    return false;
}

// now check to see if there's obstacles
// Knight exception to obstacles
if (board.at(points.i).at(points.j)->getPiece() == "Knight") {
    return true;
}

// Blue: (1,3) -> (3,3);
// slope (2/0);
// Red (6,0) -> (4,0);
// slope (-2/0);
// printPoints(points);

while (points.i != points.i2 || points.j != points.j2) {
if (points.j2-points.j > 0) {
    points.j = points.j+1;
} else if (points.j2-points.j < 0) {
    points.j = points.j-1;
}

if (points.i2-points.i < 0) {
    points.i = points.i-1;
} else if (points.i2-points.i > 0) {
    points.i = points.i+1;
}
// printPoints(points);

// CAPTURED! (if last piece is enemy, return true so that move can occur
if (board.at(points.i).at(points.j)->getPiece() != "Piece" &&
    points.i == points.i2 && points.j == points.j2 &&
    board.at(points.i).at(points.j)->getTeam() != redTeam) {
    return true;
}

if (board.at(points.i).at(points.j)->getPiece() != "Piece") {
    return false;
}

}

    return true;
}
// return true if successfully moved
bool move(bool redTurn, vector<vector<Piece*>> &board, bool &kingSacked) {

Points points;
if (!translateInput(redTurn, points) ) {  // you are here. ur too tired
    cout << "Not a valid square(s)" << endl;
    return move(redTurn, board, kingSacked);  // 0.0 possibility
}
// blue turn can only move blue pieces
// red turn can only move red pieces
// validMove is important
    if (board.at(points.i).at(points.j)->getPiece() != "Piece" &&
    redTurn == correctTeam(board.at(points.i).at(points.j) ) && 
    validMove(board, points) == true) {

        if (board.at(points.i2).at(points.j2)->getPiece() == "King") {
            kingSacked = true;
        }

        // pawn promotion
        if (pawnPromotion(board, points, redTurn) ) { // MEMORY LEAK
            //+
        //    / return true;
        }
        
        

        // put ur piece at other points
        board[points.i2][points.j2] = board.at(points.i).at(points.j);

        Piece *replacementPiece = new Piece(points.i, points.j);
        // put regular piece in place
        Piece *tempPiece = board[points.i][points.j];
        board[points.i][points.j] = replacementPiece;
        // MAKE COPY CONSTRUCTOR DEWIE
        // THATS WHY DELETING TEMP PIECE IS DELETING BOTH FUCKING RETARD LOL
        //delete tempPiece;
        // ok dont delete it lol 
        return true;
    } else {
        cout << "Invalid move. try again" << endl;
        return move(redTurn, board, kingSacked);
    }

}
void takeTurns(vector<vector<Piece*>> board) {

cout << "Red Starts: " << endl;
cout << "move like this A2:A3" << endl;
cout << "Please write in that format" << endl;

bool kingSacked = false;
while (!kingSacked) {
    printBoard(board);
    move(true, board, kingSacked);  // true means that its reds turn
    if (kingSacked) {
        cout << "Red wins" << endl;
        return;
    }
    printBoard(board);
    move(false, board, kingSacked);  // false is blues turn
}
cout << "Blue wins" << endl;

}

int main() {

vector<vector<Piece*>> board;
vector<Piece*> finishedRed;
vector<Piece*> finishedBlue;
populateBoard(board);

takeTurns(board);
printBoard(board);

    deleteBoard(board);
    return 0;
}