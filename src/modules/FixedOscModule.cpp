#include "FixedOscModule.hpp"

FixedOscModule::FixedOscModule(control_t* freq, control_t* phase) : OscModule(freq, phase)
{

}

control_t FixedOscModule::getAbsolutePhase()
{

	return (getParent()->getCurrentTime() + getPhaseMod()) * getFreqMod();

}
