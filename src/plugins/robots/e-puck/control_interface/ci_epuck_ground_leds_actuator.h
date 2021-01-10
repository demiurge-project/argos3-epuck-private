/**
 * @file <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_leds_actuator.h
 *
 * This file provides the definition of the e-puck ground LEDs actuator.
 *
 * The user can switch on the 9 LEDs on the back of of the e-puck.
 *
 * The LEDs are distributed as follows: (View from the top)
 *
 *             front
 *                           r
 *   l                       i
 *   e                       g
 *   f                       h
 *   t                       t
 *       8 6 4 2 1 3 5 7 9
 *
 *              back
 *
 * @author Muhammad Salman - <Muhammad.Salman@ulb.ac.be>
 */

#ifndef CCI_EPUCK_GROUND_LEDS_ACTUATOR_H
#define CCI_EPUCK_GROUND_LEDS_ACTUATOR_H

#include <argos3/core/utility/logging/argos_log.h>

namespace argos {
   class CCI_EPuckGroundLEDsActuator;
}

#include <argos3/core/utility/datatypes/color.h>
#include <argos3/core/control_interface/ci_actuator.h>

namespace argos {

   class CCI_EPuckGroundLEDsActuator : public CCI_Actuator {

   public:

      /**
       * RGB LED settings data type
       */
      // typedef std::vector<CColor> TUVLEDSettings;

   public:

      CCI_EPuckGroundLEDsActuator();

      virtual ~CCI_EPuckGroundLEDsActuator() {}

      virtual void Init(TConfigurationNode& t_tree);

      /**
       * Switch on a number of LEDs.
       * @param un_number_of_leds The number of LEDs required to switch on.
       */
      virtual void SwitchLEDs(size_t un_number_of_leds);

      /**
       * Switch on/off all LEDs.
       *@param b_switch_all <tt>true</tt> to switch the LEDs on; <tt>false</tt> to switch them off.
       */
      virtual void SwitchAll(bool b_switch_all);


      UInt8 GetD1ToD8();

      UInt8 GetD9();

      virtual void SetOnUVLEDs(size_t un_On_UV_LEDs);

      size_t GetOnUVLEDs();


   protected:

     /**
      * State of the LED (8 bits, one for each LED, 0 for off, 1 for on)
      */
     UInt8 m_unLEDSettingsD1ToD8;

     /**
      * State of the 9th LED (8 bits, LSB for 9th LED, 0 for off, 1 for on)
      */
     UInt8 m_unLEDSettingsD9;


     /**
     * Number of UV LEDs on
     **/
     size_t m_unOnUVLEDs;

     /**
     * PWM value for ground LEDs
     */
    UInt8 m_unPWMGroundLED;


   };

}
#endif
