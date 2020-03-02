/**
 * @file <argos3/plugins/robot/e-puck/real_robot/real_epuck_ground_leds_actuator.h>
 *
 * @author Muhammad Salman - <Muhammad.Salman@ulb.ac.be>
 */

#ifndef REAL_EPUCK_GROUND_LEDS_ACTUATOR_H
#define REAL_EPUCK_GROUND_LEDS_ACTUATOR_H

namespace argos {
   class CRealEPuckGroundLEDsActuator;
}

#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_ground_leds_actuator.h>
#include <argos3/plugins/robots/e-puck/real_robot/real_epuck_i2c_actuator.h>

namespace argos {

   class CRealEPuckGroundLEDsActuator : virtual public CCI_EPuckGroundLEDsActuator,
                                     virtual public CRealEPuckI2CActuator {

   public:

      CRealEPuckGroundLEDsActuator();
      virtual ~CRealEPuckGroundLEDsActuator();

      virtual void Init_LED_Driver();
      void InitPWM(UInt8 DRIVER_PWM);

      virtual void SendData();
      virtual void SetPWM(UInt8 un_PWM_Ground_LED);

   private:

      TI2CDeviceStream m_tDeviceStream;

   };
}
#endif
