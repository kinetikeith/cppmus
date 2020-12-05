#ifndef AUDIOINPUT_HPP
#define AUDIOINPUT_HPP

#include <memory>

#include "types.hpp"
#include "BufferInput.hpp"

using AudioInput = BufferInput<audio_t>;
using AudioInputPtr = std::shared_ptr<AudioInput>;

#endif /* AUDIOINPUT_HPP */