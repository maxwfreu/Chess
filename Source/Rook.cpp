//
//  Rook.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Rook.h"
#include <iostream>
#include <cmath>

bool Rook::moveTo(int from[], int to[])
{
    return validStraightMove(from, to);
}

bool Rook::pathIsClear(int from[], int to[], Piece*** board)
{
    int increment = 1;
    if(from[0] != to[0]) {
        if(from[0] > to[0]) {
            increment = -1;
            for(int j = from[0] + increment; j > to[0]; j += increment) {
                if(board[j][from[1]]){
                    return false;
                }
            }
        } else {
            cout << "Moving down\n";
            for(int j = from[0] + increment; j < to[0]; j += increment) {
                if(board[j][from[1]]){
                    return false;
                }
            }
        }
    }
    if(from[1] != to[1]) {
        if(from[1] > to[1]) {
            increment = -1;
            for(int j = from[1] + increment; j < to[1]; j += increment) {
                if(board[from[0]][j]){
                    return false;
                }
            }
        } else {
            for(int j = from[1] + increment; j < to[1]; j += increment) {
                if(board[from[0]][j]){
                    return false;
                }
            }
        }
    }
    return true;
}

Rook::~Rook(){};
