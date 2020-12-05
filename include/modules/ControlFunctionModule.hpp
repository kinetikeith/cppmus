#ifndef CONTROLFUNCTIONMODULE_HPP
#define CONTROLFUNCTIONMODULE_HPP

#include "types.hpp"
#include "Module.hpp"
#include "ControlFunction.hpp"
#include "SingleControlInput.hpp"
#include "SingleControlOutput.hpp"

class ControlFunctionModule : public Module, public SingleControlInput, public SingleControlOutput
{
public:

			ControlFunctionModule(control_t*, ControlFunction*);
	
	void		processFrame();

private:

	ControlFunction*	controlFunc;

};

class BiControlFunctionModule : public Module, public SingleControlOutput
{
public:

		BiControlFunctionModule(control_t*, control_t*, BiControlFunction*);

	void	processFrame();

private:

	control_t*			inputABuffer;
	control_t*			inputBBuffer;
	BiControlFunction*		controlFunc;

};

class MultiControlFunctionModule : public Module, public SingleControlOutput
{
public:

		MultiControlFunctionModule(control_t**, size_t, MultiControlFunction*);

	void	processFrame();

private:

	control_t**		inputsBuffer;
	size_t			numInputs;
	MultiControlFunction*	controlFunc;

};

#endif /* CONTROLFUNCTIONMODULE_HPP */
