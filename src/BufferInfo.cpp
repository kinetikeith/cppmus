#include "BufferInfo.hpp"

BufferInfo::BufferInfo(size_t nChan, size_t nSamp, size_t nVoic) :
	numChannels(nChan), numSamples(nSamp), numVoices(nVoic),
	bufferSize(nChan * nSamp * nVoic),
	channelIndexOffset(1),
	sampleIndexOffset(nChan),
	voiceIndexOffset(nChan * nSamp),
	channelIndexLimit(nChan),
	sampleIndexLimit(nChan * nSamp),
	voiceIndexLimit(nChan * nSamp * nVoic)
{

}

