#ifndef PLAY_HPP
#define PLAY_HPP

#include "portaudio.h"

#include "PlaybackContext.hpp"
#include "FrameInfo.hpp"
#include "BufferInfo.hpp"

struct PlayInfo
{

	PlaybackContextPtr	playbackContext;
	FrameInfo			frameInfo;
	BufferInfo			bufferInfo;

};

int audioCallback(const void*, void*, unsigned long, PaStreamCallbackTimeInfo, PaStreamCallbackFlags, void*);

PaError play(PlaybackContextPtr, size_t);

#endif /* PLAY_HPP */
