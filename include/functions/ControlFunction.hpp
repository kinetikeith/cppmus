#ifndef CONTROLFUNCTION_HPP
#define CONTROLFUNCTION_HPP

#include "types.hpp"

typedef control_t (ControlFunction)(control_t);
typedef control_t (BiControlFunction)(control_t, control_t);
typedef control_t (MultiControlFunction)(control_t**, size_t);

#endif /* CONTROLFUNCTION_HPP */
