#ifndef COMPONENT_H
#define COMPONENT_H

#include <mlv/simulation/AbstractComponent.h>

#include <mlv/utils/DynamicObject.h>
#include <mlv/utils/Mutex.h>
#include <mlv/utils/Set.h>
#include <mlv/utils/StaticObject.h>


namespace templates
{
	namespace impl_lib
	{
		class Component : public mlv::simulation::AbstractComponent
		{
			MLV_DEFINE_TYPE_1(templates::impl_lib::Component,"b9db16f2-8d5c-4074-b35f-60c624a17fdc",mlv::simulation::AbstractComponent);
		public:
			Component(mlv::simulation::SimulationFramework& simulation);
            virtual ~Component();

            void reserveEntityCount(std::size_t size);

			void enableDebugger(bool state);
            bool isDebuggerEnable() const;

            bool areEntitiesRegistered(const mlv::utils::EntityIndex entities[], std::size_t entitiesSize) const;
		private:
			virtual bool doInitializeContext( mlv::utils::AbstractLogger* logger );
			virtual void doTerminateContext();

            virtual bool doRegisterEntities( const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger* logger );
			virtual bool doUnregisterEntities( const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger* logger );

			virtual bool doInitializeEntities( const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger* logger );
			virtual void doTerminateEntities( const mlv::utils::EntityIndex entities[], std::size_t entitiesSize);

            virtual bool doUpdateEntities( const mlv::utils::Time& dt, const mlv::utils::EntityIndex entities[], std::size_t entitiesSize, mlv::utils::AbstractLogger* logger = 0 );

			mlv::utils::Set<mlv::utils::EntityIndex>::Type entities_;

		};
	}
}

#endif

