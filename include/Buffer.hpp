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

				Buffer(T);
	
	void			prepareBuffer(const BufferInfo&);
	void			finishBuffer();

	T			getDefaultValue();
	void		setDefaultValue(T);

	T*			getPtr();

	const BufferInfo&	getInfo();

private:

	T			defaultValue;
	T*			ptr;
	BufferInfoPtr	info;

};

template<typename T>
using BufferPtr = std::shared_ptr<Buffer<T>>;

template<typename T>
using BufferList = std::vector<BufferPtr<T>>;

template<typename T>
Buffer<T>::Buffer(T defValue) : defaultValue(defValue), 
	info(nullptr)
{

}

template<typename T>
void Buffer<T>::prepareBuffer(const BufferInfo& i)
{

	if(info == nullptr)
	{

		info = &(const_cast<BufferInfo>(i));
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
inline T Buffer<T>::getDefaultValue()
{

	return defaultValue;

}

template<typename T>
inline void Buffer<T>::setDefaultValue(T val)
{

	defaultValue = val;

}

template<typename T>
inline T* Buffer<T>::getPtr()
{

	return ptr;

}

template<typename T>
inline const BufferInfo& Buffer<T>::getInfo()
{

	return *info;

}

#endif /* BUFFER_HPP */
