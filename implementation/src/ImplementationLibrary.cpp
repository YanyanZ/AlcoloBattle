#include "ImplementationLibrary.h"

#include <mlv/simulation/components/NavigationComponent.h>

#include <mlv/simulation/SimulationFramework.h>

#include <mlv/utils/OstreamLogger.h>

namespace alcolo
{
	ImplementationLibrary::ImplementationLibrary()
		: AbstractImplementationLibrary("alcolo")
		, setEntityKnowledgePropertyBooleanNode_ ()
		//, customAction_()
	{
		// NOTHING
	}

	ImplementationLibrary::~ImplementationLibrary()
	{
		if (isLoaded())
			forceUnload();
	}

	bool ImplementationLibrary::doLoad(mlv::utils::AbstractLogger* logger)
	{
		bool success = true;
		
		//Actions
		//success = success && registerType<MyCustomActionParams>(logger);
		//success = success && registerAction(customAction_, logger);		
		
		// nodes
       success = success && registerType<SetEntityKnowledgePropertyBooleanParams>(logger);
       success = success && registerBTCustomNode(setEntityKnowledgePropertyBooleanNode_,logger);
		
		return success;
	}

	bool ImplementationLibrary::doUnload(mlv::utils::AbstractLogger* logger)
	{
		bool success = true;
		
		//Actions
		//success = success && unregisterAction(customAction_, logger);
		//if (success)
		//    unregisterType<MyCustomActionParams>();
		
		// nodes
        success = success && unregisterBTCustomNode(setEntityKnowledgePropertyBooleanNode_,logger);
        if (success)
            unregisterType<SetEntityKnowledgePropertyBooleanParams>();
			
		return success;
	}
}
