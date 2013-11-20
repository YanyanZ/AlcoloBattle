#include "ImplementationLibrary.h"

namespace templates
{
    namespace impl_lib
    {
        ImplementationLibrary::ImplementationLibrary()
            : AbstractImplementationLibrary("templates")
            , customAction_()
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
			success = success && registerType<setSecuEngageParams>(logger);
            success = success && registerAction(customAction_, logger);		
			
            return success;
        }

        bool ImplementationLibrary::doUnload(mlv::utils::AbstractLogger* logger)
        {
            bool success = true;
			
			//Actions
			success = success && unregisterAction(customAction_, logger);
            if (success)
                unregisterType<setSecuEngageParams>();
				
            return success;
        }
    }
}
