#include "ImplementationLibrary.h"

namespace alcolo
{
	ImplementationLibrary::ImplementationLibrary()
		: AbstractImplementationLibrary("alcolo")
		, setEntityBoolean_()
		, increment_ ()
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
		success = success && registerType<SetEntityBooleanParams>(logger);
		success = success && registerAction(setEntityBoolean_, logger);
		success = success && registerType<IncrementParams>(logger);
		success = success && registerAction(increment_, logger);			
		
		return success;
	}

	bool ImplementationLibrary::doUnload(mlv::utils::AbstractLogger* logger)
	{
		bool success = true;
		
		//Actions
		success = success && unregisterAction(setEntityBoolean_, logger);
		if (success)
			unregisterType<SetEntityBooleanParams>();
			
		success = success && unregisterAction(increment_, logger);
		if (success)
			unregisterType<IncrementParams>();
			
		return success;
	}
}
