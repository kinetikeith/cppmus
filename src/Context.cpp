#include "Context.hpp"

Context::Context(BufferInfo gBufferInfo) : globalBufferInfo(gBufferInfo)
{

}

BufferInfo Context::getGlobalBufferInfo()
{

	return globalBufferInfo;

}

void Context::addModule(ModulePtr mod)
{

	modules.push_back(mod);

}

void Context::removeModule(ModulePtr mod)
{
	
	for(auto iter = modules.begin(); iter != modules.end(); iter++)
	{

		if((*iter) == mod)
		{

			(*iter)->context = nullptr;
			iter = modules.erase(iter);
		
		}

	}

}

ModuleList Context::getModules()
{

	return modules;

}

void Context::prepareContext(const FrameInfo& frameInfo)
{

	for(auto elem : getModules())
	{

		elem->prepareModule(frameInfo, globalBufferInfo);

	}

}

void Context::processContext(const FrameInfo& frameInfo)
{

	for(auto elem : getModules())
	{

		elem->processModule(frameInfo, globalBufferInfo);

	}

}

void Context::finishContext()
{

	for(auto elem : getModules())
	{

		elem->finishModule();

	}

}
