#include "AmplifierModule.hpp"

AmplifierModule::AmplifierModule(AudioInput aInput = 0.0, AudioInput cInput = 0.0) :
	audioInput(aInput), controlInput(cInput), AudioOutput(0.0), ampAmountBuffer(ampAmount)
{

}

void AmplifierModule::prepareModule(const FrameInfo& fInfo, const BufferInfo& bInfo)
{

	Module::prepareModule(fInfo, bInfo);

}

void AmplifierModule::processModule(const FrameInfo& fInfo, const BufferInfo& bInfo)
{

	size_t cLim = bInfo.getChannelIndexLimit();
	size_t sLim = bInfo.getSampleIndexLimit();
	size_t vLim = bInfo.getVoiceIndexLimit();

	size_t 
	for(size_t cIndex = 0; cIndex < 
	
}

void AmplifierModule::finishModule()
{

	Module::finishModule();

}

AudioInput AmplifierModule::getAudioInput()
{

	return audioInput;

}

AudioInput AmplifierModule::getControlInput()
{

	return controlInput;

}

InputList AmplifierModule::getInputs()
{

	return {audioInput, controlInput};

}

OutputList AmplifierModule::getOutputs()
{

	return {audioOutput};

}

void AmplifierModule::setAudioInput(AudioInput aInput)
{

	audioInput = aInput;

}

void AmplifierModule::setControlInput(AudioInput cInput)
{

	controlInput = cInput;

}
