#include "play.hpp"

#include <iostream>

int audioCallback(const void *inputBuffer, void *outputBuffer, unsigned long frameCount,
		const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{

	PlayInfo* info = static_cast<PlayInfo*>(userData);
	float *out = static_cast<float*>(outputBuffer);

	size_t cOffset = info->bufferInfo.getChannelIndexOffset();
	size_t sOffset = info->bufferInfo.getSampleIndexOffset();
	size_t vOffset = info->bufferInfo.getVoiceIndexOffset();

	size_t cLimit = info->bufferInfo.getChannelIndexLimit();
	size_t sLimit = info->bufferInfo.getSampleIndexLimit();
	size_t vLimit = info->bufferInfo.getVoiceIndexLimit();

	info->playbackContext->processContext(info->frameInfo);

	for(size_t v = 0; v < vLimit; v += vOffset)
	{

		for(size_t s = 0; s < sLimit; s += sOffset)
		{

			for(size_t c = 0; c < cLimit; c += cOffset)
			{

				out[c+s] += info->output->getValueFast(c+s+v);

			}

		}

	}

	info->frameInfo.index += info->bufferInfo.numSamples;
	info->frameInfo.time = info->frameInfo.index / info->frameInfo.sampleRate;

	if(info->playbackContext->isConcluded())
	{

		return paComplete;

	}
	return paContinue;

}

PaError play(PlaybackContextPtr playbackContext)
{

	PlayInfo playInfo;
	playInfo.bufferInfo = playbackContext->getGlobalBufferInfo();
	playInfo.output = playbackContext->getOutput();

	PaError err = Pa_Initialize();
	if(err != paNoError)
	{

		return err;

	}
	
	PaStreamParameters outParams;
	outParams.device = Pa_GetDefaultOutputDevice();
	if(outParams.device == paNoDevice)
	{

		return paInvalidDevice;

	}

	const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo(outParams.device);
	outParams.channelCount = playInfo.bufferInfo.numChannels;
	outParams.sampleFormat = paFloat32;
	outParams.suggestedLatency = deviceInfo->defaultHighOutputLatency;
	outParams.hostApiSpecificStreamInfo = nullptr;

	playInfo.frameInfo.index = 0;
	playInfo.frameInfo.time = 0.0;
	playInfo.frameInfo.sampleRate = deviceInfo->defaultSampleRate;

	PaStream *stream;
	err = Pa_OpenStream(&stream, nullptr, &outParams, playInfo.frameInfo.sampleRate,
			playInfo.bufferInfo.numSamples, paNoFlag, audioCallback, &playInfo);
	if(err != paNoError)
	{

		return err;

	}

	playbackContext->prepareContext(playInfo.frameInfo);

	err = Pa_StartStream(stream);
	if(err != paNoError)
	{

		return err;

	}

	while(Pa_IsStreamActive(stream))
	{
		
		//std::cout << song->getCurrentFrame() << std::endl;

	}

	playbackContext->finishContext();

	err = Pa_StopStream(stream);
	if(err != paNoError)
	{

		return err;

	}

	err = Pa_CloseStream(stream);
	if(err != paNoError)
	{

		return err;

	}

	err = Pa_Terminate();
	if(err != paNoError)
	{

		return err;

	}

	return paNoError;

}
