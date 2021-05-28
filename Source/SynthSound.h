/*
  ==============================================================================

    SynthSound.h
    Created: 28 May 2021 2:43:47am
    Author:  damsc

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote(int midiNoteNumber) 
	{
		return true;
	}
	bool appliesToChannel(int midiChannel) 
	{
		return true;
	}
};