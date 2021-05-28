/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class YellowSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    YellowSynthAudioProcessorEditor (YellowSynthAudioProcessor&);
    ~YellowSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    Slider attackSlider;
    Slider decaykSlider;
    Slider sustainSlider;
    Slider releaseSlider;

    Label attackLabel;
    Label decayLabel;
    Label sustainLabel;
    Label releaseLabel;





    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> decayAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sustainAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;




    YellowSynthAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YellowSynthAudioProcessorEditor)
};
