//
//  Bishop.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Bishop.h"
#include <iostream>
#include <cmath>

bool Bishop::moveTo(int from[], int to[])
{
    return validDiagonalMove(from, to);
}

bool Bishop::pathIsClear(int from[], int to[], Piece*** board)
{
    int i_increment = 1;
    int j_increment = 1;
    if(from[0] > to[0]) {
        i_increment = -1;
    }
    if(from[1] > to[1]) {
        j_increment = - 1;
    }
    for(int i = from[0] + i_increment; i < to[0]; i += i_increment) {
        for(int j = from[1] + j_increment; j < to[1]; j += j_increment) {
            if(board[i][j]){
                return false;
            }
        }
    }
    return true;
}

Bishop::~Bishop(){};
