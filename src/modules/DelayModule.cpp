#include "DelayModule.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

DelayModule::DelayModule(audio_t* input, control_t* delayTime, control_t maxDelay) : 
	SingleAudioInput(input), SingleAudioOutput(0.0f), maxDelayTime(maxDelay),
	delayTimeBuffer(delayTime)
{

}

void DelayModule::prepareForPlay()
{

	delayBufferLength = (getParent()->getSampleRate() * maxDelayTime) + 1.0;
	delayBuffer = new audio_t[delayBufferLength];
	bufferWritePos = 0;

}

void DelayModule::processFrame()
{

	delayBuffer[bufferWritePos] = *getAudioInputBuffer();

	control_t bufferReadOffset = std::clamp((*delayTimeBuffer), 0.0, maxDelayTime) * getParent()->getSampleRate();
	size_t bufferReadPos = (bufferWritePos + (delayBufferLength - size_t(bufferReadOffset))) % delayBufferLength;
	audio_t t = std::fmod(bufferReadOffset, 1.0);

	*getAudioOutputBuffer() = std::lerp(delayBuffer[bufferReadPos], delayBuffer[(bufferReadPos + 1) % delayBufferLength], t);

	bufferWritePos = (bufferWritePos + 1) % delayBufferLength;

}

void DelayModule::finishAfterPlay()
{

	delete[] delayBuffer;

}
