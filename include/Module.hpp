#ifndef MODULE_HPP
#define MODULE_HPP

#include <memory>
#include <vector>

#include "FrameInfo.hpp"
#include "BufferInfo.hpp"

#include "Context.hpp"
#include "Input.hpp"
#include "Output.hpp"

class Context;
using ContextPtr = std::shared_ptr<Context>;

class Module
{
public:

	virtual void		prepareModule(const FrameInfo&, const BufferInfo&);
	virtual void		processModule(const FrameInfo&, const BufferInfo&) = 0;
	virtual void		finishModule();

	virtual InputList	getInputs();
	virtual OutputList	getOutputs();

	ContextPtr	getContext();

private:

	friend class	Context; 
	ContextPtr	context;

};

using ModulePtr = std::shared_ptr<Module>;
using ModuleList = std::vector<ModulePtr>;

#endif /* MODULE_HPP */
