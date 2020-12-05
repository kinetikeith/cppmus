#ifndef MIXERMODULE_HPP
#define MIXERMODULE_HPP

#include "types.hpp"
#include "Module.hpp"
#include "SingleAudioOutput.hpp"

class MixerModule : public Module, public SingleAudioOutput
{
public:

		MixerModule(audio_t**, control_t**, size_t);

	void	processFrame();

private:

	audio_t**	inputsBuffer;
	control_t**	volumesBuffer;
	size_t		numChannels;

};

#endif /* MIXERMODULE_HPP */
