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

	T*			getPtr(size_t, size_t, size_t);
	T*			getPtrFast(size_t);

	T			getValue(size_t, size_t, size_t);
	T			getValueFast(size_t);

	void			setValue(size_t, size_t, size_t, T);
	void			setValueFast(size_t, T);

	const BufferInfo&	getInfo();

private:

	T			defaultValue;
	T*			ptr;
	const BufferInfoPtr	info;

};

template<typename T>
using BufferPtr = std::shared_ptr<Buffer<T>>;

template<typename T>
using BufferList = std::vector<BufferPtr<T>>;

template<typename T>
Buffer<T>::Buffer(T defValue) : defaultValue(defValue)
{

}

template<typename T>
void Buffer<T>::prepareBuffer(const BufferInfo& i)
{

	if(info == nullptr)
	{

		info = &i;
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
inline T* Buffer<T>::getPtr(size_t sampIndex, size_t voicIndex, size_t chanIndex)
{

	return ptr + info->getIndex(sampIndex, voicIndex, chanIndex);

}

template<typename T>
inline T* Buffer<T>::getPtrFast(size_t index)
{

	return ptr + index;

}

template<typename T>
inline T Buffer<T>::getValue(size_t chanIndex, size_t sampIndex, size_t voicIndex)
{

	return *(ptr + info->getIndex(chanIndex, sampIndex, voicIndex));

}

template<typename T>
inline T Buffer<T>::getValueFast(size_t index)
{

	return *(ptr + index);

}

template<typename T>
inline void Buffer<T>::setValue(size_t chanIndex, size_t sampIndex, size_t voicIndex, T value)
{

	*(ptr + info->getIndex(chanIndex, sampIndex, voicIndex)) = value;

}

template<typename T>
inline void Buffer<T>::setValueFast(size_t index, T value)
{

	*(ptr + index) = value;

}

template<typename T>
inline const BufferInfo& Buffer<T>::getInfo()
{

	return *info;

}

#endif /* BUFFER_HPP */
