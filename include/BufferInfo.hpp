#ifndef BUFFERINFO_HPP
#define BUFFERINFO_HPP

#include <memory>

struct BufferInfo
{
	
			BufferInfo(size_t, size_t, size_t);
	
	const size_t	numChannels;
	const size_t	numSamples;
	const size_t	numVoices;
	
	const size_t	bufferSize;
	
	const size_t	channelIndexOffset;
	const size_t	sampleIndexOffset;
	const size_t	voiceIndexOffset;
	
	const size_t	channelIndexLimit;
	const size_t	sampleIndexLimit;
	const size_t	voiceIndexLimit;

	size_t		getIndex(size_t, size_t, size_t);

};

using BufferInfoPtr = std::shared_ptr<BufferInfo>;

inline size_t BufferInfo::getIndex(size_t chanNum, size_t sampNum, size_t voicNum)
{

	return ((chanNum % numChannels) * channelIndexOffset)
		+ ((sampNum % numSamples) * sampleIndexOffset)
		+ ((voicNum % numVoices) * voiceIndexOffset);

}

#endif /* BUFFERINFO_HPP */
