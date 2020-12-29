#ifndef BUFFERITERATOR_HPP
#define BUFFERITERATOR_HPP

#include <cstddef>
#include <iterator>

#include "Buffer.hpp"
#include "BufferInfo.hpp"
#include "FrameInfo.hpp"

template<typename T>
class BufferIterator : public std::iterator<std::random_access_iterator_tag, T, size_t>
{
public:

				BufferIterator(const Buffer<T>&, const BufferInfo&, const FrameInfo&);
				BufferIterator(const BufferIterator&);
	
	T& operator*() const;
	T& operator[](const size_t&) const;
	T& get(const size_t&, const size_t&, const size_t&, const bool&) const;
	
	const BufferIterator& operator++();
	const BufferIterator& operator--();
	BufferIterator& operator++(int);
	BufferIterator& operator--(int);
	BufferIterator& operator+=(const size_t&);
	BufferIterator& operator-=(const size_t&);
	
	BufferIterator& operator+(const size_t&) const;
	BufferIterator& operator-(const size_t&) const;
	BufferIterator&	operator=(const BufferIterator&);
	
	bool operator==(const BufferIterator&) const;
	bool operator!=(const BufferIterator&) const;
	bool operator<(const BufferIterator&) const;
	bool operator>(const BufferIterator&) const;
	bool operator<=(const BufferIterator&) const;
	bool operator>=(const BufferIterator&) const;
	
	size_t getCurrentIndex() const;
	
	size_t getCurrentChannelIndex() const;
	size_t getCurrentSampleIndex() const;
	size_t getCurrentVoiceIndex() const;
	
	size_t getAbsoluteSampleIndex() const;
	double getAbsoluteTime() const;

private:

	size_t currentIndex;
	
	size_t currentChannelIndex;
	size_t currentSampleIndex;
	size_t currentVoiceIndex;
	
	Buffer<T>& buffer;
	BufferInfo& bufferInfo;
	FrameInfo& frameInfo;

};

template<typename T>
BufferIterator<T>::BufferIterator(const Buffer<T>& buf,
	const BufferInfo& bInfo, const FrameInfo& fInfo) : 
		buffer(const_cast<Buffer<T>&>(buf)),
		bufferInfo(const_cast<BufferInfo&>(bInfo)),
		frameInfo(const_cast<FrameInfo&>(fInfo)),
		currentIndex(0),
		currentChannelIndex(0),
		currentSampleIndex(0),
		currentVoiceIndex(0)
{
	
}

template<typename T>
BufferIterator<T>:: BufferInfo(const BufferIterator<T>& other) :
	buffer(other.buffer),
	bufferInfo(other.bufferInfo),
	frameInfo(other.frameInfo),
	currentIndex(other.currentIndex),
	currentChannelIndex(other.currentChannelIndex),
	currentSampleIndex(other.currentSampleIndex),
	currentVoiceIndex(other.currentVoiceIndex)
{
	
}



#endif /* BUFFERITERATOR_HPP */