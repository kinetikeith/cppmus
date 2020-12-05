#ifndef BUFFERINFO_HPP
#define BUFFERINFO_HPP

#include <memory>

struct BufferInfo
{
	
	size_t		numSamples;
	size_t		numVoices;
	size_t		numChannels;

	size_t		getBufferSize() noexcept;

	size_t		getIndex(size_t, size_t, size_t) noexcept;

	size_t		getSampleIndexOffset() noexcept;
	size_t		getVoiceIndexOffset() noexcept;
	size_t		getChannelIndexOffset() noexcept;

	size_t		getSampleIndexLimit() noexcept;
	size_t		getVoiceIndexLimit() noexcept;
	size_t		getChannelIndexLimit() noexcept;

};

typedef std::shared_ptr<BufferInfo> BufferInfoPtr;

inline size_t BufferInfo::getBufferSize() noexcept
{

	return numSamples * numVoices * numChannels;

}

inline size_t BufferInfo::getIndex(size_t sampleIndex, size_t voiceIndex, size_t channelIndex) noexcept
{

	return ((sampleIndex % numSamples) * numVoices * numChannels) 
		+ ((voiceIndex % numVoices) * numChannels)
	       	+ (channelIndex % numChannels);

}

inline size_t BufferInfo::getSampleIndexOffset() noexcept
{

	return numVoices * numChannels;

}

inline size_t BufferInfo::getVoiceIndexOffset() noexcept
{

	return numChannels;

}

inline size_t BufferInfo::getChannelIndexOffset() noexcept
{

	return 1;

}

inline size_t BufferInfo::getSampleIndexLimit() noexcept
{

	return numSamples * numVoices * numChannels;

}

inline size_t BufferInfo::getVoiceIndexLimit() noexcept
{

	return numVoices * numChannels;

}

inline size_t BufferInfo::getChannelIndexLimit() noexcept
{

	return numChannels;

}

#endif /* BUFFERINFO_HPP */
