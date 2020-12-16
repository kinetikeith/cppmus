#ifndef AMPLIFIERMODULE_HPP
#define AMPLIFIERMODULE_HPP

#include "Module.hpp"
#include "FrameInfo.hpp"
#include "BufferInfo.hpp"
#include "AudioInput.hpp"
#include "AudioOutput.hpp"

class AmplifierModule : public Module
{
public:

		AmplifierModule();

	void	prepareModule(const FrameInfo&, const BufferInfo&);
	void	processModule(const FrameInfo&, const BufferInfo&);
	void	finishModule();

	AudioInput	getAudioInput();
	AudioInput	getControlInput();
	AudioOutput	getAudioOutput();

	void		setAudioInput(AudioInput);
	void		setControlInput(AudioInput);

private:

	AudioInput	audioInput;
	AudioInput	controlInput;
	AudioOutput	audioOutput;

};

#endif /* AMPLIFIERMODULE_HPP */
