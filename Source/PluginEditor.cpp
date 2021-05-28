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

    decaykSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    decaykSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    decayAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "ATTACK", decaykSlider);
    addAndMakeVisible(&decaykSlider);

    sustainSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    sustainAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "ATTACK", sustainSlider);
    addAndMakeVisible(&sustainSlider);

    releaseSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    releaseAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAPVTS(), "ATTACK", releaseSlider);
    addAndMakeVisible(&releaseSlider);



    setSize (400, 300);
}

YellowSynthAudioProcessorEditor::~YellowSynthAudioProcessorEditor()
{
}

//==============================================================================
void YellowSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void YellowSynthAudioProcessorEditor::resized()
{
    attackSlider.setBounds(0, 0, 100, 100);
    decaykSlider.setBounds(100, 0, 100, 100);
    sustainSlider.setBounds(200, 0, 100, 100);
    releaseSlider.setBounds(300, 0, 100, 100);

}
