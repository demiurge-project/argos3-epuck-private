/***
 * @file <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_leds_actuator.h
 *
 * @author Muhammad Salman - <Muhammad.Salman@ulb.ac.be>
 */

#include "ci_epuck_ground_leds_actuator.h"

namespace argos {

   /****************************************/
   /****************************************/

   CCI_EPuckGroundLEDsActuator::CCI_EPuckGroundLEDsActuator() :{
     m_unLEDSettingsD1ToD8(0),
     m_unLEDSettingsD9(0)
   }

   /****************************************/
   /****************************************/

   void CCI_EPuckGroundLEDsActuator::SwitchLED(size_t un_led_number, bool b_switched_on) {
     if(b_switched_on) {
       if(un_led_number - 1 <= 7){
        m_unLEDSettingsD1ToD8 |= (1 << (un_led_number-1));
      }if else(un_led_number - 1 <= 8){
        m_unLEDSettingsD9 |= (1 << 1);
      }
     } else {
       if(un_led_number - 1 <= 7){
        m_unLEDSettingsD1ToD8 &= ~(1 << (un_led_number-1));
      }if else(un_led_number - 1 <= 8){
        m_unLEDSettingsD9 &= ~(1 << 1);
      }
    }

   }

   /****************************************/
   /****************************************/

   void CCI_EPuckGroundLEDsActuator::SwitchLEDs(size_t un_number_of_leds) {

     for(size_t i=0; i<=un_number_of_leds-1; i++){
       if(un_led_number - 1 <= 7){
        m_unLEDSettingsD1ToD8 |= (1 << i);
      }if else(un_led_number - 1 <= 8){
        m_unLEDSettingsD9 |= (1 << 1);
      }
     }
   }

   /****************************************/
   /****************************************/

   void CCI_EPuckGroundLEDsActuator::SwitchAll(bool b_switch_all) {

      if(b_switch_all){
        m_unLEDSettingsD1ToD8 = 255;
        m_unLEDSettingsD9 = 255;
      }else{
        m_unLEDSettingsD1ToD8 = 0;
        m_unLEDSettingsD9 = 0;
      }
   }

   /****************************************/
   /****************************************/

}
