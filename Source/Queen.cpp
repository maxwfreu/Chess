//
//  Queen.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Queen.h"
#include <iostream>
#include <cmath>

bool Queen::moveTo(int from[], int to[])
{
    return
        validDiagonalMove(from, to) ||
        validStepMove(from, to, 1) ||
        validStraightMove(from, to);
}

bool Queen::pathIsClear(int from[], int to[], Piece*** board)
{
    if(from[0] - to[0] == 1 && from[1] - to[1] == 1) {
        return true;
    }
    if(from[0] == to[0] || from[1] == to[1]) {
        return clearStraight(from, to, board);
    } else {
        return clearDiagonal(from, to, board);
    }
}

bool Queen::clearDiagonal(int from[], int to[], Piece*** board)
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

bool Queen::clearStraight(int from[], int to[], Piece*** board)
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

Queen::~Queen(){};
