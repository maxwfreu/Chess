//
//  Knight.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef Knight_h
#define Knight_h

#include <stdio.h>
#include "Piece.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    bool moveTo(int from[], int to[]);
    bool pathIsClear(int from[], int to[], Piece*** board);
    ~Knight();
};

#endif /* Knight_h */
