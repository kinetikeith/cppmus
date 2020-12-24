#ifndef BUFFERITERATOR_HPP
#define BUFFERITERATOR_HPP

#include <iterator>

#include "Buffer.hpp"
#include "BufferInfo.hpp"
#include "FrameInfo.hpp"

template<typename T>
class BufferIterator : public std::iterator<std::random_access_iterator_tag, T, size_t>
{
public:

					BufferIterator(BufferInfo&, FrameInfo&);
					BufferIterator(const BufferIterator&);

	T& operator*() const;
	T& operator[](const size_t&) const;
	
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
	
	size_t getChannelIndex() const;
	size_t getSampleIndex() const;
	size_t getVoiceIndex() const;
	
	size_t getAbsoluteSampleIndex() const;
	double getAbsoluteTime() const;
	
private:

	size_t _currentIndex;

}

#endif /* BUFFERITERATOR_HPP */