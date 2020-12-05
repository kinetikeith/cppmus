#ifndef FIXEDWAVEFUNCTIONOSCMODULE_HPP
#define FIXEDWAVEFUNCTIONOSCMODULE_HPP

#include "types.hpp"
#include "FixedOscModule.hpp"
#include "SingleAudioOutput.hpp"
#include "WaveFunction.hpp"

class FixedWaveFunctionOscModule : public FixedOscModule, public SingleAudioOutput
{
public:

		FixedWaveFunctionOscModule(control_t*, control_t*, WaveFunction*);

	void	prepareForPlay();
	void	processFrame();
	void	finishAfterPlay();

private:

	WaveFunction*	waveFunc;

};

#endif /* FIXEDWAVEFUNCTIONMODULE_HPP */
