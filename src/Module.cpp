#include "Module.hpp"

ContextPtr Module::getContext()
{

	return context;

}

void Module::prepareModule(const FrameInfo&, const BufferInfo& bInfo)
{

	for(const InputPtr inp : getInputs())
	{

		inp->prepareInput(bInfo);

	}

	for(const OutputPtr oup : getOutputs())
	{

		oup->prepareOutput(bInfo);

	}
}

void Module::finishModule()
{

	for(const InputPtr inp : getInputs())
	{

		inp->finishInput();

	}

	for(const OutputPtr oup : getOutputs())
	{

		oup->finishOutput();

	}

}

InputList Module::getInputs()
{

	return {};

}

OutputList Module::getOutputs()
{

	return {};

}
