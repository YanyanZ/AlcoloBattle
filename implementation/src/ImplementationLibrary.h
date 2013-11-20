#ifndef IMPLEMENTATION_LIBRARY_H
#define IMPLEMENTATION_LIBRARY_H
#include "setSecuEngate.h"

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
			setSecuEngage customAction_;     
		}; 
	}
}

#endif
