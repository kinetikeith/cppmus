#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <memory>
#include <vector>

#include "FrameInfo.hpp"
#include "BufferInfo.hpp"

#include "Module.hpp"

class Module;
using ModulePtr = std::shared_ptr<Module>;
using ModuleList = std::vector<ModulePtr>;

class Context
{
public:

				Context(BufferInfo);

	virtual void		addModule(ModulePtr);
	virtual void		removeModule(ModulePtr);
	virtual ModuleList	getModules();
	
	virtual void		prepareContext(const FrameInfo&);
	virtual void		processContext(const FrameInfo&);
	virtual void		finishContext();

private:

	ModuleList	modules;
	BufferInfo	globalBufferInfo;

};

using ContextPtr = std::shared_ptr<Context>;

#endif /* CONTEXT_HPP */
