#include "Action.h"

#include <mlv/behavior/EntityKnowledgeFacade.h>
#include <mlv/behavior/EntityProperties.h>

namespace templates
{
    namespace impl_lib
    {
        ActionParams::ActionParams()
            : name("")
        {
            // Initialization of the parameters
        }

        bool ActionParams::setMetadata(mlv::utils::TypeManager& manager, mlv::utils::AbstractLogger* logger)
        {
            return manager.registerProperty("name", &ActionParams::name, logger);
        }

        Action::Action()
            : mlv::behavior::AbstractTypedAction<TemplateActionParams>("action") //Name used in the BT editor to create an instance of this action
        {
            // Initialization of the action
        }

        Action::~Action()
        {
            // Destruction of the action
        }


        mlv::behavior::action::Status Action::doStart(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const ActionParams& params)
        {			
			// The action begin
		
			return mlv::behavior::action::running;
        }

        mlv::behavior::action::Status Action::doUpdate(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const ActionParams& params, const mlv::utils::Time& dt)
        {
            // The action continue
			
            return mlv::behavior::action::succeeded;
        }

        mlv::behavior::action::Status Action::doCancel(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const ActionParams& params, const mlv::utils::Time& dt)
        {
            //The action is canceled
			
            return mlv::behavior::action::canceled;
        }
    }
}
