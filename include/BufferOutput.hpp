#ifndef BUFFEROUTPUT_HPP
#define BUFFEROUTPUT_HPP

#include <memory>

#include "Buffer.hpp"
#include "BufferInfo.hpp"

#include "Output.hpp"

template<typename T>
class BufferOutput : public Output
{
public:
				BufferOutput(T);
	
	void			prepareBufferOutput(const BufferInfo&);
	void			finishBufferOutput();

	T*			getPtr(size_t, size_t, size_t);
	T*			getPtrFast(size_t);

	void			setValue(size_t, size_t, size_t, T);
	void			setValueFast(size_t, T);

	T			getValue(size_t, size_t, size_t);
	T			getValueFast(size_t);

	const BufferInfo&	getBufferInfo();

private:

	BufferPtr<T>		buffer;

};

template<typename T>
using BufferOutputPtr = std::shared_ptr<BufferOutput<T>>;

template<typename T>
BufferOutput<T>::BufferOutput(T defValue) : buffer(new Buffer<T>(defValue))
{

}

template<typename T>
void BufferOutput<T>::prepareBufferOutput(const BufferInfo& info)
{

	buffer->prepareBuffer(info);

}

template<typename T>
void BufferOutput<T>::finishBufferOutput()
{

	buffer->finishBuffer();

}

template<typename T>
inline T* BufferOutput<T>::getPtr(size_t sampleIndex, size_t voiceIndex, size_t channelIndex)
{

	return buffer->getPtr(sampleIndex, voiceIndex, channelIndex);

}

template<typename T>
inline T* BufferOutput<T>::getPtrFast(size_t index)
{

	return buffer->getPtrFast(index);

}

template<typename T>
inline void BufferOutput<T>::setValue(size_t sampleIndex, size_t voiceIndex, size_t channelIndex, T value)
{

	buffer->setValue(sampleIndex, voiceIndex, channelIndex, value);

}

template<typename T>
inline void BufferOutput<T>::setValueFast(size_t index, T value)
{

	buffer->setValueFast(index, value);

}

template<typename T>
inline T BufferOutput<T>::getValue(size_t sampleIndex, size_t voiceIndex, size_t channelIndex)
{

	return buffer->getValue(sampleIndex, voiceIndex, channelIndex);

}

template<typename T>
inline T BufferOutput<T>::getValueFast(size_t index)
{

	return buffer->getValueFast(index);

}

template<typename T>
const BufferInfo& BufferOutput<T>::getBufferInfo()
{

	return buffer->getInfo();

}

#endif /* BUFFEROUTPUT_HPP */
