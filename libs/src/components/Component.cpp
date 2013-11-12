#include "Component.h"

#include <mlv/simulation/SimulationFramework.h>

#include <mlv/behavior/EntityProperties.h>

#include <algorithm>
#include <iterator>

namespace templates
{
    namespace impl_lib
    {
        Component::Component( mlv::simulation::SimulationFramework& simulation )
            : mlv::simulation::AbstractComponent(simulation)
			, entities_()
        {
        }

        Component::~Component()
        {
        }

        void Component::reserveEntityCount(std::size_t /*size*/)
        {
        }

        void Component::enableDebugger(bool state)
        {
        }

        bool Component::isDebuggerEnable() const
        {
            return false;
        }

        bool Component::areEntitiesRegistered(const mlv::utils::EntityIndex entities[], std::size_t entitiesSize) const
        {
            for (std::size_t i(0) ; i < entitiesSize ; ++i)
            {
                if (entities_.find(entities[i]) == entities_.end())
                    return false;
            }
            return true;
        }

        bool Component::doInitializeContext(mlv::utils::AbstractLogger* logger)
        {
            return true;
        }

        void Component::doTerminateContext()
        {
        }

        bool Component::doRegisterEntities(const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger*)
        {
            entities_.insert(entities, entities + entitiesSize);
            return true;
        }

        bool Component::doUnregisterEntities(const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger*)
        {
            entities_.erase(entities, entities + entitiesSize);
            return true;
        }

        bool Component::doInitializeEntities(const mlv::utils::EntityIndex*, std::size_t, mlv::utils::AbstractLogger*)
        {
            return true;
        }

        void Component::doTerminateEntities(const mlv::utils::EntityIndex*, std::size_t)
        {
        }

        bool Component::doUpdateEntities( const mlv::utils::Time& dt, const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger* logger)
        {
            for (std::size_t i(0) ; i < entitiesSize ; ++i)
            {
                mlv::utils::EntityIndex entity = entities[i];
                
            }
            return true;
        }
    }
}
