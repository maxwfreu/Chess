//
//  GameLoop.hpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#ifndef GameLoop_h
#define GameLoop_h

#include "Board.h"
#include <stdio.h>
#include <string>

using namespace std;

class GameLoop
{
public:
    Board board;
    
    int PLAYER_ONE{0};
    int PLAYER_TWO{1};
    void start();
    void startGUI();
    void endGame();
    void endTurn();
    bool attemptMove(string input);
    bool handleInputForGUI(string input);
    bool handleInput(string input);
    bool gameRunning{true};
    int current_player{PLAYER_ONE};
    int player_one_score{0};
    int player_two_score{0};
    ~GameLoop();
};
#endif /* GameLoop_h */
