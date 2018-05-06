//
//  Queen.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef Queen_h
#define Queen_h

#include <stdio.h>
#include "Piece.h"

class Queen : public Piece
{
public:
    bool moveTo(int from[], int to[]);
    bool pathIsClear(int from[], int to[], Piece*** board);
    ~Queen();
private:
    bool clearDiagonal(int from[], int to[], Piece*** board);
    bool clearStraight(int from[], int to[], Piece*** board);
};

#endif /* Queen_h */
