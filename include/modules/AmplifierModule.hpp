#ifndef AMPLIFIERMODULE_HPP
#define AMPLIFIERMODULE_HPP

#include "types.hpp"
#include "Module.hpp"
#include "SingleAudioInput.hpp"
#include "SingleAudioOutput.hpp"

class AmplifierModule : public Module, public SingleAudioInput, public SingleAudioOutput
{
public:

		AmplifierModule(audio_t*, control_t*);

	void	prepareForPlay();
	void	processFrame();
	void	finishAfterPlay();

private:

	control_t*	ampAmountBuffer;

};

#endif /* AMPLIFIERMODULE_HPP */
