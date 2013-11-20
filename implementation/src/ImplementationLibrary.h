#ifndef IMPLEMENTATION_LIBRARY_H
#define IMPLEMENTATION_LIBRARY_H

#include "SetEntityKnowledgePropertyBooleanNode.h"

#include <mlv/simulation/configuration/AbstractImplementationLibrary.h>

#include <mlv/utils/ScopedPtr.h>

namespace alcolo
{
	class ImplementationLibrary : public mlv::simulation::configuration::AbstractImplementationLibrary
	{
	public:
		ImplementationLibrary();
		virtual ~ImplementationLibrary();
	private:

		virtual bool doLoad(mlv::utils::AbstractLogger* logger);
		virtual bool doUnload(mlv::utils::AbstractLogger* logger);

		// nodes
		SetEntityKnowledgePropertyBooleanNode setEntityKnowledgePropertyBooleanNode_;
		//Custom Action
		//MyCustomAction customAction_;     
	}; 
}

#endif
