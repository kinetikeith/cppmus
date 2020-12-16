#ifndef BUFFERINFO_HPP
#define BUFFERINFO_HPP

#include <memory>

struct BufferInfo
{
	
	size_t		numChannels;
	size_t		numSamples;
	size_t		numVoices;

	size_t		getBufferSize() const noexcept;

	size_t		getIndex(size_t, size_t, size_t) const noexcept;

	size_t		getChannelIndexOffset() const noexcept;
	size_t		getSampleIndexOffset() const noexcept;
	size_t		getVoiceIndexOffset() const noexcept;

	size_t		getChannelIndexLimit() const noexcept;
	size_t		getSampleIndexLimit() const noexcept;
	size_t		getVoiceIndexLimit() const noexcept;

};

typedef std::shared_ptr<BufferInfo> BufferInfoPtr;

inline size_t BufferInfo::getBufferSize() const noexcept
{

	return numChannels * numSamples * numVoices;

}

inline size_t BufferInfo::getIndex(size_t channelIndex, size_t sampleIndex, size_t voiceIndex) const noexcept
{

	return ((voiceIndex % numVoices) * numSamples * numChannels) 
		+ ((sampleIndex % numSamples) * numChannels)
	       	+ (channelIndex % numChannels);

}

inline size_t BufferInfo::getChannelIndexOffset() const noexcept
{

	return 1;

}

inline size_t BufferInfo::getSampleIndexOffset() const noexcept
{

	return numChannels;

}

inline size_t BufferInfo::getVoiceIndexOffset() const noexcept
{

	return numChannels * numSamples;

}

inline size_t BufferInfo::getChannelIndexLimit() const noexcept
{

	return numChannels;

}

inline size_t BufferInfo::getSampleIndexLimit() const noexcept
{

	return numChannels * numSamples;

}

inline size_t BufferInfo::getVoiceIndexLimit() const noexcept
{

	return numChannels * numSamples * numVoices;

}

#endif /* BUFFERINFO_HPP */
