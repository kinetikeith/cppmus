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

				BufferIterator(const BufferInfo&, const FrameInfo&);
				BufferIterator(const BufferIterator&);
	
	T& operator*() const;
	T& operator[](const size_t&) const;
	T& get(size_t, size_t, size_t, bool) const;
	
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
	
	const BufferInfo& bufferInfo;
	const FrameInfo& FrameInfo;

};

#endif /* BUFFERITERATOR_HPP */