#include "waveFunctions.hpp"

#include <cmath>

control_t sineWaveFunc(control_t absPhase, control_t numHarmonics)
{

	if(numHarmonics >= 1.0)
	{

		return std::sin(2.0 * M_PI * absPhase);

	}

	return 0.0;
}

control_t sawWaveFunc(control_t absPhase, control_t numHarmonics)
{

	control_t res = 0.0;

	for(control_t k = 1.0; k < numHarmonics; k += 1.0)
	{

		res += std::pow(-1.0, k) * std::sin(2.0 * M_PI * absPhase * k) / k;
	}

	return res * (-2.0 / M_PI);

}

control_t squareWaveFunc(control_t absPhase, control_t numHarmonics)
{

	control_t res = 0.0;

	for(control_t k = 1.0; k < numHarmonics; k += 2.0)
	{

		res += std::sin(2.0 * M_PI * absPhase * k) / k;

	}

	return res * (4.0 / M_PI);

}

control_t triWaveFunc(control_t absPhase, control_t numHarmonics)
{

	control_t res = 0.0;

	for(control_t k = 1.0; k < numHarmonics; k += 2.0)
	{

		res += std::pow(-1.0, (k + 1.0) / 2.0) * 
			std::sin(2.0 * M_PI * absPhase * k)
			* std::pow(k, -2.0);

	}

	return res * (-8.0 / (M_PI * M_PI));

}

control_t sineWaveAliasedFunc(control_t absPhase, control_t numHarmonics)
{

	return std::sin(2.0 * M_PI * absPhase);

}

control_t sawWaveAliasedFunc(control_t absPhase, control_t numHarmonics)
{

	return std::fmod((2.0 * absPhase) + 1.0, 2.0) - 1.0;

}

control_t squareWaveAliasedFunc(control_t absPhase, control_t numHarmonics)
{

	return std::copysign(1.0, std::fmod((2.0 * absPhase) + 1.0, 2.0) - 1.0);

}

control_t triWaveAliasedFunc(control_t absPhase, control_t numHarmonics)
{

	return std::abs(std::fmod((4.0 * absPhase) - 1.0, 4.0) - 2.0) - 1.0;

}
