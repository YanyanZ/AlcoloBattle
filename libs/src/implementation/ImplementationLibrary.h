#ifndef IMPLEMENTATION_LIBRARY_H
#define IMPLEMENTATION_LIBRARY_H
#include "MyCustomAction.h"

#include <mlv/simulation/configuration/AbstractImplementationLibrary.h>

namespace templates
{
	namespace impl_lib
	{
		class ImplementationLibrary : public mlv::simulation::configuration::AbstractImplementationLibrary
		{
		public:
			ImplementationLibrary();
			virtual ~ImplementationLibrary();
		private:

			virtual bool doLoad(mlv::utils::AbstractLogger* logger);
			virtual bool doUnload(mlv::utils::AbstractLogger* logger);

			//Custom Action
			MyCustomAction customAction_;     
		}; 
	}
}

#endif
