//
//  Rook.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef Rook_h
#define Rook_h

#include <stdio.h>
#include "Piece.h"

class Rook : public Piece
{
public:
    bool moveTo(int from[], int to[]);
    bool pathIsClear(int from[], int to[], Piece*** board);
    ~Rook();
};

#endif /* Rook_h */
