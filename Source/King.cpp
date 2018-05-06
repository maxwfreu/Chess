//
//  King.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "King.h"
#include <iostream>
#include <cmath>

bool King::moveTo(int from[], int to[])
{
    return validStepMove(from, to, 1);
}

King::~King(){};
