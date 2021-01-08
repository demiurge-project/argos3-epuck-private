/**
 * @file <argos3/plugins/robots/e-puck/simulator/epuck_ground_leds_default_actuator.h>
 *
 * @author Lorenzo Garattoni - <lgaratto@ulb.ac.be>
 */
#ifndef EPUCK_GROUND_LEDS_DEFAULT_ACTUATOR_H
#define EPUCK_GROUND_LEDS_DEFAULT_ACTUATOR_H

namespace argos {
   class CEPuckGroundLEDsDefaultActuator;
}

#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_leds_actuator.h>
#include <argos3/plugins/simulator/entities/led_equipped_entity.h>
#include <argos3/core/simulator/actuator.h>

namespace argos {

   class CEPuckGroundLEDsDefaultActuator : public CSimulatedActuator,
                                           public CCI_EPuckGroundLEDsActuator {

   public:

      CEPuckGroundLEDsDefaultActuator();
      virtual ~CEPuckGroundLEDsDefaultActuator();
      void Init(TConfigurationNode& t_tree);
      virtual void SetRobot(CComposableEntity& c_entity);
      virtual void Update();
      virtual void Reset();

      #ifdef ARGOS_WITH_LUA
                /**
                 *
                 */
            virtual void CreateLuaState(lua_State* pt_lua_state) {}

      #endif

   private:

      CLEDEquippedEntity* m_pcLEDEquippedEntity;
      CLEDMedium*         m_pcLEDMedium;
      CColor              m_cUVColor;
   };
}

#endif
