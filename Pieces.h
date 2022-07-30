#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "board.h"

//#pragma once;

using namespace std;

class Piece {
    protected:
    
    private:


    public:
    int i;
    int j;
    bool isPiece;
    string piece;
    bool redTeam;
    bool isTeam;
    Piece() {
        isPiece = false;
        isTeam = false;
        i = -1;
        j = -1;
        piece = "Piece";
    }

    Piece(int I, int J) {
        isPiece = false;
        isTeam = false;
        i = I;
        j = J;
        piece = "Piece";
    }

    Piece(const Piece &other) {
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    Piece& operator=(const Piece &other) {
                cout << "operator=";
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    

    void setIJ(int i1, int j1) {
        i = i1;
        j = j1;
    }
    void virtual printPiece() {
        cout << "    ";
        piece = "Piece";
    }
    bool virtual move(Points points, vector<vector<Piece*>> &board) {
        return true;
    }
    string virtual getPiece() {
        return piece;
    }
    bool virtual getTeam() {
        return redTeam;
    }


};
class Pawn : public Piece {
    private:
    bool firstMove;
    public:
    
    Pawn(int I, int J, bool tR) {
        i = I;
        j = J;
        redTeam = tR;
        firstMove = true;
        piece = "Pawn";
        isPiece = true;
        isTeam = true;
    }
    Pawn(const Pawn &other) {
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }

    Pawn& operator=(const Pawn &other) {
        cout << "operator=";
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    

    void printPiece() {
        if (redTeam) {
        cout << "\033[1;35m";
        } else {
            cout << "\033[1;36m";
        }
        cout << "Pawn";
        cout << "\033[1;37m";
    }

    string getPiece() {
        return piece;
    }


    // spot suggested is a valid square within its movement (excluding the blockages)
    // red--i;
    // blue ++i;

    // attacking on diaganol does not work
    bool move(Points points, vector<vector<Piece*>> &board) {
    
    int j = points.j2-points.j;
    int i = points.i2-points.i;
    
    if (redTeam) {
        if (i > 0) {
            cout << "i > 0";
            return false;
        }
    } else {
        if (i < 0) {
            cout << "i < 0";
            return false;
        }
    }
    
    j = abs(j);
    i = abs(i);
    // Blue: (1,3) -> (2,3);
    // slope (1/0);
    // Red (6,0) -> (5,0);
    // slope (-1/0);
    // Pawns can only move forward. So fix it cunt


        if (firstMove) {
            firstMove = false;
            if ((i == 1 && j == 0) && board.at(points.i2).at(points.j2)->isPiece == false
            || i == 2 && j == 0 && board.at(points.i2).at(points.j2)->isPiece == false 
            || i == 1 && j == 1 && board.at(points.i2).at(points.j2)->isPiece) {
                return true;
            } else {
                return false;
            }
        }
    

    if ((i == 1 && j == 1 && board.at(points.i2).at(points.j2)->isPiece)
    || (i == 1 && j == 0 && board.at(points.i2).at(points.j2)->isPiece == false)) {
        cout << "move";
        return true;
    }
    return false;


    }



};

class King : public Piece {
    public:
    King(int I, int J, bool tR) {
        i = I;
        j = J;
        redTeam = tR;
        piece = "King";
        isPiece = true;
        isTeam = true;
    }
    /*
    King& operator=(const King &other) {
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    */

    void printPiece() {
        if (redTeam) {
        cout << "\033[1;35m";
        } else {
            cout << "\033[1;36m";
        }
        cout << "King";
        cout << "\033[1;37m";
    }
    string getPiece() {
        return piece;
    }
    bool move(Points points, vector<vector<Piece*>> &board) {
        int j = abs(points.j2-points.j);
        int i = abs(points.i2-points.i);
        if (j == 1 && i == 0 ||
            j == 1 && i == 1 ||
            i == 1 && j == 0) {
                cout << "Valid move" << endl;
                return true;
            }
        cout << "Invalid move" << endl;
        return false;
    }
};

class Queen : public Piece {
    public:
    Queen(int I, int J, bool tR) {
        i = I;
        j = J;
        redTeam = tR;
        piece = "Queen";
        isTeam = true;
        isPiece = true;
    }
    /*
    Queen& operator=(const Queen &other) {
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    */

    void printPiece() {
        if (redTeam) {
        cout << "\033[1;35m";
        } else {
            cout << "\033[1;36m";
        }
        cout << "Quee";
        cout << "\033[1;37m";
    }
    string getPiece() {
        return piece;
    }
    bool move(Points points, vector<vector<Piece*>> &board) {
       // rooks comes first 
        if (points.i2 == points.i ||
            points.j2 == points.j) {
            cout << "Rook move";
            return true;
            }

        // then bishop
        int j = abs(points.j2-points.j);
        int i = abs(points.i2-points.i);
        if (j == i) {
            cout << "Bishop move";
            return true;
        }
    cout << "Queen cannot move";
    return false;
    }
};

class Rook : public Piece {
    public:
    Rook(int I, int J, bool tR) {
        i = I;
        j = J;
        redTeam = tR;
        piece = "Rook";
        isTeam = true;
        isPiece = true;
    }
    /*
    Rook& operator=(const Rook &other) {
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    */

    void printPiece() {
        if (redTeam) {
        cout << "\033[1;35m";
        } else {
            cout << "\033[1;36m";
        }
        cout << "Rook";
        cout << "\033[1;37m";
    }
    string getPiece() {
        return piece;
    }
    bool move(Points points, vector<vector<Piece*>> &board) {
        if (points.i2 == points.i ||
            points.j2 == points.j) {
                return true;
            }
            return false;
    }
};

class Bishop : public Piece {
    public:
    Bishop(int I, int J, bool tR) {
        i = I;
        j = J;
        redTeam = tR;
        piece = "Bishop";
        isTeam = true;
        isPiece = true;
    }
    /*
    Bishop& operator=(const Bishop &other) {
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    */

    void printPiece() {
        if (redTeam) {
        cout << "\033[1;35m";
        } else {
            cout << "\033[1;36m";
        }
        cout << "Bish";
        cout << "\033[1;37m";
    }
    string getPiece() {
        return piece;
    }

    bool move(Points points, vector<vector<Piece*>> &board) {
        int j = abs(points.j2-points.j);
        int i = abs(points.i2-points.i);
        if (j == i) {
            return true;
        }
        return false;
    }
};

class Knight : public Piece {
    public:
    Knight(int I, int J, bool tR) {
        i = I;
        j = J;
        redTeam = tR;
        piece = "Knight";
        isTeam = true;
        isPiece = true;
    }
    /*
    Knight& operator=(const Knight &other) {
        if (this == &other) {
            return *this;
        }
        this->i = other.i;
        this->j = other.j;
        this->isPiece = other.isPiece;
        this->piece = other.piece;
        this->redTeam = other.redTeam;
        this->isTeam = other.isTeam;
    }
    */

    void printPiece() {
        if (redTeam) {
        cout << "\033[1;35m";
        } else {
            cout << "\033[1;36m";
        }
        cout << "Knig";
        cout << "\033[1;37m";
    }
     string getPiece() {
        return piece;
    }
    
    bool move(Points points, vector<vector<Piece*>> &board) {
        int j = abs(points.j2-points.j);
        int i = abs(points.i2-points.i);
        if (j == 2 && i == 1 ||
            j == 1 && i == 2) {
                cout << "Valid move" << endl;
                return true;
            }
            return false;
    }
};