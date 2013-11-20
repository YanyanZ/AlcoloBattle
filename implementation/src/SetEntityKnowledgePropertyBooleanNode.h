#ifndef SET_ENTITY_KNOWLEDGE_PROPERTY_BOOLEAN_NODE_H
#define SET_ENTITY_KNOWLEDGE_PROPERTY_BOOLEAN_NODE_H

#include <mlv/behavior/bt/AbstractCustomNodeT.h>

namespace alcolo
{
    class SetEntityKnowledgePropertyBooleanParams : public mlv::utils::StaticObject
    {
        MLV_DEFINE_STATIC_OBJECT(alcolo::SetEntityKnowledgePropertyBooleanParams,"f41fd2f0-430e-43a6-9c4e-0752deaaac4c",setMetadata);
    public:
        SetEntityKnowledgePropertyBooleanParams();
        mlv::utils::String key;
        bool value;
		
		//void apply(mvl::utils::DynamicObject& entityKnowledge) const;
		
    private:
        static bool setMetadata( mlv::utils::TypeManager& manager, mlv::utils::AbstractLogger* logger );
    };

    class SetEntityKnowledgePropertyBooleanNode : public mlv::behavior::bt::AbstractCustomNodeT<SetEntityKnowledgePropertyBooleanParams>
    {
    public:
        SetEntityKnowledgePropertyBooleanNode();
        virtual ~SetEntityKnowledgePropertyBooleanNode();
        mlv::behavior::bt::AbstractCustomNode* clone() const;
        void destroy();

    private:
        virtual mlv::behavior::decision::Status doPropagate(
            mlv::behavior::bt::BTNodeIndex nodeIndex,
            const SetEntityKnowledgePropertyBooleanParams& nodeParameters,
            const mlv::utils::DynamicObject& behaviorParameters,
            mlv::behavior::bt::InterpreterFacade& interpreter,
            mlv::utils::AbstractLogger* logger);
    };
}

#endif
