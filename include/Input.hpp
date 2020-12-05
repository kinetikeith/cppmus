#ifndef INPUT_HPP
#define INPUT_HPP

#include <memory>
#include <vector>

#include "BufferInfo.hpp"

class Input
{
public:
		
	virtual void	prepareInput(const BufferInfo&) = 0;
	virtual void	finishInput() = 0;

};

using InputPtr = std::shared_ptr<Input>;
using InputList = std::vector<InputPtr>;

#endif /* INPUT_HPP */
