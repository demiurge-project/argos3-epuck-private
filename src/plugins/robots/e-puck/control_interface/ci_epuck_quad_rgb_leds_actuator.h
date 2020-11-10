/**
 * @file <argos3/plugins/robots/e-puck/control_interface/ci_epuck_quad_RGB_leds_actuator.h
 *
 * This file provides the definition of the e-puck Quad_RGB LEDs actuator.
 *
 * The user can switch on the 4 RGB LEDs on ----
 * of the e-puck, specifying the RGB color.
 *
 * The LEDs are distributed as follows: (View from the top)
 *
 *        front
 *                 r
 *   l   0     1   i
 *   e             g
 *   f             h
 *   t   3     2   t
 *        back
 *
 * @author Muhammad Salman- <>
 * @author Lorenzo Garattoni- <lgaratto@ulb.ac.be>
 */

#ifndef CCI_EPUCK_QUAD_RGB_LEDS_ACTUATOR_H
#define CCI_EPUCK_QUAD_RGB_LEDS_ACTUATOR_H

#include <argos3/core/utility/logging/argos_log.h>

namespace argos {
   class CCI_EPuckQuadRGBLEDsActuator;
}

#include <argos3/core/utility/datatypes/color.h>
#include <argos3/core/control_interface/ci_actuator.h>

namespace argos {

   class CCI_EPuckQuadRGBLEDsActuator : public CCI_Actuator {

   public:

      /**
       * RGB LED settings data type
       */
      typedef std::vector<CColor> TLEDSettings;

   public:

      CCI_EPuckQuadRGBLEDsActuator();

      virtual ~CCI_EPuckQuadRGBLEDsActuator() {}

      /**
       * Sets the color of a single LED.
       * @param un_led_number The number of the LED [0-2]
       * @param c_color The wanted color.
       */
      virtual void SetColor(size_t un_led_number,
                            const CColor& c_color);

      /**
       * Sets the same color for all LEDs.
       * @param c_color The wanted color.
       */
      virtual void SetColors(const CColor& c_color);

      /**
       * Sets the colors of all LEDs individually.
       */
      virtual void SetColors(const TLEDSettings& c_colors);

// #ifdef ARGOS_WITH_LUA
//       /**
//        *
//        * @param pt_lua_state
//        */
//       virtual void CreateLuaState(lua_State* pt_lua_state);
// #endif

   protected:

      /**
       * RGB LEDs settings
       */
      TLEDSettings m_tLEDSettings;
   };

}
#endif
