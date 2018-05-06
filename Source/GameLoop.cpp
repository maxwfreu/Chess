//
//  GameLoop.cpp
//  Chess
//
//  Created by Max Freundlich on 5/5/18.
//  Copyright © 2018 Max Freundlich. All rights reserved.
//

#include "GameLoop.h"
#include <iostream>
#include <regex>
#include <cstdlib>

void GameLoop::start()
{
    board.init();
    bool shouldEndTurn = true;
    while(gameRunning) {
        cout << "Score\n";
        cout << "Player 1: " << player_one_score << "\n";
        cout << "Player 2: " << player_two_score << "\n";
        board.printBoard();
        string userInput;
        cout << "\nPlayer " << current_player << "'s turn: ";
        getline(cin, userInput);
        shouldEndTurn = handleInput(userInput);
        if(shouldEndTurn) {
            endTurn();
        }
    }
}

void GameLoop::startGUI()
{
    board.init();
//    bool shouldEndTurn = true;
}

bool GameLoop::handleInputForGUI(string input)
{
    if(input == "end") {
        endGame();
        return false;
    } else if (std::regex_match (input, std::regex("([a-m][1-9] [a-m][1-9])") )){
        return true;
    }
    return false;
}

bool GameLoop::attemptMove(string input)
{
    // Map command to numbers
    // Grap Char -> Convert to int -> offset by 1 (board 0 indexed)
    int ia = (int)input[0] - 97;
    int ib = (int)input[3] - 97;
    int from[] = {int(input[1] - '0') - 1, ia, };
    int to[] = { int(input[4] - '0') - 1, ib,};
    Piece* toPiece = board.board[to[0]][to[1]];
    bool awardPoint = false;
    if(toPiece) {
        awardPoint = true;
        if(toPiece->player == current_player) {
            cout << "Can't go there";
            return false;
        }
    }
    bool piece_moved = board.movePiece(from, to, current_player);
    if(piece_moved && awardPoint){
        if(current_player == PLAYER_ONE) {
            player_one_score++;
        } else {
            player_two_score++;
        }
    }
    return piece_moved;
}

bool GameLoop::handleInput(string input)
{
    cout << "\n";
    if(input == "end") {
        endGame();
    } else if (std::regex_match (input, std::regex("([a-m][1-9] [a-m][1-9])") )){
        // Map command to numbers
        // Grap Char -> Convert to int -> offset by 1 (board 0 indexed)
        int ia = (int)input[0] - 97;
        int ib = (int)input[3] - 97;
        int from[] = {int(input[1] - '0') - 1, ia, };
        int to[] = { int(input[4] - '0') - 1, ib,};
        Piece* toPiece = board.board[to[0]][to[1]];
        bool awardPoint = false;
        if(toPiece) {
            awardPoint = true;
            if(toPiece->player == current_player) {
                cout << "Can't go there";
                return false;
            }
        }
        bool piece_moved = board.movePiece(from, to, current_player);
        if(piece_moved && awardPoint){
            if(current_player == PLAYER_ONE) {
                player_one_score++;
            } else {
                player_two_score++;
            }
        }
        return piece_moved;
    } else {
        cout << "Unrecognized command";
    }
    cout << "\n";
    return false;
}

void GameLoop::endTurn()
{
    if(current_player == PLAYER_ONE) {
        current_player = PLAYER_TWO;
    } else {
        current_player = PLAYER_ONE;
    }
}

void GameLoop::endGame()
{
    cout << "Bye!\n";
    gameRunning = false;
}

GameLoop::~GameLoop(){};
