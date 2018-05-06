/*
  ==============================================================================

    MainComponent.cpp
    Created: 5 May 2018 9:14:07pm
    Author:  Max Freundlich

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::lightblue);
    g.setColour (Colours::darkblue);
    g.setFont (Font ("Times New Roman", 20.0f, Font::bold));
    string turn_string = "It's Your Turn!";
    if(gameLoop.current_player != 0) {
        turn_string = "Waiting for opponent...";
    }
    g.drawText (turn_string, 480, 40, 190, 40, Justification::left, true);
    g.setFont (Font ("Times New Roman", 20.0f, Font::bold));

    g.drawText ("Score", 480, 80, 80, 40, Justification::left, true);
    
    g.drawText ("Player 1: " + to_string(gameLoop.player_one_score), 480, 120, 120, 40, Justification::left, true);
    
    g.drawText ("Player 2: " + to_string(gameLoop.player_two_score), 480, 160, 120, 40, Justification::left, true);
    
    g.setFont (Font ("Times New Roman", 18.0f, Font::italic));
    g.drawText ("How To Play", 480, 220, 120, 40, Justification::left, true);
    
    g.setFont (Font ("Times New Roman", 16.0f, Font::plain));
    g.drawText ("- end => Stop the game", 480, 240, 160, 40, Justification::left, true);
    
    g.drawText ("- a1 a3 => Move piece located", 480, 260, 200, 40, Justification::left, true);
    g.drawText ("at a1 to a3", 480, 280, 160, 40, Justification::left, true);
    
    // Draw numbers
    g.setFont (Font ("Times New Roman", 20.0f, Font::bold));
    int number_start  = 85;
    int letter_start = 70;
    string letters[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    for(int i = 1; i < 9; i++) {
        g.drawText (to_string(i), 20, number_start, 20, 40, Justification::left, true);
        g.drawText (letters[i-1], letter_start, getHeight() - 65, 20, 40, Justification::left, true);
        number_start += 50;
        letter_start += 50;
    }
    Rectangle<float> house (50, 80, 400, 400);
    g.fillCheckerBoard (house, 50, 50, Colours::sandybrown, Colours::saddlebrown);
    gameLoop.board.paintBoard(g);
//
}

void MainComponent::resized()
{
    currentSizeAsString = String (getWidth()) + " x " + String (getHeight());
    titleLabel   .setBounds (10,  10, getWidth(),  30);
    inputText    .setBounds (50, 50, getWidth() - 300, 20);
}

MainComponent::~MainComponent() {}

