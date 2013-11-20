#include "setSecuEngate.h"

#include <mlv/behavior/EntityKnowledgeFacade.h>
#include <mlv/behavior/EntityProperties.h>

namespace templates
{
    namespace impl_lib
    {
		setSecuEngageParams::setSecuEngageParams()
        {
            // Initialization of the parameters
        }

        bool setSecuEngageParams::setMetadata(mlv::utils::TypeManager& manager, mlv::utils::AbstractLogger* logger)
        {
            return true;
        }

        setSecuEngage::setSecuEngage()
            : mlv::behavior::AbstractTypedAction<setSecuEngageParams>("setSecuEngage") //Name used in the BT editor to create an instance of this action
        {
            // Initialization of the action
        }

        setSecuEngage::~setSecuEngage()
        {
            // Destruction of the action
        }
	
        mlv::behavior::action::Status setSecuEngage::doStart(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const setSecuEngageParams& params)
        {			
			// The action begin
			mlv::utils::DynamicObject& knowledge = entity.getKnowledge();
			knowledge.setBool("Engage", true);
			
			return mlv::behavior::action::running;
        }

        mlv::behavior::action::Status setSecuEngage::doUpdate(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const setSecuEngageParams& params, const mlv::utils::Time& dt)
        {
            // The action continue
			
            return mlv::behavior::action::succeeded;
        }

        mlv::behavior::action::Status setSecuEngage::doCancel(mlv::behavior::EntityKnowledgeFacade& entity, mlv::behavior::ActionRequestHandle requestId, const setSecuEngageParams& params, const mlv::utils::Time& dt)
        {
            //The action is canceled
			
            return mlv::behavior::action::canceled;
        }
    }
}
