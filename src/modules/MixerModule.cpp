#include "MixerModule.hpp"

MixerModule::MixerModule(audio_t** inputs, control_t** volumes, size_t nChans) :
       	inputsBuffer(inputs), SingleAudioOutput(0.0), volumesBuffer(volumes), numChannels(nChans)
{

}

void MixerModule::processFrame()
{

	audio_t result = 0.0;

	for(size_t i = 0; i < numChannels; i++)
	{

		result += (*inputsBuffer[i]) * (*volumesBuffer[i]);

	}

	*getAudioOutputBuffer() = result;

}
