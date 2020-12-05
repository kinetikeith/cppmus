#ifndef BUFFERINPUT_HPP
#define BUFFERINPUT_HPP

#include <memory>

#include "Buffer.hpp"
#include "BufferInfo.hpp"

#include "Input.hpp"
#include "BufferOutput.hpp"

template<typename T>
class BufferInput : public Input
{
public:

					BufferInput(T);
					BufferInput(BufferPtr<T>);

	void				setBuffer(BufferPtr<T>);
	BufferPtr<T>			getBuffer();

	void				connect(BufferOutputPtr<T>);

	void				prepareBufferInput(const BufferInfo&);
	void				finishBufferInput();

	T*				getPtr(size_t, size_t, size_t);
	T*				getPtrFast(size_t);

	T				getValue(size_t, size_t, size_t);
	T				getValueFast(size_t);

	const BufferInfo&		getBufferInfo();

private:

	BufferPtr<T>			buffer;

};

template<typename T>
using BufferInputPtr = std::shared_ptr<BufferInput<T>>;

template<typename T>
BufferInput<T>::BufferInput(T defValue) : buffer(new Buffer<T>(defValue))
{

}

template<typename T>
BufferInput<T>::BufferInput(BufferPtr<T> buf) : buffer(buf)
{

}

template<typename T>
void BufferInput<T>::setBuffer(BufferPtr<T> buf)
{

	buffer = buf;

}

template<typename T>
BufferPtr<T> BufferInput<T>::getBuffer()
{

	return buffer;

}

template<typename T>
void BufferInput<T>::connect(BufferOutputPtr<T> output)
{

	buffer = output->getBuffer();

}

template<typename T>
void BufferInput<T>::prepareBufferInput(const BufferInfo& info)
{

	buffer->prepareBuffer(info);

}

template<typename T>
void BufferInput<T>::finishBufferInput()
{

	buffer->finishBuffer();

}

template<typename T>
inline T* BufferInput<T>::getPtr(size_t sampleIndex, size_t voiceIndex, size_t channelIndex)
{

	return buffer->getPtr(sampleIndex, voiceIndex, channelIndex);

}

template<typename T>
inline T* BufferInput<T>::getPtrFast(size_t index)
{

	return buffer->getPtrFast(index);

}

template<typename T>
inline T BufferInput<T>::getValue(size_t sampleIndex, size_t voiceIndex, size_t channelIndex)
{

	return buffer->getValue(sampleIndex, voiceIndex, channelIndex);

}

template<typename T>
inline T BufferInput<T>::getValueFast(size_t index)
{

	return buffer->getValueFast(index);

}

template<typename T>
inline const BufferInfo& BufferInput<T>::getBufferInfo()
{

	return buffer->getInfo();

}

#endif /* BUFFERINPUT_HPP */
