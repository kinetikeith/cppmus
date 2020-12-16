#include "AmplifierModule.hpp"

AmplifierModule::AmplifierModule(audio_t* input, control_t* ampAmount) :
	audioInput(), AudioOutput(0.0), ampAmountBuffer(ampAmount)
{

}

void AmplifierModule::prepareModule(const FrameInfo& fInfo, const BufferInfo& bInfo)
{

	Module::prepareModule(fInfo, bInfo);

}

void AmplifierModule::processModule()
{
	
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
