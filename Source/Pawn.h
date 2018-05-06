//
//  Pawn.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef Pawn_h
#define Pawn_h

#include <stdio.h>
#include "Piece.h"

class Pawn : public Piece
{
public:
    bool moveTo(int from[], int to[]);
    void setFirstMove();
    ~Pawn();
};

#endif /* Pawn_h */
