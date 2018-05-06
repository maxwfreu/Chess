//
//  Bishop.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef Bishop_h
#define Bishop_h

#include <stdio.h>
#include "Piece.h"

class Bishop : public Piece
{
public:
    bool moveTo(int from[], int to[]);
    bool pathIsClear(int from[], int to[], Piece*** board);
    ~Bishop();
};
#endif /* Bishop_h */
