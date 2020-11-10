/**
 * @file <argos3/plugins/robots/e-puck/control_interface/ci_epuck_Quad_RGB_leds_actuator.h
 *
  * @author Muhammad Salman- <>
 * @author Lorenzo Garattoni - <lgaratto@ulb.ac.be>
 */

#include "ci_epuck_quad_rgb_leds_actuator.h"

namespace argos {

   /****************************************/
   /****************************************/

   CCI_EPuckQuadRGBLEDsActuator::CCI_EPuckQuadRGBLEDsActuator() :
      m_tLEDSettings(4) {}

   /****************************************/
   /****************************************/

   void CCI_EPuckQuadRGBLEDsActuator::SetColor(size_t un_led_number,
                                                 const CColor& c_color) {
      m_tLEDSettings[un_led_number] = c_color;
   }

   /****************************************/
   /****************************************/

   void CCI_EPuckQuadRGBLEDsActuator::SetColors(const CColor& c_color) {
      SetColor(0, c_color);
      SetColor(1, c_color);
      SetColor(2, c_color);
      SetColor(3, c_color);
   }

   /****************************************/
   /****************************************/

   void CCI_EPuckQuadRGBLEDsActuator::SetColors(const TLEDSettings& t_colors) {
      SetColor(0, t_colors[0]);
      SetColor(1, t_colors[1]);
      SetColor(2, t_colors[2]);
      SetColor(2, t_colors[3]);
   }

   /****************************************/
   /****************************************/

}
