#ifndef DELAYMODULE_HPP
#define DELAYMODULE_HPP

#include "Module.hpp"
#include "SingleAudioInput.hpp"
#include "SingleAudioOutput.hpp"

class DelayModule : public Module, public SingleAudioInput, public SingleAudioOutput
{
public:

		DelayModule(audio_t*, control_t*, control_t);
	
	void	prepareForPlay();
	void	processFrame();
	void	finishAfterPlay();

private:

	audio_t*	delayBuffer;
	size_t		delayBufferLength;
	control_t	maxDelayTime;
	control_t*	delayTimeBuffer;
	size_t		bufferWritePos;

};

#endif /* DELAYMODULE_HPP */
