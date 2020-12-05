#ifndef PLAYBACKCONTEXT_HPP
#define PLAYBACKCONTEXT_HPP

#include <memory>

#include "Context.hpp"
#include "AudioOutput.hpp"

class PlaybackContext : public Context
{
public:

			PlaybackContext(BufferInfo);

	AudioOutputPtr	getOutput();
	void		setOutput(AudioOutputPtr);

	virtual void	conclude();
	virtual bool	isConcluded();

private:

	AudioOutputPtr			output;
	bool				concluded;

};

using PlaybackContextPtr = std::shared_ptr<PlaybackContext>;

#endif /* PLAYBACKCONTEXT_HPP */
