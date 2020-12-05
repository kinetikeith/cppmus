#include "FixedWaveFunctionOscModule.hpp"

#include <iostream>

FixedWaveFunctionOscModule::FixedWaveFunctionOscModule(control_t* freq,
		control_t* phase, WaveFunction* w) : FixedOscModule(freq, phase),
						 SingleAudioOutput(0.0), waveFunc(w)
{

}

void FixedWaveFunctionOscModule::prepareForPlay()
{

}

void FixedWaveFunctionOscModule::processFrame()
{
	
	control_t maxHarmonic = getParent()->getNyquist() / getFreqMod();
	*getAudioOutputBuffer() = (waveFunc)(getAbsolutePhase(), maxHarmonic);

}

void FixedWaveFunctionOscModule::finishAfterPlay()
{

}
