#ifndef ACTION_H
#define ACTION_H

#include <mlv/behavior/AbstractTypedAction.h>

namespace templates
{
    namespace impl_lib
    {
		/* Parameters of the action */
	
        class setSecuEngageParams : public mlv::utils::StaticObject
        {
            MLV_DEFINE_STATIC_OBJECT(templates::impl_lib::setSecuEngageParams,"1e74c1ca-c3cc-4739-8dcc-49744428864e",setMetadata);
        public:
            setSecuEngageParams();

        private:
            static bool setMetadata( mlv::utils::TypeManager& manager, mlv::utils::AbstractLogger* logger );
        };

        /* Action */
		
        class setSecuEngage: public mlv::behavior::AbstractTypedAction<setSecuEngageParams>
        {
        public:
            setSecuEngage();
            ~setSecuEngage();

        private:
            virtual mlv::behavior::action::Status doStart(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const setSecuEngageParams& params);
            virtual mlv::behavior::action::Status doUpdate(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const setSecuEngageParams& params, const mlv::utils::Time& dt);
            virtual mlv::behavior::action::Status doCancel(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const setSecuEngageParams& params, const mlv::utils::Time& dt);
    
			};
	}
}

#endif
