#ifndef FIXEDOSC_MODULE
#define FIXEDOSC_MODULE

#include "OscModule.hpp"

class FixedOscModule : public OscModule
{
public:

			FixedOscModule(control_t*, control_t*);

	control_t	getAbsolutePhase();

};

#endif /* FIXEDOSC_MODULE */
