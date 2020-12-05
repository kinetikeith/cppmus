#ifndef OSCMODULE_HPP
#define OSCMODULE_HPP

#include "types.hpp"
#include "Module.hpp"

class OscModule : public Module
{
public:

				OscModule(control_t*, control_t*);

	control_t		getFreqMod();
	control_t		getPhaseMod();

	virtual control_t	getAbsolutePhase() = 0;

private:

	control_t*		freqBuffer;
	control_t*		phaseBuffer;

};

#endif /* OSCMODULE_HPP */
