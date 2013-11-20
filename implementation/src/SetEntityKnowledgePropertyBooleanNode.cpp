#include "SetEntityKnowledgePropertyBooleanNode.h"

namespace alcolo
{
    SetEntityKnowledgePropertyBooleanParams::SetEntityKnowledgePropertyBooleanParams()
        : key("")
        , value()
    {

    }
	
/* 	void SetEntityKnowledgePropertyBooleanParams::apply(mlv::utils::DynamicObject& entityKnowledge) const
	{
		entityKnowledge.setBool("key", value);
	} */

    bool SetEntityKnowledgePropertyBooleanParams::setMetadata( mlv::utils::TypeManager& manager, mlv::utils::AbstractLogger* logger )
    {
        return manager.registerProperty("key", &SetEntityKnowledgePropertyBooleanParams::key, logger)
            && manager.registerProperty("value", &SetEntityKnowledgePropertyBooleanParams::value, logger);
    }

    SetEntityKnowledgePropertyBooleanNode::SetEntityKnowledgePropertyBooleanNode()
        : mlv::behavior::bt::AbstractCustomNodeT<SetEntityKnowledgePropertyBooleanParams>("SetEntityKnowledgePropertyBoolean",mlv::behavior::bt::arity::zero)
    {
    }

    SetEntityKnowledgePropertyBooleanNode::~SetEntityKnowledgePropertyBooleanNode()
    {
        // NOTHING
    }

    mlv::behavior::bt::AbstractCustomNode* SetEntityKnowledgePropertyBooleanNode::clone() const
    {
        return MLV_NEW SetEntityKnowledgePropertyBooleanNode();
    }

    void SetEntityKnowledgePropertyBooleanNode::destroy()
    {
        MLV_DELETE this;
    }

    mlv::behavior::decision::Status SetEntityKnowledgePropertyBooleanNode::doPropagate(
        mlv::behavior::bt::BTNodeIndex nodeIndex,
        const SetEntityKnowledgePropertyBooleanParams& nodeParameters,
        const mlv::utils::DynamicObject& behaviorParameters,
        mlv::behavior::bt::InterpreterFacade& interpreter,
        mlv::utils::AbstractLogger* logger )
    {
        mlv::utils::DynamicObject& entityKnowledge = interpreter.getKnowledgeFacade().getKnowledge();
        mlv::utils::DynamicObject::PropertyHandle p = entityKnowledge.getProperty(nodeParameters.key.c_str(),nodeParameters.key.length());
        if (p == 0)
        {
            p = entityKnowledge.addProperty(nodeParameters.key.c_str(),nodeParameters.key.length());
            if (p==0)
            {
                MLV_LOG_ERROR(logger, mlv::utils::error::invalidConfiguration, "Unable to add a property " << nodeParameters.key << " to the entity knowledge.");
                return mlv::behavior::decision::failed;
            }
        }
        
        // if (entityKnowledge.isTypeCompatible(p,nodeParameters.value.getType(nodeParameters.value.getRoot())))
        if (entityKnowledge.isTypeCompatible(p,mlv::utils::type::boolean))
        {
            // entityKnowledge.put(p,nodeParameters.value);
		    entityKnowledge.setBool(p, nodeParameters.value);
            return mlv::behavior::decision::succeeded;
        }
        else
        {
            MLV_LOG_ERROR(logger, mlv::utils::error::invalidConfiguration, "Unable to put the set value to 'entityKnowledge:" << nodeParameters.key << "'.");
            return mlv::behavior::decision::failed;
        }
    }
}













