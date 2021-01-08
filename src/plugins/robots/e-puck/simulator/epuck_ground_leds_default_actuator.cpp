/**
 * @file <argos3/plugins/robots/e-puck/simulator/epuck_ground_leds_default_actuator.cpp>
 *
 * @author Lorenzo Garattoni - <lgaratto@ulb.ac.be>
 */

#include "epuck_ground_leds_default_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/simulator/simulator.h>
#include <argos3/plugins/simulator/media/led_medium.h>

namespace argos {

   /****************************************/
   /****************************************/

   CEPuckGroundLEDsDefaultActuator::CEPuckGroundLEDsDefaultActuator() :
      m_pcLEDEquippedEntity(NULL) {
   }

   /****************************************/
   /****************************************/

   CEPuckGroundLEDsDefaultActuator::~CEPuckGroundLEDsDefaultActuator() {}

   /****************************************/
   /****************************************/

   void CEPuckGroundLEDsDefaultActuator::Init(TConfigurationNode& t_tree) {
      try {
         CCI_EPuckGroundLEDsActuator::Init(t_tree);
         std::string strMedium;
         GetNodeAttribute(t_tree, "medium", strMedium);
         m_pcLEDMedium = &CSimulator::GetInstance().GetMedium<CLEDMedium>(strMedium);
         m_pcLEDEquippedEntity->AddToMedium(*m_pcLEDMedium);
         m_cUVColor.SetRed(128);
         m_cUVColor.SetGreen(0);
         m_cUVColor.SetBlue(128);

      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Error initializing the e-puck Ground LEDs default actuator", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CEPuckGroundLEDsDefaultActuator::SetRobot(CComposableEntity& c_entity) {
      m_pcLEDEquippedEntity = &(c_entity.GetComponent<CLEDEquippedEntity>("leds"));
      m_pcLEDEquippedEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CEPuckGroundLEDsDefaultActuator::Update() {

     if(m_unOnUVLEDs == 0){
       m_pcLEDEquippedEntity->SetLEDColor(11,  CColor::BLACK);
       m_pcLEDEquippedEntity->SetLEDColor(12,  CColor::BLACK);
       m_pcLEDEquippedEntity->SetLEDColor(13,  CColor::BLACK);

     }
     else if (m_unOnUVLEDs <= 3){
       m_pcLEDEquippedEntity->SetLEDColor(11,  CColor::BLACK);
       m_pcLEDEquippedEntity->SetLEDColor(12,  m_cUVColor);
       m_pcLEDEquippedEntity->SetLEDColor(13,  CColor::BLACK);
     }
     else if ((m_unOnUVLEDs > 3) && (m_unOnUVLEDs <= 9)) {

      m_pcLEDEquippedEntity->SetLEDColor(11,  m_cUVColor);
      m_pcLEDEquippedEntity->SetLEDColor(12,  m_cUVColor);
      m_pcLEDEquippedEntity->SetLEDColor(13,  m_cUVColor);
     }
     // LOG<<m_pcLEDEquippedEntity->GetLED(11).GetColor()<<" color of leds in sim\n";
   }

   /****************************************/
   /****************************************/

   void CEPuckGroundLEDsDefaultActuator::Reset() {
     m_pcLEDEquippedEntity->SetLEDColor(11, CColor::BLACK);
     m_pcLEDEquippedEntity->SetLEDColor(12, CColor::BLACK);
     m_pcLEDEquippedEntity->SetLEDColor(13, CColor::BLACK);
   }

   /****************************************/
   /****************************************/

   REGISTER_ACTUATOR(CEPuckGroundLEDsDefaultActuator,
                     "epuck_ground_leds", "default",
                     "Lorenzo Garattoni [lgaratto@ulb.ac.be]",
                     "1.0",
                     "The epuck ground leds actuator.",
                     "This actuator controls a group of ground LEDs.\n"
                     "For usage, refer to [ci_epuck_ground_leds_actuator.h]\n\n"
                     "REQUIRED XML CONFIGURATION\n\n"
                     "   <controllers>\n"
                     "      ...\n"
                     "      <my_controller>\n"
                     "         ...\n"
                     "         <actuators>\n"
                     "            ...\n"
                     "            <epuck_ground_leds implementation=\"default\" medium=\"leds\"/>\n"
                     "            ...\n"
                     "         <actuators/>\n"
                     "         ...\n"
                     "      <my_controller/>\n"
                     "      ...\n"
                     "   <controllers>\n\n"
                     "The attribute [medium] refers to the [id] of the [led] medium defined\n"
                     "in the [media] xml section\n\n"
                     "   <media>\n"
                     "      ...\n"
                     "      <led id=\"leds\" grid_size=\"1,1,1\"/>\n"
                     "      ...\n"
                     "   </media>\n\n"
                     "OPTIONAL XML CONFIGURATION\n\n"
                     "None.\n",
                     "Usable");
}
