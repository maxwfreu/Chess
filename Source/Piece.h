//
//  Piece.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//
#pragma once

#ifndef Piece_h
#define Piece_h

#include <stdio.h>
#include <string>
#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class Piece
{
public:
    void printPiece();
    void setType(string piece_type, int player);
    bool moveTo(int from[], int to[]);
    bool isGoingForward(int from[], int to[]);
    bool validDiagonalMove(int from[], int to[]);
    bool validStepMove(int from[], int to[], int max_dist);
    bool validStraightMove(int from[], int to[]);
    bool validLMove(int from[], int to[]);
    string type{"P"};
    int player{0};
    bool isFirstMove{true};

    Piece ();
    ~Piece();
};

#endif /* Piece_h */
