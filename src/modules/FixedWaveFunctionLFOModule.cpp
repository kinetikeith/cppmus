#include "FixedWaveFunctionLFOModule.hpp"

FixedWaveFunctionLFOModule::FixedWaveFunctionLFOModule(control_t* freq,
		control_t* phase, WaveFunction* w) : FixedOscModule(freq, phase),
		outputBuffer(new control_t(0.5)), waveFunc(w)
{

}

FixedWaveFunctionLFOModule::~FixedWaveFunctionLFOModule()
{

	delete outputBuffer;

}

void FixedWaveFunctionLFOModule::prepareForPlay()
{

}

void FixedWaveFunctionLFOModule::processFrame()
{

	control_t maxHarmonic = getParent()->getNyquist() / getFreqMod();
	*getOutputBuffer() = (waveFunc)(getAbsolutePhase(), maxHarmonic);

}
	
void FixedWaveFunctionLFOModule::finishAfterPlay()
{

}

control_t* FixedWaveFunctionLFOModule::getOutputBuffer()
{

	return outputBuffer;

}
