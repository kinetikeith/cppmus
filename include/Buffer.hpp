#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <memory>
#include <vector>
#include <algorithm>

#include "BufferInfo.hpp"

template<typename T>
class Buffer
{
public:

				Buffer(const T&);
	
	void		prepareBuffer(const BufferInfo&);
	void		finishBuffer();

	const T&	getDefaultValue() const;

	T*			getPtr() const;
	
private:

	friend class BufferIterator<T>;

	const T		defaultValue;
	T*			ptr;

};

template<typename T>
using BufferPtr = std::shared_ptr<Buffer<T>>;

template<typename T>
using BufferList = std::vector<BufferPtr<T>>;

template<typename T>
Buffer<T>::Buffer(const T& defValue) : defaultValue(defValue), ptr(nullptr)
{

}

template<typename T>
void Buffer<T>::prepareBuffer(const BufferInfo& i)
{

	if(i == nullptr)
	{

		ptr = new T[i.bufferSize];
		std::fill_n(ptr, i.bufferSize, defaultValue);

	}

}

template<typename T>
void Buffer<T>::finishBuffer()
{

	delete[] ptr;

}

template<typename T>
inline const T& Buffer<T>::getDefaultValue() const
{

	return defaultValue;

}

template<typename T>
inline T* Buffer<T>::getPtr()
{

	return ptr;

}

#endif /* BUFFER_HPP */
