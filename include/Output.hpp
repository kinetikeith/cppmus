#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <memory>
#include <vector>

#include "BufferInfo.hpp"

class Output
{
public:

	virtual void	prepareOutput(const BufferInfo&) = 0;
	virtual void	finishOutput() = 0;

};

using OutputPtr = std::shared_ptr<Output>;
using OutputList = std::vector<OutputPtr>;

#endif /* OUTPUT_HPP */
