#ifndef FIXEDWAVEFUNCTIONLFOMODULE_HPP
#define FIXEDWAVEFUNCTIONLFOMODULE_HPP

#include "types.hpp"
#include "FixedOscModule.hpp"
#include "WaveFunction.hpp"

class FixedWaveFunctionLFOModule : public FixedOscModule
{
public:

			FixedWaveFunctionLFOModule(control_t*, control_t*, WaveFunction*);
			~FixedWaveFunctionLFOModule();

	void		prepareForPlay();
	void		processFrame();
	void		finishAfterPlay();

	control_t*	getOutputBuffer();

private:

	WaveFunction*	waveFunc;
	control_t*	outputBuffer;

};

#endif /* FIXEDWAVEFUNCTIONLFOMODULE_HPP */
