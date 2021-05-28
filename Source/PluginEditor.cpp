/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
YellowSynthAudioProcessorEditor::YellowSynthAudioProcessorEditor(YellowSynthAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{

    attackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20); 
    attackAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "ATTACK", attackSlider);
    addAndMakeVisible(&attackSlider);
    attackLabel.setText("Attack", dontSendNotification);
    attackLabel.setJustificationType(Justification::centredBottom);
    attackLabel.attachToComponent(&attackSlider, false);


    decaykSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    decaykSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    decayAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "DECAY", decaykSlider);
    addAndMakeVisible(&decaykSlider);
    decayLabel.setText("Decay", dontSendNotification);
    decayLabel.setJustificationType(Justification::centredBottom);
    decayLabel.attachToComponent(&decaykSlider, false);

    sustainSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    sustainAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "SUSTAIN", sustainSlider);
    addAndMakeVisible(&sustainSlider);
    sustainLabel.setText("Sustain", dontSendNotification);
    sustainLabel.setJustificationType(Justification::centredBottom);
    sustainLabel.attachToComponent(&sustainSlider, false);

    releaseSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    releaseAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "RELEASE", releaseSlider);
    addAndMakeVisible(&releaseSlider);
    releaseLabel.setText("Release", dontSendNotification);
    releaseLabel.setJustificationType(Justification::centredBottom);
    releaseLabel.attachToComponent(&releaseSlider, false);


    oscSelAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getAPVTS(), "OSC", oscSelector);



    setSize (400, 300);
}

YellowSynthAudioProcessorEditor::~YellowSynthAudioProcessorEditor()
{
}

//==============================================================================
void YellowSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    //// (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void YellowSynthAudioProcessorEditor::resized()
{
    attackSlider.setBounds(0, 100, 100, 100);
    decaykSlider.setBounds(100, 100, 100, 100);
    sustainSlider.setBounds(200, 100, 100, 100);
    releaseSlider.setBounds(300, 100, 100, 100);

}
