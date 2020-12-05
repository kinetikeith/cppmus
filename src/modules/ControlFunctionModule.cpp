#include "ControlFunctionModule.hpp"

ControlFunctionModule::ControlFunctionModule(control_t* input, ControlFunction* cFunc) :
	SingleControlInput(input), SingleControlOutput(0.0), controlFunc(cFunc)
{

}

void ControlFunctionModule::processFrame()
{

	*getControlOutputBuffer() = (controlFunc)(*getControlInputBuffer());

}

BiControlFunctionModule::BiControlFunctionModule(control_t* inputA, control_t* inputB, BiControlFunction* cFunc) :
	SingleControlOutput(0.0), inputABuffer(inputA), inputBBuffer(inputB), controlFunc(cFunc)
{

}

void BiControlFunctionModule::processFrame()
{

	*getControlOutputBuffer() = (controlFunc)(*inputABuffer, *inputBBuffer);

}

MultiControlFunctionModule::MultiControlFunctionModule(control_t** inputs, size_t num, MultiControlFunction* cFunc) : 
	inputsBuffer(inputs), numInputs(num), SingleControlOutput(0.0), controlFunc(cFunc)
{

}

void MultiControlFunctionModule::processFrame()
{

	*getControlOutputBuffer() = (controlFunc)(inputsBuffer, numInputs);

}

