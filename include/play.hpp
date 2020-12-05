#ifndef PLAY_HPP
#define PLAY_HPP

#include "Song.hpp"

#include "portaudio.h"

int audioCallback(const void*, void*, unsigned long, PaStreamCallbackTimeInfo, PaStreamCallbackFlags, void*);
PaError play(Song*, unsigned int);

#endif /* PLAY_HPP */
