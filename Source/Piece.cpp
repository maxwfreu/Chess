//
//  Piece.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Piece.h"
#include <iostream>
Piece::Piece() {}

void Piece::setType(string piece_type, int player_id)
{
    type = piece_type;
    player = player_id;
}

void Piece::printPiece()
{
    cout << "|" << type << "|";
}

bool Piece::moveTo(int from[], int to[])
{
    return true;
}

bool Piece::validDiagonalMove(int from[], int to[])
{
    // check right
    int x_diff = abs(from[0] - to[0]);
    int y_diff = abs(from[1] - to[1]);
    if(x_diff == y_diff){
        return true;
    }
    return false;
}

bool Piece::validStepMove(int from[], int to[], int max_dist)
{
    int x_diff = abs(from[0] - to[0]);
    int y_diff = abs(from[1] - to[1]);
    if(x_diff > max_dist || y_diff > max_dist){
        return false;
    }
    return true;
}

bool Piece::validStraightMove(int from[], int to[])
{
    int x_diff = abs(from[0] - to[0]);
    int y_diff = abs(from[1] - to[1]);
    if(x_diff == 0 || y_diff == 0){
        return true;
    }
    return false;
}

bool Piece::validLMove(int from[], int to[])
{
    int x_diff = abs(from[0] - to[0]);
    int y_diff = abs(from[1] - to[1]);
    if(x_diff == 2 && y_diff == 1){
        return true;
    }
    if(x_diff == 1 && y_diff == 2) {
        return true;
    }
    return false;
}

bool Piece::isGoingForward(int from[], int to[])
{
    if(player == 0) {
        return from[0] < to[0];
    } else {
        return from[0] > to[0];
    }
}

Piece::~Piece(){};
