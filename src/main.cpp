#include <iostream>
#include <cstdlib>
#include <cmath>

#include "play.hpp"

#include "types.hpp"
#include "Song.hpp"
#include "AmplifierModule.hpp"
#include "FixedWaveFunctionOscModule.hpp"
#include "FixedWaveFunctionLFOModule.hpp"
#include "waveFunctions.hpp"
#include "ControlFunctionModule.hpp"
#include "MixerModule.hpp"
#include "DelayModule.hpp"

control_t flipMakeUni(control_t x)
{

	return 2.0 * (-x + 1.0);

}

int main()
{

	using std::cout;
	using std::endl;

	Song song(2, 44100);
	
	control_t oscFreq = 440.0;
	control_t oscPhase = 0.0;

	control_t lfoFreq = 1.0;
	control_t lfoPhase = 0.0;

	control_t delayTime = 0.125;

	FixedWaveFunctionOscModule oscModule(&oscFreq, &oscPhase, &sawWaveFunc);
	FixedWaveFunctionLFOModule lfoModule(&lfoFreq, &lfoPhase, &sawWaveAliasedFunc);
	ControlFunctionModule uniLfoModule(lfoModule.getOutputBuffer(), &flipMakeUni);
	AmplifierModule ampModule(oscModule.getAudioOutputBuffer(), uniLfoModule.getControlOutputBuffer());

	//audio_t** mixerChannels = {amplifierModule.getOutputBuffer(), }
	
	MixerModule mixerModule(
	DelayModule delayModule(ampModule.getAudioOutputBuffer(), &delayTime, 1.0);

	song.registerModule(&oscModule);
	song.registerModule(&lfoModule);
	song.registerModule(&uniLfoModule);
	song.registerModule(&ampModule);
	song.registerModule(&delayModule);

	audio_t** fBufs = song.getFrameBuffers();
	fBufs[0] = ampModule.getAudioOutputBuffer();
	fBufs[1] = delayModule.getAudioOutputBuffer();

	play(&song, 512);

	cout << "Hello World!" << endl;

	return EXIT_SUCCESS;

}

