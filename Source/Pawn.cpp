//
//  Pawn.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "Pawn.h"
#include <iostream>
#include <cmath>

bool Pawn::moveTo(int from[], int to[])
{
    if(!isGoingForward(from, to)) {
        return false;
    }
    int max_dist = 1;
    if(isFirstMove){
        max_dist = 2;
    }
    return validStepMove(from, to, max_dist);
}

void Pawn::setFirstMove()
{
    isFirstMove = true;
}

Pawn::~Pawn(){};
