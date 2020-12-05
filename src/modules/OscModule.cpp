#include "OscModule.hpp"

OscModule::OscModule(control_t* freq, control_t* phase) : freqBuffer(freq), phaseBuffer(phase)
{

}

control_t OscModule::getFreqMod()
{

	return *freqBuffer;

}

control_t OscModule::getPhaseMod()
{

	return *phaseBuffer;

}
