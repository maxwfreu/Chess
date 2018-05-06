//
//  Knight.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Knight.h"
#include <iostream>
#include <cmath>

bool Knight::moveTo(int from[], int to[])
{
    return validLMove(from, to);
}

bool Knight::pathIsClear(int from[], int to[], Piece*** board)
{
    if(from[0] > to[0]) {
        // going left
        if(board[from[0]-1][from[1]] || board[from[0]-2][from[1]]){
            return false;
        }
    } else {
        // going right
        if(board[from[0]+1][from[1]] || board[from[0]+2][from[1]]) {
            return false;
        }
    }
    return true;
}

Knight::~Knight(){};
