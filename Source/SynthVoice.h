/*
  ==============================================================================

	SynthVoice.h
	Created: 28 May 2021 2:43:38am
	Author:  damsc

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"


class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound* sound) override;

	void startNote(int midinoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override;

	void stopNote(float velocity, bool allowTailOff) override;

	void controllerMoved(int controllerNumber, int newControllerValue) override;

	void pitchWheelMoved(int newPitchWheelValue) override;

	void prepareToPlay(double sampleRate, int samplePerBlock, int outputChannels);
		
	void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;







private:

	ADSR adsr;
	ADSR::Parameters adsrParams;
	AudioBuffer<float> synthBuffer;

	//dsp::Oscillator<float> osc{ [](float x) {return std::sin(x); } };         //sin wave
	dsp::Oscillator<float> osc{ [](float x) {return x < 0.0f ? -1.0f : 1.0f; } };
	dsp::Gain<float> gain;



	bool isPrepared { false };

	//  return std::sin(x);               //sin wave
	//  return x / MathConstants<float>::pi;        //saw(??) wave
	//  return x < 0.0f ? -1.0f : 1.0f;     //sqr wave




};