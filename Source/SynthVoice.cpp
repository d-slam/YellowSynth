/*
  ==============================================================================

    SynthVoice.cpp
    Created: 28 May 2021 2:43:38am
    Author:  damsc

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(SynthesiserSound* sound)
{
	return dynamic_cast<SynthesiserSound*> (sound) != nullptr;
}

void SynthVoice::startNote(int midinoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
	osc.setFrequency(MidiMessage::getMidiNoteInHertz(midinoteNumber));
	adsr.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
	adsr.noteOff();

	if (!allowTailOff || adsr.isActive()) 	
		clearCurrentNote();
	
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
}

void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels)
{

	adsr.setSampleRate(sampleRate);
	
	dsp::ProcessSpec spec;
	spec.maximumBlockSize = samplesPerBlock;
	spec.sampleRate = sampleRate;
	spec.numChannels = outputChannels;

	osc.prepare(spec);
	gain.prepare(spec);

	//osc.setFrequency(440.0f);

	gain.setGainLinear(0.01f);


	adsrParams.attack = 0.8f;
	adsrParams.decay = 0.8f;
	adsrParams.sustain = 1.0f;
	adsrParams.release = 1.5f;
	adsr.setParameters(adsrParams);


	isPrepared = true;
	
}

void SynthVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	jassert(isPrepared);

	if (!isVoiceActive())
		return;

	synthBuffer.setSize(outputBuffer.getNumChannels(), numSamples, false, false, true);
	synthBuffer.clear();

	dsp::AudioBlock<float> audioBlock{ synthBuffer };
	osc.process(dsp::ProcessContextReplacing<float>(audioBlock));
	gain.process(dsp::ProcessContextReplacing<float>(audioBlock));
	adsr.applyEnvelopeToBuffer(synthBuffer, 0, synthBuffer.getNumSamples());
	if (startSample != 0)
		jassertfalse;

	for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) 
	{
		outputBuffer.addFrom(channel, startSample, synthBuffer, channel, 0, numSamples);


		if (!adsr.isActive())
			clearCurrentNote();				
	}

}