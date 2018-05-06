/*
  ==============================================================================

    MainComponent.h
    Created: 5 May 2018 9:14:07pm
    Author:  Max Freundlich

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "GameLoop.h"

//==============================================================================
/*
*/
class MainComponent    : public Component
{
public:
    MainComponent()
    {
        gameLoop.startGUI();
        addAndMakeVisible (titleLabel);
        titleLabel.setFont (Font (16.0f, Font::bold));
        titleLabel.setText ("Let's play chess!", dontSendNotification);
        titleLabel.setColour (Label::textColourId, Colours::black);
        titleLabel.setJustificationType (Justification::centred);
        
        addAndMakeVisible (inputText);
        inputText.setEditable (true);
        inputText.setColour (Label::backgroundColourId, Colours::black);
        inputText.onTextChange = [this] {
            string text = inputText.getText().toStdString();
            bool valid_response = gameLoop.handleInputForGUI(text);
            if(valid_response) {
                bool should_end_turn = gameLoop.attemptMove(text);
                if(should_end_turn) {
                    gameLoop.endTurn();
                    repaint();
                }
            }
            inputText.setText("", dontSendNotification);
        };
        
        setSize (700, 550);
    }
    ~MainComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    String currentSizeAsString;
    GameLoop gameLoop;
    Label titleLabel;
    Label inputLabel;
    Label inputText;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
