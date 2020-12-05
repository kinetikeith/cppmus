#ifndef AUDIOOUTPUT_HPP
#define AUDIOOUTPUT_HPP

#include <memory>

#include "types.hpp"
#include "BufferOutput.hpp"

using AudioOutput = BufferOutput<audio_t>;
using AudioOutputPtr = std::shared_ptr<AudioOutput>;

#endif /* AUDIOOUTPUT_HPP */
