//
//  Board.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include <string>
#include "Piece.h"
#include "Pawn.h"
#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class Board
{
public:
    string intro_text{"Welcome to chess! Valid commands:\n 'end' => stop the game \n 'a0 a3' => Move piece at a0 to a3\n"};
    int BOARD_DIMIENSION{8};
    Piece ***board;
    void init();
    void printBoard();
    void paintBoard(Graphics& g);
    bool movePiece(int from[], int to[], int player);
    ~Board();
    
private:
    void initPiece(string name, int x);
    void initPawns();
    bool validateMove(int from[], int to[], int player);
    void movePieceOnBoard(int from[], int to[]);
};


#endif /* Board_h */
