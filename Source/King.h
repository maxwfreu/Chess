//
//  King.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef King_h
#define King_h

#include <stdio.h>
#include "Piece.h"

class King : public Piece
{
public:
    bool moveTo(int from[], int to[]);
    ~King();
};

#endif /* King_h */
