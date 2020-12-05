#include "play.hpp"

#include <iostream>

int audioCallback(const void *inputBuffer, void *outputBuffer, unsigned long frameCount,
		const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{

	Song* song = static_cast<Song*>(userData);
	float *out = static_cast<float*>(outputBuffer);

	unsigned int numChannels = song->getNumChannels();
	audio_t** frameBuffers = song->getFrameBuffers();

	for(unsigned long i = 0; i < frameCount; i++)
	{
		
		song->processFrame();

		for(unsigned int j = 0; j < 2; j++)
		{

			out[(i * numChannels) + j] = float(*(frameBuffers[j]));

		}

		song->nextFrame();

	}

	if(song->isFinished())
	{

		return paComplete;

	}
	return paContinue;

}

PaError play(Song* song, unsigned int blockSize = 512)
{

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
	outParams.channelCount = song->getNumChannels();
	outParams.sampleFormat = paFloat32;
	outParams.suggestedLatency = deviceInfo->defaultHighOutputLatency;
	outParams.hostApiSpecificStreamInfo = nullptr;

	song->setSampleRate(deviceInfo->defaultSampleRate);

	PaStream *stream;
	err = Pa_OpenStream(&stream, nullptr, &outParams, song->getSampleRate(),
			blockSize, paNoFlag, audioCallback, song);
	if(err != paNoError)
	{

		return err;

	}

	song->prepareForPlay();

	err = Pa_StartStream(stream);
	if(err != paNoError)
	{

		return err;

	}

	while(Pa_IsStreamActive(stream))
	{
		
		//std::cout << song->getCurrentFrame() << std::endl;

	}

	song->finishAfterPlay();

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
