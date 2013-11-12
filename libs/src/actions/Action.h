#ifndef ACTION_H
#define ACTION_H

#include <mlv/behavior/AbstractTypedAction.h>

namespace templates
{
    namespace impl_lib
    {
		/* Parameters of the action */
	
        class ActionParams : public mlv::utils::StaticObject
        {
            MLV_DEFINE_STATIC_OBJECT(templates::impl_lib::ActionParams,"1e74c1ca-c3cc-4739-8dcc-49744428864e",setMetadata);
        public:
            ActionParams();
            mlv::utils::String name; // example of a parameter

        private:
            static bool setMetadata( mlv::utils::TypeManager& manager, mlv::utils::AbstractLogger* logger );
        };

        /* Action */
		
        class Action: public mlv::behavior::AbstractTypedAction<ActionParams>
        {
        public:
            Action();
            ~Action();

        private:
            virtual mlv::behavior::action::Status doStart(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const ActionParams& params);
            virtual mlv::behavior::action::Status doUpdate(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const ActionParams& params, const mlv::utils::Time& dt);
            virtual mlv::behavior::action::Status doCancel(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const ActionParams& params, const mlv::utils::Time& dt);
        };
	}
}

#endif
