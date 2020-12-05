#include "PlaybackContext.hpp"

PlaybackContext::PlaybackContext(BufferInfo bufferInfo) : Context(bufferInfo), concluded(false)
{

}

void PlaybackContext::setOutput(AudioOutputPtr out)
{

	output = out;

}

AudioOutputPtr PlaybackContext::getOutput()
{

	return output;

}

void PlaybackContext::conclude()
{

	concluded = true;

}

bool PlaybackContext::isConcluded()
{

	return concluded;

}
