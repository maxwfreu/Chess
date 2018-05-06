//
//  Board.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Board.h"
#include <iostream>
#include <vector>
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"

void Board::init()
{
    cout << intro_text + "\n";
    board = new Piece**[BOARD_DIMIENSION];
    for (int i = 0; i < BOARD_DIMIENSION; ++i) {
        board[i] = new Piece*[BOARD_DIMIENSION];
    }
    // Null out the pointers contained in the array:
    for (int i = 0; i < BOARD_DIMIENSION; ++i) {
        for (int j = 0; j < BOARD_DIMIENSION; ++j) {
            board[i][j] = NULL;
        }
    }
    // Set Rooks
    initPiece("R", 0);
    initPiece("R", 7);
    // Set Knight (Horse)
    initPiece("H", 1);
    initPiece("H", 6);
    // Set Biships
    initPiece("B", 2);
    initPiece("B", 5);
    // Set Queen
    initPiece("Q", 3);
    // Set King
    initPiece("K", 4);
    initPawns();
}

void Board::initPiece(string name, int x)
{
    //White
    board[0][x] = new Piece;
    board[0][x]->setType(name, 0);
    //Black
    board[7][x] = new Piece;
    board[7][x]->setType(name, 1);
}

void Board::initPawns()
{
    // Set White Pawns
    for (int j = 0; j < BOARD_DIMIENSION; ++j) {
        board[1][j] = new Pawn;
        board[1][j]->setType("P", 0);
    }
    
    // Set Black Pawns
    for (int j = 0; j < BOARD_DIMIENSION; ++j) {
        board[6][j] = new Pawn;
        board[6][j]->setType("P", 1);
    }
}

void Board::printBoard()
{
    cout << "\n";
    for(int i = 0; i < BOARD_DIMIENSION; i ++) {
        cout << i+1 << "  ";
        for(int j = 0; j < BOARD_DIMIENSION; j ++) {
            if(board[i][j]) {
                board[i][j]->printPiece();
            } else {
                cout << "| |";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    std::vector<std::string> v = {"A", "B", "C", "D", "E", "F", "G", "H"};
    cout << "   ";
    for(int i = 0; i < v.size(); i ++) {
        cout << " " << v[i] << " ";
    }
    cout << "\n";
}

void Board::paintBoard(Graphics& g)
{
    int vertical_offset = 80;
    int horizontal_offset = 50;
    int square_size = 50;
    int centered_offset = 2;
    for(int i = 0; i < BOARD_DIMIENSION; i ++) {
        int i_pos = i*square_size + vertical_offset + centered_offset;
        for(int j = 0; j < BOARD_DIMIENSION; j ++) {
            int j_pos = j*square_size + horizontal_offset + centered_offset;
            if(board[i][j]) {
                PNGImageFormat img_file;
                Image img;
                string root_folder = "/Users/maxfreundlich/Workspace/ChessGUI/source/Images/";
                if (board[i][j]->player == 0) {
                    g.setColour (Colours::white);
                } else {
                    g.setColour (Colours::black);
                }
                string board_type = board[i][j]->type;
                if(board_type == "P"){
                    img = img_file.loadFrom(BinaryData::pawn_png, 881);
                } else if(board_type == "R") {
                    img = img_file.loadFrom(BinaryData::rook_png, 508);
                } else if(board_type == "H") {
                    img = img_file.loadFrom(BinaryData::knight_png, 1331);
                } else if(board_type == "B") {
                    img = img_file.loadFrom(BinaryData::bishop_png, 1389);
                } else if(board_type == "Q") {
                    img = img_file.loadFrom(BinaryData::queen_png, 1518);
                } else if(board_type == "K") {
                    img = img_file.loadFrom(BinaryData::king_png, 1189);
                }
                g.drawImage(img, j_pos, i_pos, 40, 40, 0, 0, 40, 40, true);
            }
        }
    }
}

// Returns true if piece was moved
bool Board::movePiece(int from[], int to[], int player)
{
    if(!validateMove(from, to, player)) {
        return false;
    }
    Piece* currentPiece = board[from[0]][from[1]];
    // Pawn Case:
    if(currentPiece->type == "P") {
        Pawn* pawn = (Pawn*)currentPiece;
        bool canMove = pawn->moveTo(from, to);
        if (canMove) {
            movePieceOnBoard(from, to);
        } else {
            cout << "You can't go there\n";
            return false;
        }
        if(pawn->isFirstMove) {
            pawn->setFirstMove();
        }
        // Rook Case:
    } else if(currentPiece->type == "R") {
        Rook* rook = (Rook*)currentPiece;
        bool canMove = rook->moveTo(from, to);
        if (canMove) {
            if(rook->pathIsClear(from, to, board)){
                movePieceOnBoard(from, to);
            } else {
                cout << "Path Blocked\n";
                return false;
            }
        } else {
            cout << "You can't go there\n";
            return false;
        }
        // Knight Case:
    } else if(currentPiece->type == "H") {
        Knight* knight = (Knight*)currentPiece;
        bool canMove = knight->moveTo(from, to);
        if (canMove) {
            if(knight->pathIsClear(from, to, board)){
                movePieceOnBoard(from, to);
            } else {
                cout << "Path Blocked\n";
                return false;
            }
        } else {
            cout << "You can't go there\n";
            return false;
        }
        // Bishop Case:
    } else if(currentPiece->type == "B") {
        Bishop* bishop = (Bishop*)currentPiece;
        bool canMove = bishop->moveTo(from, to);
        if (canMove) {
            if(bishop->pathIsClear(from, to, board)){
                movePieceOnBoard(from, to);
            } else {
                cout << "Path Blocked\n";
                return false;
            }
        } else {
            cout << "You can't go there\n";
            return false;
        }
        // Queen Case:
    } else if(currentPiece->type == "Q") {
        Queen* queen = (Queen*)currentPiece;
        bool canMove = queen->moveTo(from, to);
        if (canMove) {
            if(queen->pathIsClear(from, to, board)){
                movePieceOnBoard(from, to);
            } else {
                cout << "Path Blocked\n";
                return false;
            }
        } else {
            cout << "You can't go there\n";
            return false;
        }
        // King Case:
    } else if(currentPiece->type == "K") {
        King* king = (King*)currentPiece;
        bool canMove = king->moveTo(from, to);
        if (canMove) {
            movePieceOnBoard(from, to);
        } else {
            cout << "You can't go there\n";
            return false;
        }
    }
    return true;
}

void Board::movePieceOnBoard(int from[], int to[])
{
    Piece* currentPiece = board[from[0]][from[1]];
    Piece* toPiece = board[to[0]][to[1]];
    cout << " Moving Piece: " << currentPiece->type << "\n";
    toPiece = new Piece();
    toPiece->type = currentPiece->type;
    toPiece->player = currentPiece->player;
    toPiece->isFirstMove = false;
    board[to[0]][to[1]] = toPiece;
    board[from[0]][from[1]] = NULL;
    delete currentPiece;
}

bool Board::validateMove(int from[], int to[], int player)
{
    // Sanity check
    if(from[0] < 0 || from[0] >= BOARD_DIMIENSION) {
        cout << "Invalid board position" <<"\n";
        return false;
    } else if(to[0] < 0 || to[0] >= BOARD_DIMIENSION) {
        cout << "Invalid board position" <<"\n";
        return false;
    }
    
    // Check if piece exists
    Piece* currentPiece = board[from[0]][from[1]];
    if(!currentPiece) {
        cout << "There is nothing there..." <<"\n";
        return false;
    }
    
    if(currentPiece->player != player) {
        cout << "You can only move your own pieces" <<"\n";
        return false;
    }
    return true;
}

// Define the destructor.
Board::~Board()
{
    for(int i = 0; i < BOARD_DIMIENSION; ++i){
        delete[] board[i];
    }
    delete[] board;
}
