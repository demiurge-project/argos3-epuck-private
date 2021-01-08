/***
 * @file <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_leds_actuator.h
 *
 * @author Muhammad Salman - <Muhammad.Salman@ulb.ac.be>
 */

#include "ci_epuck_ground_leds_actuator.h"

namespace argos {

   /****************************************/
   /****************************************/

   CCI_EPuckGroundLEDsActuator::CCI_EPuckGroundLEDsActuator()
   {
     m_unLEDSettingsD1ToD8 = 0;
     m_unLEDSettingsD9 = 0;
     m_unOnUVLEDs = 0;
   }

   /****************************************/
   /****************************************/

   void CCI_EPuckGroundLEDsActuator::Init(TConfigurationNode& t_tree) {
      try {
         /* get the ground leds' PWM value from configuration file */

           GetNodeAttributeOrDefault(t_tree, "ground_led_pwm", m_unPWMGroundLED, 50);
         if (m_unPWMGroundLED > 255) {
            LOGERR << "[WARNING] Ground LEDS' PWM value =" << m_unPWMGroundLED
                   << ", value incorrect, back to default value data_size=" << 50 << std::endl;
            m_unPWMGroundLED = 50;
            LOGERR << "PWM in ci_robot Init" << m_unPWMGroundLED << std::endl;
         }
      } catch (CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Error initializing ground leds actuator", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CCI_EPuckGroundLEDsActuator::SwitchLEDs(size_t un_number_of_leds) {

     m_unOnUVLEDs = un_number_of_leds;

     m_unLEDSettingsD1ToD8 = 0;
     m_unLEDSettingsD9 = 0;

     switch (un_number_of_leds) {
       case 0:{
         m_unLEDSettingsD1ToD8 = 0;
         m_unLEDSettingsD9 = 0;
         break;
       }
       case 1:{
         m_unLEDSettingsD1ToD8 = 1;  // (0 0 0 0 0 0 0 1)
         m_unLEDSettingsD9 = 0;      // (x x x x x x x 0)
         break;
       }
       case 2:{
         m_unLEDSettingsD1ToD8 = 3; // (0 0 0 0 0 0 1 1)
         m_unLEDSettingsD9 = 0;     // (x x x x x x x 0)
         break;
       }
       case 3:{
         m_unLEDSettingsD1ToD8 = 7; // (0 0 0 0 0 1 1 1)
         m_unLEDSettingsD9 = 0;     // (x x x x x x x 0)
         break;
       }
       case 4:{
         m_unLEDSettingsD1ToD8 = 15; // (0 0 0 0 1 1 1 1)
         m_unLEDSettingsD9 = 0;      // (x x x x x x x 0)
         break;
       }
       case 5:{
         m_unLEDSettingsD1ToD8 = 31; // (0 0 0 1 1 1 1 1)
         m_unLEDSettingsD9 = 0;      // (x x x x x x x 0)
         break;
       }
       case 6:{
         m_unLEDSettingsD1ToD8 = 63; // (0 0 1 1 1 1 1 1)
         m_unLEDSettingsD9 = 0;      // (x x x x x x x 0)
         break;
       }
       case 7:{
         m_unLEDSettingsD1ToD8 = 127; // (0 1 1 1 1 1 1 1)
         m_unLEDSettingsD9 = 0;       // (x x x x x x x 0)
         break;
       }
       case 8:{
         m_unLEDSettingsD1ToD8 = 255; // (1 1 1 1 1 1 1 1)
         m_unLEDSettingsD9 = 0;       // (x x x x x x x 0)
         break;
       }
       case 9:{
         m_unLEDSettingsD1ToD8 = 255; // (1 1 1 1 1 1 1 1)
         m_unLEDSettingsD9 = 255;       // (1 1 1 1 1 1 1 1)
         break;
       }
       default:{
         m_unLEDSettingsD1ToD8 = 170; // (1 0 1 0 1 0 1 0)
         m_unLEDSettingsD9 = 0;     // (x x x x x x x 0)
       }

     }

   }

   /****************************************/
   /****************************************/

   UInt8 CCI_EPuckGroundLEDsActuator::GetD1ToD8(){
     return m_unLEDSettingsD1ToD8;
   }

   /****************************************/
   /****************************************/

   UInt8 CCI_EPuckGroundLEDsActuator::GetD9(){
     return m_unLEDSettingsD9;

   }

   void CCI_EPuckGroundLEDsActuator::SwitchAll(bool b_switch_all) {

      if(b_switch_all){
        m_unLEDSettingsD1ToD8 = 255;
        m_unLEDSettingsD9 = 255;
      }else{
        m_unLEDSettingsD1ToD8 = 0;
        m_unLEDSettingsD9 = 0;
      }
   }

}
//
//    // void CCI_EPuckGroundLEDsActuator::SetColor(size_t un_led_number,
//    //                                               const CColor& c_color) {
//    void CCI_EPuckGroundLEDsActuator::SetColor(size_t un_led_number, const CColor& c_color) {
//       // m_tUVLEDSettings[un_led_number] = c_color;
//       m_tUVLEDSettings[0] = CColor::RED;
//
//    }
//
//    /****************************************/
//    /****************************************/
//
//    void CCI_EPuckGroundLEDsActuator::SetColors(const CColor& c_color) {
//       SetColor(0, c_color);
//       SetColor(1, c_color);
//       SetColor(2, c_color);
//
//       // SetColor(0, CColor::BLUE);
//       // SetColor(1, CColor::RED);
//       // SetColor(2, CColor::BLUE);
//    }
//
//    /****************************************/
//    /****************************************/
//
//    void CCI_EPuckGroundLEDsActuator::SetColors(const TLEDSettings& t_colors) {
//       SetColor(0, t_colors[0]);
//       SetColor(1, t_colors[1]);
//       SetColor(2, t_colors[2]);
//
//       // SetColor(0, CColor::GREEN);
//       // SetColor(1, CColor::RED);
//       //
//       // SetColor(2, CColor::BLUE);
//
//    }
//
//    /****************************************/
//    /****************************************/
//
// }
