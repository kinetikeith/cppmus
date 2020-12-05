#include "AmplifierModule.hpp"

AmplifierModule::AmplifierModule(audio_t* input, control_t* ampAmount) :
	SingleAudioInput(input), SingleAudioOutput(0.0), ampAmountBuffer(ampAmount)
{

}

void AmplifierModule::prepareForPlay()
{

}

void AmplifierModule::processFrame()
{
	
	*getAudioOutputBuffer() = *getAudioInputBuffer() * (*ampAmountBuffer);

}

void AmplifierModule::finishAfterPlay()
{

}
